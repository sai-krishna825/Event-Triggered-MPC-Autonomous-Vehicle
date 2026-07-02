#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 
#include <SoftwareSerial.h> 
#define SCREEN_WIDTH 128  // OLED display width, in pixels 
#define SCREEN_HEIGHT 64  // OLED display height, in pixels 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins) 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 
const int trigPin = 15; 
const int echoPin = 14; 
#define IR 21 
#define motor1 17 
#define motor2 18 
#define motor3 19 
#define motor4 20 
#define Buzz 16 
//define sound velocity in cm/uS 
#define SOUND_VELOCITY 0.034 
#define CM_TO_INCH 0.393701 
long duration1; 
float distanceCm; 
float distanceInch; 
void setup() { 
Serial.begin(9600); 
pinMode(IR, INPUT); 
pinMode(echoPin, INPUT); 
pinMode(trigPin, OUTPUT); 
pinMode(Buzz, OUTPUT); 
pinMode(motor1, OUTPUT); 
pinMode(motor2, OUTPUT); 
pinMode(motor3, OUTPUT); 
pinMode(motor4, OUTPUT); 
delay(200); 
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3D for 
128x64 
Serial.println(F("SSD1306 allocation failed")); 
for (;;) 
; 
} 
delay(1000); 
display.clearDisplay(); 
display.setCursor(0, 0); 
display.setTextSize(1); 
display.setTextColor(WHITE); 
display.println("EVENT-TRIGGERED OUTPUT FEEDBACK MODEL PREDICTIVE 
CONTROL FOR PATH FOLLOWING OF AUTONOMOUS VEHICLES"); 
display.display(); 
digitalWrite(motor1, LOW); 
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW); 
digitalWrite(motor4, LOW);
 delay(500); 
} 
void loop() { 
  display.clearDisplay(); 
  delay(500); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  // Sets the trigPin on HIGH state for 10 micro seconds 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
 
  // Reads the echoPin, returns the sound wave travel time in 
microseconds 
  duration1 = pulseIn(echoPin, HIGH); 
 
  // Calculate the distance 
  distanceCm = duration1 * SOUND_VELOCITY / 2; 
 
  // Convert to inches 
  distanceInch = distanceCm * CM_TO_INCH; 
 
  display.setCursor(0, 0); 
  display.print("Distance "); 
  display.print(distanceInch); 
  display.display(); 
  Serial.print("Distance :"); 
  Serial.println(distanceInch); 
  if (distanceInch < 3) { 
    digitalWrite(Buzz, HIGH); 
    digitalWrite(motor1, LOW); 
    digitalWrite(motor2, LOW); 
    digitalWrite(motor3, LOW); 
    digitalWrite(motor4, LOW); 
    display.setCursor(0, 10); 
    display.println("OBSTACLE DETECTED"); 
    display.display(); 
    Serial.print("OBSTACLE DETECTED"); 
    delay(1000); 
    digitalWrite(Buzz, LOW); 
  } else { 
    digitalWrite(Buzz, LOW); 
    digitalWrite(motor1, HIGH); 
    digitalWrite(motor2, LOW); 
    digitalWrite(motor3, HIGH); 
    digitalWrite(motor4, LOW); 
    display.setCursor(0, 10); 
    display.println("FREE TO MOVE"); 
    display.display(); 
    Serial.print("FREE TO MOVE"); 
    delay(1000); 
  } 
  int IR_State = digitalRead(IR); 
  IR_State = digitalRead(IR); 
  display.setCursor(0, 20); 
  display.print("IR right:"); 
  display.print(IR_State); 
 display.display(); 
  Serial.print("IR right:"); 
  Serial.println(IR_State); 
  delay(1000); 
 
  if (IR_State == LOW) { 
    digitalWrite(Buzz, LOW); 
    digitalWrite(motor1, HIGH); 
    digitalWrite(motor2, LOW); 
    digitalWrite(motor3, HIGH); 
    digitalWrite(motor4, LOW); 
    display.setCursor(0, 30); 
    display.println("Path Detected"); 
    display.display(); 
    digitalWrite(Buzz, LOW); 
    delay(500); 
 
  } else { 
    digitalWrite(Buzz, HIGH); 
    digitalWrite(motor1, LOW); 
    digitalWrite(motor2, LOW); 
    digitalWrite(motor3, LOW); 
    digitalWrite(motor4, LOW); 
    display.setCursor(0, 30); 
    display.println("Path not Detected"); 
    display.display(); 
    delay(2000); 
  } 
} 
