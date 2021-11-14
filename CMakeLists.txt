cmake_minimum_required(VERSION 3.20)
project(VigenereCipher C)

set(CMAKE_C_STANDARD 99)

add_executable(VigenereCipher src/main.c includes/vigenereCipher.h src/vigenereCipher.c includes/babageAttack.h src/babageAttack.c)
