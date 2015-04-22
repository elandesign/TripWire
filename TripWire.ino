#define SENSOR_PIN 2 // Needs to be a pin with an interrupt
#define SENSOR_INTERRUPT 1

#define LCD_DC A0
#define LCD_CE A1
#define LCD_RST 10
#define LCD_BL 20
#define LCD_TIMEOUT 3000

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Timer.h>

Timer timer;
Adafruit_PCD8544 display = Adafruit_PCD8544(LCD_DC, LCD_CE, LCD_RST);
int dimmer = -1;
int lastCount, count = 0;

void dimDisplay()
{
  digitalWrite(LCD_BL, LOW);
}

void updateDisplay()
{
  // If we're already lit, stop the current dim timeout
  if(dimmer >= 0)
    timer.stop(dimmer);

  display.clearDisplay();
  digitalWrite(LCD_BL, HIGH);
  display.setCursor(0,0);
  display.println(count);
  display.display();

  // Set a timeout to dim the LCD
  dimmer = timer.after(LCD_TIMEOUT, dimDisplay);
}

void incrementCounter()
{
  count++;
}

void setupDisplay()
{
  display.begin();
  display.setContrast(50);
  display.setTextSize(5);
  display.setTextColor(BLACK);
  display.clearDisplay();
  updateDisplay();
}

void setup()
{
  pinMode(LCD_BL, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  setupDisplay();
  attachInterrupt(SENSOR_INTERRUPT, incrementCounter, FALLING);
}

void loop()
{
  timer.update();

  if(lastCount != count)
  {
    // ISR has fired
    lastCount = count;
    updateDisplay();
  }
}
