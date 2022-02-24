#include <Arduino_JSON.h>
#include <Servo.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define redpin 6
#define greenpin 10
#define bluepin 11

// common cathode LED
#define commonAnode false
byte gammatable[256];
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

Servo servo360;

KnikkerPoort poortBoven = KnikkerPoort();
Wissel wisselPoort = Wissel();
WiFiCommunicator wifi = WiFiCommunicator(WIFI_NETWERK, WIFI_WACHTWOORD, SERVER_DOMEINNAAM);
Teller tellerA = Teller(TELLER_A_PIN);
Teller tellerB = Teller(TELLER_B_PIN);
Solenoid solenoid = Solenoid(SOLENOID_A_PIN);

int serverContactInterval = 15; // 15 seconden
int oudAantalKnikkers = 0;
int tijdKnikkerInDoosje = 3000;
int tijdRGBSensor = 60;
bool wisselRechts = false;
bool knikkerWaargenomen = false; 
unsigned long tijdVoorContactMetServer = 0;
unsigned long tijdWisselScheef = 0;


void setup() {
  Serial.begin(9600);
  
  poortBoven.begin(BOVEN_POORT_PIN, 0, 90);
  wisselPoort.begin(WISSEL_PIN,0, 90, 45);
  
  //wifi.begin();

  //wifi.stuurVerzoek("/api/set/nieuwerun", "");

  poortBoven.open();
  wisselPoort.midden();

  servo360.attach(3);

  // Voor RGB sensor
  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;
    }
  }

}


void loop() {
  // laat de teller detecteren:
  tellerA.update();
  tellerB.update();
  solenoid.update();
  
  // pauzeer de knikkerbaan als het tijd is voor contact met server
  if (millis() > tijdVoorContactMetServer && poortBoven.getOpen()) {
    poortBoven.sluit();
  }

  // knikkerbaan is leeggelopen, er zijn geen sensors dit iets moeten meten
  // nu is het tijd om contact te leggen met de server:
  if (millis() > tijdVoorContactMetServer + LEEGLOOP_TIJD) {
    Serial.print("Er zijn nu zoveel knikkers geteld bij sensor 1: ");
    Serial.println(tellerA.getAantal());
    Serial.print("Er zijn nu zoveel knikkers geteld bij sensor 2: ");
    Serial.println(tellerB.getAantal());

    String data = "knikkers=";
    data += tellerA.getAantal();

    wifi.stuurVerzoek("/api/set/sensordata", data. c_str());

    String serverAntwoord = wifi.stuurVerzoek("/api/get/instellingen", "");
    Serial.println(serverAntwoord);

    JSONVar ontvangenInstellingen = JSON.parse(serverAntwoord);

    if(JSON.typeof(ontvangenInstellingen != "undefined")){
      //nieuwe wachttijd instellen:
      serverContactInterval = (int)ontvangenInstellingen["wachttijdPoort"];
      wisselRechts = (int)ontvangenInstellingen["wisselStaatRechts"];
    }
    else{
      Serial.println("FOUT: serverAntwoord kon niet worden verwerkt");
    }

    tijdVoorContactMetServer = millis() + (unsigned long)serverContactInterval * 1000;

    if (wisselPoort.getMidden() && tellerB.getAantal() > oudAantalKnikkers) {
      Serial.println("Knikker waargenomen");
      Serial.println(tellerB.getAantal());
      knikkerWaargenomen = true;
    }

    if (knikkerWaargenomen == true) {
      Serial.println("tijd in doosje wordt bepaald");
      tijdKnikkerInDoosje = millis() + 3000;
      if (millis() >  tijdKnikkerInDoosje) {
        Serial.println("tijd in doosje is voorbij");
        if (wisselRechts == true) {
          wisselPoort.rechts();
        }
        else {
          wisselPoort.links();
        }
        tijdWisselScheef = millis() + 3000;
        if (millis() > tijdWisselScheef && !wisselPoort.getMidden()) {
          Serial.println("wissel gaat weer sluiten");
          wisselPoort.midden();
        }
      }
      knikkerWaargenomen = false;
      oudAantalKnikkers = oudAantalKnikkers + 1;
    }
      
    // en zet nu het poortje weer open:
    poortBoven.open();

    servo360.write(80);

    // Voor RGB sensor
    float red, green, blue;
  
    tcs.setInterrupt(false);  // RGB LED aan
  
    // heeft 60ms nodig om te lezen
    if(millis() > tijdRGBSensor){
      tcs.getRGB(&red, &green, &blue);
      
      tcs.setInterrupt(true);  // turn off LED
    
      Serial.print("R:\t"); Serial.print(int(red)); 
      Serial.print("\tG:\t"); Serial.print(int(green)); 
      Serial.print("\tB:\t"); Serial.print(int(blue));
      Serial.print("\n");
    
      analogWrite(redpin, gammatable[(int)red]);
      analogWrite(greenpin, gammatable[(int)green]);
      analogWrite(bluepin, gammatable[(int)blue]);
      
      tijdRGBSensor = millis() + 60;
    }
  }
}
