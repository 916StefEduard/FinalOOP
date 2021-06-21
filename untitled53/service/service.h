//
// Created by eddis on 6/20/2021.
//

#ifndef UNTITLED53_SERVICE_H
#define UNTITLED53_SERVICE_H


#include <repository/sourcefile_repo.h>
#include <QObject>
#include "../repository/programmer_repo.h"

class service:public QObject {
Q_OBJECT
private:
    programmer_repo &programmerRepo;
    sourcefile_repo &sourcefileRepo;
public:
    service(programmer_repo &programmerRepo1, sourcefile_repo &sourcefileRepo);
    void add_programmer(Programmer p);

    vector<Programmer> get_programmer();

    void load_programmer();

    void load_sources();
    void someFunctions();
    vector<SourceFile> &get_sources();
    void store_data(const vector<SourceFile> &array);
    void store_source(const SourceFile &sourceFile);
    void add_sourcefile(SourceFile s);

signals:
    void someSignal();
};


#endif //UNTITLED53_SERVICE_H
