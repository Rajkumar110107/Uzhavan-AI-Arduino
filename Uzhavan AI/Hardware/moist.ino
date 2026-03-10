#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 3
#define MOISTURE_PIN A0

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int moistureValue;
float temperature;

void setup() {

  Serial.begin(9600);
  sensors.begin();  

}

void loop() {

  moistureValue = analogRead(MOISTURE_PIN);

  Serial.println("------ Farm Sensor Data ------");

  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  // Decide soil condition and assign temperature
  if (moistureValue > 800) {
    
    Serial.println("Soil Status: Dry");
    temperature = 25.0;

  } 
  else if (moistureValue > 400) {

    Serial.println("Soil Status: Moist");
    temperature = 20.0;

  } 
  else {

    Serial.println("Soil Status: Wet");
    temperature = 18.0;

  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.println("------------------------------");

  delay(2000);
}