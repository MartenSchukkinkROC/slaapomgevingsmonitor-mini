#define TEMP_PIN A1

void  setup()
{
  pinMode(TEMP_PIN, INPUT);

  Serial.begin(9600);
  Serial.println("Initialising...");
}

void loop()
{
  // Temperatuur
  int sensorInput = analogRead(TEMP_PIN);       // Uitgelezen waarde tussen 0 en 1023
  double voltage = sensorInput / 1024.0 * 5.0;  // Omzetten naar voltage
  double temperature = (voltage - 0.5) * 100;   // Omzetten naar temperatuur

  Serial.print("curTemp:");
  Serial.println(curTemperature, 2);

  delay(1000);
}

