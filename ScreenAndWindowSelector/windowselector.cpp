//#include "windowselector.h"

//#include "imagewidget.h"
//#include <QPainter>
//#include <QColor>
//#include <QMessageBox>
//#include <QByteArray>
//#include <QBuffer>
//#include <QPainter>
//#include <QDesktopWidget>
//#include <QPen>


//#include <Windows.h>
//#include <vector>



//std::vector<QRect> allWindowRect;		//用于存储所有的窗口
//std::vector<HWND> allWindowHwnd;		//用于存储所有的窗口句柄
//std::vector<MyRect> myRectRestlt;		// 找到所有包含 鼠标当前移动点的矩形，并保存其到各边的距离之和。


////声明回调函数
//bool CALLBACK MyEnumWindowsProc(HWND hwnd,LPARAM lParam);

//ImageWidget::ImageWidget(QWidget *parent)
//    : QWidget(parent)
//{
//    ui.setupUi(this);

//    //用于获取窗口大小
//    QDesktopWidget *dtw = QApplication::desktop();
//    //获得 整个屏幕
//    pixmap_ = pixmap_.grabWindow(QApplication::desktop()->winId(),0,0,dtw->width(),dtw->height());

//    isPressed = false;
//    isDragging = false;

//    captureMenu_ = new CaptureMenu();

//    //打开鼠标 跟踪
//    setMouseTracking(true);

//    //关联 用于保存文件名
//    connect(captureMenu_,SIGNAL(toSaveFile(QString)),this,SLOT(slotGetFileName(QString)));

//    //遍历窗口 获得各个窗口的大小
//    ::EnumWindows((WNDENUMPROC)MyEnumWindowsProc,0);
//}

//ImageWidget::~ImageWidget()
//{
//}
//void ImageWidget::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    pixmap_ = pixmap_.scaled(width(),height(),Qt::KeepAspectRatio);


//    //pixmap_没有 alpha通道 添加通道
//    QPixmap temp(pixmap_.size());
//    temp.fill(Qt::transparent);

//    QPainter p(&temp);
//    p.setCompositionMode(QPainter::CompositionMode_Source);
//    p.drawPixmap(0, 0, pixmap_);
//    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
//    p.fillRect(temp.rect(), QColor(50, 50, 50, 100)); //把图片调 暗 以显示截图全屏
////	pixmap_ = temp;


//    //水印？？？？
//    painter.drawPixmap(0,0,temp);
//    QPen penWather;
//    penWather.setWidth(10);
//    penWather.setBrush(QColor(125,125,125,125));
//    painter.setPen(penWather);
//    QString tempStr;
//    tempStr = QString(tr("开始按钮X:%1 Y:%2 移动中的X:%3 Y:%4")).arg(pStart_.x()).arg(pStart_.y()).arg(pMove_.x()).arg(pMove_.y());
//    painter.drawText(100,100,tempStr);

//    //显示 截图拖动的区域
//    QPen pen;
//    pen.setWidth(5);
//    pen.setColor(QColor(0,255,255,127));
//    painter.setPen(pen);

//    if (isDragging)
//    {
//        painter.drawPixmap(pStart_.x(),pStart_.y(),pixmap_,pStart_.x(),pStart_.y(),pMove_.x()-pStart_.x(),pMove_.y()-pStart_.y());
//        painter.drawRect(pStart_.x()-2,pStart_.y()-2,pMove_.x()-pStart_.x()-2,pMove_.y()-pStart_.y()-2);
//    }
//    else
//    {
//        painter.drawPixmap(miniRect.myRect_.left(),miniRect.myRect_.top(),pixmap_,miniRect.myRect_.left(),miniRect.myRect_.top(),miniRect.myRect_.width(),miniRect.myRect_.height());
//        painter.drawRect(miniRect.myRect_.left()-2, miniRect.myRect_.top()-2, miniRect.myRect_.width()-2, miniRect.myRect_.height()-2);
//    }
//}
//void ImageWidget::mousePressEvent(QMouseEvent *event)
//{
//    pStart_.setX(event->x());
//    pStart_.setY(event->y());

//    isPressed = true;
//}

//void ImageWidget::mouseMoveEvent(QMouseEvent *event)
//{
//    if (isPressed)		//如果按下 鼠标 开始 区域截图
//    {
//        isDragging = true;
//        pMove_.setX(event->x());
//        pMove_.setY(event->y());
//    }
//    else			//如果没有按下鼠标 开始自动寻找合适窗口  //、应该改为 找到距离最近的 矩形块 。。。！！！！！！
//    {
//        //每次移动都清空
//        myRectRestlt.clear();
//        for (std::vector<QRect>::iterator it = allWindowRect.begin()+1;it != allWindowRect.end();it++)
//        {
//            if (it->contains(event->x(),event->y()))
//            {
//                calculateRectDistance(*it);
//            }
//        }
//        MyRect tempMinRect;
//        for(std::vector<MyRect>::iterator it = myRectRestlt.begin();it != myRectRestlt.end();it++)
//        {
//            if (it->distance < tempMinRect.distance)	//找到最小的矩形
//            {
//                tempMinRect = *it;		//
//            }
//        }
//        miniRect = tempMinRect;
//    }
//    update();
//}
//void ImageWidget::mouseReleaseEvent(QMouseEvent *event)
//{
//    //记录 结束点
//    if (isDragging)
//    {
//        pEnd_.setX(event->x());
//        pEnd_.setY(event->y());
//    }
//    else
//    {
//        pStart_.setX(miniRect.myRect_.left());
//        pStart_.setY(miniRect.myRect_.top());
//        pEnd_.setX(miniRect.myRect_.right());
//        pEnd_.setY(miniRect.myRect_.bottom());
//    }

//    isPressed = false;
//    //isDragging = false;

//    //新建菜单窗口
//    captureMenu_->move(event->x()-152,event->y());
//    captureMenu_->setWindowFlags(Qt::FramelessWindowHint);
//    captureMenu_->exec();

//    //退出窗口
//    close();
//    //发射 信号给截图软件窗口 可以显示
//    emit beVisible();

//}
////回调函数
//bool CALLBACK MyEnumWindowsProc(HWND hwnd,LPARAM lParam)
//{
//    if (::IsWindow(hwnd) && ::IsWindowVisible(hwnd))
//    {
//        RECT tempRect;
//        QRect tempQRect;
//        ::GetWindowRect(hwnd,&tempRect);

//        tempQRect.setTopLeft(QPoint(tempRect.left,tempRect.top));
//        tempQRect.setBottomRight(QPoint(tempRect.right,tempRect.bottom));


//        allWindowRect.push_back(tempQRect);
//        allWindowHwnd.push_back(hwnd);

//        ::EnumChildWindows(hwnd,(WNDENUMPROC)MyEnumWindowsProc,0);
//    }
//    return true;
//}
//void ImageWidget::slotGetFileName(QString filename)
//{
//    pixmapSave_ = pixmap_.copy(pStart_.x(),pStart_.y(),pEnd_.x()-pStart_.x(),pEnd_.y()-pStart_.y());
//    //保存截图
//    QByteArray bytes;//用于存放2进制数据
//    QBuffer buffer(&bytes);	//设置缓存
//    buffer.open(QIODevice::ReadOnly);
//    pixmapSave_.save(filename,"PNG",1);

//}
//void ImageWidget::calculateRectDistance(QRect rect)
//{
//    int dis = rect.width() + rect.height();
//    MyRect tempMyRect;
//    tempMyRect.myRect_ = rect;
//    tempMyRect.distance = dis;
//    //添加进入
//    myRectRestlt.push_back(tempMyRect);
//}
