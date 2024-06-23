#include <ps5Controller.h>

unsigned long lastTimeStamp = 0;

void notify()
{
  char messageString[200];
  sprintf(messageString, "%4d,%4d,%4d,%4d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d",
  ps5.LStickX(),
  ps5.LStickY(),
  ps5.RStickX(),
  ps5.RStickY(),
  ps5.Left(),
  ps5.Down(),
  ps5.Right(),
  ps5.Up(),
  ps5.Square(),
  ps5.Cross(),
  ps5.Circle(),
  ps5.Triangle(),
  ps5.L1(),
  ps5.R1(),
  ps5.L2(),
  ps5.R2(),  
  ps5.Share(),
  ps5.Options(),
  ps5.PSButton(),
  ps5.Touchpad(),
  ps5.Charging(),
  ps5.Audio(),
  ps5.Mic(),
  ps5.Battery());

  //Only needed to print the message properly on serial monitor. Else we dont need it.
  if (millis() - lastTimeStamp > 50)
  {
    Serial.println(messageString);
    lastTimeStamp = millis();
  }
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void setup() 
{
  Serial.begin(115200);
  ps5.attach(notify);
  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.begin("ac:36:1b:2e:ad:e5");  //your PS5 controller mac address 
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














