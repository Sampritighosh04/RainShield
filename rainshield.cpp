#include <Servo.h>

Servo clothes_servo;

const int rain_sensor_pin = A0; // Using analog pin for better accuracy
const int servo_pin = 5;        // Pin for the servo motor
const int threshold = 600;      // Adjust this based on your sensor

void setup() 
{
  pinMode(rain_sensor_pin, INPUT);
  clothes_servo.attach(servo_pin);
  clothes_servo.write(0); // Initial position (uncovered)
}

void loop() 
{
  int sensor_value = analogRead(rain_sensor_pin); // Read analog value
  Serial.println(sensor_value); // Debugging purpose

  if (sensor_value < threshold) 
  { // Rain detected (wet sensor)
    clothes_servo.write(180); // Move servo to collect clothes
  } 
  else 
  { // No rain detected (dry sensor)
    clothes_servo.write(0); // Move back to previous position
  }

  delay(500); // Small delay to prevent rapid movements
}
