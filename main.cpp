// main.cpp
 
#include <QApplication>
#include <QTimer>
 
#include "traffic_light.h"
 
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  TrafficLight light;
  QTimer timer;
 
  // every timeout -> advance the light
  QObject::connect(&timer, &QTimer::timeout, &light, &TrafficLight::light_update);
 
  light.show();
  timer.start(500);   // 500 ms = half a second
 
  return app.exec();
}