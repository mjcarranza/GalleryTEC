//
// Created by abner on 24/11/21.
//

#ifndef GALLERYTEC_MAINWINDOW_H
#define GALLERYTEC_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //GALLERYTEC_MAINWINDOW_H
