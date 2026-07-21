#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

Adafruit_MPU6050 imu;
Adafruit_BMP280 bmp;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int SERVO1_PIN = 12;
const int SERVO2_PIN = 13;
const int SERVO3_PIN = 14;
const int SERVO4_PIN = 15;

const float SEA_LEVEL_HPA = 1013.25;

float altitudeZero = 0.0;

// Function prototypes for PlatformIO / normal C++
void readSensors();
void callrecovery();
void TVC();

void setup() {
  Serial.begin(115200);
  Wire.begin();

  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);

  // BMP280 I2C address is usually 0x76 or 0x77.
  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 not found at 0x76, trying 0x77...");

    if (!bmp.begin(0x77)) {
      Serial.println("BMP280 not found. Check wiring/address.");
      while (1) {
        delay(10);
      }
    }
  }

  bmp.setSampling(
    Adafruit_BMP280::MODE_NORMAL,
    Adafruit_BMP280::SAMPLING_X8,   // temperature oversampling
    Adafruit_BMP280::SAMPLING_X8,   // pressure oversampling
    Adafruit_BMP280::FILTER_X4,
    Adafruit_BMP280::STANDBY_MS_1
  );

  if (!imu.begin()) {
    Serial.println("MPU6050 not found");
    while (1) {
      delay(10);
    }
  }

  imu.setAccelerometerRange(MPU6050_RANGE_8_G);
  imu.setGyroRange(MPU6050_RANGE_500_DEG);
  imu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(1000);

  altitudeZero = bmp.readAltitude(SEA_LEVEL_HPA);

  Serial.print("Altitude zero: ");
  Serial.println(altitudeZero);
}

void loop() {
  readSensors();
  delay(500);
  TVC();
  callrecovery();
}

void readSensors() {
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure();
  float altitude = bmp.readAltitude(SEA_LEVEL_HPA) - altitudeZero;

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  imu.getEvent(&accel, &gyro, &temp);

  Serial.print("BMP280 Temp C: ");
  Serial.print(temperature);

  Serial.print(" | Pressure Pa: ");
  Serial.print(pressure);

  Serial.print(" | Relative Altitude m: ");
  Serial.print(altitude);

  Serial.print(" | Accel X: ");
  Serial.print(accel.acceleration.x);

  Serial.print(" Y: ");
  Serial.print(accel.acceleration.y);

  Serial.print(" Z: ");
  Serial.println(accel.acceleration.z);
}

void callrecovery() {
  // some logic here
  servo1.write(90);
  servo2.write(90);
}

void TVC() {
  // some logic here
  servo3.write(45);
  servo4.write(135);
}
