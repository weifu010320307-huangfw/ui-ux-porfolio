
#include "adjustWindowSize.h"
#include <QObjectList>
//#include <QDesktopWidget>
#include <QApplication>
#include <QMetaProperty>
#include <QPushButton>
#include <QScreen>
#include <QGuiApplication>
#include <windows.h>
#include <QtDebug>


resizeWindow::resizeWindow()
{

}

void resizeWindow::resizeUI(QWidget *pWidget)
{
    if(!pWidget)
    {
        return;
    }

    //QDesktopWidget* desktopWidget = QApplication::desktop();



    //获取可用桌面大小
    //QRect deskRect = desktopWidget->availableGeometry();
//    QList<QScreen *> desktops = QGuiApplication::screens();
//    int size = desktops.size();
//    QRect deskRect = QGuiApplication::primaryScreen()->geometry();


//    QRect deskRect = QGuiApplication::primaryScreen()->availableVirtualGeometry();

//    qDebug() << deskRect.width() << deskRect.height();

    int width = GetSystemMetrics ( SM_CXSCREEN );
    int height = GetSystemMetrics ( SM_CYSCREEN );


    qDebug() << "resizeUI " << width << height;


    // 如果分辨率已经在1920及以上，则不需要进行处理
    //if(deskRect.width() >= 1920)
    if(width >= 1920)
    {
        return;
    }

    //仅使用x比例，否则窗口会变形
    //float scale = deskRect.width() / 1920.0;

    float scale = width / 1920.0;
    QObjectList lst = pWidget->children();
    QPoint pt(0,0);

    for(auto l : lst)
    {
        auto widget = qobject_cast<QWidget*>(l);
        if(widget)
        {
            pt = widget->pos();

            widget->move(QPoint(pt.x() * scale, pt.y() * scale));
            widget->resize(widget->width() * scale, widget->height() * scale);

            QFont font;
            int nIndex = widget->metaObject()->indexOfProperty("font");
            auto propertyFont = widget->metaObject()->property(nIndex);

            QVariant var =  propertyFont.read(widget);
            if(var.canConvert(QMetaType::QFont))
            {
                font = var.value<QFont>();

                font.setPointSizeF(font.pointSizeF() * scale);
                propertyFont.write(widget,QVariant::fromValue(font));
            }

            QPixmap pixmap;
            nIndex = widget->metaObject()->indexOfProperty("pixmap");
            auto pixmapProp = widget->metaObject()->property(nIndex);

            var = pixmapProp.read(widget);
            if(var.canConvert(QMetaType::QPixmap))
            {
                pixmap = var.value<QPixmap>();
                if(!pixmap.isNull())
                {
                    QSize sizePixmap(pixmap.size().width() * scale, pixmap.size().height() * scale);

                    pixmap =  pixmap.scaled(sizePixmap);
                    pixmapProp.write(widget,QVariant::fromValue(pixmap));
                }
            }
        }
    }

    pWidget->resize(pWidget->width() * scale, pWidget->height() * scale);
}

float resizeWindow::getScale()
{
    //QDesktopWidget* desktopWidget = QApplication::desktop();

//    QList<QScreen *> desktops = QGuiApplication::screens();
//    QRect deskRect = desktops[0]->availableGeometry();

    //QRect deskRect = QGuiApplication::primaryScreen()->geometry();

    int width = GetSystemMetrics ( SM_CXSCREEN );
    int height = GetSystemMetrics ( SM_CYSCREEN );

    qDebug() << "width = " << width;

    //获取可用桌面大小
    //QRect deskRect = desktopWidget->availableGeometry();

    if(width >= 1920)
    {
        // keep window size
        return 1;
    }

    return width / 1920.0;

    //return deskRect.width() / 1920.0;
}
