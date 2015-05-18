#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QCalendarWidget>
#include <QTextEdit>

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
    QTextEdit *edit=new QTextEdit("欢迎交流");
    setCentralWidget(edit);
    createDockWidget01();
    createDockWidget02();
    createDockWidget03();
    createDockWidget04();

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
    this->addDockWidget(Qt::TopDockWidgetArea, firstDockWidget);


}
void MainWindow::createDockWidget02(){

    //设置第二个QDockWidget
    QDockWidget *secondDockWidget = new QDockWidget(this);
    secondDockWidget->setWindowTitle(tr("场景"));
    secondDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    QTextEdit *myInfo = new QTextEdit(tr("<br>欢迎交流</br><br>博客地址:hhtp://blog.csdn.net/qiurisuixiang</br>"));
    secondDockWidget->setWidget(myInfo);
    this->addDockWidget(Qt::LeftDockWidgetArea, secondDockWidget);

}
void MainWindow::createDockWidget03(){

    //设置第二个QDockWidget
    QDockWidget *secondDockWidget = new QDockWidget(this);
    secondDockWidget->setWindowTitle(tr("场景"));
    secondDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    QTextEdit *myInfo = new QTextEdit(tr("<br>欢迎交流</br><br>博客地址:hhtp://blog.csdn.net/qiurisuixiang</br>"));
    secondDockWidget->setWidget(myInfo);
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
