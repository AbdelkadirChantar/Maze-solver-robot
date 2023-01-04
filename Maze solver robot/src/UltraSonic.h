#include <Arduino.h>

#define trigPin1 11
#define echoPin1 A0

#define trigPin2 A1
#define echoPin2 4

#define trigPin3 7
#define echoPin3 8


float duration;
float distance;


void dclrUltrason()
{
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);
}

float frontDistance()
{
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin1, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}

float leftDistance()
{
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration = pulseIn(echoPin2, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}
float rightDistance()
{
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    duration = pulseIn(echoPin3, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}