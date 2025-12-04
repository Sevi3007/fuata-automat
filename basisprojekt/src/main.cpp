#include <Arduino.h>
#include <Bounce2.h>

// Definierte Pins für die Buttons
const int BTN_PINK = 2;
const int BTN_BLUE = 3;

// Definierte Pins für die LEDs
const int LED_PINK = 9;
const int LED_BLUE = 8; // LED_BLUE ist auf Pin 8

// Bounce2 Objekte für die Buttons
Bounce2 :: Button btnPink = Bounce2 :: Button();
Bounce2 :: Button btnBlue = Bounce2 :: Button();

// Eine Konstante für die Verzögerungszeit in Millisekunden beim Blinken
const int BLINK_DELAY = 250; 


void setup() {
  // Pin-Modi für beide LEDs als OUTPUT setzen
  pinMode(LED_PINK, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  // Serielle Kommunikation starten
  Serial.begin(9600);
  
  // Pinker Button initialisieren
  // INPUT_PULLUP verwenden und den gedrückten Zustand auf LOW setzen (wenn der Knopf Masse schaltet)
  btnPink.attach(BTN_PINK, INPUT_PULLUP);
  btnPink.setPressedState(LOW);

  // Blauer Button initialisieren
  btnBlue.attach(BTN_BLUE, INPUT_PULLUP);
  btnBlue.setPressedState(LOW);
}

void loop() {
  // Die Button-Objekte aktualisieren
  btnPink.update();
  btnBlue.update();

  // --- Logik für den PINKEN Knopf ---
  if(btnPink.pressed())
  {
      Serial.println("pink pressed");
      // Pink LED 2 Sekunden lang einschalten
      digitalWrite(LED_PINK, HIGH);
      delay(2000); // Achtung: delay blockiert den gesamten Code
      digitalWrite(LED_PINK, LOW);
  }

  // --- Logik für den BLAUEN Knopf ---
  if(btnBlue.pressed())
  {
      Serial.println("blue pressed - Starte 10x abwechselndes Blinken");
      
      // Schleife, die 10 Mal durchläuft
      for(int i = 0; i < 10; i++)
      {
          // 1. Pinke LED an, Blaue LED aus
          digitalWrite(LED_PINK, HIGH);
          digitalWrite(LED_BLUE, LOW);
          delay(BLINK_DELAY); // Wartezeit

          // 2. Pinke LED aus, Blaue LED an
          digitalWrite(LED_PINK, LOW);
          digitalWrite(LED_BLUE, HIGH);
          delay(BLINK_DELAY); // Wartezeit
      }
      
      // Nach dem Blinken: Beide LEDs ausschalten, um den Zustand zurückzusetzen
      digitalWrite(LED_PINK, LOW);
      digitalWrite(LED_BLUE, LOW);
      
      Serial.println("Blinken beendet.");
  }
}