#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "DataObject.h"

template <typename outData, int sensorCount>
class SensorData : public DataObject
{
  public:
    SensorData& operator=(SensorData other)
    {
      if(this == &other)
      {
        return *this;
      }
      if(sensorCount==other.getSensorCount())
      {
        for(int i= 0; i<sensorCount; i++)
        {
          sensors[i] = getValue(i);      
        }
      }
      return *this;
    }
    
    int getSensorCount() {return sensorCount;};
    
    outData getValue(int num) {return sensors[num];};
    outData getValue() {return sensors[0];};
    
    void setValue(outData value, int num) {sensors[num] = value;};
    void setValue(outData value) {sensors[0] = value;};
  private:
    outData sensors[sensorCount];   
};
#endif
