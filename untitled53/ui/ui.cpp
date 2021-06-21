#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include "ui.h"
#include <QLineEdit>
#include <UserModel/UserModel.h>
#include <QSortFilterProxyModel>
#include <QStandardItem>
#include <QDebug>
#include <QTextEdit>
#include <sstream>
#include <utility>
#include "../service/service.h"

ui::ui(QSharedPointer<service> serv): serv(std::move(serv)) {
};


void ui::construct(){
    this->serv->load_sources();
    this->serv->load_programmer();
    auto programmers=std::vector<Programmer>(this->serv->get_programmer());
    for(auto &element:programmers){
        auto interface=new Interface{this->serv,element};
        interface->show();
    }
}

QStandardItemModel* Interface::create_model(){
    auto model=new QStandardItemModel;
    auto item1=new QStandardItem(QObject::tr("Name"));
    model->setHorizontalHeaderItem(0,item1);
    auto item2=new  QStandardItem(QObject::tr("Status"));
    model->setHorizontalHeaderItem(1,item2);
    auto item3=new QStandardItem(QObject::tr("Creator"));
    model->setHorizontalHeaderItem(2,item3);
    auto item4=new QStandardItem(QObject::tr("Reviser"));
    model->setHorizontalHeaderItem(3,item4);
    auto sources=std::vector<SourceFile>(this->serv->get_sources());
    int value=sources.size();
    std::sort(sources.begin(),sources.end(),[=](const SourceFile& sourceFile1,const SourceFile& sourceFile2){
        return sourceFile1.status<sourceFile2.status;
    });
    for(int i=0;i<sources.size();++i){
        auto name=new QStandardItem(QString::fromStdString(sources[i].name));
        model->setItem(i,0,name);
        auto status=new QStandardItem(QString::fromStdString(sources[i].status));
        model->setItem(i,1,status);
        auto creator=new QStandardItem(QString::fromStdString(sources[i].creator));
        model->setItem(i,2,creator);
        auto reviser=new QStandardItem(QString::fromStdString(sources[i].reviser));
        model->setItem(i,3,reviser);
        if(status->text().toStdString()=="revised"){
            model->item(i,0)->setBackground(Qt::green);
            model->item(i,1)->setBackground(Qt::green);
            model->item(i,2)->setBackground(Qt::green);
            model->item(i,3)->setBackground(Qt::green);
        }
    }
    return model;
}


Interface::Interface(QSharedPointer<service> serv,Programmer &programmer1) : serv{std::move(serv)},programmer{programmer1}{
    auto view=new QTableView;
    auto button=new QPushButton("add");
    button->setMinimumSize(20,20);
    auto layout=new QGridLayout{};
    this->setLayout(layout);
    auto model=this->create_model();
    view->setWindowTitle(QString::fromStdString(programmer.name));
    view->setModel(model);
    view->setMinimumSize(400,400);
    layout->addWidget(button);
    layout->addWidget(view);
    QPushButton::connect(button,&QPushButton::clicked,[=]{
        auto widget3=new QWidget;
        auto layout3=new QFormLayout;
        widget3->setLayout(layout3);
        auto name=new QLineEdit;
        layout3->addRow(new QLabel("name"),name);
        auto status=new QLineEdit;
        layout3->addRow(new QLabel("status"),status);
        auto creator=new QLineEdit;
        layout3->addRow(new QLabel("creator"),creator);
        auto reviser=new QLineEdit;
        layout3->addRow(new QLabel("reviser"),reviser);
        auto button5=new QPushButton("add");
        layout3->addWidget(button5);
        QObject::connect(button5, &QPushButton::clicked, [=]() {
            SourceFile s;
            s.name=name->text().toStdString();
            s.status=status->text().toStdString();
            s.creator=creator->text().toStdString();
            s.reviser=reviser->text().toStdString();
            this->serv->add_sourcefile(s);
            this->serv->someFunctions();
            widget3->hide();
        });
        widget3->show();
    });
    QObject::connect(this->serv.get(), &service::someSignal, [=]() mutable {
          view->setModel(nullptr);
          model=this->create_model();
          view->setModel(model);
    });
    auto button6=new QPushButton("revise");
    layout->addWidget(button6);
    QPushButton::connect(button6,&QPushButton::clicked,[=]{
        auto selection=view->selectionModel()->currentIndex().row();
        auto &file=this->serv->get_sources()[selection];
        file.status="revised";
        this->serv->someFunctions();
    });

}
