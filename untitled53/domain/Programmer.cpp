//
// Created by eddis on 6/20/2021.
//
#include <sstream>
#include "Programmer.h"


string Programmer::get_string(){
    stringstream ss;
    ss<<" Id"<<id<<" Name"<<name;
    return ss.str();
}