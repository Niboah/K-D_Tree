all: KDTree

CC = g++
CFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11

KDTree: KDTree.o Main.o
<<<<<<< HEAD
	$(CC) $(CFLAGS) -o Main.exe KDTree.o Main.o
	rm *.o

Main.o: src/main.cpp src/KDTree.h
	$(CC) $(CFLAGS) -c src/main.cpp

KDTree.o: src/KDTree.cpp src/KDTree.h
	$(CC) $(CFLAGS) -c src/KDTree.cpp
=======
	$(CC) $(CFLAGS) -o Main KDTree.o Main.o

Main.o: main.cpp KDTree.h
	$(CC) $(CFLAGS) -c main.cpp

KDTree.o: KDTree.cpp KDTree.h
	$(CC) $(CFLAGS) -c KDTree.cpp
>>>>>>> 136e675 (first commit)

clean:
	rm *.o
	rm *.exe
