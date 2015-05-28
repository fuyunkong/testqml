#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDeclarativeView>

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

#include <QTextCodec>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QDeclarativeView *view;

    void createDockWidget();    //创建可停靠窗口
    void createDockWidget01();    //创建可停靠窗口
    void createDockWidget02();    //创建可停靠窗口
    void createDockWidget03();    //创建可停靠窗口
    void createDockWidget04();    //创建可停靠窗口
    void createJson();    //创建json文件
    void createJson2();    //创建json文件

    void createJson3();    //创建json文件
    void createJson4();    //创建json文件

    void createJson41();    //创建json文件

    void createJson5();    //创建json文件


    void readJsonObject(); //解析Json文件
    void readJsonArray(); //解析Json文件

    void readJson3(); //解析Json文件
    void readJson4(); //解析Json文件
    void readJson41(); //解析Json文件

    void readJson42(); //解析Json文件

    void readJson5(); //解析Json文件

    void craeteUIfBgS(); //创建 UI 静止的背景图片fBgS 数据 Json描述
    void readUIfBgS(); //解析fBgS Json数据文件

    QString getJVFkey(QJsonObject obj,QString key);//获得Json key 对应的字符串

};

#endif // MAINWINDOW_H
