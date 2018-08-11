#include <SPI.h>
#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include "dataStructures.h"
#include "printf.h"


int P2_0 = 7; //CE
int P2_1 = 8; //CSN
int P2_2 = 2; //IRQ 

Enrf24 radio(P2_0, P2_1, P2_2);  // P2.0=CE, P2.1=CSN, P2.2=IRQ
const uint8_t txaddr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x01 };

void inIt(){
  
  //for getting data in serial monitor 
  Serial.begin(9600);   
  printf_begin();

  
   //SPI initialization
  SPI.begin();               
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);

  //radio initialization
  radio.begin();  // Defaults 1Mbps, channel 0, max TX power 
  radio.setTXaddress((void*)txaddr);

}

void sendMessage(node_Data test){
  typedef struct {
   byte red;
   byte green;
   byte blue;
  } color_t;

  color_t color;
  
  tx_Bytes txTest;
  char* str = "1234567890123456789";
  for (int i=0; i<10; i++){
   memcpy(&txTest.deviceID, &test.deviceID, sizeof(test.deviceID));
   memcpy(&txTest.timestamp, &test.timestamp, sizeof(test.timestamp));
   memcpy(&txTest.fieldName, &fieldName[i], 10*sizeof(char));
   memcpy(&txTest.fieldValue, &test.data[i], sizeof(float));

   //radio.println((char*) txTest);
   radio.write(&txTest, sizeof(tx_Bytes));
   //radio.write(&color, sizeof(color));

   radio.flush();  // Force transmit (don't wait for any more data)
   delay(100);
 }
}

void dump_radio_status_to_serialport(uint8_t status)
{
  Serial.print("Enrf24 radio transceiver status: ");
  switch (status) {
    case ENRF24_STATE_NOTPRESENT:
      Serial.println("NO TRANSCEIVER PRESENT");
      break;

    case ENRF24_STATE_DEEPSLEEP:
      Serial.println("DEEP SLEEP <1uA power consumption");
      break;

    case ENRF24_STATE_IDLE:
      Serial.println("IDLE module powered up w/ oscillators running");
      break;

    case ENRF24_STATE_PTX:
      Serial.println("Actively Transmitting");
      break;

    case ENRF24_STATE_PRX:
      Serial.println("Receive Mode");
      break;

    default:
      Serial.println("UNKNOWN STATUS CODE");
  }
}


