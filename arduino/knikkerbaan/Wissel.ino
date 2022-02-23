class Wissel {
  private:
    Servo wisselServo;
    int pin;
    int gradenLinks;
    int gradenRechts;
    int gradenMidden;
    bool staatLinks = false;
    bool staatRechts = false;
    bool staatMidden = true;

  public:
    Wissel(){}

    begin(int _pin, int _gradenLinks, int _gradenRechts, int _gradenMidden){
      pin = _pin;
      pinMode(pin, OUTPUT);
      wisselServo.attach(pin);
      gradenLinks = _gradenLinks;
      gradenRechts = _gradenRechts;
      gradenMidden = _ gradenMidden;
      midden();
    }
    
   void midden(){
    wisselServo.write(gradenMidden);
    staatMidden = true;
    staatRechts = false;
    staatLinks = false;
   }
   
   void rechts(){
    wisselServo.write(gradenRechts);
    staatRechts = true;
    staatMidden = false;
    staatLinks = false;
   }
   
   void links(){
    wisselServo.write(gradenLinks);
    staatLinks = true;
    staatRechts = false;
    staatMidden = false;
   }

   bool getMidden() {
      return staatMidden;
    }
};
