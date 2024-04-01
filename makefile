default: build_and_run

build_and_run: 
	g++ -g -std=c++20 source/src/* -o main -lglew
	./main
