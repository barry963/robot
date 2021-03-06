#ifndef FIELD_ROBOT_H
#define FIELD_ROBOT_H

#include "field_constants.h"
#include "field_item.h"
#include "motion_simulation_tools/field_vectors.h"
#include "field_item.h"



#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QVector>
#include <QGraphicsView>
#include <QPainterPath>
#include <QApplication>
#include <QThread>
#include <QGLWidget>
#include <QMutex>


extern void TimerInit();

const int teamUnknown = 0;
const int teamBlue = 1;
const int teamYellow = 2;
const int NA = 0xffff;
const double NAOrientation = 1000.0;



class RobotItem : public FieldItem
{
public:
        double orientation;     //In degrees
        int teamID;             //Team ID. 0 = blue, 1 = yellow
        int id;                 //ID of the robot in its team
        int key;
        QString robotLabel;
        QString robotTactic;
        double vx,vy;
        bool bKick;

private:
        QBrush *brush;
        QPen *pen, *id_pen, *conf_pen;
        QPainterPath robotOutline, robotOutlineCircle, robotID;
        QFont drawFont;
        void keyPressEvent(QKeyEvent *event);

public:
        QRectF boundingRect() const;
        QPainterPath shape() const;
        unsigned long int tStamp;
        void paint ( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
        void SetLocationPossibility(double _location_possibility);
        int get_teamID()
        {
                return teamID;
        }
        RobotItem();
        RobotItem ( double _x, double _y, double _orientation, int _teamID, int _id, int _key, double _conf );
        void Setid(int _teamID,int _id);
        void SetTactic(QString s);
        ~RobotItem();

protected:
        void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
        void wheelEvent(QGraphicsSceneWheelEvent *event);//Lu_test add

};

#endif // FIELD_ROBOT_H
