class Tracker{
  private:
    int ttl = 0, period;

  public:
    Tracker(int period){ this->period = period; }
    void stop(){ m1.stop(); m2.stop(); }
    void track(int reset = 0){
      if (reset) ttl = period; else if (!ttl) return;
      if (opto.readC()){
        if (!opto.readR())  { m1.fw(m1.rspeed()); m2.fw(); dir = 0; } // turn left
        else if (!opto.readL())  { m1.fw(); m2.fw(m2.rspeed()); dir = 1; } // turn right
      } else { m1.fw(); m2.fw(); }                                    // forward
      // when in doubt, steer left! (or right ;/) 
      if (opto.readL() && opto.readR() && opto.readC())
        for (ibyte = 3000; ibyte--;) { 
          if (ibyte == 2999) {
            if (started){
              bt.print("i'm lost :(, last direction: ");
              bt.println((dir)? "left": "right");
            } else bt.println("find starting point!"); 
          }
          if (!started) { m1.fw(); m2.fw(); } 
          else {
            if (dir) { m1.rv(); m2.fw(); }
            else     { m1.fw(); m2.rv(); }
          }
          if (!opto.readC()){ if (!started) started = true; break;}
        }
      delay(10);
    }
  }
};

Tracker tracker(trackPeriod);
