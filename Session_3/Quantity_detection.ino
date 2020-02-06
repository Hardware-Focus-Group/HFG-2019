
#include <Blynk.h>

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
 int x;
 const int container_length = 80;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "your_auth_token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your_SSID";
char pass[] = "your_password";
// defines pins numbers
const int trigPin = 4;
const int echoPin = 5;

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  

  Blynk.begin(your_auth_token, ssid, pass);

}

void loop() {
   Blynk.run();
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
x = container_length-distance;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println("");
Serial.println(" Amount of grain left ");
Serial.print(x);
delay(1000);
Serial.println("");


Blynk.virtualWrite(V5,x);
 if (x<45)
 {
  Serial.println(" Grains empty! Refill soon");
  Blynk.email("your_email_ID@mail.com", "Alert: Grains empty. Refill soon ", "Link to purchase /n https://www.flipkart.com/origo-fresh-grain-amaranth-seeds/p/itmf54wmfetxfdhz?pid=GNMF54WMGKAMHGEV&lid=LSTGNMF54WMGKAMHGEVMQPUHD&marketplace=GROCERY&iid=6c16ed05-d24e-4ad5-91ea-4d8226dd3025.GNMF54WMGKAMHGEV.SEARCH");
 }

}
