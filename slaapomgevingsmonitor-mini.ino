#include <Servo.h>  // Standaard lib

#define LIGHT_PIN A0  // analog
#define TEMP_PIN A1  // analog

#define THUMB_UP 2400
#define THUMB_DOWN 600

#define LIGHT_MAX 10.0
#define TEMP_MAX 23.0

Servo servo_light;
Servo servo_temp;

double curLight;
double curTemperature;

void  setup()
{
  Serial.begin(9600);
  Serial.println("Initialising...");
  pinMode(LIGHT_PIN, INPUT);
  pinMode(TEMP_PIN, INPUT);
  servo_light.attach(9);
  servo_temp.attach(10);
}

void loop()
{
  // 1) Licht
  curLight = analogRead(LIGHT_PIN) / 1024.0 * 100.0; // 0..1023 converted to percentage

  if (curLight <= LIGHT_MAX) {
    servo_light.writeMicroseconds(THUMB_UP);
  }
  else {
    servo_light.writeMicroseconds(THUMB_DOWN);
  }

  Serial.print("curLight:");
  Serial.println(curLight, 2);

  // Temperatuur
  int sensorInput = analogRead(TEMP_PIN);

  curTemperature = (double)sensorInput / 1024; //find percentage of input reading
  curTemperature = curTemperature * 5; //multiply by 5V to get voltage
  curTemperature = curTemperature - 0.5; //Subtract the offset
  curTemperature = curTemperature * 100; //Convert to degrees

  if (curTemperature <= TEMP_MAX) {
    servo_temp.writeMicroseconds(THUMB_UP);
  }
  else {
    servo_temp.writeMicroseconds(THUMB_DOWN);
  }

  Serial.print("curTemp:");
  Serial.println(curTemperature, 2);

  delay(1000);
}
