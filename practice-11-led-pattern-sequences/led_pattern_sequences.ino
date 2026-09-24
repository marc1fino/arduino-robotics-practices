// C++ code
//

int led1=7;
int led2=6;
int led3=5;
int led4=4;
int led5=3;
int espera=500;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void encen(int led){
	digitalWrite(led, HIGH);
}

void apaga(int led){
  	digitalWrite(led, LOW);
}

void parpadear(int led){
  encen(led);
  delay(espera); // Wait for 1000 millisecond(s)
  apaga(led);
  delay(espera); // Wait for 1000 millisecond(s)
}

void encenTot(){
  encen(led1);
  encen(led2);
  encen(led3);
  encen(led4);
  encen(led5);
  delay(1000);

}

void apagaTot(){
  apaga(led1);
  apaga(led2);
  apaga(led3);
  apaga(led4);
  apaga(led5);
  delay(1000);

}

void parpadearTot(){
  encenTot();
  apagaTot();
}

void estel(){
  Serial.println("Estel");
  for ( int i = 7 ; i >= 3 ; i-- ) {
    parpadear(i);
  }
}

void zigzag(){
  Serial.println("Zigzag");
  for ( int i = 7 ; i >= 3 ; i-- ) {
    parpadear(i);
  }
  for ( int i = 3 ; i <= 7 ; i++ ) {
    parpadear(i);
  }
}

void simetria() {
  Serial.println("Simetria");
  encen(led1);
  encen(led5);
  delay(espera);
  apaga(led1);
  apaga(led5);
  encen(led2);
  encen(led4);
  delay(espera);
  apaga(led2);
  apaga(led4);
  encen(led3);
  delay(espera);
  apaga(led3);
  encen(led2);
  encen(led4);
  delay(espera);
  apaga(led2);
  apaga(led4);
  encen(led1);
  encen(led5);
  delay(espera);
}

void dimm() {
  Serial.println("Dimm");
  encen(led1);
  encen(led5);
  encen(led2);
  encen(led3);
  encen(led4);
  delay(espera);
  apaga(led1);
  delay(espera);
  apaga(led2);
  delay(espera);
  apaga(led3);
  delay(espera);
  apaga(led4);
  delay(espera);
  delay(espera);
  encen(led4);
  delay(espera);
  encen(led3);
  delay(espera);
  encen(led2);
  delay(espera);
  encen(led1);
  delay(espera);
}

void loop()
{
  estel();
  apagaTot();
  simetria();
  apagaTot();
  zigzag();
  dimm();
  apagaTot();
  for (int i = 1; i <= 5; i++) {
    parpadearTot();
  }
  while(true) {
    // Para el programa així només 5 vegades
  }
}
