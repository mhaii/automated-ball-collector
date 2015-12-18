class Optosensor{
  private:
    int l, m, r;
  public:
    Optosensor(int l, int m, int r){
      this->l = l; this->m = m; this->r = r;
      pm(l, 0); pm(m, 0); pm(r, 0);
    }
    bool read(char x){ 
      switch (x){
        case 'l': return digitalRead(l);
        case 'm': return digitalRead(m);
        case 'r': return digitalRead(r);
      }
    }
};

