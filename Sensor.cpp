#include "Sensor.h"

float Sensor::getSensorData(int sensor){
  switch (sensor){
    case LONG:
      return getLong();
    break;
    
    case LATT:
      return getLatt();
    break;
    
    case PM10:
      return getPM10();
    break;
    
    case PM25:
      return getPM25();
    break;
    
    case CO2:
      return getCO2();
    break;
    
    case TEMP:
      return getTemp();
    break;
    
    case HUMIDITY:
      return getHumidity();
    break;
    
    case OZONE:
      return getOzone();
    break;
    
    case NTH:
      return;
    break;
    
    default:
      return;   
  }
  
}

