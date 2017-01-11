# THIS FILE IS OUTDATED AND NEEDS TO BE UPDATED!!! iT WON'T COMPILE ALL FILES NEEDED AT THIS POINT
# Quake2 gamesparc.so Makefile for Solaris 2.6
#

ARCH=sparc
CC=gcc
BASE_CFLAGS=-Dstricmp=strcasecmp

#use these cflags to optimize it
CFLAGS=$(BASE_CFLAGS) -funroll-loops \
	-fomit-frame-pointer -fexpensive-optimizations -fno-strength-reduce
#use these when debugging 
#CFLAGS=$(BASE_CFLAGS) -g

LDFLAGS=-ldl -lm -lsocket
SHLIBEXT=so
SHLIBCFLAGS=-fPIC
SHLIBLDFLAGS=-G

DO_CC=$(CC) $(CFLAGS) $(SHLIBCFLAGS) -o $@ -c $<

#############################################################################
# SETUP AND BUILD
# GAME
#############################################################################

.c.o:
	$(DO_CC)

GAME_OBJS = \
	darray.o e_arena.o e_ftrack.o e_game.o e_gbstat.o e_grapple.o \
	e_id.o e_matrix.o e_motd.o e_obit.o e_overlay.o e_team.o e_util.o \
	g_ai.o g_cmds.o g_combat.o g_ctf.o g_func.o g_items.o \
	g_main.o g_misc.o g_monster.o g_observe.o g_phys.o g_save.o \
	g_spawn.o g_svcmds.o g_target.o g_trigger.o g_utils.o g_weapon.o \
	list.o m_move.o p_client.o p_hud.o p_menu.o p_trail.o p_view.o \
	p_weapon.o props.o q_shared.o
	# g_so.o # this file is a shared library thingie needed for Solaris

game$(ARCH).$(SHLIBEXT) : $(GAME_OBJS)
	$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(GAME_OBJS)


#############################################################################
# MISC
#############################################################################

clean:
	-rm -f $(GAME_OBJS)

depend:
	gcc -MM $(GAME_OBJS:.o=.c)

