SoftwareSerial bt(12, 13);        // RX, TX
Motor m1(2, 3, 11), m2(4, 5, 10); // left, right
Optosensor opto(6, 7, 8);

// for storing received serial data
int ibyte = 0;
// keep track of last turn
int dir = -1, started = 0;

