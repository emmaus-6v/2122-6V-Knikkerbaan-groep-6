// gebruik Grove - Mosfet (Rood > 5V, Zwart > GND, Geel > Pin 6)


// the setup function runs once when you press reset or power the board
/*int SolenoidPin = 6;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(SolenoidPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(SolenoidPin, HIGH);   
  delay(1000);                       
  digitalWrite(SolenoidPin, LOW);    
  delay(10000);                       
}*/

class Solenoid{
  private:
  int pin;
  bool solenoidHigh = true;
  unsigned long solenoidTijd = 0;

  public:
  Solenoid(){}

  Solenoid(int _pin) {
    pinMode(pin, OUTPUT);
    pin = _pin;
    
  }

  void update(){
    if(millis() > solenoidTijd){
      if(solenoidHigh == false){
        solenoidHigh = true;
        digitalWrite(pin, HIGH);
        solenoidTijd = millis() + 5000;
      }
      if(solenoidHigh == true){
        solenoidHigh = false;
        digitalWrite(pin, LOW);
        solenoidTijd = millis() + 5000;
      }
    }
  }
  
};

Solenoid solenoid = Solenoid(7);
 void setup(){
  
  }

  void loop(){
    solenoid.update();
  }
