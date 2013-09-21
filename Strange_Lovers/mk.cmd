
echo off 
set path = C:\cygwin\usr\local\bin;C:\cygwin\usr\bin;C:\cygwin\bin 
del /Q *.rxe 
 
<<<<<<< HEAD
make all 

IF EXIST * sh appflash.sh
=======
make all 

IF EXIST appflash.sh sh appflash.sh
>>>>>>> look

