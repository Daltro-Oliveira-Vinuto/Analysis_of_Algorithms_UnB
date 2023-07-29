all: clear compile test


clear:
	cls

compile:
	g++ -Wall -Wextra -pthread -std=c++17 test.cpp -o test.exe

run:
	./test.exe

test:
	test.exe < in > myout
	fc myout out