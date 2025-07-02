 #include "DHT.h"


#define DHTPIN 15       // GPIO15 where the DHT22 is connected
#define DHTTYPE DHT22   // We're using a DHT22
#define LDR_PIN 34      // GPIO34 for LDR
#define SOIL_PIN 4      // GPIO4 for soil sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(500);
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);
  int ldrValue = analogRead(LDR_PIN);
  float temperature = dht.readTemperature();  // Celsius
  float humidity = dht.readHumidity();        // %

  Serial.print("Soil Moisture: ");
  Serial.print(soilValue);
  Serial.print(" | Light: ");
  Serial.print(ldrValue);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.print("°C | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
} 