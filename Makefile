all:
	clang++ -O3 -std=c++20 -Iinclude. -o Main Main.cpp

run: all
	./Main
