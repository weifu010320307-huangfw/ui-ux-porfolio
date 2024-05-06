/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "coloritem.h"

#include <QApplication>
#include <QBitmap>
#include <QCursor>
#include <QDrag>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QPainter>
#include <QRandomGenerator>
#include <QWidget>

#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QSequentialAnimationGroup>
#include <qdebug.h>
#include "adjustWindowSize.h"
#include <QLabel>
#include <QtMath>
#include <QGraphicsScene>
#include <QMap>
#include "soundsurround.h"


ColorItem::ColorItem(QString strItemName, QWidget *widget)
    : color(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256)),
      m_strItemName(strItemName), m_pSoundSurroundPage((soundSurround*)widget)
{
//    setToolTip(QString("QColor(%1, %2, %3)\n%4")
//              .arg(color.red()).arg(color.green()).arg(color.blue())
//              .arg("Click and drag this color onto the robot!"));



    m_scalRatio = resizeWindow::getScale();

    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);






}

QRectF ColorItem::boundingRect() const
{
    return QRectF(-15.5, -15.5, 60 * m_scalRatio, 60 * m_scalRatio);
}

void ColorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    int width = 50 * m_scalRatio;
    int height = 50 * m_scalRatio;

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-12, -12, width, height);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawEllipse(-15, -15, width, height);

    painter->setPen(QPen(Qt::white, 1));


    if(m_strItemName == "x")
    {


        QPixmap headPicture = QPixmap(":/resources/head.png");
        headPicture = headPicture.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        painter->drawPixmap(-15, -15, headPicture);
    }
    else
    {

        painter->drawText(QPoint(3 * m_scalRatio, 12 * m_scalRatio), m_strItemName);
    }




}

QVariant ColorItem::itemChange(GraphicsItemChange change, const QVariant &value)
{


    // when in animation, skip area constrain checking
    if(m_pSoundSurroundPage->isInAnimation())
    {
        return QGraphicsItem::itemChange(change, value);
    }



    qreal ratio = resizeWindow::getScale();

    int circleRadius = 200 * ratio;
    int internalCircleRadius = 50 * ratio;


    if (change == ItemPositionChange && scene()) {
        // value is the new position.
        QPointF newPos = value.toPointF();





        QRectF rect = scene()->sceneRect();
        // qDebug() << "scene()->sceneRect() " << scene()->sceneRect();

        // limit area inside below

        if(ratio < 1)
        {
            rect.setRect(-200 * ratio, -200 * ratio,
                     400 * ratio, 400 * ratio);
        }
        else
        {
            rect.setRect(-200, -200,
                     400, 400);
        }




        //newPos = mapFromItem(this, newPos);

        //求点到圆心的距离
        double distanceToCircleCenter = pow(pow(newPos.x(), 2)+ pow(newPos.y(), 2), 0.5);

 

        // for the outside circle
        if(distanceToCircleCenter > circleRadius)
        {

             qDebug() << "Keep the item inside the outside circle";


             newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
             newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));

             constrainInCircle(newPos, circleRadius);




             return newPos;








        }

        // for the inside circle
        if(distanceToCircleCenter < internalCircleRadius)
        {
            qDebug() << "Keep the item outside the inside circle";


            // for x
            if(abs(newPos.x() - rect.left()) > abs(newPos.x() - rect.right()))
            {
                // set to the close side
                newPos.setX(rect.right());
            }
            else
            {
                newPos.setX(rect.left());
            }

            // for y
            if(abs(newPos.y() - rect.top()) > abs(newPos.y() - rect.bottom()))
            {
                // set to the close side
                newPos.setY(rect.bottom());
            }
            else
            {
                newPos.setY(rect.top());
            }



            constrainInCircle(newPos, internalCircleRadius);



            return newPos;
        }





    }
    return QGraphicsItem::itemChange(change, value);
}

void ColorItem::constrainInCircle(QPointF& position, int circleRadius)
{

    if(qIsNaN(position.x()) && qIsNaN(position.y()))
    {
        // both x, y is not valid
        qDebug() << "both x, y is not valid..";

        // set to a fix position
        position.setX(circleRadius);
        position.setY(0);


        return;
    }
    else
    {
        if(false == qIsNaN(position.x()) && false == qIsNaN(position.y()))
        {
            // x = r * cos, y = r * sin
            double angle = atan2(position.y(), position.x());
            double yposValue = circleRadius * sin(angle);
            double xposValue = circleRadius * cos(angle);


            position.setX(xposValue);
            position.setY(yposValue);
            qDebug() << "after calculation newPos for both valid x/y = " << position;



            return;

        }

        if(false == qIsNaN(position.x()))
        {
            // x value is valid

            // x = r * cos, y = r * sin
            double angle = acos(position.x() / circleRadius);
            double yposValue = circleRadius * sin(angle);
            double xposValue = circleRadius * cos(angle);


            position.setX(xposValue);
            position.setY(yposValue);

            qDebug() << "after calculation newPos for x valid = " << position;
            return;


        }

        if(false == qIsNaN(position.y()))
        {

            // y value is valid

            // x = r * cos, y = r * sin
            double angle = asin(position.y() / circleRadius);
            double xposValue = circleRadius * cos(angle);
            double yposValue = circleRadius * sin(angle);

            position.setX(xposValue);
            position.setY(yposValue);

            qDebug() << "after calculation newPos for y valid = " << position;
            return;
        }


    }

}



void ColorItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{



    event->accept();





}

void ColorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{








    // call two times, if not icon is shaking
    QGraphicsItem::mouseMoveEvent(event);









    QPointF itemPos = mapToScene(pos());

   qDebug() << "event->scenePos()" << event->scenePos();


    qDebug() << "this-> pos " << pos();

    qDebug() << "item map pos " << itemPos;



    qreal ratio = resizeWindow::getScale();
    int circleRadius = 200 * ratio;
    int internalCircleRadius = 60 * ratio;
    //double distanceToCircleCenter = pow(pow(event->scenePos().x(), 2)+ pow(event->scenePos().y(), 2), 0.5);

    double distanceToCircleCenter = pow(pow(pos().x(), 2)+ pow(pos().y(), 2), 0.5);


    qDebug() << "mouseMoveEvent, distanceToCircleCenter = " << distanceToCircleCenter;

  //  qDebug() << "circleRadius = " << circleRadius;





    if(distanceToCircleCenter <= circleRadius && distanceToCircleCenter >= internalCircleRadius)
    {
       //emit itemMoveSignal(this, distanceToCircleCenter);
        m_pSoundSurroundPage->adjustAllVolumeByMoveItem(this, distanceToCircleCenter);



    }







    QGraphicsObject::mouseMoveEvent(event);


}

void ColorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsItem::mouseReleaseEvent(event);

}




animateColorItem::animateColorItem(QWidget *parent) : ColorItem("x", parent),
    m_pSoundSurroundPage((soundSurround*)parent)
{







    animation = new QParallelAnimationGroup(this);





    setAnimationPosition();





    animation->setLoopCount(-1);
    animation->start();


}

void animateColorItem::clearOldAnimation()
{
    if(animation)
    {
        animation->clear();


    }
}

void animateColorItem::setAnimationPosition()
{

    // initialize state
    m_pSoundSurroundPage->m_channelItems.clear();
    m_pSoundSurroundPage->scene->clear();
   // m_pSoundSurroundPage->m_soundSurrondScene->clear();
    animation->clear();

    qreal ratio = resizeWindow::getScale();

    QStringList iconNames = { "C", "L", "LS", "LB", "W", "RB", "RS", "R" };

    QVector<QPointF> points;
    for(int i = 0; i < 8; i++)
    {
        double radius = ratio * 150;
        double xPos = ::sin((i * 6.28) / 8.0) * radius;
        double yPos = ::cos((i * 6.28) / 8.0) * radius;

        QPointF position(xPos, yPos);
        points.push_back(position);

    }

    //m_pSoundSurroundPage->saveInitializeChannelPosition(points);

    for (int i = 0; i < 8; ++i)
    {


        ColorItem *item = new ColorItem(iconNames[i], m_pSoundSurroundPage);


        m_pSoundSurroundPage->m_channelItems.insert(iconNames[i], item);
        m_pSoundSurroundPage->linkChannelItemToSlider(item, i);


        double radius = ratio * 150;
        double xPos = ::sin((i * 6.28) / 8.0) * radius;
        double yPos = ::cos((i * 6.28) / 8.0) * radius;


        item->setPos(xPos, yPos);
        item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);

       

        m_pSoundSurroundPage->scene->addItem(item);

        QPropertyAnimation *itemAnimation = new QPropertyAnimation(item, "pos", this);


//        itemAnimation->setKeyValueAt(0, QPoint(xPos, yPos));
//        itemAnimation->setKeyValueAt(1/8.0, QPoint(::sin(((i + 1) * 6.28) / 8.0) * radius, ::cos(((i + 1) * 6.28) / 8.0) * radius));
//        itemAnimation->setKeyValueAt(2/8.0, QPoint(::sin(((i + 2) * 6.28) / 8.0) * radius, ::cos(((i + 2) * 6.28) / 8.0) * radius));
//        itemAnimation->setKeyValueAt(3/8.0, QPoint(::sin(((i + 3) * 6.28) / 8.0) * radius, ::cos(((i + 3) * 6.28) / 8.0) * radius));

//        itemAnimation->setKeyValueAt(4/8.0, QPoint(::sin(((i + 4) * 6.28) / 8.0) * radius, ::cos(((i + 4) * 6.28) / 8.0) * radius));
//        itemAnimation->setKeyValueAt(5/8.0, QPoint(::sin(((i + 5) * 6.28) / 8.0) * radius, ::cos(((i + 5) * 6.28) / 8.0) * radius));
//        itemAnimation->setKeyValueAt(6/8.0, QPoint(::sin(((i + 6) * 6.28) / 8.0) * radius, ::cos(((i + 6) * 6.28) / 8.0) * radius));
//        //itemAnimation->setKeyValueAt(7/8.0, QPoint(::sin(((i + 7) * 6.28) / 8.0) * radius, ::cos(((i + 7) * 6.28) / 8.0) * radius));



//        itemAnimation->setKeyValueAt(1, QPoint(xPos, yPos));


        itemAnimation->setKeyValueAt(0, QPointF(xPos, yPos));
        int currentIndex = i;
        for(int j = 0; j < 7; j++)
        {


            currentIndex += 1;
            if(currentIndex > 7)
            {
                currentIndex = 0;
            }

            //qDebug() << "moving forward, currentIndex = " << currentIndex;
            itemAnimation->setKeyValueAt((j + 1)/8.0, points[currentIndex]);


        }


        itemAnimation->setKeyValueAt(1, QPointF(xPos, yPos));


        itemAnimation->setDuration(30000);

        animation->addAnimation(itemAnimation);




    }

}



