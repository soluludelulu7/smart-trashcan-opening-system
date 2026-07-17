#include <Servo.h>
Servo s;
enum {Closed, Open} state = Closed;

void setup() {
    s.attach(9);
}

void loop() {
    bool button = !digitalRead(2);
    bool vibration = !digitalRead(3);
    bool angle = !analogRead(A0);

    switch (state) {
        case Closed:
            s.write(0);
            digitalWrite(5, HIGH);
            if (button || vibration || angle) {
                state = Open;
            }
        
        case Open:
            s.write(0);
            digitalWrite(6, HIGH);
            if (button || vibration || angle) {
                state = Closed;
            }
    }
}