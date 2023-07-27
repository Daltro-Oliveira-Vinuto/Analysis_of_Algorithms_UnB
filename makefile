all: clear compile run


clear:
	cls

compile:
	g++ -Wall -Wextra -pthread -std=c++17 test.cpp -o test.exe

run:
	./test.exe