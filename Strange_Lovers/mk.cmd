
echo off 
set path = C:\cygwin\usr\local\bin;C:\cygwin\usr\bin;C:\cygwin\bin 
del /Q *.rxe 
 
make all -f Makefile_in

IF EXIST appflash.sh sh appflash.sh

