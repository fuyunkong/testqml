#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDeclarativeView>

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
};

#endif // MAINWINDOW_H
