#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QPalette>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_comboColorMix_currentIndexChanged(int index);

    void on_shapeBox_currentIndexChanged(int index);

    void on_checkBox_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QColor pickedColor;
};

#endif // MAINWINDOW_H
