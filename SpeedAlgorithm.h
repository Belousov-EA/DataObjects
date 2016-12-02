#ifndef SPEED_ALGORITHM_H
#define SPEED_ALGORITHM_H

#include "Algorithm.h"
#include "SpeedData.h"

class ExcData;

class SpeedAlgorithm : public Algorithm
{
  public:
    void init(float P, float D, float MidSpeed, unsigned long VozvratTime)
    {
      p = P;
      d = D;
      midSpeed = MidSpeed;
      vozvratTime = VozvratTime;
    }
    
    void call()
    {
      if(excData->getDarks()!=0)
      {
        speedData.setDifference ( excData -> getExc()*p+(excData -> getExc()-lastExc)*d/(excData->getExcTime() - lastTime));
    
        lastTime = excData->getExcTime();
        lastExc = excData->getExc();
      }else
      {
        vozvrat();
      }      
      speedData.setAvgSpeed(midSpeed);   
    }

    void vozvrat()
    {
      if(excData->getExcTime()-excData->getLastTime()>vozvratTime)
      {
        if(excData->getValid()>0)
        {
          speedData.setDifference(p);
          lastExc = 1.00;
        }else
        {
          speedData.setDifference(-p);
          lastExc = -1.00;
        }
      }
    }
    
    void setExcDataPtr(ExcData* data)
    {
      this -> excData = data;
    }
    
    SpeedData *getDataPtr()
    {
      return &speedData;
    }  
  private:
    float p;
    float d;
    float midSpeed;
    unsigned long vozvratTime;
    SpeedData speedData;
    ExcData* excData;
    float lastExc;
    unsigned long lastTime;
};

#endif
