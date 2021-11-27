#include "ClientWindow.h"
#include "ui_clientwindow.h"

using namespace std;
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
            ui->ImageLabel->setPixmap(QPixmap::fromImage(image));
            //QColor clrCurrent(image.);


            int sizeY = 500;
            int sizeX = 500;

            for(int i = 0; i<sizeY;i++){
                for (int j = 0; i<sizeX;i++){
                        //get the pixel color (rgb)
                        QColor currColor(image.pixel(i,j));
                        pixArray[i][j] = currColor;
                }
            }
            cout<<"image mapped"<<endl;
            string coded_pic;
            for(int row = 0;row<sizeY;row++){
                for(int col = 0;col<sizeX;col++){
                    int red = pixArray[row][col].red();
                    int green = pixArray[row][col].green();
                    int blue = pixArray[row][col].blue();
                    coded_pic+=to_string(red);
                    coded_pic+= to_string(green);
                    coded_pic+= to_string(blue);
                }
            }
            cout<<"image coded in a string"<<endl;
        string path = filename.toStdString();
        string base_filename = path.substr(path.find_last_of('/')) ;

        string compressedpic = compressor->LZ78Compress(coded_pic);
        cout<<"Image compressed"<<endl;

        raidLib->save(base_filename, compressedpic);



        }
        else{
            //Error handling
        }
    }

}