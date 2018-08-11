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

class Sensor{
  float getLong(void);
  float getLatt(void);
  float getPM10(void);
  float getPM25(void);
  float getCO2(void);
  float getTemp(void);
  float getHumidity(void);
  float getOzone(void);
  
  MHZ19_RESULT response;
  SoftwareSerial* CO2Serial;//(CO2_TXPIN, CO2_RXPIN);
  SoftwareSerial* PMSerial;  //(PM_TXPIN, PM_RXPIN);
  MHZ19* mhz;

public:
 
  float getSensorData(int);
  void fetchData(void*);
  Sensor();
  
  
  
};


#endif SENSORS_H
