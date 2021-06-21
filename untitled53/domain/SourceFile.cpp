//
// Created by eddis on 6/20/2021.
//

#include "SourceFile.h"
#include <sstream>

string SourceFile::to_string(){
    stringstream ss;
    ss<<" Name:"<<name<<" |Status:"<<status<<" |Creator:"<<creator<<" |Reviser:"<<reviser;
    return ss.str();
}