#include <Wire.h>
#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pinos dos botões
const int botao1 = 9; // Área de espera. alarme com LCD, potenciômetro p/LCD, led efeito fade, e o buzzer na frequência 520HZ
const int botao2 = 8;  // Buzzer na frequência 520HZ, led vermelho no efeito fade 
const int botao3 = 7; // Buzzer normal e led verde com efeito fade.

// LEDs
const int ledSuave1 = 1;   // Para alarme com fade
const int ledVermelho = A5; // LED vermelho SEM fade (botão 2)
const int ledSuave3 = A2;  // LED verde com fade (botão 3)

// Buzzers
const int buzzer = 6;   // Para alarme (botão 1)
const int buzzer2 = A4; // Para botão 2
const int buzzer3 = A3; // Buzzer normal para botão 3

// Estados dos botões
bool ultimoEstadoBotao1 = HIGH;
bool ultimoEstadoBotao2 = HIGH;
bool ultimoEstadoBotao3 = HIGH;

bool alarmeAtivado = false;
bool led2Ativado = false;
bool led3Ativado = false;

// Controle de brilho dos LEDs com fade
int brilho1 = 0;
int passo1 = 5;

int brilho3 = 0;
int passo3 = 5;

void setup() {
  // Botões
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);

  // LEDs e buzzers
  pinMode(ledSuave1, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledSuave3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);

  noTone(buzzer);
  noTone(buzzer2);
  digitalWrite(buzzer3, LOW);
  digitalWrite(ledVermelho, LOW); // Garante desligado no início

  // LCD
  lcd.begin(16, 2);
  lcd.print("BEM-VINDO");
  lcd.setCursor(0, 1);
  lcd.print("SALA DE ESPERA");
}

void loop() {
  // Leitura dos botões
  bool estadoBotao1 = digitalRead(botao1);
  bool estadoBotao2 = digitalRead(botao2);
  bool estadoBotao3 = digitalRead(botao3);

  // Botão 1 - Alarme principal
  if (ultimoEstadoBotao1 == HIGH && estadoBotao1 == LOW) {
    alarmeAtivado = !alarmeAtivado;
    lcd.clear();

    if (alarmeAtivado) {
      lcd.print("ALERTA DE ");
      lcd.setCursor(0, 1);
      lcd.print("INCENDIO");
      tone(buzzer, 520);
    } else {
      lcd.print("ALARME DESATIVADO");
      noTone(buzzer);
      delay(2000);
      lcd.clear();
      analogWrite(ledSuave1, 0);
    }
  }
  ultimoEstadoBotao1 = estadoBotao1;

  // Botão 2 - LED vermelho imediato + buzzer 520Hz
  if (ultimoEstadoBotao2 == HIGH && estadoBotao2 == LOW) {
    led2Ativado = !led2Ativado;

    if (!led2Ativado) {
      digitalWrite(ledVermelho, LOW);
      noTone(buzzer2);
    }
  }
  ultimoEstadoBotao2 = estadoBotao2;

  // Botão 3 - LED verde com fade + buzzer normal
  if (ultimoEstadoBotao3 == HIGH && estadoBotao3 == LOW) {
    led3Ativado = !led3Ativado;

    if (!led3Ativado) {
      analogWrite(ledSuave3, 0);
      digitalWrite(buzzer3, LOW);
    }
  }
  ultimoEstadoBotao3 = estadoBotao3;

  // Efeito de fade no LED 1 (alarme)
  if (alarmeAtivado) {
    analogWrite(ledSuave1, brilho1);
    brilho1 += passo1;
    if (brilho1 <= 0 || brilho1 >= 255) {
      passo1 = -passo1;
    }
  }

  // LED vermelho SEM fade (liga/desliga direto) + buzzer2
  if (led2Ativado) {
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer2, 520);
  }

  // LED verde com fade + buzzer normal
  if (led3Ativado) {
    analogWrite(ledSuave3, brilho3);
    brilho3 += passo3;
    if (brilho3 <= 0 || brilho3 >= 255) {
      passo3 = -passo3;
    }
    digitalWrite(buzzer3, HIGH);
  }

  delay(50); // Menor delay para mais resposta nos cliques
}