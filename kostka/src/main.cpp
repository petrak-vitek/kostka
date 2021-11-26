#include <Arduino.h>

#define stred 4
#define rovne 3
#define vpred 2
#define vzad 0
#define tl 1
#define pauza 20

void zhasni();
void toc();
void rozsvit();

byte cislo = 0;

void setup()
{
  // put your setup code here, to run once:
  pinMode(stred, OUTPUT);
  pinMode(rovne, OUTPUT);
  pinMode(vpred, OUTPUT);
  pinMode(vzad, OUTPUT);
  pinMode(tl, INPUT_PULLUP);
}

void loop()
{
  while (digitalRead(tl) == 1)
  {
  }
  zhasni();
  while (digitalRead(tl) == 0)
  {
    toc();
  }
  
  cislo = random(1, 6);
  rozsvit();
  delay(30);
  zhasni();

  switch (cislo)
  {
  case 1:
    digitalWrite(stred, HIGH);
    break;

  case 2:
    digitalWrite(vzad, HIGH);
    break;

  case 3:
    digitalWrite(vzad, HIGH);
    digitalWrite(stred, HIGH);
    break;

  case 4:
    digitalWrite(vzad, HIGH);
    digitalWrite(vpred, HIGH);
    break;

  case 5:
    digitalWrite(vzad, HIGH);
    digitalWrite(vpred, HIGH);
    digitalWrite(stred, HIGH);
    break;

  case 6:
    digitalWrite(vzad, HIGH);
    digitalWrite(vpred, HIGH);
    digitalWrite(rovne, HIGH);
    break;

  default:
    break;
  }
}

void zhasni()
{
  digitalWrite(stred, LOW);
  digitalWrite(rovne, LOW);
  digitalWrite(vpred, LOW);
  digitalWrite(vzad, LOW);
}

void rozsvit()
{
  digitalWrite(stred, HIGH);
  digitalWrite(rovne, HIGH);
  digitalWrite(vpred, HIGH);
  digitalWrite(vzad, HIGH);
}

void toc()
{
  digitalWrite(stred, HIGH);
  digitalWrite(rovne, HIGH);
  delay(pauza);
  digitalWrite(rovne, LOW);
  digitalWrite(vpred, HIGH);
  delay(pauza);
  digitalWrite(vpred, LOW);
  digitalWrite(vzad, HIGH);
  delay(pauza);
  digitalWrite(vzad, LOW);
}