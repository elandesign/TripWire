#define SENSOR_PIN 2 // Needs to be a pin with an interrupt
#define SENSOR_INTERRUPT 1

#define LCD_DC 10
#define LCD_CS 18
#define LCD_RST 19
#define LCD_BACKLIGHT 20
#define LCD_TIMEOUT 1000

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Timer.h>

Timer timer;
Adafruit_PCD8544 display = Adafruit_PCD8544(LCD_DC, LCD_CS, LCD_RST);

int count = 0;

void dimDisplay()
{
  digitalWrite(LCD_BACKLIGHT, LOW);
}

void updateDisplay()
{
  display.clearDisplay();
  digitalWrite(LCD_BACKLIGHT, HIGH);
  display.setCursor(0,0);
  display.println(count);
  timer.after(LCD_TIMEOUT, dimDisplay);
}

void incrementCounter()
{
  count++;
  updateDisplay();
}

void setupDisplay()
{
  display.begin();
  display.setContrast(50);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.clearDisplay();
  updateDisplay();
}

void setup()
{
  pinMode(LCD_BACKLIGHT, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  setupDisplay();
  attachInterrupt(SENSOR_INTERRUPT, incrementCounter, RISING);
}

void loop()
{
  timer.update();
}
