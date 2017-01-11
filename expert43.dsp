# Microsoft Developer Studio Project File - Name="expert40" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (ALPHA) Dynamic-Link Library" 0x0602

CFG=expert40 - Win32 Debug Alpha
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "expert40.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "expert40.mak" CFG="expert40 - Win32 Debug Alpha"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "expert40 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "expert40 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "expert40 - Win32 Debug Alpha" (based on "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE "expert40 - Win32 Release Alpha" (based on "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/expert40", JAAAAAAA"
# PROP Scc_LocalPath "."

!IF  "$(CFG)" == "expert40 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir "."
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\release"
# PROP Intermediate_Dir ".\release"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir "."
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /G5 /MT /GX /O1 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "WIN32_LEAN_AND_MEAN" /YX /FD /c
# SUBTRACT CPP /Fr
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# SUBTRACT MTL /mktyplib203 /Oicf
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib winmm.lib /nologo /base:"0x20000000" /subsystem:windows /dll /machine:I386 /out:".\release/gamex86.dll"
# SUBTRACT LINK32 /incremental:yes /debug /nodefaultlib

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir "."
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\debug"
# PROP Intermediate_Dir ".\debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir "."
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /G5 /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "BUILDING_REF_GL" /FR /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib winmm.lib /nologo /base:"0x20000000" /subsystem:windows /dll /incremental:no /map /debug /machine:I386 /out:".\debug/gamex86.dll"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug Alpha"
# PROP BASE Intermediate_Dir "Debug Alpha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\DebugAxp"
# PROP Intermediate_Dir ".\DebugAxp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /MTd /c
# ADD CPP /nologo /Gt0 /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "C_ONLY" /YX /FD /QA21164 /MTd /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x20000000" /subsystem:windows /dll /debug /machine:ALPHA
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x20000000" /subsystem:windows /dll /debug /machine:ALPHA /out:"..\DebugAxp/gameaxp.dll"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "game___W"
# PROP BASE Intermediate_Dir "game___W"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\ReleaseAXP"
# PROP Intermediate_Dir ".\ReleaseAXP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /Gt0 /W3 /GX /Zd /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /Gt0 /W3 /GX /Zd /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "C_ONLY" /YX /FD /QA21164 /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /base:"0x20000000" /subsystem:windows /dll /machine:ALPHA /out:"..\Release/gamex86.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib /nologo /base:"0x20000000" /subsystem:windows /dll /machine:ALPHA /out:"..\ReleaseAXP/gameaxp.dll"

!ENDIF 

# Begin Target

# Name "expert40 - Win32 Release"
# Name "expert40 - Win32 Debug"
# Name "expert40 - Win32 Debug Alpha"
# Name "expert40 - Win32 Release Alpha"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\darray.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_arena.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_ftrack.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_game.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_gbstat.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_grapple.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_id.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_matrix.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_motd.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_obit.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_overlay.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_team.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\e_util.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_ai.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_cmds.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_combat.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_ctf.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_func.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_items.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_main.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_misc.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_monster.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_observe.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_pakread.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_phys.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_save.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_spawn.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_svcmds.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_target.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_trigger.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_utils.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\g_weapon.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\list.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\m_move.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\p_client.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\p_hud.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\p_menu.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\p_trail.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\p_view.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\p_weapon.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\props.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\q_shared.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\warp.c

!IF  "$(CFG)" == "expert40 - Win32 Release"

# ADD CPP /O2 /D "WIN32_LEAN_AND_MEAN" /YX

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Debug Alpha"

!ELSEIF  "$(CFG)" == "expert40 - Win32 Release Alpha"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\darray.h
# End Source File
# Begin Source File

SOURCE=.\e_arena.h
# End Source File
# Begin Source File

SOURCE=.\e_defs.h
# End Source File
# Begin Source File

SOURCE=.\e_ftrack.h
# End Source File
# Begin Source File

SOURCE=.\e_gbstat.h
# End Source File
# Begin Source File

SOURCE=.\e_grapple.h
# End Source File
# Begin Source File

SOURCE=.\e_iovr.h
# End Source File
# Begin Source File

SOURCE=.\e_matrix.h
# End Source File
# Begin Source File

SOURCE=.\e_obit.h
# End Source File
# Begin Source File

SOURCE=.\e_overlay.h
# End Source File
# Begin Source File

SOURCE=.\e_team.h
# End Source File
# Begin Source File

SOURCE=.\e_util.h
# End Source File
# Begin Source File

SOURCE=.\g_ctf.h
# End Source File
# Begin Source File

SOURCE=.\g_local.h
# End Source File
# Begin Source File

SOURCE=.\g_observe.h
# End Source File
# Begin Source File

SOURCE=.\g_pakread.h
# End Source File
# Begin Source File

SOURCE=.\game.h
# End Source File
# Begin Source File

SOURCE=.\list.h
# End Source File
# Begin Source File

SOURCE=.\m_player.h
# End Source File
# Begin Source File

SOURCE=.\p_menu.h
# End Source File
# Begin Source File

SOURCE=.\props.h
# End Source File
# Begin Source File

SOURCE=.\q_shared.h
# End Source File
# Begin Source File

SOURCE=.\warp.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\game.def
# End Source File
# End Group
# End Target
# End Project
