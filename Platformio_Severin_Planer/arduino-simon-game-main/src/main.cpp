
#include <Arduino.h>
int counter = 0; 
void setup() {
  Serial.begin(9600);
}
void loop() {
  
if (counter % 3 == 0) {
    Serial.println("Fizz");
  } else if counter % 5 == 0 {
    Serial.println("Buzz");
  } else {
    Serial.println(counter);
  }
  Serial.print("Counter: ");
  Serial.println(counter);
  counter++;
  delay(1000); // wait for a second
}
