void setup() { bt.begin(115200); bt.println("Started"); }

void loop() {
  if (bt.available() > 0) {
    ibyte = bt.read();
    bt.println(ibyte);
    
    //delay to allow serial update time
    delay(10);

    switch (ibyte){
      case 116: tracker.start(); break; // 't' start tracker
      default: tracker.stop();
    }

  }
  // let tracker run // condition true after 3 corners
  if (!tracker.track()){
    tracker.stop();
  }
}

