#include "SensorData.h"
#include "ExcData.h"
#include "SpeedData.h"
#include "Sensor.h"
#include "ExcAlgorithm.h"
#include "SpeedAlgorithm.h"
#include "Motors.h"

#define SENSOR_COUNT 8

//initialization
  Sensor<int, 8> sensor;
  ExcAlgorithm<8> excAlgorithm;
  SpeedAlgorithm speedAlgorithm;
  Motors motors;

int sensors[SENSOR_COUNT] = {6, 7, 8, 9, 0, 1, 10, 11};
int white[SENSOR_COUNT]= {77,  72,  71,  77,  68,  70,  76,  296 }; 
int black[SENSOR_COUNT]= {513,  423, 433, 556, 398, 441, 518, 640};

float p = 1;
float d = 20;
float midSpeed = 0.5;


void setup()
{
  //get references
    motors.setSpeedData(speedAlgorithm.getDataPtr());
    speedAlgorithm.setExcDataPtr(excAlgorithm.getDataPtr());
    excAlgorithm.setSensorDataPtr(sensor.getDataPtr());

  //init
    sensor.init(sensors);
    excAlgorithm.init(white, black);
    speedAlgorithm.init(p, d, midSpeed, 10);
    motors.init(5, 0, 11, 1);
}

void loop() 
{
  sensor.call();
  excAlgorithm.call();
  speedAlgorithm.call();
  motors.call();
}

