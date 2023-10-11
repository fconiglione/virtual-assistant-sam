// Francesco Coniglione
// December 15, 2022
// Final Project: Virtual Assistant Sam

/*************************************************
* Public Constants For Piezo
*************************************************/
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
int buzzerPin = 6 ; //The buzzerPin is connected to pin 6 of the Arduino.
int songA[] = {
  NOTE_C1, NOTE_C1, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5,
  NOTE_F4, NOTE_F4, NOTE_E3, NOTE_E3, NOTE_D2, NOTE_D2, NOTE_C1
};
int songB[] = { // song 2 array
  NOTE_B1, NOTE_F1, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_E5, NOTE_G5,
  NOTE_A4, NOTE_F4, NOTE_E3, NOTE_A3, NOTE_D2, NOTE_D2, NOTE_D1
};
int songC[] = { // song 3 array
  NOTE_D1, NOTE_D1, NOTE_A5, NOTE_E5, NOTE_A5, NOTE_DS8, NOTE_G5,
  NOTE_B7, NOTE_D4, NOTE_E3, NOTE_A3, NOTE_D2, NOTE_D2, NOTE_D1
};
int length[] = { // Length array for each song and note
  108, 408, 208, 408, 508, 408, 408, 308, 208, 408, 408, 708, 408, 408
};

#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd( 12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.

// Declaring the LED variables
int RedLED = 7;
int BlueLED = 13;
int GreenLED = 8;
int WhiteLED = 9;


// For responses
int response = 0;

void setup()
{
  // Setting everything up, especially serial monitor declaration
  pinMode(buzzerPin, OUTPUT);
  lcd.begin (16,2); //Initialize the LCD.
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(WhiteLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Initial introduction phase
  if(response == 0){ // Default response == 0
  Serial.println("Hello, I am Sam - your virtual assistant.");
  Serial.println(" ");
  Serial.println("How can I help you today?");
  Serial.println(" ");
  Serial.println("Tip: For a list of commands, input '0'");
  Serial.println(" ");
  }
  while (Serial.available() == 0) { // Empty while loop to await response
  }
  response = Serial.read();
  if(response == 48){ // Help menu function
    Serial.println("Help Menu");
    Serial.println("------------------------------");
    Serial.println("'0' - Help Menu");
    Serial.println("'1' - Turn On Red LED");
    Serial.println("'2' - Turn On Blue LED");
    Serial.println("'3' - Turn On Green LED");
    Serial.println("'4' - Turn On White LED");
    Serial.println("'5' - Turn Off LEDs");
    Serial.println("'6' - Play Song A");
    Serial.println("'7' - Play Song B");
    Serial.println("'8' - Play Song C");
    Serial.println("'9' - Stop Song");
    Serial.println("'a' - Display Animation");
    Serial.println("'l' - Display Light Show");
    Serial.println("'j' - Display Joke");
    Serial.println("'q' - Display Quote");
  }
  if(response == 49){ // Turn on Red LED function
    digitalWrite(RedLED,HIGH);
	delay(100);
  }
  if(response == 50){ // Turn on Blue LED function
    digitalWrite(BlueLED,HIGH); 
	delay(100);
  }
  if(response == 51){ // Turn on Green LED function
    digitalWrite(GreenLED,HIGH);
	delay(100);
  }
  if(response == 52){ // Turn on White LED function
    digitalWrite(WhiteLED,HIGH);
	delay(100);
  }
  if(response == 53){ // Turn off all/any LEDs function
  	digitalWrite(RedLED,LOW);
    delay(100);
    digitalWrite(BlueLED,LOW);
    delay(100);
    digitalWrite(GreenLED,LOW);
    delay(100);
    digitalWrite(WhiteLED,LOW);
  }
  if(response == 54){
    songONE(); // plays the songONE function
  }
  if(response == 55){
    songTWO(); // plays the songTWO function
  }
  if(response == 56){
    songTHREE(); // plays the songTHREE function
  }
  if(response == 57){ // Turns off the Piezo function for any song
    noTone(6);
    // Controlling the buzzer. Circuitar. (2018). Retrieved November 29, 2022, from https://www.circuitar.com/projects/controlling-the-buzzer/index.html 
  }
  if(response == 97){ // Animation function
    frame01(); // Calling the frame function
    delay(250); // Delays between each frame
    frame02(); // Calling the frame function
    delay(250); // Delays between each frame
    frame03(); // Calling the frame function
    delay(250); // Delays between each frame
    frame04(); // Calling the frame function
    delay(250); // Delays between each frame
    frame05(); // Calling the frame function
    delay(250); // Delays between each frame
    frame06(); // Calling the frame function
    delay(250); // Delays between each frame
    frame07(); // Calling the frame function
    delay(250); // Delays between each frame
    frame08(); // Calling the frame function
    delay(250); // Delays between each frame
    frame09(); // Calling the frame function
    delay(250); // Delays between each frame
    // Create custom animations on 16x2 LCD displays. Arduino Project Hub. (n.d.). Retrieved December 1, 2022, from https://create.arduino.cc/projecthub/tusindfryd/create-custom-animations-on-16x2-lcd-displays-025fb6?ref=tag&amp;ref_id=lcd&amp;offset=3 
  }
  if(response == 108){ // Light show function
    for(int i = 0; i<= 4; i++){ // For loop to repeat the initial sequence 4 times
      digitalWrite(RedLED,HIGH);
      delay(200);
      digitalWrite(RedLED,LOW);
      digitalWrite(BlueLED,HIGH);
      delay(200);
      digitalWrite(BlueLED,LOW);
      digitalWrite(GreenLED,HIGH);
      delay(200);
      digitalWrite(GreenLED,LOW);
      digitalWrite(WhiteLED,HIGH);
      delay(200);
      digitalWrite(WhiteLED,LOW);
      delay(500);
    }
  }
  if(response == 106){ // Joke function
    lcd.clear();
	lcd.setCursor(0,0); //go to first column and first line (0,0)
	lcd.print("Why did the Oreo"); //Print at cursor Location
	lcd.setCursor(0,1); //go to first column and second line
	lcd.print("go to a Dentist?"); //Print at cursor Location
  	delay(5000); // Delay to allow time to read
    lcd.clear();
	lcd.setCursor(0,0); //go to first column and first line (0,0)
	lcd.print("Because he lost"); //Print at cursor Location
	lcd.setCursor(0,1); //go to first column and second line
	lcd.print("his filling!"); //Print at cursor Location
    delay(5000); // Delay to allow time to read
    lcd.clear();
  }
    if(response == 113){ // Quote function
    lcd.clear();
	lcd.setCursor(0,0); //go to first column and first line (0,0)
	lcd.print("All limitations"); //Print at cursor Location
	lcd.setCursor(0,1); //go to first column and second line
	lcd.print("are self-imposed."); //Print at cursor Location
  	delay(5000); // Delay to allow time to read
    lcd.clear();
	lcd.setCursor(0,0); //go to first column and first line (0,0)
	lcd.print("- Oliver Wendell"); //Print at cursor Location
	lcd.setCursor(0,1); //go to first column and second line
	lcd.print("Holmes"); //Print at cursor Location
    delay(5000); // Delay to allow time to read
    lcd.clear();
  }
}

// The next 9 functions are used/called for the animation

void frame01() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11100};
  byte image19[8] = {B11100, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B00000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B00000};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
}

