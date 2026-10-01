// traffic_light.h
#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H
 
#include <QWidget>
 
class QRadioButton;
 
class TrafficLight: public QWidget{
  Q_OBJECT
 
public:
  TrafficLight(QWidget * parent = nullptr);
 
public slots:
  void light_update();   // advance to the next light
 
private:
  QRadioButton * redlight;
  QRadioButton * yellowlight;
  QRadioButton * greenlight;
  int counter = 0;       // tracks which light is next
};
 
#endif