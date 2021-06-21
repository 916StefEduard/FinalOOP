//
// Created by eddis on 6/20/2021.
//

#ifndef HELLOWORLD_SOURCEFILE_REPO_H
#define HELLOWORLD_SOURCEFILE_REPO_H
#include <vector>
#include <domain/SourceFile.h>

using namespace std;
class sourcefile_repo {
private:
    std::vector<SourceFile> array;
public:


    void add_sourcefile(SourceFile s);

    vector<SourceFile>& get_array();

    void load_sourcefiles();

    void store_datas(const vector<SourceFile>&);

    void store_source(const SourceFile &sourceFile);
};


#endif //HELLOWORLD_SOURCEFILE_REPO_H
