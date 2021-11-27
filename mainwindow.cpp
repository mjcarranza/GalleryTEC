#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ClientWindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->Username_lineEdit->text();
    QString password = ui->Password_lineEdit->text();

    if(username == "User" && password == "1234"){
        QMessageBox::information(this, "Login", "Username and password is correct!");
        CWindow = new ClientWindow(this);
        CWindow->show();
        this->hide();


    }
    else {
        QMessageBox::warning(this, "Login", "Username and password is not correct!");
    }
}

