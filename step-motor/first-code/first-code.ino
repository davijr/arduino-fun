#include <Stepper.h>

int TEMPO_LIXEIRA_ABERTA = 5; // segundos

int passosPorVolta = 32; // capacidade de passos do motor
int reducao = 64;
int totalPassos = passosPorVolta * reducao;
int velocidadeMaxima = 1200; // rpm

Stepper mp(passosPorVolta, 8, 9, 10, 11);

void setup() {
  mp.setSpeed(velocidadeMaxima); // velocidade em rpm: rotações por minuto
}

void loop() {
  runLixeira();
  delay(10 * 1000); // todo remover
  //vaiEVolta();
  //vaiPraFrenteVoltaUmPouquinho();
  //praFrente();
  //praTras();
}

void runLixeira() {
  abrirLixeira();
  delay(TEMPO_LIXEIRA_ABERTA * 1000);
  fecharLixeira();
}

void abrirLixeira() {
  int passos = (totalPassos / 2);
  mp.step(passos);
}

void fecharLixeira() {
  int passos = (totalPassos / 2);
  mp.step(-passos);
}

// ************ OUTRAS FUNÇÕES ************

void vaiEVolta() {
  mp.step(totalPassos);
  delay(1000);
  mp.step(-totalPassos);
  delay(1000);
}

void vaiPraFrenteVoltaUmPouquinho() {
  mp.step(200);
  delay(50);
  mp.step(-100);
  delay(50);
}

void praFrente() {
  mp.step(1);
}

void praTras() {
  mp.step(-1);
}
