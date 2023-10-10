all: KDTree KDTree_Correctesa cleano

CC = g++
CFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11

KDTree: KDTree.o main.o
	$(CC) $(CFLAGS) -o main.exe KDTree.o main.o

KDTree_Correctesa: KDTree.o main_correctesa.o
	$(CC) $(CFLAGS) -o main_correctesa.exe KDTree.o main_correctesa.o

main.o: src/main.cpp src/KDTree.h
	$(CC) $(CFLAGS) -c src/main.cpp

main_correctesa.o: src/main_correctesa.cpp src/KDTree.h
	$(CC) $(CFLAGS) -c src/main_correctesa.cpp

KDTree.o: src/KDTree.cpp src/KDTree.h
	$(CC) $(CFLAGS) -c src/KDTree.cpp

cleano:
	rm *.o

clean:
	rm *.exe