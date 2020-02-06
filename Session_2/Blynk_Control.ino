// download blynk library from https://github.com/blynkkk/blynk-library/releases 
// source code (zip)
// add the .zip file library to the code 


#include <Blynk.h>

#define BLYNK_PRINT Serial

int pin = 2;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "your auth code";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your ssid";
char pass[] = "your pswd ";

void setup() {  
  pinMode(pin, OUTPUT); 
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  

  Blynk.begin(auth, ssid, pass);

}

void loop(){   
  Blynk.run();
}
