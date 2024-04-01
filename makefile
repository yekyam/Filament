# MAKEFILE FOR MAC
SOURCES = source/src/*
TEST_SOURCES = source/tests/*.cpp
STANDARD = -std=c++20
DEBUG_BUILD_FLAGS = -g -Wall -Werror
LIBRARIES = -lglew -lglfw -framework OpenGL

default: release

build_release: 
	g++ -O3 $(STANDARD) $(LIBRARIES) $(SOURCES) source/main.cpp -o main 

build_test:
	g++ $(DEBUG_BUILD_FLAGS) $(STANDARD) $(LIBRARIES) $(SOURCES) $(TEST_SOURCES) -o tester

release: build_release
	./main

test: build_test
	./tester
