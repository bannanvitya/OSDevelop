src = /cygdrive/c/yniver/OSDevelop/src/
build = /cygdrive/c/yniver/OSDevelop/bin/
release_path = ${build}release/
debug_path = ${build}debug/
object_path = ${debug_path}obj/

default: main

main: ${object_path}main.o 
	gcc ${object_path}main.o  -o ${debug_path}main

${object_path}main.o: ${src}main.c
	gcc -c ${src}main.c -o ${object_path}main.o 