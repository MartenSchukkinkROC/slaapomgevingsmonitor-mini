#define TEMP_PIN A0
#define LIGHT_PIN A1

void  setup()
{
  pinMode(TEMP_PIN, INPUT);
  pinMode(LIGHT_PIN, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // Temperatuur
  int sensorInputTemp = analogRead(TEMP_PIN);       // Uitgelezen waarde tussen 0 en 1023
  double voltage = sensorInputTemp / 1024.0 * 5.0;  // Omzetten naar voltage
  double temperature = (voltage - 0.5) * 100;       // Omzetten naar temperatuur

  Serial.print("Temperatuur:");
  Serial.println(temperature, 2);

  // Licht
  int sensorInputLight = analogRead(LIGHT_PIN);     // Uitgelezen waarde tussen 0 en 1023
  double light = sensorInputLight / 1024.0 * 100.0; // Omzetten naar percentage

  Serial.print("Licht:");
  Serial.println(light, 2);

  delay(1000);
}

