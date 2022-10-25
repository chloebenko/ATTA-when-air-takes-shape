#include <Arduino.h>
#include <Wire.h>

#define MOTORFREQ 100
#define speed 500
#define speedt 1000
#define c_time 2000 //Contract time
#define e_time 1000 //Extend time
#define b_time 1000 //break between contract and extend

//top right motor, extend
#define MOTOR1_PWM PB_1
#define MOTOR1_CCW PA5
#define MOTOR1_CW PA4
#define ON 1

//second from top right motor, contract
#define MOTOR2_PWM PB_0
#define MOTOR2_CCW PA3
#define MOTOR2_CW PA2

//third from top right motor, contract
#define MOTOR3_PWM PA_7
#define MOTOR3_CCW PA1
#define MOTOR3_CW PA0

//bottom right motor, extend
#define MOTOR4_PWM PA_6
#define MOTOR4_CCW PA10
#define MOTOR4_CW PA11

//top left motor, extend
#define MOTOR5_PWM PA_8
#define MOTOR5_CCW PB15
#define MOTOR5_CW PB13

//second from top left motor, contract
#define MOTOR6_PWM PA_9
#define MOTOR6_CCW PB14
#define MOTOR6_CW PB12

//third from top left motor, contract
#define MOTOR7_PWM PB_6
#define MOTOR7_CCW PA15
#define MOTOR7_CW PB5

//bottom left motor, extend
#define MOTOR8_PWM PB_7
#define MOTOR8_CCW PA12
#define MOTOR8_CW PB4


volatile int loopcount = 0;


void setup()
{
  pinMode(MOTOR1_PWM, OUTPUT);
  pinMode(MOTOR1_CCW, OUTPUT);
  pinMode(MOTOR1_CW, OUTPUT);
  pinMode(MOTOR2_PWM, OUTPUT);
  pinMode(MOTOR2_CCW, OUTPUT);
  pinMode(MOTOR2_CW, OUTPUT);
  pinMode(MOTOR3_PWM, OUTPUT);
  pinMode(MOTOR3_CCW, OUTPUT);
  pinMode(MOTOR3_CW, OUTPUT);
  pinMode(MOTOR4_PWM, OUTPUT);
  pinMode(MOTOR4_CCW, OUTPUT);
  pinMode(MOTOR4_CW, OUTPUT);
  pinMode(MOTOR5_PWM, OUTPUT);
  pinMode(MOTOR5_CCW, OUTPUT);
  pinMode(MOTOR5_CW, OUTPUT);
  pinMode(MOTOR6_PWM, OUTPUT);
  pinMode(MOTOR6_CCW, OUTPUT);
  pinMode(MOTOR6_CW, OUTPUT);
  pinMode(MOTOR7_PWM, OUTPUT);
  pinMode(MOTOR7_CCW, OUTPUT);
  pinMode(MOTOR7_CW, OUTPUT);
  pinMode(MOTOR8_PWM, OUTPUT);
  pinMode(MOTOR8_CCW, OUTPUT);
  pinMode(MOTOR8_CW, OUTPUT);

  pwm_start(MOTOR1_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
  pwm_start(MOTOR2_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
  pwm_start(MOTOR3_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
  pwm_start(MOTOR4_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
  pwm_start(MOTOR5_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
  pwm_start(MOTOR6_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
  pwm_start(MOTOR7_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
  pwm_start(MOTOR8_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);

  pinMode(PC13, OUTPUT);  // could have INPUT or INPUT_PULLUP  // slopeServoPosition(1);
}

void loop() {
      digitalWrite(MOTOR1_CCW, ON); digitalWrite(MOTOR1_CW, !ON);
      digitalWrite(MOTOR2_CW, ON); digitalWrite(MOTOR2_CCW, !ON);
      digitalWrite(MOTOR3_CW, ON); digitalWrite(MOTOR3_CCW, !ON);
      digitalWrite(MOTOR4_CCW, ON); digitalWrite(MOTOR4_CW, !ON);
      digitalWrite(MOTOR5_CCW, ON); digitalWrite(MOTOR5_CW, !ON);
      digitalWrite(MOTOR6_CW, ON); digitalWrite(MOTOR6_CCW, !ON);
      digitalWrite(MOTOR7_CW, ON); digitalWrite(MOTOR7_CCW, !ON);
      digitalWrite(MOTOR8_CCW, ON); digitalWrite(MOTOR8_CW, !ON);

      pwm_start(MOTOR1_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR2_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR3_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR4_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR5_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR6_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR7_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR8_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);

      delay(c_time);

      digitalWrite(MOTOR1_CCW, !ON); digitalWrite(MOTOR1_CW, !ON);
      digitalWrite(MOTOR2_CCW, !ON); digitalWrite(MOTOR2_CW, !ON);
      digitalWrite(MOTOR3_CCW, !ON); digitalWrite(MOTOR3_CW, !ON);
      digitalWrite(MOTOR4_CCW, !ON); digitalWrite(MOTOR4_CW, !ON);
      digitalWrite(MOTOR5_CCW, !ON); digitalWrite(MOTOR5_CW, !ON);
      digitalWrite(MOTOR6_CCW, !ON); digitalWrite(MOTOR6_CW, !ON);
      digitalWrite(MOTOR7_CCW, !ON); digitalWrite(MOTOR7_CW, !ON);
      digitalWrite(MOTOR8_CCW, !ON); digitalWrite(MOTOR8_CW, !ON);

      delay(b_time);

      digitalWrite(MOTOR1_CW, ON); digitalWrite(MOTOR1_CCW, !ON);
      digitalWrite(MOTOR2_CCW, ON); digitalWrite(MOTOR2_CW, !ON);
      digitalWrite(MOTOR3_CCW, ON); digitalWrite(MOTOR3_CW, !ON);
      digitalWrite(MOTOR4_CW, ON); digitalWrite(MOTOR4_CCW, !ON);
      digitalWrite(MOTOR5_CW, ON); digitalWrite(MOTOR5_CCW, !ON);
      digitalWrite(MOTOR6_CCW, ON); digitalWrite(MOTOR6_CW, !ON);
      digitalWrite(MOTOR7_CCW, ON); digitalWrite(MOTOR7_CW, !ON);
      digitalWrite(MOTOR8_CW, ON); digitalWrite(MOTOR8_CCW, !ON);

      pwm_start(MOTOR1_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR2_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR3_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR4_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR5_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR6_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR7_PWM, MOTORFREQ, speed, RESOLUTION_12B_COMPARE_FORMAT);
      pwm_start(MOTOR8_PWM, MOTORFREQ, speedt, RESOLUTION_12B_COMPARE_FORMAT);

      delay(e_time);

      digitalWrite(MOTOR1_CCW, !ON); digitalWrite(MOTOR1_CW, !ON);
      digitalWrite(MOTOR2_CCW, !ON); digitalWrite(MOTOR2_CW, !ON);
      digitalWrite(MOTOR3_CCW, !ON); digitalWrite(MOTOR3_CW, !ON);
      digitalWrite(MOTOR4_CCW, !ON); digitalWrite(MOTOR4_CW, !ON);
      digitalWrite(MOTOR5_CCW, !ON); digitalWrite(MOTOR5_CW, !ON);
      digitalWrite(MOTOR6_CCW, !ON); digitalWrite(MOTOR6_CW, !ON);
      digitalWrite(MOTOR7_CCW, !ON); digitalWrite(MOTOR7_CW, !ON);
      digitalWrite(MOTOR8_CCW, !ON); digitalWrite(MOTOR8_CW, !ON);

      delay(b_time);
}