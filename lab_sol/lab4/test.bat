@echo off
mingw32-make
.\pdadd.exe
pause
.\pdlist.exe
pause
.\pdlist.exe 20140424 20140426
pause
.\pdshow.exe 20140423
pause
.\pdremove.exe 20140428
pause
