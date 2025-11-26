// Welcome to my humble PIDino library. It ain't much, but it's honest work

#ifndef PIDINO_HPP
#define PIDINO_HPP

class PIDino {
public:
    PIDino(float setPoint, float Kp, float Ki, float Kd, float bias = 0.0f);

    float compute(float input);
    void setKp(float Kp);
    void setKi(float Ki);
    void setKd(float Kd);
    void setBias(float bias);
    void setIntegralMax(float maxVal);
    void setSetPoint(float sp);

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
