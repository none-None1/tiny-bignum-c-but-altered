@echo off
gcc -c bn.c -o bn.o
ar -crv libbn.a bn.o
g++ -c bn_cpp.cpp -o bn_cpp.o -std=c++11
ar -crv libbn_cpp.a bn_cpp.o
g++ testcpp.cpp -o testcpp.exe -L. -lbn_cpp -lbn -std=c++11
