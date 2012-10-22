#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/// own algorithms lib
#include <../algorithms/rocextractor.h>

/// opencv lib
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/// Qt lib
#include <QMainWindow>
#include <QImage>
#include <QDateTime>
#include <QDir>
#include <QDebug>
#include <QShortcut>
#include <QFileDialog>


//class naming conventions
//m for members
//c for constants/readonlys
//p for pointer (and pp for pointer to pointer)
//v for volatile
//s for static
//i for indexes and iterators
//e for events


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private slots:
    void on_imagebutton_clicked();

    void on_videobutton_clicked();

    void change_camera(int camid = 0);
    void change_camera_0();
    void change_camera_1();
    void change_camera_2();
    void change_configure();
    void change_rootDir();

    void on_userHandComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    int miImage;
    int miVideoFrame;

    cv::VideoCapture mShowingCapture;
    cv::Mat mCapturedMat;
    cv::Mat mTempMat;
    cv::VideoWriter mRecordVideo;

    RocExtractor mRocExtractor;

    QImage mDisplayImage;
    QString mLastTimeString;

    QDir mRootSaveDir;
    static const QString scImageDir;
    static const QString scVideoDir;
    QString mUserHand;

    QString mConfigFileName;

    static const int scReordTimeLength = 5;
    static const int scRecordFps = 20;

    void loadConfigure(QString configureFileName);
};

#endif // MAINWINDOW_H
