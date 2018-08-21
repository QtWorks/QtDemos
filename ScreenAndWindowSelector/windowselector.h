#ifndef WINDOWSELECTOR_H
#define WINDOWSELECTOR_H


//#include <QWidget>
//#include "ui_imagewidget.h"
//#include <QPixmap>
//#include <QPoint>
//#include <QMouseEvent>
//#include <capturemenu.h>
//#include <QRect>

//struct MyRect
//{
//    QRect myRect_;	//矩形
//    int distance;	//鼠标当前点到 所有边的距离之和，用于比较
//};

//class ImageWidget : public QWidget
//{
//    Q_OBJECT

//public:
//    ImageWidget(QWidget *parent = 0);
//    ~ImageWidget();

//    void paintEvent(QPaintEvent *event);
//    //重写 鼠标按下 事件，记录截图起始点
//    void mousePressEvent(QMouseEvent *event);
//    //重写 鼠标松下 事件，记录截图结束点
//    void mouseReleaseEvent(QMouseEvent *event);
//    //重写 鼠标移动 事件，当拉动截图区域时 改变截图区域为正常图片（非蒙尘）
//    void mouseMoveEvent(QMouseEvent *event);
//    //用于计算 鼠标当前点到各个边的距离之和
//    void calculateRectDistance(QRect rect);
//private:
//    Ui::ImageWidget ui;
//    QPixmap pixmap_;	//用于显示 截的整个屏幕
//    QPixmap pixmapSave_; //用于 保存截图

//    QPoint pStart_;	//记录开始截图位置
//    QPoint pEnd_;	//记录结束截图位置
//    QPoint pMove_;	//记录移动中的坐标
//    bool isPressed;	//是否按下按钮
//    bool isDragging;	//是否用户拖选

//    MyRect miniRect;	//最小矩形

//    CaptureMenu *captureMenu_;	//截图结束时的菜单
//    QString fullPath;	//保存文件名以及 路径

//    public slots:
//        void slotGetFileName(QString filename);

//signals:
//        void beVisible();  //给 截图软件发射可见 信号
//};


#endif // WINDOWSELECTOR_H
