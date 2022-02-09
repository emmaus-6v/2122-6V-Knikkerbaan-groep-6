
// globale variabelen
var aantalKnikkersBoven = 0;    // aantal knikkers dat bovenin is binnengekomen
var wachttijd = 15;             // wachttijd voor het poortje in seconden
const UPDATE_INTERVAL = 5000;   // tijd in milliseconden tussen het door widget opvragen van gegevens
var button;
var teller;
var wachtijdInput;


/**
 * setup
 * de code in deze functie wordt eenmaal uitgevoerd,
 * als p5js wordt gestart
 */
function setup() {
  // Maak het canvas van je widget
  createCanvas(300, 600);

  teller = new Teller(150, 50);


  // om de ... milliseconden wordt 'vraagSensorData' uitgevoerd
  setInterval(vraagSensorData, UPDATE_INTERVAL);
}


/**
 * draw
 * de code in deze functie wordt meerdere keren per seconde
 * uitgevoerd door de p5 library, nadat de setup functie klaar is
 */
function draw() {
  // schrijf hieronder de code van je widget
  // hieronder wordt schematisch een knikkerbaan getekend
  var xRad = 40;
  var yRad = 100;
  // achtergrond: houtkleur, kies gerust iets anders
  background(0, 0, 0);

  noStroke();
  ellipse(xRad, yRad, 65, 65);
  fill(0, 0, 0);
  ellipse(xRad + 20, yRad + 20, 20, 20);
  ellipse(xRad - 20, yRad + 20, 20, 20);
  ellipse(xRad, yRad - 30, 20, 20);
  // twee dikke strepen als 'opvangbak'
  stroke(255, 255, 255);
  strokeWeight(5);
  line(50, 7, 135, 40);
  line(250, 7, 165, 40);
  line(135, 40, 135, 50);
  line(165, 40, 165, 50);
  line(170, 70, 80, 100);
  line(60, 135, 125, 175);
  line(150, 200, 100, 220);
  line(150, 200, 200, 220);
  line(150, 200, 150, 500);
  line(300, 210, 190, 250);
  line(0, 210, 110, 250);
  line(150, 260, 260, 300);
  line(300, 310, 250, 340);
  line(150, 320, 225, 345);
  line(260, 330, 248, 326);

  stroke(255, 255, 255);
  strokeWeight(2);
  fill(0 , 0, 0);
  rect(125, 130, 50, 50);


  teller.show();
}


// stuurt een verzoek aan de server dat alle
// sensordata opvraagt
function vraagSensorData() {
  var request = new XMLHttpRequest();

  // maak een http-verzoek
  request.open('GET', '/api/get/sensordata', true)

  // wat uitvoeren als het antwoord teruggegeven wordt?
  request.onload = function () {
    var data = JSON.parse(request.response);

    if (request.status == 200) {
      console.log("Dit geeft de server terug:" + data);
      teller.aantal = data.aantalKnikkers;
    }
    else {
      console.log("server reageert niet zoals gehoopt");
      console.log(request.response);
    }
  }

  // verstuur het request
  request.send()
}


// stuurt een http-verzoek aan de server met de
// nieuwe instellingen
function stuurNieuweInstellingen() {
  // moet nog worden gemaakt
}