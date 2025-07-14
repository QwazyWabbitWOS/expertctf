#
# Quake2 Makefile for Linux
#
#
# Edited July 13, 2025 by QwazyWabbit
#

.DEFAULT_GOAL := game

# this nice line comes from the linux kernel makefile
ARCH := $(shell uname -m | sed -e s/i.86/i386/ \
	-e s/sun4u/sparc64/ -e s/arm.*/arm/ \
	-e s/sa110/arm/ -e s/alpha/axp/)

# On 64-bit OS use the command: setarch i386 make all
# to obtain the 32-bit binary DLL on 64-bit Linux.

CC = gcc -std=c17 -Wall -Wpedantic

# on x64 machines do this preparation:
# sudo apt-get install ia32-libs
# sudo apt-get install libc6-dev-i386
# On Ubuntu 16.x and higher use sudo apt install libc6-dev-i386
# this will let you build 32-bits on ia64 systems
#
# This is for native build
CFLAGS=-O3 -DARCH="$(ARCH)" -DSTDC_HEADERS
# This is for 32-bit build on 64-bit host
ifeq ($(ARCH),i386)
CFLAGS += -m32 -I/usr/include
endif

# use this when debugging
#CFLAGS=-g -Og -DDEBUG -DARCH="$(ARCH)" -Wall -pedantic

# flavors of Linux
ifeq ($(shell uname),Linux)
CFLAGS += -DLINUX
LIBTOOL = ldd
endif

# OS X wants to be Linux and FreeBSD too.
ifeq ($(shell uname),Darwin)
CFLAGS += -DLINUX
LIBTOOL = otool
endif

SHLIBEXT=so
#set position independent code
SHLIBCFLAGS=-fPIC

# Build directory
BUILD_DIR = build$(ARCH)

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# List of source files
GAME_SRCS = \
	g_ai.c p_client.c g_cmds.c g_combat.c g_func.c g_items.c \
	g_main.c g_pakread.c g_misc.c g_monster.c g_phys.c g_save.c g_spawn.c \
	g_target.c g_trigger.c g_utils.c g_weapon.c m_move.c p_hud.c \
	p_trail.c p_view.c p_weapon.c q_shared.c warp.c \
	e_arena.c e_game.c e_gbstat.c e_grapple.c e_id.c e_ftrack.c \
	e_matrix.c e_motd.c e_obit.c e_overlay.c e_team.c e_util.c \
	darray.c list.c props.c g_ctf.c p_menu.c g_svcmds.c \
	g_observe.c
GAME_OBJS = $(GAME_SRCS:%.c=$(BUILD_DIR)/%.o)

# Pattern rule to place objects in build directory
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SHLIBCFLAGS) -MMD -MP -MF $(@:.o=.d) -o $@ -c $<

-include $(GAME_OBJS:.o=.d)

# Build all object files that are out-of-date
game: $(GAME_OBJS) game$(ARCH).real.$(SHLIBEXT)

# Main target: depends on all object files
game$(ARCH).real.$(SHLIBEXT): $(GAME_OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $(GAME_OBJS) -ldl -lm
	$(LIBTOOL) -r $@
	file $@

# Build everything (always rebuild all objects and the shared library)
all:
	$(MAKE) clean
	$(MAKE) $(BUILD_DIR)
	$(MAKE) $(GAME_OBJS)
	$(MAKE) game$(ARCH).real.$(SHLIBEXT)

clean:
	rm -rf $(BUILD_DIR)
