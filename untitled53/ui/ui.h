//
// Created by eddis on 6/20/2021.
//

#ifndef UNTITLED53_UI_H
#define UNTITLED53_UI_H
#include <QWidget>
#include <QStandardItemModel>

#include "../service/service.h"

class Interface:public QWidget{
private:
    Programmer &programmer;
    QSharedPointer<service> serv;
public:
    Interface( QSharedPointer<service> serv,Programmer &programmer1);

    QStandardItemModel *create_model();
};

class ui:public QWidget {
private:
    QSharedPointer<service> serv;
public:
    ui(QSharedPointer<service> service);

    void construct();

};


#endif //UNTITLED53_UI_H
