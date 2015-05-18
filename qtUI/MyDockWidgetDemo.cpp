
//mydockwidget.h
#include "mydockwidgetdemo.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>
#include <QMessageBox>
#include <QCalendarWidget>

MyDockWidgetDemo::MyDockWidgetDemo(QWidget *parent) :
    QMainWindow(parent)
{
    //创建一个QTextEdit控件，作为主窗口
    textEdit = new QTextEdit;
    this->setCentralWidget(textEdit);

    createActions();
    createMenus();
    createToolBars();
    createStatusBars();
    createDockWidget();

    this->setWindowTitle(tr("停靠窗口"));
}

void MyDockWidgetDemo::newSlot()
{
    //清空QTextEdit控件中的内容
    textEdit->clear();
}

void MyDockWidgetDemo::saveSlot()
{
    QMessageBox::warning(this, tr("事件"), tr("你触发了保存文件事件"),
                         QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void MyDockWidgetDemo::aboutSlot()
{
    QMessageBox::warning(this, tr("关于"), tr("欢迎交流。"),
                         QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void MyDockWidgetDemo::createActions()
{
    newAct = new QAction(tr("新建"), this);
    newAct->setShortcut(tr("Ctrl + N"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newSlot()));

    saveAct = new QAction(tr("保存"), this);
    saveAct->setShortcut(tr("Ctrl + S"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveSlot()));

    quitAct = new QAction(tr("退出"), this);
    quitAct->setShortcut(tr("Ctrl + Q"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("关于"), this);
    aboutAct->setShortcut(tr("Ctrl + A"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutSlot()));
}

void MyDockWidgetDemo::createMenus()
{
    fileMenu = this->menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(quitAct);

    viewMenu = this->menuBar()->addMenu(tr("视图"));

    helpMenu = this->menuBar()->addMenu(tr("帮助"));
    helpMenu->addAction(aboutAct);
}

void MyDockWidgetDemo::createToolBars()
{
    //给应用程序添加工具条
    fileToolBar = this->addToolBar(tr("文件"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(quitAct);

    viewToolBar = this->addToolBar(tr("视图"));

    helpToolBar = this->addToolBar(tr("帮助"));
    helpToolBar->addAction(aboutAct);
}

void MyDockWidgetDemo::createStatusBars()
{
    //设置应用程序的状态栏
    statusBar()->showMessage(tr("准备"));
}

void MyDockWidgetDemo::createDockWidget()
{
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
    this->addDockWidget(Qt::RightDockWidgetArea, firstDockWidget);
    //向菜单和工具栏中添加第一个QDockWidget的显示和隐藏动作
    viewMenu->addAction(firstDockWidget->toggleViewAction());
    viewToolBar->addAction(firstDockWidget->toggleViewAction());

    //设置第二个QDockWidget
    QDockWidget *secondDockWidget = new QDockWidget(this);
    secondDockWidget->setWindowTitle(tr("About Me"));
    secondDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea);
    QTextEdit *myInfo = new QTextEdit(tr("<br>欢迎交流</br><br>博客地址:hhtp://blog.csdn.net/qiurisuixiang</br>"));
    secondDockWidget->setWidget(myInfo);
    this->addDockWidget(Qt::BottomDockWidgetArea, secondDockWidget);
    //向菜单和工具栏中添加第一个QDockWidget的显示和隐藏动作
    viewMenu->addAction(secondDockWidget->toggleViewAction());
    viewToolBar->addAction(secondDockWidget->toggleViewAction());
}
