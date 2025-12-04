#include <Arduino.h>
#include <Bounce2.h>

//buttons an den pins 2 und 3

const int BTN_PINK = 2;
const int BTN_BLUE = 3;

const int LED_PINK = 9;
const int LED_BLUE = 8;

Bounce2 :: Button btnPink = Bounce2 :: Button();
Bounce2 :: Button btnBlue = Bounce2 :: Button();

int counter = 0;




void kurz(int led) {
  digitalWrite(led, HIGH);
  delay(200);      
  digitalWrite(led, LOW);
  delay(200);      
}


void lang_(int led) {
  digitalWrite(led, HIGH);
  delay(600);      
  digitalWrite(led, LOW);
  delay(200);      
}


void sosBlink(int led) {

  
  kurz(led);
  kurz(led);
  kurz(led);

  delay(300); 

  
  lang_(led);
  lang_(led);
  lang_(led);

  delay(300);

 
  kurz(led);
  kurz(led);
  kurz(led);

  delay(500); 
}

void setup() {

  pinMode(LED_PINK,OUTPUT);
  pinMode (LED_BLUE,OUTPUT);   

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
      
      for(int i = 0; i < 3; i++) {   
        sosBlink(LED_PINK);
      }
  }

  
   if(btnBlue.pressed())
  {
      Serial.println("blue pressed");
  }

}
