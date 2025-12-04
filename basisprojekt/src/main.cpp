#include <Arduino.h>
#include <Bounce2.h>



//buttons an den pins 2 und 3

//#define BTN_pink 2
//#define BTN_blue 3

const int BTN_PINK = 2;
const int BTN_BLUE = 3;


const int LED_PINK = 9;
const int LED_BLUE = 8;

Bounce2 :: Button btnPink = Bounce2 :: Button();
Bounce2 :: Button btnBlue = Bounce2 :: Button();





int counter = 0;


void setup() {

  pinMode(LED_PINK,OUTPUT);
  pinMode (LED_PINK,OUTPUT);




  Serial.begin(9600);
  btnPink.attach(BTN_PINK,INPUT_PULLUP);
  btnPink.setPressedState(LOW);

  btnBlue.attach(BTN_BLUE,INPUT_PULLUP);
  btnBlue.setPressedState(LOW);
}

void loop() {
  btnPink.update();
  btnBlue.update();

  if(btnPink.pressed())
  {
      Serial.println("pink pressed");
      digitalWrite(LED_PINK,HIGH);
      delay(2000);
      digitalWrite(LED_PINK,LOW);
  }

   if(btnBlue.pressed())
  {
      Serial.println("blue pressed");
  }


}

