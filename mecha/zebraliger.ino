// variable to store serial data
int incomingByte = 0;

// variable to store speed value
int speed_val = 250;

void setup() {
  bt.begin(115200);
  bt.println("Robot program started");
}

void loop() {
  if (bt.available() > 0) {
    incomingByte = bt.read();
    bt.println(incomingByte);
    
    // delay 10 milliseconds to allow serial update time
    delay(10);

    if (incomingByte == 116) {
      for (int ms = 0; ms < 2000; ms++) { // Track line for 2s
        // Turn right
        if (opto.readL() && opto.readR() && opto.readC()){ m1.fw(); m2.fw(m2.speed - 200); }
        // Turn left
        if (opto.readL() && !opto.readR() && opto.readC()){ m1.fw(m1.speed - 200); m2.fw(); }
        // Forward
        if (opto.readC()) { m1.fw(); m2.fw(); }

        while (opto.readR() && opto.readL() && opto.readC()) { m1.rv(); m2.fw(); }
        delay(10);
      }
    } else {
      m1.stop();
      m2.stop();
    }
  }
}

