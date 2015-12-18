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

