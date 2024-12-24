#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// pin led dan buzzer
#define LED_RED 32
#define LED_GREEN 33
#define LED_YELLOW 25
#define BUZZER_1 26
#define BUZZER_2 27
#define BUZZER_3 14

int melody[] = {
  392, 392, 440, 392, 523, 494,
  392, 392, 440, 392, 587, 523,
  392, 392, 784, 659, 523, 494, 440,
  698, 698, 659, 523, 587, 523
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  ledcAttachPin(BUZZER_1, 0);
  ledcAttachPin(BUZZER_2, 1);
  ledcAttachPin(BUZZER_3, 2);
  ledcSetup(0, 1000, 8);
  ledcSetup(1, 1000, 8);
  ledcSetup(2, 1000, 8);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  String name = "[NAMA]";
  String umur = "YANG KE 25";

  display.setTextSize(2);  // 1 ukuran kecil 2 kuran besar
  int xPos1 = (SCREEN_WIDTH - 10 * 5 - 18) / 2;
  display.setCursor(xPos1, 0);
  display.println("HAPPY");
  
  int xPosH = (SCREEN_WIDTH - 10 * 8 - 18) / 2;
  display.setCursor(xPosH, 25);
  display.println("BIRTHDAY");
    
  display.setCursor(xPos1, 50);
  display.println(name);
  display.display();
  delay(5000);

  display.clearDisplay();

  display.setTextSize(2);  // 1 ukuran kecil 2 ukuran besar
  int xPos2 = (SCREEN_WIDTH - 10 * String(umur).length() - 18) / 2;
  display.setCursor(xPos2, SCREEN_HEIGHT / 2); 
  display.println(umur);
  display.display(); 
  delay(5000); 

  display.clearDisplay();
  drawBirthdayCake();
  display.display();  
}

void loop() {
  for (int thisNote = 0; thisNote < 25; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];

    // play nada pada buzzer
    ledcWriteTone(0, melody[thisNote]);  // BUZZER_1
    ledcWriteTone(1, melody[thisNote]);  // BUZZER_2
    ledcWriteTone(2, melody[thisNote]);  // BUZZER_3

    // on led bergantian
    digitalWrite(LED_RED, HIGH);
    delay(noteDuration / 2);
    digitalWrite(LED_RED, LOW);

    digitalWrite(LED_GREEN, HIGH);
    delay(noteDuration / 2);
    digitalWrite(LED_GREEN, LOW);

    digitalWrite(LED_YELLOW, HIGH);
    delay(noteDuration / 2);
    digitalWrite(LED_YELLOW, LOW);

    delay(50);
  }
  
  ledcWriteTone(0, 0);
  ledcWriteTone(1, 0);
  ledcWriteTone(2, 0);

}

// gambar kue ulang tahun
void drawBirthdayCake() {
  display.drawRect(20, 30, 88, 30, SSD1306_WHITE);  // Kue
  display.fillRect(25, 35, 78, 10, SSD1306_WHITE);  // Bagian atas kue
  display.fillRect(25, 40, 10, 10, SSD1306_WHITE);  // Lilin kiri
  display.fillRect(93, 40, 10, 10, SSD1306_WHITE);  // Lilin kanan
  display.drawLine(30, 30, 30, 20, SSD1306_WHITE);  // Api lilin kiri
  display.drawLine(100, 30, 100, 20, SSD1306_WHITE);  // Api lilin kanan
  display.fillCircle(30, 19, 3, SSD1306_WHITE);  // Api lilin kiri
  display.fillCircle(100, 19, 3, SSD1306_WHITE);  // Api lilin kanan
}
