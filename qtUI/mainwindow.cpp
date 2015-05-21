#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QCalendarWidget>
#include <QTextEdit>

#include <QDeclarativeView>
#include <QWidget>
#include <QVBoxLayout>

#include <QtDebug>
#include <QString>

#include <QJsonObject>
#include <QJsonDocument>

#include <QJsonArray>
#include <QByteArray>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createDockWidget();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDockWidget(){
   // view = new QDeclarativeView();
   // view->setSource(QUrl("../qtUI/application.qml"));
   // setCentralWidget(view);
    createDockWidget01();
    createDockWidget02();
    createDockWidget03();
    createDockWidget04();


    createJson();
    createJson2();

}

void MainWindow::createDockWidget01(){
    //设置主窗体的第一个QDockWidget
    QDockWidget *firstDockWidget = new QDockWidget(this);
    //设置第一个QDockWidget的窗口名称
    firstDockWidget->setWindowTitle(tr("日期"));
    //设置第一个QDockWidget的可停靠区域,全部可停靠
    firstDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    //设置第一个QDockWidget内的控件并设置该控件的属性
    QCalendarWidget *calendar = new QCalendarWidget;
    calendar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    calendar->setGridVisible(true);
    //将QCalendarWidget控件设置成QDockWidget的主控件 使其能随窗口大小改变而改变
    firstDockWidget->setWidget(calendar);
    //向主窗体中添加第一个QDockWidget控件 第一个参数表示初始显示的位置 第二个参数是要添加的QDockWidget控件
    this->addDockWidget(Qt::LeftDockWidgetArea, firstDockWidget);


}
void MainWindow::createDockWidget02(){

    //设置第二个QDockWidget
    QDockWidget *secondDockWidget = new QDockWidget(this);
    secondDockWidget->setWindowTitle(tr("场景"));
    secondDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    QTextEdit *myInfo = new QTextEdit(tr("<br>欢迎交流</br><br>博客地址:hhtp://blog.csdn.net/qiurisuixiang</br>"));
    secondDockWidget->setWidget(myInfo);
    this->addDockWidget(Qt::RightDockWidgetArea, secondDockWidget);

}
void MainWindow::createDockWidget03(){

    //设置第二个QDockWidget
    QDockWidget *secondDockWidget = new QDockWidget(this);
    secondDockWidget->setWindowTitle(tr("场景"));
    secondDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    QDeclarativeView *view1 = new QDeclarativeView(this);
    view1->setSource(QUrl("qrc:/application.qml"));

    secondDockWidget->setWidget(view1);
    this->addDockWidget(Qt::RightDockWidgetArea, secondDockWidget);

}
void MainWindow::createDockWidget04(){

    //设置第二个QDockWidget
    QDockWidget *secondDockWidget = new QDockWidget(this);
    secondDockWidget->setWindowTitle(tr("场景"));
    secondDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);


    QTextEdit *myInfo = new QTextEdit(tr("<br>欢迎交流</br><br>博客地址:hhtp://blog.csdn.net/qiurisuixiang</br>"));
    secondDockWidget->setWidget(myInfo);

    this->addDockWidget(Qt::BottomDockWidgetArea, secondDockWidget);

}
void MainWindow::createJson()   //创建json文件
{
    QJsonObject json;
    json.insert("name", QString("Qt"));
    json.insert("version", 5);
    json.insert("windows", true);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);

    qDebug() << json_str;

//    QString file_full, file_name, file_path;
//    QFileInfo fi;
//    file_full = QFileDialog::getOpenFileName(this);
//    fi = QFileInfo(file_full);
//    file_name = fi.fileName();
//    file_path = fi.absolutePath();
//    ui->textEdit->setText(file_path+"\\"+file_name);
     QString path = "f:\\txt.json";
     QFile file(path);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(
                        this,
                        QObject::tr("Write failure"),
                        QObject::tr("Cannot write file \n%1\n%2").arg(file.fileName()).arg(
                            file.errorString()));
            return;
        }

       QTextStream out(&file);
       out<<json_str<<endl;
       file.close();
}
 void MainWindow::createJson2()    //创建json文件
{
     QJsonArray json;
     json.insert(0, QString("Qt"));
     json.insert(1, QString("version"));
     json.insert(2, true);


     QJsonDocument document;
     document.setArray(json);
     QByteArray byte_array = document.toJson(QJsonDocument::Compact);
     QString json_str(byte_array);
     QString json_str02(byte_array);
     json_str += json_str02;
     qDebug() << json_str;

     QString path = "f:\\txt01.json";
     QFile file(path);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(
                        this,
                        QObject::tr("Write failure"),
                        QObject::tr("Cannot write file \n%1\n%2").arg(file.fileName()).arg(
                            file.errorString()));
            return;
        }

       QTextStream out(&file);
       out<<json_str<<endl;
       file.close();
}