void frame02() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11100};
  byte image19[8] = {B11100, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B00000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B00000};
  byte image31[8] = {B11111, B01110, B00100, B00000, B00000, B00000, B00000, B00000};
  byte image15[8] = {B00000, B00000, B00000, B00000, B00000, B00100, B01110, B11111};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);
  lcd.createChar(6, image31);
  lcd.createChar(7, image15);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(14, 1);
  lcd.write(byte(6));
  lcd.setCursor(14, 0);
  lcd.write(byte(7));
}

void frame03() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11100};
  byte image19[8] = {B11100, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B00000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B00000};
  byte image29[8] = {B11111, B01110, B00100, B00000, B00000, B00000, B00000, B00000};
  byte image13[8] = {B00000, B00000, B00000, B00000, B00000, B00100, B01110, B11111};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);
  lcd.createChar(6, image29);
  lcd.createChar(7, image13);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(12, 1);
  lcd.write(byte(6));
  lcd.setCursor(12, 0);
  lcd.write(byte(7));
}

void frame04() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11100};
  byte image19[8] = {B11100, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B00000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B00000};
  byte image27[8] = {B11111, B01110, B00100, B00000, B00000, B00000, B00000, B00000};
  byte image11[8] = {B00000, B00000, B00000, B00000, B00000, B00100, B01110, B11111};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);
  lcd.createChar(6, image27);
  lcd.createChar(7, image11);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(10, 1);
  lcd.write(byte(6));
  lcd.setCursor(10, 0);
  lcd.write(byte(7));
}

