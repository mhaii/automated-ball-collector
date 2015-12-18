// for storing received serial data
int ibyte = 0;

void setup() { bt.begin(115200); bt.println("Started"); }

void loop() {
  if (bt.available() > 0) {
    ibyte = bt.read();
    bt.println(ibyte);
    
    //delay to allow serial update time
    delay(10);

    if (ibyte == 116) {
      for (int ms = 2000; ms--;) { // Track line for 2s
        // turn left
        if (opto.readL() && opto.readC() && !opto.readR()){ m1.fw(m1.rspeed()); m2.fw(); }
        // turn right
        else if (!opto.readL() && opto.readC() && opto.readR()){ m1.fw(); m2.fw(m2.rspeed()); }
        // forward
        else { m1.fw(); m2.fw(); }

        // when in doubt, steer left!
        for (ibyte = 10000; ibyte-- && opto.readC();) { m1.rv(); m2.fw(); }
        delay(10);
      }
    } else { m1.stop(); m2.stop(); }
  }
}

