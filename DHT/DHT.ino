#include <DHT.h>

#define DHTPIN 4  // Define the GPIO pin where the DHT11 data pin is connected
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int _moisture,sensor_analog;
const int sensor_pin = 36;  /* Soil moisture sensor O/P pin */

void setup(void){
  Serial.begin(9600); 
   Serial.begin(9600);
  Serial.println("DHT11 Sensor Test");
  dht.begin();/* Set the baudrate to 115200*/
}

void loop(void){
  sensor_analog = analogRead(sensor_pin);
  _moisture = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  Serial.print("Moisture = ");
  Serial.print(_moisture);  /* Print Temperature on the serial window */
  Serial.println("%");
  delay(1000);  
    // Delay for 2 seconds between measurements

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}/* Wait for 1000mS */
