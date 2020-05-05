### Expert CTF DLL code for Windows and Linux ###

* This is Expert CTF for Quake 2
* Version 4.0.5 is some slight bug fixes and system portability across Windows, Linux, OS X
* This code is forked from V4.0.3 code originally downloaded from http://expertctf.net/index.php?linkid=11&SELOPT=5
* Client side files are available from the expertctf.net site above.

### How to set up? ###

* git clone https://github.com/QwazyWabbitWOS/expertctf.git
* On Linux, make clean, then make.
* Dependencies: Visual Studio 2010 on Windows, or gcc/clang and GNU make on Linux
* On Windows with VS2010, use git clone per above, then open the .sln file with VS.
* This version compiles cleanly on Debian Linux GCC 4.3.2 and OS X 10.12.2 with Clang 8.0.0
* NOTE: the Debug directory will be created by cloning the repo, you'll need to delete it after your local repository is created, sorry about that. The .gitignore file wasn't up to date before I installed the repo here.

### Knowns bugs as of 2020.05.05 ###

* The game used to leak memory like crazy. The props commands again. The props list doesn't use the game allocator but uses malloc, realloc and calloc without freeing it properly while the game is running and it doesn't free them on shutdown. (Note: this has been fixed. All malloc calls have been converted to gi.TagMalloc per standard Q2 practice. Hopefully no more leaks and the server no longer needs periodic resets. Please report any issues.)
* Potential null pointer dereferences in the obituary code. Possible lost pointer calling realloc. (Fixed. All reallocs have been transformed into resizes via gi.TagMalloc and gi.TagFree)

### Who do I talk to? ###

* This repository is maintained by QwazyWabbit[WOS], www.clanwos.org

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)
