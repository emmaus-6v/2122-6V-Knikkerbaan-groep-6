
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
  
  int pin;
  bool wasOnderbroken;
  wasOnderbroken = false;


}


// the loop function runs over and over again forever
void loop() {


  bool isOnderbroken() {
    return !digitalRead(pin);
  }

  bool wordtOnderbroken() {
    return (wasOnderbroken == false && isOnderbroken() == true);
  }
  

if (wordtOnderbroken()) {
  digitalWrite(6, HIGH);   
        } 
      }

      wasOnderbroken = isOnderbroken();
    }

}
