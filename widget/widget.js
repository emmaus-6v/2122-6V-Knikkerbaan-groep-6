
// globale variabelen
var aantalKnikkersBoven = 0;    // aantal knikkers dat bovenin is binnengekomen
var wachttijd = 15;             // wachttijd voor het poortje in seconden
const UPDATE_INTERVAL = 5000;   // tijd in milliseconden tussen het door widget opvragen van gegevens
var button;
var teller;
var solenoid;
var wachttijdInput;
var wisselStaatRechts = false;



/**
 * setup
 * de code in deze functie wordt eenmaal uitgevoerd,
 * als p5js wordt gestart
 */
function setup() {
  // Maak het canvas van je widget
  createCanvas(300, 600);

  // classes worden aangeroepen
  teller = new Teller(147.5, 40);
  solenoid = new Solenoid(255, 515, 510, -2);
  poortje = new Poortje(135, 50, 165, 50, 0.2);
  rad = new Rad(40, 100);

  // knop voor instellingen
  button = createButton('Verstuur');
  button.position(235, 50);
  button.mouseClicked(stuurNieuweInstellingen);

  wachttijdInput = createInput();
  wachttijdInput.position(180, 50);
  wachttijdInput.size(50);

  button = createButton('Links');
  button.position(110, 110);
  button.mouseClicked(links);

  button = createButton('Rechts');
  button.position(150, 110);
  button.mouseClicked(rechts);

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

  // achtergrond: houtkleur, kies gerust iets anders
  background(0, 0, 0);

  stroke(255, 255, 255);
  strokeWeight(2);
  fill(0, 0, 0);
  triangle (60, 525, 150, 630, 240, 525);

  // dikke strepen waar de knikker door kan rollen
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
  line(150, 260, 110, 280);
  line(110, 280, 90, 280);
  line(90, 290, 70, 290);
  line(70, 300, 50, 300);
  line(50, 310, 30, 310);
  line(90, 280, 90, 290);
  line(70, 290, 70, 300);
  line(50, 300, 50, 310);
  line(0, 330, 110, 370);
  line(150, 380, 70, 410);
  line(250, 510, 250, 580);
  line(290, 510, 290, 580);
  line(250, 580, 290, 580);

  stroke(255, 255, 255);
  strokeWeight(2);
  fill(0 , 0, 0);
  rect(125, 130, 50, 50);
  ellipse(20, 400, 20, 20);
  ellipse(30, 420, 20, 20);
  ellipse(45, 435, 20, 20);
  ellipse(65, 445, 20, 20);
  ellipse(85, 455, 20, 20);
  ellipse(105, 465, 20, 20);
  ellipse(225, 420, 110, 110);
 
  noStroke();
  fill(0, 0, 0);
  rect(222, 355, 30, 30);
  rect(192, 445, 100, 60);
  rect(250, 400, 60, 60);

  stroke(255, 255, 255);
  strokeWeight(2);
  line(276, 400, 276, 500);
  line(276, 500, 272, 505);
  line(220, 390, 220, 470);
  line(220, 470, 250, 510);
  line(220, 470, 190, 515);


  teller.show();
  solenoid.update();
  solenoid.show();
  poortje.update();
  poortje.show();
  rad.show();
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
  var request = new XMLHttpRequest();

  request.open('GET', '/api/set/instellingen?wachttijd=' + wachttijdInput.value() +"&wisselStaatRechts=" + wisselStaatRechts, true);

  request.onload = function (){
    if(request.status == 200){
        console.log("Server accepteerde instellingen");
    }
    else{
      console.log("Server reageert niet zoals gehoopt");
      console.log(request.response);
    }
  }
  // verstuur het request
  request.send()
}

//stuurt door dat er op knop links is geklikt
function links(){
  wisselStaatRechts = false;
  stuurNieuweInstellingen(); //to do kijken of deze haakjes en functie kloppen
}

//stuurt door dat er op knop links is geklikt
function rechts(){
  wisselStaatRechts = true;
  stuurNieuweInstellingen(); //to do kijken of deze haakjes en functie kloppen
}
