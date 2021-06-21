//
// Created by eddis on 6/20/2021.
//

#include "service.h"

service::service(programmer_repo &programmerRepo1, sourcefile_repo &sourcefileRepo) : programmerRepo{programmerRepo1},sourcefileRepo{ sourcefileRepo} {};

void service::add_programmer(Programmer p){
    this->programmerRepo.add_programmer(p);
}

void service::store_data(const vector<SourceFile>& array){
    this->sourcefileRepo.store_datas(array);
}

void service::add_sourcefile(SourceFile s){
    this->sourcefileRepo.add_sourcefile(s);
}

void service::store_source(const SourceFile& sourceFile){
    this->sourcefileRepo.store_source(sourceFile);
}

vector<Programmer> service::get_programmer(){
    return this->programmerRepo.get_programmers();
}

void service::someFunctions(){
    emit this->someSignal();
}

void service::load_programmer(){
    this->programmerRepo.load_data();
}

void service::load_sources(){
    this->sourcefileRepo.load_sourcefiles();
}

vector<SourceFile> & service::get_sources(){
    return this->sourcefileRepo.get_array();
}

