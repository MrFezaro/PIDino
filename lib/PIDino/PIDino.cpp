#include "PIDino.hpp"
#include <Arduino.h>

PIDino::PIDino(float setPoint, float minOutput, float maxOutput,
               float Kp, float Ki, float Kd, float bias)
    : setPoint_(setPoint), minOutput_(minOutput), maxOutput_(maxOutput),
      Kp_(Kp), Ki_(Ki), Kd_(Kd), bias_(bias),
      integral_(0), integralMax_(1000.0f),
      lastError_(0), lastTime_(millis())
{}

float PIDino::compute(float input) {
    unsigned long now = millis();
    float dt = (now - lastTime_) / 1000.0f;
    if (dt <= 0.0f) dt = 0.001f;  // prevent div by zero

    float error = setPoint_ - input;

    // Trapezoidal integral with anti-windup
    integral_ += 0.5f * (error + lastError_) * dt;
    integral_ = constrain(integral_, -integralMax_, integralMax_);

    // Derivative
    float derivative = (error - lastError_) / dt;

    lastError_ = error;
    lastTime_ = now;

    return Kp_ * error + Ki_ * integral_ + Kd_ * derivative + bias_;
}

void PIDino::setSetPoint(float sp) { setPoint_ = sp; }
