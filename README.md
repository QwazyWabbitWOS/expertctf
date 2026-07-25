## Expert CTF DLL code for Windows and Linux ##

* This is Expert CTF for Quake 2
* Version 4.0.5 is some slight bug fixes and system portability across Windows, Linux, OS X
* This code is forked from V4.0.3 code originally downloaded from http://expertctf.org/index.php?linkid=11&SELOPT=5
* Client side files are available from http://expertctf.org/index.php.

## How to set up? ##

### Linux ###
* git clone https://github.com/QwazyWabbitWOS/expertctf.git
* Then 'make clean', then 'make -j all'. This builds x64 by default on x64 Linux. See the instructions in the Makefile for x86 targets in on x64 Linux hosts.
* Dependencies: gcc and GNU make.
* Copy or move the resulting *.so files to the ctf folder of your quake2 installation. This will be either 'ctf' or 'expert'.

### Windows ###
* On Windows with VS2022, use git clone per above, then open the .sln file with VS.
* Rebuild Solution.

## Knowns bugs as of 2020.05.17 ##

* None

## Who do I talk to? ##

* This repository is maintained by QwazyWabbit[WOS] gandalf.2004 at gmail.com
