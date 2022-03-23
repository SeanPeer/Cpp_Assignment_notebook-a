/**
 * @file Test.cpp
 * @author Sean Peer (SeanPeer@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

#include <string>
using namespace std;


ariel::Notebook notebook;

TEST_CASE("Good input") {
    CHECK_NOTHROW(notebook.write(1, 2, 3, Direction::Horizontal, "string"));
    CHECK_NOTHROW(notebook.write(0, 0, 0, Direction::Horizontal, "Hello World"));
    CHECK_NOTHROW(notebook.write(15, 20, 30, Direction::Horizontal, "Hello World!@#"));
    CHECK_NOTHROW(notebook.read(1, 10, 1, Direction::Horizontal, 15)); 
    CHECK_NOTHROW(notebook.read(1, 10, 1, Direction::Horizontal, 110)); 
    CHECK_NOTHROW(notebook.erase(1, 10, 1, Direction::Horizontal, 10)); 
}

TEST_CASE("Bad input - Negetive input") {
    CHECK_THROWS(notebook.write(-1, 1, 1, Direction::Horizontal, ""));
    CHECK_THROWS(notebook.write(1, -1, 1, Direction::Horizontal, ""));
    CHECK_THROWS(notebook.write(1, 1, -1, Direction::Horizontal, "Walla"));
    CHECK_THROWS(notebook.write(-1, -1., 1, Direction::Horizontal, "Negativee"));
    CHECK_THROWS(notebook.write(-1, 1, -1, Direction::Horizontal, "Negativee"));
    CHECK_THROWS(notebook.write(1, -1, -1, Direction::Horizontal, "Negativee!!"));
    CHECK_THROWS(notebook.write(-1, -1, -1, Direction::Horizontal, "Negativee"));
    CHECK_THROWS(notebook.read(1, 10, 1, Direction::Horizontal, -10)); 
    CHECK_THROWS(notebook.read(1, 10, 1, Direction::Horizontal, -110)); 
    CHECK_THROWS(notebook.erase(1, 10, 1, Direction::Horizontal, -30)); 
    CHECK_THROWS(notebook.erase(1, 10, 1, Direction::Horizontal, -2)); 
    
}

TEST_CASE("Bad input - Out of range ") {
    CHECK_THROWS(notebook.write(1, 1, 1, Direction::Horizontal, "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
    CHECK_THROWS(notebook.write(0, 12, 3, Direction::Horizontal, "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
    CHECK_THROWS(notebook.write(1, 50, 10, Direction::Horizontal, "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
    CHECK_THROWS(notebook.write(1, 101, 1, Direction::Horizontal, "Negative"));    
}