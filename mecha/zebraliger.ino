// variable to store serial data
int incomingByte = 0;

// variable to store speed value
int speed_val = 250;

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
      for (int ms = 0; ms < 2000; ms++) { // Track line for 2s

        if (opto.readL && opto.readR && opto.readC) { // Turn right
          m1.forward(speed_val);
          //m2.reverse(speed_val);
          m2.forward(speed_val - 200);
        }

        if (opto.readR && opto.readL && opto.readC) { // Turn left
          //m1.reverse(speed_val);
          m1.forward(speed_val - 200);
          m2.forward(speed_val);
        }

        if (opto.readC) {  // Forward
          m1.forward(speed_val);
          m2.forward(speed_val);
        }

        while (opto.readR && opto.readL && opto.readC)) {
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

