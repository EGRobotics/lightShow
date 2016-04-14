unsigned int mils;

void setup() {
  //Serial.begin(9600);
  for (int i = 1; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void writeAllPins(int state, int minpin = 1, int maxpin = 13) {
  for (int i = minpin; i < maxpin + 1; i++) {
    digitalWrite(i, state);
  }
}

void flash(unsigned long start, int timer = 500, int minpin = 1, int maxpin = 13) {
  if (mils < start) {
    return;
  } else if (mils - start < timer) {
    writeAllPins(HIGH, minpin, maxpin);
  } else if (mils - start < timer * 2) {
    writeAllPins(LOW, minpin, maxpin);
  }
}

void sweep(unsigned long start, int state = HIGH, int dir = 1, int minpin = 1, int maxpin = 13, int timer = 100) {
  int dur = timer * ((maxpin - minpin) + 1);
  if (mils > start && mils < start + dur) {
    int now = (mils - start) / timer;
    int num = 0;
    if (dir > 0) {
      num = now + minpin;
    } else {
      num = maxpin - now;
    }
    digitalWrite(num, state);
  }
}

void loop() {
  mils = millis() % 12000;
  // half bar fill
  sweep(100, HIGH, 1, 1, 7);
  sweep(100, HIGH, -1, 8, 13);
  // half bar unfill
  sweep(900, LOW, -1, 1, 7);
  sweep(900, LOW, 1, 8, 13);
  // crazy strobe flashing
  flash(1600);
  flash(2600, 400);
  flash(3400, 300);
  flash(4000, 200);
  flash(4400, 100);
  flash(4600, 50);
  flash(4700, 50);
  flash(4800, 50);
  flash(4900, 50);
  flash(5000, 50);
  flash(5100, 50);
  flash(5200, 50);
  // full fill
  if(mils > 5250 && mils < 5300){ writeAllPins(HIGH); }
  // halfbar unfill
  sweep(5300, LOW, -1, 1, 7, 10);
  sweep(5300, LOW, 1, 8, 13, 10);
  // halfbar fill
  sweep(5400, HIGH, 1, 1, 7, 10);
  sweep(5400, HIGH, -1, 8, 13, 10);
  // halfbar unfill
  sweep(5500, LOW, -1, 1, 7, 20);
  sweep(5500, LOW, 1, 8, 13, 20);
  // halfbar fill
  sweep(5700, HIGH, 1, 1, 7, 20);
  sweep(5700, HIGH, -1, 8, 13, 20);
  // halfbar unfill
  sweep(5900, LOW, -1, 1, 7, 30);
  sweep(5900, LOW, 1, 8, 13, 30);
  // halfbar fill
  sweep(6200, HIGH, 1, 1, 7, 30);
  sweep(6200, HIGH, -1, 8, 13, 30);
  // halfbar unfill
  sweep(6500, LOW, -1, 1, 7, 40);
  sweep(6500, LOW, 1, 8, 13, 40);
  // halfbar fill
  sweep(6800, HIGH, 1, 1, 7, 40);
  sweep(6800, HIGH, -1, 8, 13, 40);
  // sweep two off from left
  sweep(7100);
  sweep(7200, LOW);
  sweep(7300, LOW);
  sweep(7400);
  // sweep two off from left
  sweep(8000);
  sweep(8100, LOW);
  sweep(8200, LOW);
  sweep(8300);
  // sweep two off from left
  sweep(8900);
  sweep(9000, LOW);
  sweep(9100, LOW);
  sweep(9200);
  // sweep two off from left
  sweep(9800);
  sweep(9900, LOW);
  sweep(10000, LOW);
  sweep(10100);
  // full unfill
  if(mils > 11500 && mils < 11600){ writeAllPins(LOW); }
  /*
  // half bar unfill
  sweep(5300, LOW, -1, 1, 7);
  sweep(5300, LOW, 1, 8, 13);
  // sweep from left
  sweep(6000);
  sweep(6100, LOW);
  // sweep from right
  sweep(7400, HIGH, -1);
  sweep(7500, LOW, -1);
  */
}

