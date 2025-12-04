#include <Arduino.h>
#include <Bounce2.h>

// ----------------------
// PIN-DEFINITIONEN
// ----------------------
// Definierte Pins für die Buttons
const int BTN_PINK = 2;
const int BTN_BLUE = 3;

// Definierte Pins für die LEDs
const int LED_PINK = 9;
const int LED_BLUE = 8; // LED_BLUE ist auf Pin 8

// ----------------------
// VARIABLEN UND OBJEKTE
// ----------------------
// Bounce2 Objekte für die Buttons
Bounce2 :: Button btnPink = Bounce2 :: Button();
Bounce2 :: Button btnBlue = Bounce2 :: Button();

// Eine Konstante für die Verzögerungszeit in Millisekunden beim Blinken (aus HEAD übernommen)
const int BLINK_DELAY = 250; 

// Die Variable 'counter' aus dem Konflikt wurde entfernt, da sie nirgends verwendet wurde.

// ----------------------
// HILFSFUNKTIONEN
// ----------------------

// Kurzes Blinken für SOS-Signal
void kurz(int led) {
  digitalWrite(led, HIGH);
  delay(200);       
  digitalWrite(led, LOW);
  delay(200);       
}

// Langes Blinken für SOS-Signal
void lang_(int led) {
  digitalWrite(led, HIGH);
  delay(600);       
  digitalWrite(led, LOW);
  delay(200);       
}

// SOS-Signal (S-O-S)
void sosBlink(int led) {
  // S (. . .)
  kurz(led);
  kurz(led);
  kurz(led);

  delay(300); // Pause zwischen S und O 

  // O (- - -)
  lang_(led);
  lang_(led);
  lang_(led);

  delay(300); // Pause zwischen O und S

  // S (. . .)
  kurz(led);
  kurz(led);
  kurz(led);

  delay(500); // Längere Pause nach einem vollständigen SOS
}

// ----------------------
// SETUP
// ----------------------

void setup() {
  // Pin-Modi für beide LEDs als OUTPUT setzen
  pinMode(LED_PINK, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  // Serielle Kommunikation starten
  Serial.begin(9600);
  
  // Pinker Button initialisieren (INPUT_PULLUP und gedrückter Zustand LOW)
  btnPink.attach(BTN_PINK, INPUT_PULLUP);
  btnPink.setPressedState(LOW);

  // Blauer Button initialisieren
  btnBlue.attach(BTN_BLUE, INPUT_PULLUP);
  btnBlue.setPressedState(LOW);
}

// ----------------------
// LOOP
// ----------------------

void loop() {
  // Die Button-Objekte aktualisieren
  btnPink.update();
  btnBlue.update();

  // --- Logik für den PINKEN Knopf (verwendet SOS-Logik des Kollegen) ---
  if(btnPink.pressed())
  {
    Serial.println("pink pressed - Starte 3x SOS-Signal");
    
    // Führe das SOS-Signal 3 Mal aus
    for(int i = 0; i < 3; i++) { 
      sosBlink(LED_PINK);
    }
    Serial.println("SOS-Signale beendet.");
  }

  // --- Logik für den BLAUEN Knopf (verwendet abwechselndes Blinken) ---
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