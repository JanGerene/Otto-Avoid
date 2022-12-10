#include <Arduino.h>
#include <Otto.h>
#include <Ultrasonic.h>

#define LEFT_LEG 2
#define RIGHT_LEG 3
#define LEFT_FOOT 4
#define RIGHT_FOOT 5
#define TRIGGER 8
#define ECHO 9
#define BUZZER 13

Otto otto;
Ultrasonic sonar(TRIGGER, ECHO);

void setup() {
  otto.init(LEFT_LEG, RIGHT_LEG, LEFT_FOOT, RIGHT_FOOT, true, BUZZER);
}

void loop() {
  if (sonar.read() <= 15) {
    otto.sing(S_surprise);
    otto.walk(2, 1000, BACKWARD);
    otto.turn(3, 1000, LEFT);
  }
  otto.walk(1, 1000, FORWARD);
}