#ifndef ADJUSTWINDOWSIZE_H
#define ADJUSTWINDOWSIZE_H




#include <QObject>
#include <QWidget>

///
/// \brief The resizeWindow class,适用于固定尺寸及内部控件大小位置固定的窗口
///

class resizeWindow : public QObject
{
    Q_OBJECT

public:
    resizeWindow();
    static void resizeUI(QWidget* pWidget);
    static float getScale();

};




#endif // ADJUSTWINDOWSIZE_H
