# Archivo make de mi album de programas
ProyectoPA_01.exe:Fraccion.o main.o
	mingw32-g++.exe  -o ProyectoPA_01.exe Fraccion.o main.o  -s
Fraccion.o:Fraccion.cpp
	mingw32-g++.exe -Wall -fexceptions -O2 -IC:\Users\LMC\2021\ProyectoPA_01 -c Fraccion.cpp -o Fraccion.o
main.o:main.cpp	
	mingw32-g++.exe -Wall -fexceptions -O2 -IC:\Users\LMC\2021\ProyectoPA_01 -c main.cpp -o main.o
test.exe:Fraccion.o main.o test.o
	mingw32-g++.exe  -o text.exe Fraccion.o main.o test.o  -s
test.o:test.cpp
	mingw32-g++.exe -Wall -fexceptions -O2 -IC:\Users\LMC\2021\ProyectoPA_01 -c test.cpp -o test.o

