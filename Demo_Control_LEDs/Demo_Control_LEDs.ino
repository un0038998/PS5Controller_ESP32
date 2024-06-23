#include <ps5Controller.h>

int   led1 = 15;
int   led2 = 16;
int   led3 = 17;
int   led4 = 18;
int   led5 = 19;
int   led6 = 21;
int   led7 = 22;
int   led8 = 23;

void notify()
{
  digitalWrite(led1, ps5.Left());
  digitalWrite(led2, ps5.Down());
  digitalWrite(led3, ps5.Right());
  digitalWrite(led4, ps5.Up()); 

  digitalWrite(led5, ps5.Square());
  digitalWrite(led6, ps5.Cross());
  digitalWrite(led7, ps5.Circle());
  digitalWrite(led8, ps5.Triangle()); 
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void setUpPinModes()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);      

  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT); 
}

void setup() 
{
  setUpPinModes();
  Serial.begin(115200);
  ps5.attach(notify);
  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.begin("ac:36:1b:2e:ad:e5");
  while (ps5.isConnected() == false) 
  { 
    Serial.println("PS5 controller not found");
    delay(300);
  } 
  Serial.println("Ready.");
}

void loop() 
{

}








