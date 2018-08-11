#define LONG 0
#define LATT 1
#define PM10 2
#define PM25 3
#define CO2 4
#define TEMP 5
#define HUMIDITY 6
#define OZONE 7
#define NTH 8

class Sensor{
  float getLong(void);
  float getLatt(void);
  float getPM10(void);
  float getPM25(void);
  float getCO2(void);
  float getTemp(void);
  float getHumidity(void);
  float getOzone(void);
  
  float getSensorData(int);

public:
  void fetchData(void);
  
  
  
  
};

