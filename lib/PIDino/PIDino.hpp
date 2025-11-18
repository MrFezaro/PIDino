// Welcome to my humble PIDino library. It ain't much, but it's honest work

#ifndef PIDINO_HPP
#define PIDINO_HPP

class PIDino {
public:
    // Constructor: setpoint, output limits, PID gains, optional bias
    PIDino(float setPoint, float Kp, float Ki, float Kd, float bias = 0.0f);

    // Compute PID output given current input
    float compute(float input);

    void setSetPoint(float sp);       // change setpoint

private:
    float setPoint_;       // desired value
    float Kp_, Ki_, Kd_;   // PID gains
    float bias_;           // output bias (feedforward)

    float integral_;       // integral accumulator
    float integralMax_;    // integral anti-windup limit
    float lastError_;      // last error for derivative
    unsigned long lastTime_; // last time compute() was called
};

#endif
