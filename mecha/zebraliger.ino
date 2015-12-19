void setup() { bt.begin(115200); bt.println("Started"); }

void loop() {
  if (bt.available() > 0) {
    ibyte = bt.read();
    bt.println(ibyte);
    
    //delay to allow serial update time
    delay(10);

    if (ibyte == 116) {
      if (!started) { m1.fw(); m2.fw(); for (ibyte = 1000; ibyte--;){  } started = true; }
      for (ibyte = 2000; ibyte--;) { // Track line for 2s
        if (opto.readC()){
          if (opto.readL() && !opto.readR())  { m1.fw(m1.rspeed()); m2.fw(); }  // turn left
          if (!opto.readL() && opto.readR())  { m1.fw(); m2.fw(m2.rspeed()); }  // turn right
        } else { m1.fw(); m2.fw(); }                                // forward
        // when in doubt, steer left! 
        for (ibyte = 10000; ibyte-- && opto.readL() && opto.readR() && opto.readC();) { m1.rv(); m2.fw(); }
        delay(10);
      }
    } else { m1.stop(); m2.stop(); }
  }
}

