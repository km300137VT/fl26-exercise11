// traffic_light.cpp
 
#include "traffic_light.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
 
TrafficLight::TrafficLight(QWidget * parent): QWidget(parent) {
 
  // Add the red traffic light
  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();   // initialize the red light to be ON
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");
 
  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");
 
  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
 
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);
 
  setLayout(layout);
}
 
// Turning one light ON turns the others OFF (radio buttons are exclusive)
void TrafficLight::light_update(){
  switch (counter){
    case 0: greenlight->toggle();  break;  // red -> green
    case 1: yellowlight->toggle(); break;  // green -> yellow
    case 2: redlight->toggle();    break;  // yellow -> red
  }
  counter = (counter + 1) % 3;   // cycle 0, 1, 2, 0, ...
}
 