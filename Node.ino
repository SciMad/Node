#include "dataStructures.h"
#include "Sensor.h"
#include "tx_helper.h"

void setup() {
  inIt(); // Check this function to initialize all the necessary parameters  
}

Sensor sensor;

void loop() {
node_Data test = {"IOE",65535,"lab", {85.3167,27.7167,145.50,449,55,66,77,88,99,100}};


  while (1){
    Serial.println(sensor.getSensorData(CO2));
  }



  
  while(1){
    for (int i=0; i<5; i++){
      test.data[i] = sensor.getSensorData(i);
    }
    
    Serial.println("Started to print");
    for(int i=0;i<5;i++){
      sendMessage(test);
      Serial.println("Sent");
      dump_radio_status_to_serialport(radio.radioState());
    }
   delay(100);
   test.timestamp+=millis();
  }
 
 
 }



