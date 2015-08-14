#ifndef FRAMAINWINDOW_H
#define FRAMAINWINDOW_H

#include <QDialog>
#include "videocapturethread.h"
#include "utils.h"
#include <QVector>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QString>
#include <QStringList>

using namespace std;

namespace Ui {
class fraMainWindow;
}

class fraMainWindow : public QDialog
{
    Q_OBJECT
    VideoCaptureThread *thread[4];
    QTreeWidgetItem *item1;
    Utils util;
public:
    explicit fraMainWindow(QWidget *parent = 0);
    ~fraMainWindow();

private slots:
    void displayFrame(const Mat &newFrame, int cameraNum);
    void startRecording();
    void stopRecording();
    void addTreeWidgetItem(int cameraNum);

public:
    Ui::fraMainWindow *ui;
};

#endif // FRAMAINWINDOW_H
