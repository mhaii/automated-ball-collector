class Motor{
  private:
    int a,b,c, s = 0;

  public:
    Motor(int a, int b, int c){
      this->a = a; this->b = b; this->c = c;
      pm(a, 1); pm(b, 1); pm(c, 1);
    }
    int speed(){ return s; }
    void stop(){ dw(a, LOW); dw(b, LOW);  dw(c, LOW); }
    void reverse(int v) { dw(b, LOW); dw(a, HIGH); aw(c, v); }
    void forward(int v) { dw(a, LOW); dw(b, HIGH); aw(c, v); }
};

