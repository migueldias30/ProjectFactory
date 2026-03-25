#include <Arduino.h>
#include <TFT_eSPI.h>

// put function declarations here:
TFT_eSPI tft = TFT_eSPI();

void setup()
{
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1); // Adjust rotation if needed
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.println("Display WPSH412 funcionando!");
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0);
  tft.println("Texto atualizado");
  tft.println(millis() / 1000);
}