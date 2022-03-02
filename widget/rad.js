
class Rad {
  x;
  y;

  constructor(_x, _y) {
    this.x = _x;
    this.y = _y;
  }

  show() {
    noStroke(); // geen rand

    fill(255, 255, 255);
    ellipse(this.x, this.y, 65, 65);

    fill(0, 0, 0);
    ellipse(this.x + 20, this.y + 20, 20, 20);
    ellipse(this.x - 20, this.y + 20, 20, 20);
    ellipse(this.x, this.y - 30, 20, 20);
  }
}