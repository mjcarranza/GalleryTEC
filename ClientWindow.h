#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "StorageManager.h"
#include "CompressionAlgorithm.h"

namespace Ui {
    class ClientWindow;
}

class ClientWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientWindow *ui;
    QColor pixArray[500][500];
    CompressionAlgorithm* compressor = new CompressionAlgorithm();
    StorageManager* raidLib = new StorageManager();

};

#endif // CLIENTWINDOW_H