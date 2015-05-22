#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QTextCodec>


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>
#include <QQuickWindow>
#include <QtQml>
#include <QDebug>



#include <MyDockWidgetDemo.h>




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



//        //创建主分割窗口 设置方向为水平分割窗口
//        QSplitter *mainSplitter = new QSplitter(Qt::Horizontal, 0);
//        //创建一个QTextEdit控件 设置其父控件为mainSplitter
//        QTextEdit *leftEdit = new QTextEdit(QObject::tr("左窗口"), mainSplitter);
//        //设置QTextEdit控件中的文字的对齐方式居中显示
//        leftEdit->setAlignment(Qt::AlignCenter);



//        //创建右分割窗口 设置其父控件为mainSplitter 设置方向为垂直分割窗口 最后其分割成上下两个窗口
//        QSplitter *rightSplitter = new QSplitter(Qt::Vertical, mainSplitter);
//        //设定分割窗口的分割条在拖动时是否为实时更新 true为实时更新 false则在拖动时只显示一条灰色的线条
//        //在拖动到位并弹起鼠标后再显示分隔条
//        rightSplitter->setOpaqueResize(false);
//        //开始将其分割成上下两个窗口
//        QTextEdit *upEdit = new QTextEdit(QObject::tr("上窗口"), rightSplitter);
//        upEdit->setAlignment(Qt::AlignCenter);
//        QTextEdit *bottomEdit = new QTextEdit(QObject::tr("下窗口"), rightSplitter);
//        bottomEdit->setAlignment(Qt::AlignCenter);
//        //设定可伸缩控件 第一个参数指定控件设置的控件序号，该控件序号按插入的先后次序依次从0开始编号
//        //第二个参数大于0表示此控件为伸缩控件 此例中设置右部分割窗口为可伸缩控件
//        mainSplitter->setStretchFactor(1, 1);
//        mainSplitter->setWindowTitle(QObject::tr("分割窗口"));
//        mainSplitter->show();



        MainWindow mainW;
        mainW.show();

        //MyDockWidgetDemo dock;
        //dock.show();

        return app.exec();
}
