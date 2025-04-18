# This can be generilized, but  i am learning
# The -c flag stands for "compile only"
# 	so the compiler does not try to link
#	and find a main() function

all: allocator

allocator: Main.o GC.o
	g++ -o allocator Main.o GC.o

Main.o: code/Main.cpp  code/GC.h
	g++ -o Main.o code/Main.cpp -c -Wall

GC.o: code/GC.cpp code/GC.h
	g++ -o GC.o code/GC.cpp -c -Wall

clean:
	rm -rf *.o *~allocator

