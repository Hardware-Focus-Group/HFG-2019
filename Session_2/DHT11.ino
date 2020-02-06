/* download the dht sensor library by adafruit from library manager or from external link 
and add it to the code by using "add .zip file" in library manager */



#include <DHT.h>
DHT dht(4,DHT11);
void setup() 
{
  Serial.begin(115200);
  dht.begin();
  
}

void loop()
{
  float h=dht.readHumidity(); //reads humidity and temp 
  float t=dht.readTemperature();
  if(isnan(h)||isnan(t))
  {
    Serial.println("error");
  }
  Serial.print("Humidity:");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print(" C");
  delay(1000);
    
}
