#
# Quake2 gamei386.so Makefile for Linux 
#

ARCH=i386
CC=gcc
BASE_CFLAGS=

# The optimization flags below cause a crash immediately after connect 
# with slackware. You might try adding flags one by one and recompiling 
# for some extra speed.
# -funroll-loops

#use these cflags to optimize it
CFLAGS=$(BASE_CFLAGS)-m32 -O3 -ffast-math

#use these when debugging 
#CFLAGS=$(BASE_CFLAGS) -g

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
	$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(GAME_OBJS)


#############################################################################
# MISC
#############################################################################

clean:
	-rm -f $(GAME_OBJS)
	-rm -f game$(ARCH).$(SHLIBEXT)

depends:
	$(CC) $(CFLAGS) -MM *.c > dependencies

all:
	make clean
	make depends
	make

-include dependencies
