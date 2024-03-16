# Praktikum Pembuatan Alat Sensor IoT : Fire Alarm dengan Sensor Suhu dan Gas

## Anggota Kelompok 3
- Jihaan Jasmine Jahroo (09021282126058)
- Jonathan Immanuel (09021282126098)
- Bonanda Siregar (09021382126135)
- Fauzan Abghi Patra (09021382126139)
- Muhammad Rizky Ramadhian Putra (09021382126149)

## Link Tinkercad :
https://www.tinkercad.com/things/745lBe2jod2-fire-alarm-with-gas-and-temp-sensors-led-and-piezo-output?sharecode=asYaXC-M7e-IFXb-C9Hb8ErT26PwkpzqgLLdUcM1fOY

## Simulasi Rancangan Sensor Tinkercad
<img src="https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/93305164/148c1f8f-28ef-4b15-97f9-e2a472b18734" width="600" />

## Rancangan Alat Sensor Fisik
<img src="https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/93305164/7bdd21ab-1f85-45ad-b128-2c390ff69dd1" width="300" />

## Komponen-Komponen yang digunakan di Simulasi Tinkercad
<img src="https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/93305164/d1cb4573-10a3-49e0-876c-82c7752aec3d" width="500" />

## Komponen-Komponen Fisik yang Digunakan
| Nama            | Gambar                                                                                                                    |
-----------------|-----------------------|
| Arduino Uno R3 | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/46b02a06-b0e7-44a9-828e-ecdad386be47) |
| Temperature Sensor LM35 | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/0019bbbc-ae7a-441b-9321-446e64946def) |
| Gas Sensor MQ2 | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/9704490d-b68a-4279-a885-b89446380b2f) |
| Piezo/Buzzer Speaker Active 5V | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/7acc815c-46e5-43af-8de0-7c37771d09d9) |
| Lampu LED 5mm | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/dad7ea5f-9f00-4914-b0c1-8500d1535912) |
| Resistor 1 KΩ | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/6e8ee131-4fac-47a8-9c52-c77c2c72b77b) |
| Kabel Jumper F to M dan M to M | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/8928d2e5-d519-4607-a3c1-2ddea949c2f6) |
| Breadboard | ![image](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/26ad0e52-b7bf-41af-b2e5-234f065a5de8) |

## Program Sketch
```
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
```

## Hasil Eksperimen
### Output
```
In Degree (C) = -22.16
Gas Sensor = 14
In Degree (C) = -22.4
Gas Sensor = 14
...
```

### Gambar Eksperimen
![crop gambar eksperimen](https://github.com/JejeTrue/Fire-Alarm-dengan-Sensor-Suhu-dan-Gas/assets/90818914/ff5976a2-0e96-44b5-b185-86e784421517)

### Kesimpulan
Alarm kebakaran merupakan perangkat vital dalam menjaga keselamatan dan melindungi properti dari bahaya kebakaran. Ada dua jenis utama alarm kebakaran: yang menggunakan sumber daya listrik dan yang menggunakan bahan khusus seperti detektor asap atau gas. Meskipun alarm kebakaran dengan sumber daya listrik mungkin lebih murah, yang menggunakan bahan khusus cenderung memberikan deteksi yang lebih sensitif terhadap kebakaran.

Praktik alarm kebakaran melibatkan pemasangan alarm di lokasi strategis di dalam bangunan untuk memastikan deteksi yang cepat dan efektif. Selain itu, penting untuk secara teratur melakukan tes fungsi alarm kebakaran.

Sistem alarm kebakaran yang diproposikan merupakan kombinasi dari sensor gas, sensor suhu, LED, dan output piezo yang terintegrasi dalam satu perangkat. Sistem ini dapat mendeteksi perubahan gas atau suhu yang signifikan di lingkungan sekitarnya dan memberikan tanda visual dan bunyi alarm yang cukup nyaring untuk memperingatkan penghuni bangunan tentang bahaya kebakaran. Untuk kedepannya, sistem ini akan dikendalikan dan dimonitor melalui koneksi internet atau jaringan lokal untuk memberikan notifikasi keamanan yang lebih lanjut kepada pengguna. Dengan demikian, sistem ini merupakan solusi yang komprehensif dalam meningkatkan keselamatan dan perlindungan terhadap kebakaran.
