#ifndef SENSORS_H
#define SENSORS_H

#define LONG 0
#define LATT 1
#define PM10 2
#define PM25 3
#define CO2 4
#define TEMP 5
#define HUMIDITY 6
#define OZONE 7
#define NTH 8

#define CO2_RX_PIN 18
#define CO2_TX_PIN 19
#define PM_RX_PIN 1
#define PM_TX_PIN 2
#define ONOZE_PIN A0       //TODO Must assign a pin number instead of A0 //Must Be in AnalogPin

#include "MHZ19.h"
#include "dataStructures.h"

SoftwareSerial CO2Serial(CO2_TX_PIN, CO2_RX_PIN);
SoftwareSerial PMSerial(PM_TX_PIN, PM_RX_PIN);

MHZ19_RESULT response;

MHZ19 mhz(&CO2Serial);




float getLong(void);
float getSensorData(int sensor){
  switch (sensor){
    
    case PM10:
      //return getPM10();
    break;
    
    case PM25:
      //return getPM25();
    break;
    
    case CO2:
        return mhz.getCO2();
    break;
    
   
    default:
      return;   
  }  
}
#endif
