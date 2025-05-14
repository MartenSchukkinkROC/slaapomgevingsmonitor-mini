#include <Servo.h>

#define TEMP_PIN A0
#define LIGHT_PIN A1

#define THUMB_UP 180  // Aantal graden voor duim omhoog
#define THUMB_DOWN 0  // Aantal graden voor duim omlaag

#define LIGHT_MAX 20.0  // Maximaal toegestane lichthoeveelheid
#define TEMP_MAX 23.0   // Maximaal toegestane temperatuur

Servo servoTemperature;
Servo servoLight;

void  setup()
{
  pinMode(TEMP_PIN, INPUT);
  pinMode(LIGHT_PIN, INPUT);

  servoTemperature.attach(9);
  servoLight.attach(10);

  Serial.begin(9600);
}

void loop()
{
  // Temperatuur
  int sensorInputTemp = analogRead(TEMP_PIN);       // Uitgelezen waarde tussen 0 en 1023
  double voltage = sensorInputTemp / 1024.0 * 5.0;  // Omzetten naar voltage
  double temperature = (voltage - 0.5) * 100;       // Omzetten naar temperatuur

  if (temperature <= TEMP_MAX) {
    servoTemperature.write(THUMB_UP);
  }
  else {
    servoTemperature.write(THUMB_DOWN);
  }

  Serial.print("Temperatuur:");
  Serial.println(temperature, 2);

  // Licht
  int sensorInputLight = analogRead(LIGHT_PIN);     // Uitgelezen waarde tussen 0 en 1023
  double light = sensorInputLight / 1024.0 * 100.0; // Omzetten naar percentage

  if (light <= LIGHT_MAX) {
    servoLight.write(THUMB_UP);
  }
  else {
    servoLight.write(THUMB_DOWN);
  }

  Serial.print("Licht:");
  Serial.println(light, 2);

  delay(1000);
}

