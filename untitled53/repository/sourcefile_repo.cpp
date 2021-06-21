//
// Created by eddis on 6/20/2021.
//
#include <sstream>
#include "sourcefile_repo.h"
#include <fstream>
void sourcefile_repo::add_sourcefile(SourceFile s){
    array.push_back(s);
}

vector<SourceFile> &sourcefile_repo::get_array(){
    return array;
}

std::vector<string> split_strings(const std::string &s, char delimitator) {
    std::vector<string> elements;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delimitator)) {
        elements.push_back(number);
    }
    return elements;
}

void sourcefile_repo::store_source(const SourceFile& sourceFile){
    ofstream file;
    string element;
    file.open("../data/sourcefile.txt");
    if(file.is_open()){
            element="";
            element+=string(sourceFile.name);
            element+=";";
            element+=string(sourceFile.status);
            element+=";";
            element+=string(sourceFile.creator);
            element+=";";
            element+=string(sourceFile.reviser);
            file<<element;
            file<<"\n";

    }
}

void sourcefile_repo::store_datas(const vector<SourceFile>& vectors){
    ofstream file;
    string element;
    file.open("../data/sourcefile.txt");
    if(file.is_open()){
        for(auto & i : vectors){
            element="";
            element+=string(i.name);
            element+=";";
            element+=string(i.status);
            element+=";";
            element+=string(i.creator);
            element+=";";
            element+=string(i.reviser);
            file<<element;
            file<<"\n";
        }
    }
}

void sourcefile_repo::load_sourcefiles(){
    fstream file;
    SourceFile sourceFile;
    file.open("../data/sourcefile.txt");
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            std::vector<string> strings=split_strings(line,';');
            sourceFile.name=strings[0];
            sourceFile.status=strings[1];
            sourceFile.creator=strings[2];
            sourceFile.reviser=strings[3];
            array.push_back(sourceFile);
        }
        file.close();
    }
}