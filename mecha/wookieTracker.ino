class Tracker{
  private:
    int counter, lastDir = -1, started = 0, x;
    bool work = false;
    Motor *leftM, *rightM;
    Optosensor *opto;
  public:
    Tracker(Motor *m1, Motor *m2, Optosensor *opto){
      leftM = m1; rightM = m2; this->opto = opto;
    }

    void start(){ work = true; }
    void stop(){ work = false; leftM->stop(); rightM->stop(); }
    
    // when in doubt, steer left! (or right ;/) 
    bool lostMode(){
      x = 3000;
      while (--x) { 
        // respond to controller
        delay(10); if (x == 2999) { if (!started) bt.println("finding starting point!"); else { bt.print("i'm lost :(, last direction: "); bt.println((lastDir)? "left": "right");}}
        
        if (!started) { leftM->fw(); rightM->fw(); } 
        else {
          //if (lastDir)  { leftM->rv(); rightM->fw(); } // rotate left
          //else          { 
            leftM->fw(); rightM->rv(); 
            //} // rotate right
        }
        
        if (opto->blackL()) lastDir = 1;
        else if (opto->blackR()) lastDir = 0;
        delay(10);
        if (opto->blackC()){ 
          bt.println("FOUND IT!!");
          if (!started) { started = true; break; }
          else 
            //if (++counter == 3){ bt.println("End of the journey~!"); return false; }
            //else 
            break; 
        }
      }
      if (!x){ bt.println("Imma say sorry, imma hopelessly lost..."); return false; }
      return true;
    }
    
    bool track(){
      if (work){
        delay(10);
        if (opto->blackC()){
          if (!started) { started = true; bt.println("started on a line! ;3"); }
          if (opto->blackR()) { 
            leftM->fw(leftM->rspeed()); rightM->fw(); lastDir = 0; // slight left
          }
          else if (opto->blackL()) { 
            leftM->fw(); rightM->fw(rightM->rspeed()); lastDir = 1; // slight right
          }
          else { 
            leftM->fw(); rightM->fw();
          } // forward
        } else if (!opto->blackL() && !opto->blackR()) { return lostMode(); }  
        bt.println("track");
      }            
      return true;
    }            
};

Tracker tracker(new Motor(2, 3, 11), new Motor(4, 5, 10), new Optosensor(6, 7, 8));

