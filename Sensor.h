#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "SensorData.h"
#include "Algorithm.h"

template <typename T, int sensorCount>
class Sensor
{
  public:
    void operator>>(Algorithm other)
    {
      call();
      
    }
    
    void call()
    {
      for(int i = 0; i<sensorCount; i++)
      {
        data.setValue(i) = analogRead(sensors[i]);
      }
    }


    SensorData<int, 8> &getDataPtr()
    {
      return data;
    }
    
    void init(int Sensors[])
    {
      for(int i=0; i<sensorCount; i++)
      {
        sensors[i] = Sensors[i];
      }
    }
  private:
    SensorData<int, 8> data;
    int sensors[sensorCount];
};
#endif
