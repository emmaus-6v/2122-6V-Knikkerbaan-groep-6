#include <Arduino_JSON.h>
#include <Servo.h>

Servo servo360;



KnikkerPoort poortBoven = KnikkerPoort();
WiFiCommunicator wifi = WiFiCommunicator(WIFI_NETWERK, WIFI_WACHTWOORD, SERVER_DOMEINNAAM);
Teller tellerA = Teller(TELLER_A_PIN);
Teller tellerB = Teller(TELLER_B_PIN);

int serverContactInterval = 15;                // 15 seconden
unsigned long tijdVoorContactMetServer = 0;

void setup() {
  Serial.begin(9600);
  
  poortBoven.begin(BOVEN_POORT_PIN, 0, 90);
  
  //wifi.begin();

  //wifi.stuurVerzoek("/api/set/nieuwerun", "");

  poortBoven.open();

  servo360.attach(3);

}


void loop() {
  // laat de teller detecteren:
  tellerA.update();

  
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

    tijdVoorContactMetServer = millis() + (unsigned long)serverContactInterval * 1000;
    // en zet nu het poortje weer open:
    poortBoven.open();

     servo360.write(80);

  }
}
