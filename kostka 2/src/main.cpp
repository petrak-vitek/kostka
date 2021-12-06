#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

#define stred 4
#define rovne 3
#define vpred 2
#define vzad 0
#define tl 1
#define pauza 20

void zhasni();
void rozsvit();
void otoc();
void vstan();
void spi();

byte cislo = 0;
byte toc = 0;
int cas = 0;
int cas_min = 0;

void setup()
{
  pinMode(stred, OUTPUT);
  pinMode(rovne, OUTPUT);
  pinMode(vpred, OUTPUT);
  pinMode(vzad, OUTPUT);
  pinMode(tl, INPUT_PULLUP);
  spi();
}

void loop()
{

  // while (digitalRead(tl) == 1)
  // {

  // }
  zhasni();
  while (digitalRead(tl) == 0)
  {
    delay(1);
    cas++;
    cislo++;
    if (cislo > 6)
    {
      cislo = 1;
    }
    if (cas_min + pauza < cas)
    {
      otoc();
      cas_min = cas;
    }
  }

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
  }

  /*
  
  for (int i = 0; i < 500; i++)
  {
    delay(1);
    if (digitalRead(tl) == 0){
    while (digitalRead(tl) == 0)
    {
      
    } 
    break;
    }
  }
*/
  delay(400);
  while (digitalRead(tl) == 0)
  {
  }

  spi();
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

void otoc()
{
  toc++;
  switch (toc)
  {
  case 1:
    digitalWrite(stred, HIGH);
    digitalWrite(vzad, LOW);
    digitalWrite(rovne, HIGH);
    break;

  case 2:
    digitalWrite(rovne, LOW);
    digitalWrite(vpred, HIGH);
    break;

  case 3:
    digitalWrite(vpred, LOW);
    digitalWrite(vzad, HIGH);
    toc = 0;
    break;
  }
}

void spi()
{

  zhasni();
  GIMSK |= _BV(PCIE);
  PCMSK |= _BV(PCINT1);
  sei();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  // cli();
  //  sleep_enable();
  sleep_mode();
  //  sleep_cpu ();
 cli();
  //sleep_disable();
  // power_all_enable();
  //attachInterrupt (digitalPinToInterrupt(1), vstan, FALLING);
  //interrupts ();
  //losuj();
}

//void vstan(){
//  sleep_disable();
//}

ISR(PCINT0_vect)
{
  //  sleep_disable();
}
