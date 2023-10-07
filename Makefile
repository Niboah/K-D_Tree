all: KDTree

CC = g++
CFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11

KDTree: KDTree.o main.o
	$(CC) $(CFLAGS) -o main.exe KDTree.o main.o
	rm *.o

main.o: src/main.cpp src/KDTree.h
	$(CC) $(CFLAGS) -c src/main.cpp

KDTree.o: src/KDTree.cpp src/KDTree.h
	$(CC) $(CFLAGS) -c src/KDTree.cpp

clean:
	rm *.exe
