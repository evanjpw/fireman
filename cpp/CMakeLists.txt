cmake_minimum_required(VERSION 3.13)
project(fireman)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(fireman
        src/fireman.cpp
        src/fireman.h
        src/main.cpp
        src/TwoLetterBuckets.cpp
        src/TwoLetterBuckets.h
        src/WordDepthPair.cpp
        src/WordDepthPair.h
        src/WordList.cpp
        src/WordList.h
        words.txt
        words_alpha.txt)
