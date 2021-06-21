//
// Created by eddis on 6/20/2021.
//

#include "programmer_repo.h"
#include <sstream>
#include <fstream>

void programmer_repo::add_programmer(Programmer p){
    array.push_back(p);
}

vector<Programmer> programmer_repo::get_programmers(){
    return array;
}

std::vector<string> split_string(const std::string &s, char delimitator) {
    std::vector<string> elements;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delimitator)) {
        elements.push_back(number);
    }
    return elements;
}

void programmer_repo::load_data(){
    fstream file;
    Programmer programmer;
    file.open("../data/programmer.txt");
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            std::vector<string> strings=split_string(line,';');
            programmer.id=std::stoi(strings[0]);
            programmer.name=strings[1];
            array.push_back(programmer);
        }
        file.close();
    }
}