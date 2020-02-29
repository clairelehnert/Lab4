#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <array>
#include <QMainWindow>
#include <QTimer>
#include <QTime>

#include "httpmanager.h"
#include "todomodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setCurrentTime();
    void processImage(QPixmap *);
    void processWeatherJson(QJsonObject *json);

    void on_imageDownloadPushButton_clicked();

    void on_weatherDownloadPushButton_clicked();



    void on_actionTo_Do_List_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
   // QTimer *change;
    HTTPManager *httpManager;
    QList<QTimeZone*> *timeZones;


    QPixmap image1, image2, image3, image4, image5, image6, image7;
    void loadFrame();

    ToDoModel *myModel;



};
#endif // MAINWINDOW_H
