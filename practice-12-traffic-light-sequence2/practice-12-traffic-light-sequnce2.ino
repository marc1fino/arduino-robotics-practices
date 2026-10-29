#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int PULSADOR = 7;
const int ROJO_PEATONES = 2;
const int VERDE_PEATONES = 3;
const int ROJO_COCHES = 4;
const int AMARILLO_COCHES = 5;
const int VERDE_COCHES = 6;

void encen(int led){
	digitalWrite(led, HIGH);
}

void apaga(int led){
  	digitalWrite(led, LOW);
}

void apagaTot(){
  apaga(ROJO_PEATONES);
  apaga(VERDE_PEATONES);
  apaga(ROJO_COCHES);
  apaga(AMARILLO_COCHES);
  apaga(VERDE_COCHES);
  delay(1000);
}

void apagaTotMenysVerdeCoches(){
  apaga(ROJO_PEATONES);
  apaga(VERDE_PEATONES);
  apaga(ROJO_COCHES);
  apaga(AMARILLO_COCHES);
}

void parpadear(int led){
  encen(led);
  delay(1000);
  apaga(led);
  delay(1000);
}

void aturaCotxes() {
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Cars stop");
  apagaTot();
  parpadear(AMARILLO_COCHES);
  parpadear(AMARILLO_COCHES);
  parpadear(AMARILLO_COCHES);
}

void secuenciaInicial(){
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Peatons go");
  apagaTot();
  encen(ROJO_COCHES);
  encen(ROJO_PEATONES);
  delay(1000);
  apaga(ROJO_PEATONES);
  parpadear(VERDE_PEATONES);
  parpadear(VERDE_PEATONES);
  encen(VERDE_PEATONES);
  delay(1000);
  apaga(VERDE_PEATONES);
  encen(ROJO_PEATONES);
  delay(1000);
  apaga(ROJO_COCHES);
  encen(VERDE_COCHES);
  delay(3000);
}

void setup()
{
  pinMode(PULSADOR, INPUT);
  pinMode(ROJO_PEATONES, OUTPUT);
  pinMode(VERDE_PEATONES, OUTPUT);
  pinMode(ROJO_COCHES, OUTPUT);
  pinMode(VERDE_COCHES, OUTPUT);
  pinMode(AMARILLO_COCHES, OUTPUT);
}

void loop() {
  if (digitalRead(PULSADOR) == HIGH) {
    aturaCotxes();
    secuenciaInicial();
  } else {
    lcd.setCursor(0,0);
    lcd.println("Peatons stop");
    apagaTotMenysVerdeCoches();
    encen(VERDE_COCHES);
  }
}
