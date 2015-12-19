class Motor{
  private:
    int a,b,c, s = 250;

  public:
    Motor(int a, int b, int c){
      this->a = a; this->b = b; this->c = c;
      pm(a, 1); pm(b, 1); pm(c, 1);
    }
    int rspeed(){ return s - 200; }
    void stop(){ dw(a, LOW); dw(b, LOW);  dw(c, LOW); }
    void rv(int v = 0) { dw(b, LOW); dw(a, HIGH); aw(c, v?v:s); }
    void fw(int v = 0) { dw(a, LOW); dw(b, HIGH); aw(c, v?v:s); }
};

class Optosensor{
  private:
    int l, c, r;
  public:
    Optosensor(int l, int c, int r){
      this->l = l; this->c = c; this->r = r;
      pm(l, 0); pm(c, 0); pm(r, 0);
    }
    bool readL(){ return digitalRead(l); }
    bool readC(){ return digitalRead(c); }
    bool readR(){ return digitalRead(r); }
};

