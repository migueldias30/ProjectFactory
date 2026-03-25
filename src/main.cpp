#include <Arduino.h>
#include <TFT_eSPI.h>

// put function declarations here:
TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  delay(50);
  Serial.println("startup");
  tft.init();
  Serial.println("tft.init done");
  tft.setRotation(1);        // 0..3, teste qual funciona melhor
  tft.fillScreen(TFT_WHITE); // fundo branco

  // Primeiro quadrado pequeno
  int x = 70, y = 70, size = 20;
  tft.fillRect(x, y, size, size, TFT_BLACK);

  // Deslocamento de pixels (diferença)
  int delta = 16;
  tft.drawRect(x + delta, y + delta, size, size, TFT_RED);

  // Texto inicial para confirmar
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("DIF PXL: 16");
}

void loop() {
  // Contador simples para mostrar vida do sketch
  tft.setTextColor(TFT_BLUE, TFT_WHITE); // background branco
  tft.setTextSize(2);
  tft.setCursor(10, 40);
  tft.printf("Segundos: %4u", millis() / 1000);
  delay(500);
}