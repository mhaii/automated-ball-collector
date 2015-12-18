

// Define pin number for phototransistor
int OPTO_L = 6; // Left
int OPTO_C = 7; // Center
int OPTO_R = 8; // Right

// variable to store serial data
int incomingByte = 0;


// variable to store speed value
int speed_val = 250;

// actual speed of M1 and M2
int n = 0;
void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(115200);
  BTSerial.println("Robot program started");

  // initialize digital pin 6-8 as output for wheel control
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available() > 0) {
    incomingByte = BTSerial.read();
    BTSerial.print("I received: ");
    BTSerial.println(incomingByte);
    // delay 10 milliseconds to allow serial update time
    delay(10);

    if (incomingByte == 116) {
      for (n = 0; n < 2000; n++) { // Track line for 2s

        if ((digitalRead(OPTO_L) == LOW) && (digitalRead(OPTO_R) == HIGH) && (digitalRead(OPTO_C) == HIGH )) { // Turn right
          m1.forward(speed_val);
          //m2.reverse(speed_val);
          m2.forward(speed_val - 200);
        }

        if ((digitalRead(OPTO_R) == LOW) && (digitalRead(OPTO_L) == HIGH) && (digitalRead(OPTO_C) == HIGH )) { // Turn left
          //m1.reverse(speed_val);
          m1.forward(speed_val - 200);
          m2.forward(speed_val);
        }

        if (digitalRead(OPTO_C) == LOW) {  // Forward
          m1.forward(speed_val);
          m2.forward(speed_val);
        }

        while ((digitalRead(OPTO_R) == HIGH) && (digitalRead(OPTO_L) == HIGH) && (digitalRead(OPTO_C) == HIGH )) {
          m1.reverse(speed_val);
          m2.forward(speed_val);

        }
        delay(10);
      }
    } else {
      m1.stop();
      m2.stop();
    }
  }
}

