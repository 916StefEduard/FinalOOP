//
// Created by eddis on 6/20/2021.
//

#ifndef HELLOWORLD_SOURCEFILE_H
#define HELLOWORLD_SOURCEFILE_H
#include <string>
using namespace std;
class SourceFile {
public:
    string name;
    string status;
    string creator;
    string reviser;
public:


    string to_string();
};


#endif //HELLOWORLD_SOURCEFILE_H
