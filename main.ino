#include <Servo.h>
Servo h, v; //servos for horizontal and vertical movement
int hval, vval, hin, vin; //values for the input to servos and the joystick values

void setup()
{
    pinMode(12, INPUT_PULLUP); //pullup because i didnt want to include a resistor 
    h.attach(9);
    v.attach(10);
    h.write(90);
    v.write(90);
    delay(1000); //delay so it gets back to 90
}

void loop()
{   
    hval = analogRead(0);
    hin = map(hval, 0, 1023, 45, 135); //feel free to change the 45 and 135 around depending on how you hold the joystick. Also change them to numbers between 0 and 180 for larger or smaller angles
    h.write(hin);
    vval = analogRead(2);
    vin = map(vval, 0, 1023, 135, 45); //feel free to change the 45 and 135 around depending on how you hold the joystick.  Also change them to numbers between 0 and 180 for larger or smaller angles
    v.write(vin);
    if (digitalRead(12) == LOW) //incase of issues, pressing on the joysick will reset the motors back to 90 and 90.
    {
        h.write(90);
        v.write(90);
    }
}