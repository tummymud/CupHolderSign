//Matrix libraries
#include <Adafruit_NeoMatrix.h>

//OLED libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Matrix
#define MATRIX_PIN 6
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, MATRIX_PIN, NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);
const int amber = matrix.Color(255, 128, 0);

//OLED SCL = Pin 2 & SDA = Pin 3
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Messages
const char* message1 = "THANK YOU! :)     THANK YOU! :)";
const char* message2 = "SORRY :(      SORRY :(";
const char* message3 = "NOT YOUR BEST WORK :(     NOT YOUR BEST WORK :(";
const char* message4 = "PLEASE MAINTAIN A SAFE DISTANCE      PLEASE MAINTAIN A SAFE DISTANCE";
const char* message5 = "WWW.BUGWORLD.ORG      WWW.BUGWORLD.ORG";

int message1Length = strlen(message1) * 6;
int message2Length = strlen(message2) * 6;
int message3Length = strlen(message3) * 6;
int message4Length = strlen(message4) * 6;
int message5Length = strlen(message5) * 6;

int pos1 = 32;
int pos2 = 32;
int pos3 = 32;
int pos4 = 32;
int pos5 = 32;


//Buttons
#define BUTTON_1 10
#define BUTTON_2 18
#define BUTTON_3 4
#define BUTTON_4 5
#define BUTTON_5 9


void setup() {
  
//Matrix
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(100);

//Button
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);

// OLED
  Serial.begin(115200);
  display.clearDisplay();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for (;;) // Don't proceed, loop forever
      ;
  }

  // Display welcome message
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.println("Welcome");
  display.display();
  delay(2000); // Change delay duration to adjust how long the welcome message is displayed
  display.clearDisplay();
  display.display();
}



void loop() {
  
if (digitalRead(BUTTON_3) == LOW) {
display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(3);
display.setTextColor(WHITE);
display.println("SAFE D");
display.display();



    matrix.clear();
    pos3 = 32;
    while (pos3 + message3Length >= 0) {
      matrix.clear();
      matrix.setCursor(pos3, 0);
      matrix.setTextColor(amber);
      matrix.println(message3);
      matrix.show();
      delay(15); // decrease the delay value to make the text scroll faster
      pos3--;
    }
matrix.clear();
delay(10);
display.clearDisplay();
display.display();

     }
if (digitalRead(BUTTON_1) == LOW) {
display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(3);
display.setTextColor(WHITE);
display.println("THANKS");
display.display();



    matrix.clear();
    pos1 = 32;
    while (pos1 + message1Length >= 0) {
      matrix.clear();
      matrix.setCursor(pos1, 0);
      matrix.setTextColor(amber);
      matrix.println(message1);
      matrix.show();
      delay(20); // decrease the delay value to make the text scroll faster
      pos1--;
    }
matrix.clear();
delay(10);
display.clearDisplay();
display.display();
     }
     
if (digitalRead(BUTTON_2) == LOW) {
display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(3);
display.setTextColor(WHITE);
display.println("SORRY:(");
display.display();



    matrix.clear();
    pos2 = 32;
    while (pos2 + message2Length >= 0) {
      matrix.clear();
      matrix.setCursor(pos2, 0);
      matrix.setTextColor(amber);
      matrix.println(message2);
      matrix.show();
      delay(20); // decrease the delay value to make the text scroll faster
      pos2--;
    }
matrix.clear();
delay(10);
display.clearDisplay();
display.display();
     }

if (digitalRead(BUTTON_4) == LOW) {
display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(3);
display.setTextColor(WHITE);
display.println("NOTBEST");
display.display();



    matrix.clear();
    pos4 = 32;
    while (pos4 + message4Length >= 0) {
      matrix.clear();
      matrix.setCursor(pos4, 0);
      matrix.setTextColor(amber);
      matrix.println(message4);
      matrix.show();
      delay(20); // decrease the delay value to make the text scroll faster
      pos4--;
    }
matrix.clear();
delay(10);
display.clearDisplay();
display.display();
     }

if (digitalRead(BUTTON_5) == LOW) {
display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(3);
display.setTextColor(WHITE);
display.println("BUG");
display.display();



    matrix.clear();
    pos5 = 32;
    while (pos5 + message5Length >= 0) {
      matrix.clear();
      matrix.setCursor(pos5, 0);
      matrix.setTextColor(amber);
      matrix.println(message5);
      matrix.show();
      delay(20); // decrease the delay value to make the text scroll faster
      pos5--;
    }
matrix.clear();
delay(10);
display.clearDisplay();
display.display();

     } 

}
    
