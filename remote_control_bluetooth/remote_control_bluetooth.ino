/******************* Robot Remote Control Mode - L298N 2A ********************/

// connections for drive Motor FR & BR
int enA = 9;
int in1 = 7;
int in2 = 6;
// connections for drive Motor FL & BL
int in3 = 5;
int in4 = 4;
int enB = 3;

const int buzPin = 2;  // set digital pin 2 as buzzer pin (use active buzzer)
const int ledPin = A5;  // set digital pin A5 as LED pin (use super bright LED)
int valSpeed = 255;

String readString;  // declaring string

void setup(){
  Serial.begin(9600);    // set up Serial library at 9600 bps
  Serial.println("*Robot Remote Control Mode - L298N 2A*");

  pinMode(buzPin, OUTPUT);  // sets the buzzer pin as an Output
  pinMode(ledPin, OUTPUT);  // sets the LED pin as an Output

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set the speed to start, from 0 (off) to 255 (max speed)
  analogWrite(enA, valSpeed);
  analogWrite(enB, valSpeed);
 
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  while (Serial.available() > 0) {
     char command = Serial.read();    // gets one byte from serial buffer
     Serial.println(command);

    switch(command){
    case 'F':   // move forward
        SetSpeed(valSpeed);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
    case 'B':   // move backward
        SetSpeed(valSpeed);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
    case 'R':   // turn right
        SetSpeed(valSpeed);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
    case 'L':   // turn left
        SetSpeed(valSpeed);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
    case 'G':   // forward left
        analogWrite(enB, valSpeed/4);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
    case 'H':   // backward left
        analogWrite(enB, valSpeed/4);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
    case 'I':   // forward right
        analogWrite(enA, valSpeed/4);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
    case 'J':   // backward right
        analogWrite(enA, valSpeed/4);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
    case 'S':   // stop
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
    case 'V':   // beep buzzer
        digitalWrite(buzPin, HIGH);
        delay(150);       
        digitalWrite(buzPin, LOW);
        delay(100);       
        digitalWrite(buzPin, HIGH);
        delay(250);       
        digitalWrite(buzPin, LOW);
        break;
    case 'W':   // turn light on
        digitalWrite(ledPin, HIGH);
        break;
    case 'w':   // turn light off
        digitalWrite(ledPin, LOW);
        break;
    case '0':   // set speed motor to 0 (min)
        SetSpeed(0);
        break;
    case '1':   // set speed motor to 30
        SetSpeed(30);
        break;
    case '2':   // set speed motor to 55
        SetSpeed(55);
        break;
    case '3':   // set speed motor to 80
        SetSpeed(80);
        break;
    case '4':   // set speed motor to 105
        SetSpeed(105);
        break;
    case '5':   // set speed motor to 130
        SetSpeed(130);
        break;
    case '6':   // set speed motor to 155
        SetSpeed(155);
        break;
    case '7':   // set speed motor to 180
        SetSpeed(180);
        break;
    case '8':   // set speed motor to 205
        SetSpeed(205);
        break;
    case '9':   // set speed motor to 230
        SetSpeed(230);
        break;
    case 'q':   // set speed motor to 255 (max)
        SetSpeed(255);
        break;
    }
  }
}

// function for setting speed of motors
void SetSpeed(int val){
  valSpeed = val;
  analogWrite(enA, valSpeed);
  analogWrite(enB, valSpeed);
} 
