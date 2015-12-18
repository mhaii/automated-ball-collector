#include <SoftwareSerial.h>// import the serial library

inline void pm(int p, bool out) { pinMode(p, out? OUTPUT: INPUT); }
inline void dw(int p, int v) { digitalWrite(p, v); }
inline void aw(int p, int v) { analogWrite(p, v); }


