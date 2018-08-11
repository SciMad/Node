#ifndef DATA_STR_H
#define DATA_STR_H

const char fieldName[10][10] = {
  "____longt",
  "____lattd",
  "_____PM10",
  "_____PM25",
  "______C02",
  "_____temp",
  "_humidity",
  "____ozone",
  "______JPT",
  "_____addr" 
 };

typedef struct{
  byte deviceID[4];   //4 byte
  byte  timestamp[4]; //4byte
  byte fieldName[10]; //10 byte
  byte fieldValue[4];
  char nothing;       // if \0 is needed
}tx_Bytes;
 

typedef struct{
  char deviceID[4];
  unsigned long  timestamp;  //4 byte
  char address[12];
  float data[10]; // always maintain the order as lon, lat, PM10, PM2_5, CO2, temp, humidity, ozone, nth;
}node_Data;

 
#endif
