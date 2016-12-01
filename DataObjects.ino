#include "SensorData.h"
#include "ExcData.h"
#include "SpeedData.h"
#include "Sensor.h"
#include "ExcAlgorithm.h"
#include "SpeedAlgorithm.h"
#include "Motors.h"

Sensor<int, 8> sensor;
ExcAlgorithm<8> excAlgorithm;
SpeedAlgorithm speedAlgorithm;
Motors motors;
void setup()
{
  motors.setSpeedData(speedAlgorithm.getDataPtr());
  speedAlgorithm.setExcDataPtr(excAlgorithm.getDataPtr());
  excAlgorithm.setSensorDataPtr(sensor.getDataPtr());
}

void loop() 
{
  
}