void frame05() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11100};
  byte image19[8] = {B11100, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B00000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B00000};
  byte image25[8] = {B11111, B01110, B00100, B00000, B00000, B00000, B00000, B00000};
  byte image09[8] = {B00000, B00000, B00000, B00000, B00000, B00100, B01110, B11111};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);
  lcd.createChar(6, image25);
  lcd.createChar(7, image09);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
  lcd.setCursor(8, 0);
  lcd.write(byte(7));
}

void frame06() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11100};
  byte image19[8] = {B11100, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B00000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B00000};
  byte image23[8] = {B11111, B01110, B00100, B00000, B00000, B00000, B00000, B00000};
  byte image07[8] = {B00000, B00000, B00000, B00000, B00000, B00100, B01110, B11111};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);
  lcd.createChar(6, image23);
  lcd.createChar(7, image07);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(6, 1);
  lcd.write(byte(6));
  lcd.setCursor(6, 0);
  lcd.write(byte(7));
}

void frame07() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11100};
  byte image19[8] = {B11100, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B00000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B00000};
  byte image05[8] = {B00000, B00000, B00000, B00000, B00000, B00100, B01110, B11111};
  byte image21[8] = {B11111, B01110, B00100, B00000, B00000, B00000, B00000, B00000};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);
  lcd.createChar(6, image05);
  lcd.createChar(7, image21);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(4, 0);
  lcd.write(byte(6));
  lcd.setCursor(4, 1);
  lcd.write(byte(7));
}

void frame08() {
  lcd.clear();

  byte image02[8] = {B00001, B00011, B00110, B01100, B11000, B10000, B10000, B10000};
  byte image18[8] = {B10000, B10000, B10000, B11000, B01100, B00110, B00011, B00001};
  byte image03[8] = {B11111, B00001, B00000, B01100, B01100, B00000, B00111, B11111};
  byte image19[8] = {B11111, B00111, B00000, B00000, B00000, B00000, B00001, B11111};
  byte image20[8] = {B11000, B11000, B01100, B01100, B01100, B11000, B10000, B00000};
  byte image04[8] = {B00000, B10000, B11000, B01100, B00100, B01100, B11000, B11000};

  lcd.createChar(0, image02);
  lcd.createChar(1, image18);
  lcd.createChar(2, image03);
  lcd.createChar(3, image19);
  lcd.createChar(4, image20);
  lcd.createChar(5, image04);

  lcd.setCursor(1, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 0);
  lcd.write(byte(2));
  lcd.setCursor(2, 1);
  lcd.write(byte(3));
  lcd.setCursor(3, 1);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
}

void frame09() {
  lcd.clear();

  byte image18[8] = {B00000, B00000, B00000, B00000, B00000, B00001, B00011, B01111};
  byte image19[8] = {B00001, B10000, B01000, B00100, B00000, B11111, B11111, B11111};
  byte image20[8] = {B00000, B00000, B01000, B00000, B00000, B10000, B11000, B11100};
  byte image02[8] = {B00000, B00010, B00000, B01010, B10000, B00000, B00100, B00001};
  byte image03[8] = {B00000, B10000, B00000, B00100, B00000, B00000, B00100, B00000};
  byte image04[8] = {B00000, B00010, B00000, B10000, B00100, B00000, B00000, B01000};

  lcd.createChar(0, image18);
  lcd.createChar(1, image19);
  lcd.createChar(2, image20);
  lcd.createChar(3, image02);
  lcd.createChar(4, image03);
  lcd.createChar(5, image04);

  lcd.setCursor(1, 1);
  lcd.write(byte(0));
  lcd.setCursor(2, 1);
  lcd.write(byte(1));
  lcd.setCursor(3, 1);
  lcd.write(byte(2));
  lcd.setCursor(1, 0);
  lcd.write(byte(3));
  lcd.setCursor(2, 0);
  lcd.write(byte(4));
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
}

void songONE(){ // function for song A
  
  for(int i = 0; i < 14; i++){ // for loop for 14 notes
    tone(buzzerPin, songA[i], length[i]); // tone
    delay(length[i]); //delay
	}
}

void songTWO(){ // function for second song
  
  for(int j = 0; j < 14; j++){ // for loop for 14 notes
    tone(buzzerPin, songB[j], length[j]); // tone
    delay(length[j]); // delay
  }
}
  
void songTHREE(){ // function for third song
  
  for(int k = 0; k < 14; k++){ // for loop for 14 notes
    tone(buzzerPin, songC[k], length[k]); // tone
    delay(length[k]); //delay
  }
}

// End of code and thus the project