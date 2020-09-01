main: main.cc
	clang++ -fsanitize=address -o main -std=c++14 -I/Users/bokken/blib/include -L/Users/bokken/blib/lib -lbokken main.cc

test: main
	./test.sh

