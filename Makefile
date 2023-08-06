#
# Quake2 gamei386.so Makefile for Linux 
#

# this nice line comes from the linux kernel makefile
ARCH := $(shell uname -m | sed -e s/i.86/i386/ -e s/sun4u/sparc64/ -e s/arm.*/arm/ -e s/sa110/arm/ -e s/alpha/axp/)

#ARCH = i386
CC = gcc -std=c11 -Wall -Wpedantic

# on x64 machines do this preparation:
# sudo apt-get install ia32-libs
# sudo apt-get install libc6-dev-i386
# On Ubuntu 16.x use sudo apt install libc6-dev-i386
# this will let you build 32-bits on ia64 systems
#
# This is for native build
CFLAGS=-O3 -DARCH="$(ARCH)"
# This is for 32-bit build on 64-bit host
ifeq ($(ARCH),i386)
CFLAGS =-m32 -O3 -fPIC -DARCH="$(ARCH)" -DSTDC_HEADERS -I/usr/include
endif

# use this when debugging
#CFLAGS=-g -Og -DEBUG -DARCH="$(ARCH)" -Wall -pedantic

# The optimization flags below cause a crash immediately after connect 
# with slackware. You might try adding flags one by one and recompiling 
# for some extra speed.
# -funroll-loops

# flavors of Linux
ifeq ($(shell uname),Linux)
#SVNDEV := -D'SVN_REV="$(shell svnversion -n .)"'
#CFLAGS += $(SVNDEV)
CFLAGS += -DLINUX
LIBTOOL = ldd
endif

# OS X wants to be Linux and FreeBSD too.
ifeq ($(shell uname),Darwin)
#SVNDEV := -D'SVN_REV="$(shell svnversion -n .)"'
#CFLAGS += $(SVNDEV)
CFLAGS += -DLINUX
LIBTOOL = otool
endif

LDFLAGS=-ldl -lm
SHLIBEXT=so
SHLIBCFLAGS=-fPIC
SHLIBLDFLAGS=-shared

DO_CC=$(CC) $(CFLAGS) $(SHLIBCFLAGS) -o $@ -c $<

#############################################################################
# SETUP AND BUILD
# GAME
#############################################################################

.c.o:
	$(DO_CC)

GAME_OBJS = \
	g_ai.o p_client.o g_cmds.o g_combat.o g_func.o g_items.o \
	g_main.o g_pakread.o g_misc.o g_monster.o g_phys.o g_save.o g_spawn.o \
	g_target.o g_trigger.o g_utils.o g_weapon.o m_move.o p_hud.o \
	p_trail.o p_view.o p_weapon.o q_shared.o warp.o \
	e_arena.o e_game.o e_gbstat.o e_grapple.o e_id.o e_ftrack.o \
	e_matrix.o e_motd.o e_obit.o e_overlay.o e_team.o e_util.o \
	darray.o list.o props.o g_ctf.o p_menu.o g_svcmds.o \
	g_observe.o

game$(ARCH).$(SHLIBEXT) : $(GAME_OBJS)
	$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(GAME_OBJS) $(LDFLAGS)
	$(LIBTOOL) -r $@


#############################################################################
# MISC
#############################################################################

clean:
	-rm -f $(GAME_OBJS)

depends:
	$(CC) $(CFLAGS) -MM *.c > dependencies

all:
	$(MAKE) clean
	$(MAKE) depends
	$(MAKE)
	$(MAKE) clean
	setarch i386 $(MAKE)

-include dependencies
