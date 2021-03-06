// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int led1 = 3;           // the pin that the LED1 is attached to
int led2 = 5;           // the pin that the LED2 is attached to
int led3 = 6;           // the pin that the LED3 is attached to

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int distance;

void setup() {
  // declare pin 3,5,6 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  distance = 0;
}

void loop() {
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  distance = (uS / US_ROUNDTRIP_CM);
  if(distance > 0) {
    Serial.print("Ping: ");
    Serial.print(distance); // Convert ping time to distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
  }

  if(distance > 0) {
    if(distance <= 10) {
      analogWrite(led1, distance*25);
    }
    else if(distance <= 20) {
      analogWrite(led2, distance*12);
    }
    else if(distance <= 30) {
      analogWrite(led3, distance*6);
    }
  }
}
