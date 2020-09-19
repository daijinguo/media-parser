#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QStringList>
#include <QFont>
#include <QFileDialog>

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

static byte print_input_char(byte c) {
    if(c >= 128 || c <= 32) return '.';
    return c;
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow),
    reader{nullptr}
{
    ui->setupUi(this);
#ifdef Q_OS_MACX
    QFont font("SimSun", 14, QFont::Normal);
    ui->hexView->setFont(font);
#endif

    byte data[8] = { '1', '2', ' ', '5', 'x', '7', 'n', 'R' };
    displayHex(data, 8);
}

MainWindow::~MainWindow()
{
    if(!reader) delete reader;
    delete ui;
}

void MainWindow::displayHex(byte* data, size_t len) {
    Q_ASSERT(data && len >= 0);

    len          = MIN(len, 4096);
    size_t rows  = len / 16 + (len % 16 == 0 ? 0 : 1);
    size_t index = 0;
    for(size_t i = 0; i < rows; ++i) {
        QString str1;
        QString str2;
        QString str3;

        size_t num = 16;
        if( (i + 1) * 16 > len ) num = len - i * 16;
        for(size_t j = 0; j < num; ++j) {
            QString tmp;
            tmp.sprintf("%02X ", data[index]);
            str2.append(tmp);

            tmp.sprintf("%c", print_input_char(static_cast<byte>(data[index])));
            str3.append(tmp);

            ++index;
        }

        if(num < 16) {
            for(size_t x = 0; x < 16; ++x) {
                str2 += "   ";
            }
        }
        str1 = str2 + "    " + str3;
        ui->hexView->append(str1);
    }

}

void MainWindow::displayHexFromReader(FileReader* reader, size_t start, size_t len) {
    byte *buffer = new byte[len];
    reader->setPosition(start);
    reader->readBuffer(buffer, len);
    displayHex(buffer, len);
    delete[] buffer;

    // setHight(0, 0);
}

void MainWindow::clearDisplay() {
    ui->structTree->clear();
    ui->hexView->clear();
}


void MainWindow::resetSampleInfo() {

}

void MainWindow::showSample() {

}

void MainWindow::on_openButton_clicked() {
    QFileDialog *dialog = new QFileDialog(this);
    if(dialog->exec() == QFileDialog::Accepted) {
        QStringList files = dialog->selectedFiles();
        QString file_name = files.at(0);
        ui->filePathEdit->setText(file_name);

        if(!reader) delete reader;
        reader = new FileReader;


        resetSampleInfo();
        ui->tabWidget->setCurrentIndex(0);
        ui->hexView->clear();

        // display the mp4 inforamtion
        displayHexFromReader(reader, 0, 1024);
    }
}

