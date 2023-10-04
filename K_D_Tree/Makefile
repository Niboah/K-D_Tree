all: KDTree

CC = g++
CFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11

KDTree: KDTree.o Main.o
	$(CC) $(CFLAGS) -o Main KDTree.o Main.o

Main.o: main.cpp KDTree.h
	$(CC) $(CFLAGS) -c main.cpp

KDTree.o: KDTree.cpp KDTree.h
	$(CC) $(CFLAGS) -c KDTree.cpp

clean:
	rm *.o
	rm *.exe
