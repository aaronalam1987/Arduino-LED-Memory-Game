#include <Adafruit_NeoPixel.h>

//Define our button and led pins, set up initial game difficulty.
const int buttonPin = 4;
const int ledPin = 5;
int difficulty = 3;

/*If start is 0, run initial cycle which is to show white for a moment, the new random color and then blank.
0 is then set to 1 and the game will cycle through random colors, correctColorNum is a randomly generated number
between 0 and difficulty, it is used as reference of when to show the correct, initial color.
correctColor is just incremented after each led cycle and is compared to correctColorNum, if its value is less, show random color otherwise show init(correct) color */

int start = 0;
int correctColor = 0;
int correctColorNum = 0;

//Initialise NeoPixel composing of a single LED and connected to our previously defined ledPin.
Adafruit_NeoPixel led = Adafruit_NeoPixel(1, ledPin, NEO_GRB + NEO_KHZ800);

//Define our NeoPixel Colors
const uint32_t white = Adafruit_NeoPixel::Color(255, 255, 255);
const uint32_t correctAnswer = Adafruit_NeoPixel::Color(0, 0, 255);
const uint32_t wrongAnswer = Adafruit_NeoPixel::Color(255, 0, 0);
uint32_t startColor;
uint32_t currColor;

unsigned long previousMillis = 0;
long speed = 1000;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  //randomSeed used to generate random color RGB values.
  randomSeed(analogRead(0));
  led.begin();
  led.setBrightness(20);
}

void checkPress(){
  if (correctColor == 0){
        //Correct color:
        //Display the correctAnswer color.
        led.fill(correctAnswer, 0, 1);
        //Decrease speed between led cycle with each correct press.
        speed -= 25;
        //Increase difficulty which increases the range of the correct color being displayed.
        difficulty < 16 ? difficulty += 2 : difficulty = difficulty;
        previousMillis = 0;

      }
      else{
        //Incorrect color:
        //Display wrongAnswer color.
        led.fill(wrongAnswer, 0, 1);
        //Reset speed to 1000(ms);
        speed = 1000;
        //Reset difficulty to 3.
        difficulty = 3;
      }
      //Display correct or wrong color, delay for 1000(ms) and set start to 0 which starts the next loop of colors based on previously set variables.
      led.show();
      delay(1000);
      //Reset game
      start = 0;
}

void cycleLED(){
  //CorrectColorNum is a randomly generated number between 0 and difficulty int.
      //correctColor is a variable we use to increment, if it less than CorrectColorNum, show a random color.
      if(correctColor < correctColorNum){
        led.fill(currColor, 0, 1);
        led.show();
        correctColor++;
      }
      else{
        //This would be displaying the "startColor" which is the color initially displayed and the color that the player is attempting to identify.
        //Assign correctColor to 0 as this is the startColor and we can use this to compare button press.
        led.fill(startColor, 0, 1);
        led.show();
        correctColor = 0;
        }
    
}

void gameInit(){
  startColor = Adafruit_NeoPixel::Color(random(0, 255), random(0, 255), random(0, 255));
  led.fill(white, 0, 1);
  led.show();
  delay(1000);
  led.fill(startColor, 0, 1);
  led.show();
  delay(2000);
  led.clear();
  led.show();
  delay(500);
  //Random color starts.
  correctColorNum = random(0, difficulty);
  start = 1;
}


void loop() {
  //Assign current milliseconds
  unsigned long currentMillis = millis();

  //Generate a random color
  currColor = Adafruit_NeoPixel::Color(random(0, 255), random(0, 255), random(0, 255));

  //Read button pin
  int button = digitalRead(buttonPin);

  //Button pressed, check if its the right color
  if(button == LOW){
    checkPress();
  }
  
  if(start == 0){
    //Game init, assign the start color, fill with white, then start color, then blank, set game to start.
    gameInit();
  }
    else{
      //If duration has passed, cycle led color.
      if(currentMillis - previousMillis >= speed){
        previousMillis = currentMillis;
        cycleLED();
    }
  }
}


