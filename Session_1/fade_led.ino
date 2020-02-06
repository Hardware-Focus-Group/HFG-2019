const int ledpin = 2;
const int freq= 5000;
const int ledChannel=0;
const int resolution= 8;

void setup() {
  ledcSetup(ledChannel,freq,resolution);
  ledcAttachPin(ledpin,ledChannel);
  
  // put your setup code here, to run once:

}

void loop() {
  for(int i=0;i<=255;i++)
  {
    ledcWrite(ledChannel,i);
    delay(15);
  }
  for(int i=255;i>=0;i--)
  {
    ledcWrite(ledChannel,i);
    delay(15);
  }
  // put your main code here, to run repeatedly:

}
