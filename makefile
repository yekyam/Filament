# MAKEFILE FOR MAC
SOURCES = source/src/*
TEST_SOURCES = source/tests/*.cpp
STANDARD = -std=c++20
DEBUG_BUILD_FLAGS = -g -Wall
LIBRARIES = -lglew -lglfw -framework OpenGL
INCLUDE_DEPS = source/deps/glad/include

default: release

build_release: 
	g++ -O3 $(STANDARD) $(LIBRARIES) $(SOURCES) -I$(INCLUDE_DEPS) source/deps/glad/src/glad.c source/main.cpp -o main 

build_test:
	g++ $(DEBUG_BUILD_FLAGS) $(STANDARD) $(LIBRARIES) $(SOURCES) $(TEST_SOURCES) -I$(INCLUDE_DEPS) source/deps/glad/src/glad.c -o tester

release: build_release
	./main

test: build_test
	./tester

clean:
	rm ./main
	rm ./tester