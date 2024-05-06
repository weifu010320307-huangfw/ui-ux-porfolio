#ifndef DRAGOBJFRAME_H
#define DRAGOBJFRAME_H

#include "qwidget.h"
#include "qframe.h"


class DragWidget : public QFrame
{
public:
    explicit DragWidget(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};


#endif // DRAGOBJFRAME_H
