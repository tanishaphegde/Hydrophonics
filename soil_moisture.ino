 #include <Adafruit_Seesaw.h>

#define SOIL_MOISTURE_PIN 36  // GPIO pin connected to the soil moisture sensor
#define LED_PIN 2             // GPIO pin for the built-in LED

Adafruit_Seesaw ss;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  if (!ss.begin(0x36)) {
    Serial.println("Seesaw not found, check wiring!");
    while (1);
  }
}

void loop() {
  // Read soil moisture value
  int moistureValue = ss.analogRead(SOIL_MOISTURE_PIN);
  Serial.print("Moisture: ");
  Serial.println(moistureValue);

  // Check if moisture is greater than 50%
  if (moistureValue > 50) {
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED
    Serial.println("LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn off the LED
    Serial.println("LED OFF");
  }

  delay(1000);  // Delay for a second before the next reading
}
