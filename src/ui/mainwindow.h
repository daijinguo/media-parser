#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "basic/types.hpp"
#include "basic/filereader.hpp"

using namespace media;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void displayHex(byte* data, size_t len);
    void displayHexFromReader(FileReader* reader, size_t start, size_t len);
    void clearDisplay();


    void resetSampleInfo();
    void showSample(); // todo

private slots:
    void on_openButton_clicked();


private:
    Ui::MainWindow *ui;

private:
    FileReader     *reader;
};
#endif // MAINWINDOW_H
