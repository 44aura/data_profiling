gcc -Wall main main.cpp
valgrind --leak-check=full ./main
valgrind --tool=cachegrind ./main