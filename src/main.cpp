#include <Arduino.h>
#include "PIDino.hpp"

// Create a PIDino object with the following parameters:
PIDino pid1(100, 0, 255, 0.1, 0.01, 0.01);

void setup() {
    Serial.begin(9600); // Initialize the serial monitor
}

void loop() {
    constexpr float sensorValue = 100; // Simulated sensor value

    pid1.setpoint(50); // Change the setpoint to 50
    pid1.Kp(0.5); // Change the proportional gain to 0.5
    pid1.Ki(0.02); // Change the integral gain to 0.02
    pid1.Kd(0.03); // Change the derivative gain to 0.03

    const float output = pid1.compute(sensorValue); // Compute the PID output
    Serial.println(output); // Print the output to the serial monitor
}
