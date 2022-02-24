class Solenoid {
  x;
  y;
  veerY;
  bounceY;

  constructor(_x, _y,_veerY, _bounceY) {
    this.x = _x;
    this.y = _y;
    this.veerY = _veerY;
    this.bounceY = _bounceY;
  }

  update(){
    this.veerY = this.veerY + this.bounceY;
    if(this.veerY <= 490){
      this.bounceY = this.bounceY * -0.25;
    }
    if(this.veerY >= 510){
      this.bounceY = this.bounceY * -4;
    }
  }

  show() {

    noStroke();               // geen rand
    fill(100, 100, 100);
    rect(this.x + 5, this.veerY, 7, 25);
    rect(this.x + 5, this.y + 40, 7, 17);

    fill(150, 150, 150);
    rect(this.x, this.y, 17, 40);

    fill(0, 0, 255);
    rect(this.x + 5, this.y + 5, 7, 30);

    stroke(220, 220, 220);  // wel rand
    strokeWeight(1);
    fill(150, 150, 150);
    ellipse(this.x + 8.5, this.y + 43, 10, 3);
    ellipse(this.x + 8.5, this.y + 46, 10, 3);
    ellipse(this.x + 8.5, this.y + 49, 10, 3);
    ellipse(this.x + 8.5, this.y + 52, 10, 3);
  }
}