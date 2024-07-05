
#define motor1 4
#define motor2 5
#define motor3 6
#define motor4 7

int pinState1;
int pinState2;
int pinState3;
int pinState4;

void setup() {
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}

void loop() {
  Serial.println("direitoTras() esquerdoFrente()");
  direitoTras();
  esquerdoFrente();
  showPortStates();
  delay(3000);
  Serial.println("direitoFrente() esquerdoTras()");
  direitoFrente();
  esquerdoTras();
  showPortStates();
  delay(3000);
  Serial.println("direitoTras() esquerdoFrente()");
  direitoTras();
  esquerdoFrente();
  showPortStates();
  delay(3000);
  Serial.println("direitoFrente() esquerdoTras()");
  direitoFrente();
  esquerdoTras();
  showPortStates();
  delay(3000);
  parado();
  showPortStates();
  delay(10 * 1000);
  /*frente();
  showPortStates();
  delay(5000);
  tras();
  showPortStates();
  delay(5000);
  esquerda();
  showPortStates();
  delay(5000);
  direita();
  showPortStates();
  delay(5000);*/
}

void girarEsquerda() {
  Serial.println("girarEsquerda()");
  esquerdoTras();
  direitoFrente();
}

void girarDireita() {
  Serial.println("girarDireita()");
  esquerdoFrente();
  direitoTras();
}

void moverEsquerda() {
  Serial.println("moverEsquerda()");
  esquerdoParado();
  direitoFrente();
}

void moverDireita() {
  Serial.println("moverDireita()");
  esquerdoFrente();
  direitoParado();
}

void parado() {
  Serial.println("parado()");
  direitoParado();
  esquerdoParado();
}

void direitoFrente() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
}

void esquerdoFrente() {
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
} 

void direitoTras() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
}

void esquerdoTras() {
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}

void direitoParado() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
}

void esquerdoParado() {
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}

void showPortStates() {
  pinState1 = digitalRead(motor1);
  pinState2 = digitalRead(motor2);
  pinState3 = digitalRead(motor3);
  pinState4 = digitalRead(motor4);
  Serial.println(pinState1);
  Serial.println(pinState2);
  Serial.println(pinState3);
  Serial.println(pinState4);
}
