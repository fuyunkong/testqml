#include "mainwindow.h"
#include "ui_mainwindow.h"







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


//    createJson();
//    createJson2();

//    createJson3();
//    createJson4();

//    createJson5();

//    createJson41();

//    readJsonObject();
//    readJsonArray();

//    readJson3();
//    readJson4();

//    readJson5();

//    readJson41();
//    readJson42();

 //   craeteUIfBgS();
 //   readUIfBgS();

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

    qDebug() << "以对象的方式创建Json文件01"<<endl;

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
 void MainWindow::createJson2()    //创建json文件
{

     qDebug() << "以属性的方式创建Json文件02"<<endl;

     QJsonArray json;
     json.insert(0, QString("Qt"));
     json.insert(1, QString("version"));
     json.insert(2, true);


     QJsonDocument document;
     document.setArray(json);
     QByteArray byte_array = document.toJson(QJsonDocument::Compact);
     QString json_str(byte_array);
     QString json_str02(byte_array);
    // json_str += json_str02;
     qDebug() << json_str;

     QString path = "f:\\txt02.json";
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


 void MainWindow::createJson3()    //创建json文件
 {
     qDebug() << "以创建Json文件03"<<endl;
        //基本使用
        QMap<QString, QVariant> m_map;

        QMap<QString, QVariant> map1;
        QMap<QString, QVariant> map2;

        map1.insert("name","zhangsan");
        map1.insert("sex","man");
        map1.insert("age","25");

        map2.insert("name","xiali");
        map2.insert("sex","women");
        map2.insert("age","18");

        m_map.insert("0",map1);
        m_map.insert("1",map2);

        QJsonDocument doc=QJsonDocument::fromVariant(QVariant(m_map));
        QByteArray a=doc.toJson();
        qDebug()<<a;

        QString path = "f:\\txt03.json";
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
          QString json_str(a);
          out<<json_str<<endl;
          file.close();

 }
 void MainWindow::createJson4()    //创建json文件
 {

      qDebug() << "以创建Json文件04"<<endl;

      QMap<QString, QVariant> map1;
      QList<QVariant> list2;
      QMap<QString, QVariant> map3;
      QMap<QString, QVariant> map4_1;
      QMap<QString, QVariant> map4_2;

      map4_1.insert("姓名","张三");
      map4_1.insert("性别","男");
      map4_1.insert("年龄","25");

      map4_2.insert("姓名","小丽");
      map4_2.insert("性别","女");
      map4_2.insert("年龄","18");

      map3.insert("0",map4_1);
      map3.insert("1",map4_2);

      list2.append(map3);

      map1.insert("资料列表",list2);

      QJsonDocument doc2=QJsonDocument::fromVariant(QVariant(map1));
      QByteArray b=doc2.toJson();
      qDebug()<<b;

      QString path = "f:\\txt04.json";
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
        QString json_str(b);
        out<<json_str<<endl;
        file.close();

 }

  void MainWindow::createJson41()    //创建json文件
  {
      qDebug() << "以创建Json文件06"<<endl;

      QMap<QString, QVariant> map1;
      QList<QVariant> list2;
      QMap<QString, QVariant> map3;
      QMap<QString, QVariant> map4_1;
      QMap<QString, QVariant> map4_2;

      map4_1.insert("name","张三");
      map4_1.insert("sex","男");
      map4_1.insert("age","25");

      map4_2.insert("name","小丽");
      map4_2.insert("sex","女");
      map4_2.insert("age","18");

      map3.insert("0",map4_1);
      map3.insert("1",map4_2);

      list2.append(map3);

      map1.insert("资料列表",list2);

      QJsonDocument doc2=QJsonDocument::fromVariant(QVariant(map1));
      QByteArray b=doc2.toJson();
      qDebug()<<b;

      QString path = "f:\\txt06.json";
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
        QString json_str(b);
        out<<json_str<<endl;
        file.close();
  }

  void MainWindow::createJson5()    //创建json文件
  {
      qDebug() << "以创建Json文件05"<<endl;


      QString path = "f:\\txt05.json";
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
        QString json_str= "{\"name\":\"mxq\",\"number\":1,\"array\":[23,\"asdf\",true]}";
        out<<json_str<<endl;
        file.close();
  }


 void MainWindow::readJsonObject() //解析Json文件
 {
    qDebug() << "以对象的方式解析Json文件"<<endl;
//    QFile f("f:\\txt.json");
//    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "Open failed." << endl;
//        return ;
//    }

//    QTextStream txtInput(&f);
//    QString lineStr;
//    while(!txtInput.atEnd())
//    {
//        lineStr = txtInput.readLine();
//        qDebug() << lineStr;

//    }

//    f.close();

        QFile file("f:\\txt01.json");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
          return ;
        QByteArray str = file.readAll ();
        qDebug() << str.constData ();
        QJsonParseError json_error;
        QJsonDocument parse_doucment = QJsonDocument::fromJson(str, &json_error);
        if(json_error.error == QJsonParseError::NoError)
        {
            if(parse_doucment.isObject())
            {
                QJsonObject obj = parse_doucment.object();
                if(obj.contains("name"))
                {
                    QJsonValue name_value = obj.take("name");
                    if(name_value.isString())
                    {
                        QString name = name_value.toString();
                        qDebug()<< "name:" << name;
                    }
                }
                if(obj.contains("version"))
                {
                    QJsonValue version_value = obj.take("version");
                    if(version_value.isDouble())
                    {
                        int version = version_value.toVariant().toInt();
                        qDebug()<< "version:" << version;
                    }
                }
                if(obj.contains("windows"))
                {
                    QJsonValue version_value = obj.take("windows");
                    if(version_value.isBool())
                    {
                          bool flag = version_value.toBool();
                          qDebug() << "windows:" << flag;
                    }
                }
            }
        }

        file.close ();


 }
 void MainWindow::readJsonArray() //解析Json文件
 {
    qDebug() << "以属性的方式解析Json文件";

    QFile file("f:\\txt02.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return ;
    QByteArray str = file.readAll ();
    qDebug() << str.constData ();
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(str, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isArray())
        {
            QJsonArray array = parse_doucment.array();
            int size = array.size();
            for(int i=0; i<size ;i++)
             {
                QJsonValue value = array.at(i);
                if(value.isString())
                {
                     QString name = value.toString();
                     qDebug() << name;
                }
                else if(value.isBool())
                {
                      bool flag = value.toBool();
                      qDebug() << flag;
                }
             }
        }
    }

    file.close ();

 }

 void MainWindow::readJson3() //解析Json文件
 {
   qDebug() << "解析Json文件03";
   QFile *file=new QFile("f:\\txt03.json");
   file->open(QIODevice::ReadOnly);
   QByteArray b= file->readAll();
   QJsonParseError *error=new QJsonParseError;
   QJsonDocument doc=QJsonDocument::fromJson(b,error);
   if(error->error==QJsonParseError::NoError)
   {
       if(doc.isObject())
       {


           qDebug()<<"json is object";
           QJsonObject jobj = doc.object();
           QStringList jsonkeylist = jobj.keys();
           qDebug()<<"jsonkeylist="<<jsonkeylist.count();
           for (int i=0;i<jsonkeylist.count();i++)
           {
               qDebug()<<jsonkeylist.at(i);
           }
           QJsonObject::iterator it = jobj.begin();
           while(it != jobj.end())
           {
               if(it.value().type() == QJsonValue::Object ){
                   qDebug()<<"type is Object!";
                   qDebug()<<it.key()<<"="<<it.value().toObject();

                   QJsonObject obj3 = it.value().toObject();
                   QString name = getJVFkey(obj3,"name");
                   qDebug()<< "name:" << name;
                   QString age = getJVFkey(obj3,"age");
                   qDebug()<< "age:" << age;
                   QString sex = getJVFkey(obj3,"sex");
                   qDebug()<< "sex:" << sex;

               }

               it++;
           }




       }

   }else
   {
       qDebug()<<error->errorString();
   }


 }
 void MainWindow::readJson4() //解析Json文件 wll 文件解决读取 中文乱码 问题  json文件解析中文乱码   通过 if(subit2.key() == "姓名") 判断
 {
     qDebug() << "解析Json文件04";
     QFile *file=new QFile("f:\\txt04.json");
     file->open(QIODevice::ReadOnly|QIODevice::Text);
     QTextStream in(file);
     QString b= in.readAll();
     qDebug() << b;

     QJsonParseError jsonErr;
     QJsonDocument doc = QJsonDocument::fromJson(b.toUtf8(),&jsonErr);

     if(jsonErr.error==QJsonParseError::NoError)
     {
         if(doc.isObject())
         {


             qDebug()<<"json is object";
             QJsonObject jobj = doc.object();
             QStringList jsonkeylist = jobj.keys();
             qDebug()<<"jsonkeylist="<<jsonkeylist.count();
             for (int i=0;i<jsonkeylist.count();i++)
             {
                 qDebug()<<jsonkeylist.at(i);
             }
             QJsonObject::iterator it = jobj.begin();
             while(it != jobj.end())
             {
                 if(it.value().type() == QJsonValue::Object ){
                     qDebug()<<"type is Object!";
                     qDebug()<<it.key()<<"="<<it.value().toObject();

                 }
                 if(it.value().type() == QJsonValue::Array ){
                     qDebug()<<"type is array!";
                     qDebug()<<it.key()<<"="<<it.value().toArray();
                     QJsonArray subarray = it.value().toArray();
                     qDebug()<<"subarray count = "<<subarray.count();
                     for(int i=0;i<subarray.count();i++)
                     {
                        QJsonValue subValue = subarray.at(i);
                        if(subValue.isObject()){
                            QJsonObject subobj = subValue.toObject();
                            QJsonObject::iterator subit = subobj.begin();
                            while(subit != subobj.end()){
                                if(subit.value().type() == QJsonValue::Object ){
                                    qDebug()<<"type is Object!";
                                    qDebug()<<subit.key()<<"="<<subit.value().toObject();



                                    QJsonObject  subobj2 = subit.value().toObject();
                                    qDebug()<<subobj2;

                                    QJsonObject::iterator subit2 = subobj2.begin();
                                    while(subit2 != subobj2.end()){

                                        // qDebug()<<"type is Object!";
                                        qDebug()<<subit2.key()<<"="<<subit2.value().toString();

                                        if(subit2.key() == "姓名"){
                                            QString name = subit2.value().toString();
                                            qDebug()<<"name"<<"="<<name;
                                        }
                                        if(subit2.key() == "性别"){
                                            QString sex = subit2.value().toString();
                                            qDebug()<<"sex"<<"="<<sex;
                                        }
                                        if(subit2.key() == "年龄"){
                                            QString age = subit2.value().toString();
                                            qDebug()<<"age"<<"="<<age;
                                        }



                                        subit2++;
                                     }



//                                    QJsonObject obj3 = subit.value().toObject();
//                                    QString name = getJVFkeyUTF(obj3,"姓名");
//                                    qDebug()<<"姓名 ："<<name;

                                }
                                subit++;
                            }
                            //qDebug()<<subobj.key()<<"="<<subobj.value().toObject();
                        }
                     }

                 }

                 it++;
             }




         }

     }else
     {
         qDebug()<<jsonErr.errorString();
     }

    file->close();



 }


 void MainWindow::readJson41() //解析Json文件
 {
     qDebug() << "解析Json文件041";
     QFile *file=new QFile("f:\\txt06.json");
     file->open(QIODevice::ReadOnly|QIODevice::Text);
     QTextStream in(file);
     QString b= in.readAll();
     qDebug() << b;

     QJsonParseError jsonErr;
     QJsonDocument doc = QJsonDocument::fromJson(b.toUtf8(),&jsonErr);

     if(jsonErr.error==QJsonParseError::NoError)
     {
         if(doc.isObject())
         {


             qDebug()<<"json is object";
             QJsonObject jobj = doc.object();
             QStringList jsonkeylist = jobj.keys();
             qDebug()<<"jsonkeylist="<<jsonkeylist.count();
             for (int i=0;i<jsonkeylist.count();i++)
             {
                 qDebug()<<jsonkeylist.at(i);
             }
             QJsonObject::iterator it = jobj.begin();
             while(it != jobj.end())
             {
                 if(it.value().type() == QJsonValue::Object ){
                     qDebug()<<"type is Object!";
                     qDebug()<<it.key()<<"="<<it.value().toObject();

                 }
                 if(it.value().type() == QJsonValue::Array ){
                     qDebug()<<"type is array!";
                     qDebug()<<it.key()<<"="<<it.value().toArray();
                     QJsonArray subarray = it.value().toArray();
                     qDebug()<<"subarray count = "<<subarray.count();
                     for(int i=0;i<subarray.count();i++)
                     {
                        QJsonValue subValue = subarray.at(i);
                        if(subValue.isObject()){
                            QJsonObject subobj = subValue.toObject();
                            QJsonObject::iterator subit = subobj.begin();
                            while(subit != subobj.end()){
                                if(subit.value().type() == QJsonValue::Object ){
                                    qDebug()<<"type is Object!";
                                    qDebug()<<subit.key()<<"="<<subit.value().toObject();



                                    QJsonObject  subobj2 = subit.value().toObject();
                                    qDebug()<<subobj2;

                                    QStringList jsonkeylist = subobj2.keys();
                                    qDebug()<<"jsonkeylist="<<jsonkeylist.count();
                                    for (int i=0;i<jsonkeylist.count();i++)
                                    {
                                        qDebug()<<jsonkeylist.at(i);

                                        QJsonValue value = subobj2.value(jsonkeylist.at(i)).toString(); //wll 如果key的值有中文 则得不到 对应的value的值
                                        qDebug()<<jsonkeylist.at(i)<<"=="<<value.toString();


                                    }





//                                    QJsonObject obj3 = subit.value().toObject();
//                                    QString name = getJVFkeyUTF(obj3,"姓名");
//                                    qDebug()<<"姓名 ："<<name;

                                }
                                subit++;
                            }
                            //qDebug()<<subobj.key()<<"="<<subobj.value().toObject();
                        }
                     }

                 }

                 it++;
             }




         }

     }else
     {
         qDebug()<<jsonErr.errorString();
     }

    file->close();

 }

void MainWindow::readJson42() //解析Json文件
{

    qDebug() << "解析Json文件041";
    QFile *file=new QFile("f:\\txt06.json");
    file->open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(file);
    QString b= in.readAll();
    qDebug() << b;

    QJsonParseError jsonErr;
    QJsonDocument doc = QJsonDocument::fromJson(b.toUtf8(),&jsonErr);

    if(jsonErr.error==QJsonParseError::NoError)
    {
        if(doc.isObject())
        {


            qDebug()<<"json is object";
            QJsonObject jobj = doc.object();
            QStringList jsonkeylist = jobj.keys();
            qDebug()<<"jsonkeylist="<<jsonkeylist.count();
            for (int i=0;i<jsonkeylist.count();i++)
            {
                qDebug()<<jsonkeylist.at(i);
            }
            QJsonObject::iterator it = jobj.begin();
            while(it != jobj.end())
            {
                if(it.value().type() == QJsonValue::Object ){
                    qDebug()<<"type is Object!";
                    qDebug()<<it.key()<<"="<<it.value().toObject();

                }
                if(it.value().type() == QJsonValue::Array ){
                    qDebug()<<"type is array!";
                    qDebug()<<it.key()<<"="<<it.value().toArray();
                    QJsonArray subarray = it.value().toArray();
                    qDebug()<<"subarray count = "<<subarray.count();
                    for(int i=0;i<subarray.count();i++)
                    {
                       QJsonValue subValue = subarray.at(i);
                       if(subValue.isObject()){
                           QJsonObject subobj = subValue.toObject();
                           QJsonObject::iterator subit = subobj.begin();
                           while(subit != subobj.end()){
                               if(subit.value().type() == QJsonValue::Object ){
                                   qDebug()<<"type is Object!";
                                   qDebug()<<subit.key()<<"="<<subit.value().toObject();



                                   QJsonObject  subobj2 = subit.value().toObject();
                                   qDebug()<<subobj2;

                                   QStringList jsonkeylist = subobj2.keys();
                                   qDebug()<<"jsonkeylist="<<jsonkeylist.count();
                                   for (int i=0;i<jsonkeylist.count();i++)
                                   {
                                       qDebug()<<jsonkeylist.at(i);

                                       //QJsonValue value = subobj2.value(jsonkeylist.at(i)); //wll 如果key的值有中文 则得不到 对应的value的值
                                       //qDebug()<<jsonkeylist.at(i)<<"=="<<value.toString();
                                       QJsonObject::iterator  subobj3 = subobj2.find("sex");
                                       qDebug()<<subobj3.value().toString();
                                   }





//                                    QJsonObject obj3 = subit.value().toObject();
//                                    QString name = getJVFkeyUTF(obj3,"姓名");
//                                    qDebug()<<"姓名 ："<<name;

                               }
                               subit++;
                           }
                           //qDebug()<<subobj.key()<<"="<<subobj.value().toObject();
                       }
                    }

                }

                it++;
            }




        }

    }else
    {
        qDebug()<<jsonErr.errorString();
    }

   file->close();
}
 void MainWindow::readJson5() //解析Json文件
 {
      qDebug() << "解析Json文件05";

      QFile file("f:\\txt05.json");
      if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;
      QByteArray str = file.readAll ();
      qDebug() << str.constData ();
      QJsonParseError jsonErr;
      QJsonDocument myjsonDoc1 = QJsonDocument::fromJson(str,&jsonErr);

      if (jsonErr.error == QJsonParseError::NoError)
      {
          if (myjsonDoc1.isEmpty())
          {
              qDebug()<<"the json is empty!";
          }
          if (myjsonDoc1.isObject())
          {
              qDebug()<<"json is object";
              QJsonObject jobj = myjsonDoc1.object();
              QStringList jsonkeylist = jobj.keys();
              qDebug()<<"jsonkeylist="<<jsonkeylist.count();
              for (int i=0;i<jsonkeylist.count();i++)
              {
                  qDebug()<<jsonkeylist.at(i)<<"\n";
              }
              QJsonObject::iterator it = jobj.begin();
              while(it != jobj.end())
              {
                  switch (it.value().type())
                  {
                  case QJsonValue::String:
                      qDebug()<<"type is String!";
                      qDebug()<<it.key()<<"="<<it.value().toString();
                      break;
                  case QJsonValue::Array:
                      {

                          qDebug()<<"type is array!";
                          qDebug()<<it.key()<<"="<<it.value().toArray();
                          QJsonArray subarray = it.value().toArray();
                          qDebug()<<"subarray count = "<<subarray.count();
                          qDebug()<<"index 1 ="<<subarray.at(0).toDouble();
                          qDebug()<<"index 2 ="<<subarray.at(1).toString();
                          qDebug()<<"index 3 ="<<subarray.at(2).toBool();

                          break;
                      }
                  case QJsonValue::Bool:
                      qDebug()<<"type is bool!";
                      qDebug()<<it.key()<<"="<<it.value().toBool();
                      break;
                  case QJsonValue::Double:
                      qDebug()<<"type is Double!";
                      qDebug()<<it.key()<<"="<<it.value().toDouble();
                      break;
                  case QJsonValue::Object:
                      qDebug()<<"type is Object!";
                      qDebug()<<it.key()<<"="<<it.value().toObject();
                      break;
                  case QJsonValue::Null:
                      qDebug()<<"type is null!";
                      qDebug()<<it.key()<<"=null";
                      break;
                  case QJsonValue::Undefined:
                      qDebug()<<"type is Undefined!";
                      break;
                  }
                  it++;
              }
          }

          }

      file.close ();

 }

  QString MainWindow::getJVFkey(QJsonObject obj,QString key)//获得Json key 对应的字符串
  {
      QString value;
      QJsonValue name_value = obj.take(key);
      if(name_value.isString())
      {
          value = name_value.toString();
          //qDebug()<< "name:" << name;
      }
      return value;
  }


  void MainWindow::craeteUIfBgS() //创建 UI 静止的背景图片fBgS 数据 Json描述
  {
      qDebug() << "以创建静止的背景图片fBgSJson文件UIfBgS"<<endl;

      QMap<QString, QVariant> map1;
      QList<QVariant> list2;

      QMap<QString, QVariant> map31;
      QMap<QString, QVariant> map32;
      QMap<QString, QVariant> map4_1;
      QMap<QString, QVariant> map4_2;

      QList<QVariant> list3;

      map4_1.insert("x","100");
      map4_1.insert("y","100");
      map4_1.insert("with","800");
      map4_1.insert("height","480");
      map4_1.insert("scaleX","1");
      map4_1.insert("scaleY","800");
      map4_1.insert("orderZ","0");
      map4_1.insert("image","bg1.png");

      map4_2.insert("x","200");
      map4_2.insert("y","200");
      map4_2.insert("with","800");
      map4_2.insert("height","480");
      map4_2.insert("scaleX","1");
      map4_2.insert("scaleY","800");
      map4_2.insert("orderZ","0");
      map4_2.insert("image","bg1.png");

      map31.insert("bgs",map4_1);
      map32.insert("bgs",map4_2);

      list3.append(map31);
      list3.append(map32);

      list2.append(list3);

      map1.insert("fBgS",list2);

      QJsonDocument doc2=QJsonDocument::fromVariant(QVariant(map1));
      QByteArray b=doc2.toJson();
      qDebug()<<b;

      QString path = "f:\\UIfBgS.json";
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
        QString json_str(b);
        out<<json_str<<endl;
        file.close();
  }
  void MainWindow::readUIfBgS() //解析fBgS Json数据文件
  {
        qDebug() << "以解析静止的背景图片fBgSJson文件UIfBgS"<<endl;
        QFile *file=new QFile("f:\\UIfBgS.json");
        file->open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream in(file);
        QString b= in.readAll();
        qDebug() << b;

        file->close();

  }








