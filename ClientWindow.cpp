#include "ClientWindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.gif)"));
    if(QString::compare(filename,QString())!=0){
        QImage image;
        bool valid = image.load(filename);

        if(valid){
            ui->label_image->setPixmap(QPixmap::fromImage(image));
            //QColor clrCurrent(image.);


        }
        else{
            //Error handling
        }
    }

}

