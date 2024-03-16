float temp;
float vout;
float vout1;
int LED = 8;
int gasSensor;
int piezo = 7;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(1200);
}

int readSensor() {
  unsigned int sensorValue = analogRead(A1);
  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255);
  return outputValue;
}

void loop() {
  vout = analogRead(A0);
  vout1 = (vout/1023) * 5000;
  temp = (vout1 - 500) / 10;
  gasSensor = readSensor();

  if (temp >= 80) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }

  if (gasSensor >= 65) {
    digitalWrite(piezo, HIGH);
  }
  else {
    digitalWrite(piezo, LOW);
  }
  Serial.print("In Degree (C) = ");
  Serial.print(" ");
  Serial.print(temp);
  Serial.println();
  Serial.print("Gas Sensor = ");
  Serial.print(" ");
  Serial.print(gasSensor);
  Serial.println();
  delay(1000);
}
