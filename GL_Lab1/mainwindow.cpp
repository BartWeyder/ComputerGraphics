#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->pickedColor = QColorDialog::getColor();
    ui->openGLWidget->setPickedColor(this->pickedColor);
    QPalette palette = ui->pushButton->palette();
    palette.setColor(QPalette::Button, this->pickedColor);
    ui->pushButton->setAutoFillBackground(true);
    ui->pushButton->setPalette(palette);
    ui->pushButton->update();
}
