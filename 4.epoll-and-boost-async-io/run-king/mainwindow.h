#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "interfaces.h"
#include "plugins/basic.h"
#include "plugins/editor.h"
#include "plugins/animations.h"
#include "plugins/shadow.h"
#include "plugins/controls.h"
#include "plugins/observer.h"

#include <QMainWindow>
#include <QList>
#include <QMap>
#include <QTcpSocket>

#include <tuple>
using std::tuple;
using std::get;
using std::make_tuple;

using namespace ThreeQt;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void connected();
    void readyRead();
    void error(QAbstractSocket::SocketError);

    void on_pushButton_connect_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    float xyz[3];
    QMap<QString,tuple<float,float,float>> runners;

    ThreeWidget* tw;
    Basic* bp;
    Editor* ep;
    Animations* ap;
    Shadow* sp;
    Controls* cp;
    Observer* op;
    QMap<QTcpSocket*,bool> tcpList;
};

#endif // MAINWINDOW_H
