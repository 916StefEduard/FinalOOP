#include <iostream>
#include <QApplication>
#include <repository/programmer_repo.h>
#include <service/service.h>
#include <ui/ui.h>

int main(int argc,char**argv) {
    QApplication app(argc,argv);
    programmer_repo programmerRepo{};
    sourcefile_repo sourcefileRepo{};
  //  service serv{programmerRepo,sourcefileRepo};
    auto serv= QSharedPointer<service>(new service{programmerRepo,sourcefileRepo});
    ui ui{serv};
    ui.construct();
    return QApplication::exec();
}
