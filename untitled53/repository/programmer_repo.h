//
// Created by eddis on 6/20/2021.
//

#ifndef UNTITLED53_PROGRAMMER_REPO_H
#define UNTITLED53_PROGRAMMER_REPO_H
#include <vector>
#include "../domain/Programmer.h"

class programmer_repo {
private:
    std::vector<Programmer> array;
public:


    void add_programmer(Programmer p);

    vector<Programmer> get_programmers();

    void load_data();
};


#endif //UNTITLED53_PROGRAMMER_REPO_H
