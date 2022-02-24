// gebruik Grove - Mosfet (Rood > 5V, Zwart > GND, Geel > Pin 6)

class Solenoid{
  private:
  int pin;
  bool solenoidStatus = LOW;
  unsigned long solenoidTijd = 0;

  public:
  Solenoid(int _pin) {
    pin = _pin;
    pinMode(pin, OUTPUT);
  }

  void update(){
    unsigned long huidigeTijd = millis();
    
    if(huidigeTijd > solenoidTijd){
      if(solenoidStatus == LOW){
        solenoidStatus = HIGH;
        solenoidTijd = huidigeTijd + 5000;
      }
      if(solenoidStatus == HIGH){
        solenoidStatus = LOW;
        solenoidTijd = huidigeTijd + 5000;
      }
      digitalWrite(pin, solenoidStatus);
    }
  }
  
};
