#include <IRremote.h>

int RECV_PIN = 2;
int diodica1 = 7;
int diodica2 = 8;
int piezo = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define CRVENO 0x707005FA
#define ZELENO 0x7070857A
#define ZUTO 0x707045BA
#define PLAVO 0x7070C53A

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(diodica1, OUTPUT);
  pinMode(diodica2, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == CRVENO) {
      digitalWrite(piezo, LOW);
      digitalWrite(diodica2, LOW);
      digitalWrite(diodica1, HIGH);
    }
    if(results.value == ZELENO) {
      digitalWrite(piezo, LOW);
      digitalWrite(diodica1, LOW);
      digitalWrite(diodica2, HIGH);
    }
    if(results.value == ZUTO) {
      digitalWrite(diodica1, HIGH);
      digitalWrite(diodica2, HIGH);
      digitalWrite(piezo, HIGH);
    }
    if(results.value == PLAVO) {
      digitalWrite(piezo, LOW);
      digitalWrite(diodica2, LOW);
      digitalWrite(diodica1, LOW);
    }
    irrecv.resume();
  }
}
