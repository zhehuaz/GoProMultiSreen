#ifndef FRAMAINWINDOW_H
#define FRAMAINWINDOW_H

#include <QDialog>
#include "videocapturethread.h"
#include "utils.h"
#include <QVector>

using namespace std;

namespace Ui {
class fraMainWindow;
}

class fraMainWindow : public QDialog
{
    Q_OBJECT
    VideoCaptureThread *thread;
    Utils util;

public:
    explicit fraMainWindow(QWidget *parent = 0);
    ~fraMainWindow();

private slots:
    void on_start1btn_clicked();
    void displayFrame(const QVector<Mat> &newFrame);
    void on_startallbtn_clicked();

private:
    Ui::fraMainWindow *ui;
};

#endif // FRAMAINWINDOW_H
