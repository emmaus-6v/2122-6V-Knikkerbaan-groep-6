
class Poortje {
  xBegin;
  yBegin;
  xEind;
  yEind;
  bounceY;

  constructor(_xBegin, _yBegin, _xEind, _yEind, _bounceY) {
    this.xBegin = _xBegin;
    this.yBegin = _yBegin;
    this.xEind = _xEind;
    this.yEind = _yEind;
    this.bounceY = _bounceY;
  }

  update(){
    this.yBegin = this.yBegin + this.bounceY;
    if(this.yBegin <= 50){
      this.bounceY = this.bounceY * -1;
    }
    if(this.yBegin >= 70){
      this.bounceY = this.bounceY * -1;
    }
  }

  show() {

    stroke(255, 255, 255); // wel rand
    strokeWeight(5);
    line(this.xBegin, this.yBegin, this.xEind, this.yEind );
  }
}