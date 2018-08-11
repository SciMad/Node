#include "Sensor.h"


Sensor::Sensor(){
  CO2Serial = new SoftwareSerial(CO2_RX_PIN, CO2_TX_PIN);
  PMSerial = new SoftwareSerial(PM_RX_PIN, PM_TX_PIN);  
}



float Sensor::getSensorData(int sensor){
  switch (sensor){
    case LONG:
      //return getLong();
    break;
    
    case LATT:
      //return getLatt();
    break;
    
    case PM10:
      //return getPM10();
    break;
    
    case PM25:
      //return getPM25();
    break;
    
    case CO2:
      mhz = new MHZ19(CO2Serial);
      response = mhz->retrieveData();
      if (response == MHZ19_RESULT_OK){
        return mhz->getCO2();
      }
      else
      {
        return -1;
      }
     
    break;
    
    case TEMP:
      mhz = new MHZ19(CO2Serial);
      return mhz->getTemperature();
    break;
    
    case HUMIDITY:
      //return getHumidity();
    break;
    
    case OZONE:
      return analogRead(ONOZE_PIN);
      //return getOzone();
    break;
    
    case NTH:
      return;
    break;
    
    default:
      return;   
  }
  
}

