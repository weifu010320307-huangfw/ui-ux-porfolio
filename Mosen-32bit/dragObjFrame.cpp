
#include "dragObjFrame.h"
#include "qlabel.h"
#include "qmimedata.h"
#include "QMouseEvent"
#include "qdrag.h"
#include "qpainter.h"
#include "qdebug.h"


DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(300, 300);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    QLabel *boatIcon = new QLabel(this);
    boatIcon->setPixmap(QPixmap(":/dragIcon/dragIcons/e3.png"));
    boatIcon->move(10, 10);
    boatIcon->show();
    boatIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *carIcon = new QLabel(this);
    carIcon->setPixmap(QPixmap(":/dragIcon/dragIcons/e6.png"));
    carIcon->move(100, 10);
    carIcon->show();
    carIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon = new QLabel(this);
    houseIcon->setPixmap(QPixmap(":/dragIcon/dragIcons/e9.png"));
    houseIcon->move(10, 80);
    houseIcon->show();
    houseIcon->setAttribute(Qt::WA_DeleteOnClose);
}


void DragWidget::mousePressEvent(QMouseEvent *event)
{
   // QLabel *child = static_cast<QLabel*>(childAt(event->position().toPoint()));
    QLabel *child = static_cast<QLabel*>(childAt(event->pos())); // for 32bit exe


    qDebug() << "before check child";
    if (!child)
    {
        qDebug() << "return here";
        event->ignore();
        return;
    }


    QPixmap pixmap = child->pixmap(Qt::ReturnByValue);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//    dataStream << pixmap << QPoint(event->position().toPoint() - child->pos());

    dataStream << pixmap << QPoint(event->pos() - child->pos()); // for 32bit compile

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
//    drag->setHotSpot(event->position().toPoint() - child->pos());

    drag->setHotSpot(event->pos() - child->pos());  // for 32bit exe compile


    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}


void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);

//        newIcon->move(event->position().toPoint() - offset); // for 32bit code compile
        newIcon->move(event->pos() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}
