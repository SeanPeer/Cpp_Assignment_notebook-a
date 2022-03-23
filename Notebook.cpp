/**
 * @file Notebook.cpp
 * @author Sean Peer (SeanPeer@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <string>
#include <iostream>

using namespace std;

namespace ariel {

            void Notebook::write (int page, int row , int column , Direction direction, string str) 
            {

            };

            string Notebook::read (int page, int row , int column , Direction direction, int length)
            {
                string str = "BLAH BLAH";
                return str;
            };

            string Notebook::erase (int page, int row , int column , Direction direction, int length)
            {
                string str = "String has been deleted";
                return str;
            };

            void Notebook::show (int pageNumber)
            {
                
            };

};