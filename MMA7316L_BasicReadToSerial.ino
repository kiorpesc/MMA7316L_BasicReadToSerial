// Modified slightly from 

#include <AcceleroMMA7361.h>

AcceleroMMA7361 accel;
int x;
int y;
int z;

void setup()
{
  Serial.begin(9600);
  accel.begin(13, 12, 11, 10, A0, A1, A2);
  accel.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
  accel.setSensitivity(LOW);                   //sets the sensitivity to +/-6G
  accel.calibrate();
}

void loop()
{
  // 10Hz update - each line has format "x y z"
  x = accel.getXAccel();
  y = accel.getYAccel();
  z = accel.getZAccel();
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println(z);
  delay(100);                                     
}
