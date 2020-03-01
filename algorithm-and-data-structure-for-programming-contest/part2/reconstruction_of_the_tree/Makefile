main: main.cc
	clang++ -o main -std=c++11 main.cc

test: main
	./test.sh

test_v: validate.cc
	clang++ -o validate -std=c++11 validate.cc
	./test_v.sh
