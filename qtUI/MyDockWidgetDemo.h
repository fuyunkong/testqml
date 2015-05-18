//mydockwidget.h
#ifndef MYDOCKWIDGETDEMO_H
#define MYDOCKWIDGETDEMO_H
#include <QMainWindow>
class QAction;
class QMenu;
class QToolBar;
class QStatusBar;
class QDockWidget;
class QTextEdit;
class MyDockWidgetDemo : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyDockWidgetDemo(QWidget *parent = 0);
signals:
public slots:

private slots:
    void newSlot();
    void saveSlot();
    void aboutSlot();

private:
    void createActions();        //创建动作
    void createMenus();          //创建菜单
    void createToolBars();      //创建工具条
    void createStatusBars();    //创建状态栏
    void createDockWidget();    //创建可停靠窗口

    QAction *newAct;
    QAction *saveAct;
    QAction *quitAct;
    QAction *aboutAct;

    QMenu *fileMenu;
    QMenu *viewMenu;            //viewMenu主要控制QDockWidget控件的显示和隐藏
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *viewToolBar;      //viewToolBar主要控制QDockWidget控件的显示和隐藏
    QToolBar *helpToolBar;

    QTextEdit *textEdit;
};
#endif // MYDOCKWIDGETDEMO_H
