// gebruik Grove - Mosfet (Rood > 5V, Zwart > GND, Geel > Pin 6)


// the setup function runs once when you press reset or power the board
int SolenoidPin = 6;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(SolenoidPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(SolenoidPin, HIGH);   
  delay(1000);                       
  digitalWrite(SolenoidPin, LOW);    
  delay(1000);                       
}
