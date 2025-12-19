#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// ========== CONFIGURATION ==========
#define DHTPIN 4          // DHT sensor pin
#define DHTTYPE DHT22     // DHT 22 (AM2302)
#define MOISTURE_PIN 34   // Moisture sensor analog pin
#define FAN_RELAY_PIN 26  // Fan relay control
#define HEATER_RELAY_PIN 27 // Heater relay control
#define BUZZER_PIN 25     // Buzzer

#define HUMIDITY_THRESHOLD 70  // Threshold for moisture
#define TEMP_THRESHOLD 40      // Max temp for safety (Celsius)

// Blynk auth token
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// WiFi credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

DHT dht(DHTPIN, DHTTYPE);

bool manualMode = false; // Manual/Automatic control

// ========== BLYNK VIRTUAL PINS ==========
#define VPIN_FAN V1
#define VPIN_HEATER V2
#define VPIN_MODE V3
#define VPIN_STATUS V4

BLYNK_WRITE(VPIN_FAN) {
  if (manualMode) {
    digitalWrite(FAN_RELAY_PIN, param.asInt());
  }
}

BLYNK_WRITE(VPIN_HEATER) {
  if (manualMode) {
    digitalWrite(HEATER_RELAY_PIN, param.asInt());
  }
}

BLYNK_WRITE(VPIN_MODE) {
  manualMode = param.asInt();
}

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(FAN_RELAY_PIN, OUTPUT);
  pinMode(HEATER_RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(FAN_RELAY_PIN, LOW);
  digitalWrite(HEATER_RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);
}

// ========== LOOP ==========
void loop() {
  Blynk.run();

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  int moisture = analogRead(MOISTURE_PIN);
  int moisturePercent = map(moisture, 0, 4095, 0, 100);

  Serial.print("Temp: "); Serial.print(temp); Serial.print(" C, ");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.print("%, ");
  Serial.print("Moisture: "); Serial.print(moisturePercent); Serial.println("%");

  // Automatic control
  if (!manualMode) {
    // Fan control
    if (moisturePercent > HUMIDITY_THRESHOLD) {
      digitalWrite(FAN_RELAY_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH); // alert wet shoes
    } else {
      digitalWrite(FAN_RELAY_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
    }

    // Heater control (skip for leather)
    if (moisturePercent > HUMIDITY_THRESHOLD && temp < TEMP_THRESHOLD) {
      digitalWrite(HEATER_RELAY_PIN, HIGH);
    } else {
      digitalWrite(HEATER_RELAY_PIN, LOW);
    }
  }

  // Send data to Blynk
  Blynk.virtualWrite(VPIN_STATUS, moisturePercent);
  Blynk.virtualWrite(VPIN_FAN, digitalRead(FAN_RELAY_PIN));
  Blynk.virtualWrite(VPIN_HEATER, digitalRead(HEATER_RELAY_PIN));

  delay(2000); // Delay between readings
}
