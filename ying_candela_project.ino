const int buttonPin = 2;
const int ledYellowPin_1 = 8;
const int ledYellowPin_2 = 10;
const int ledYellowPin_3 = 12;
const int ledGreenPin_1 = 9;
const int ledGreenPin_2 = 11;
const int ledGreenPin_3 = 13;

const int ledOn = HIGH;
const int ledOff = LOW;
int prime = 0;
unsigned long previousMillis = 0;
unsigned long standardInterval = 300;
unsigned long endInterval = 200;
int buttonState = 0;

void ledOnOff (int yellow, int green, unsigned long interval, int blinks){
  for (int i = 0; i < blinks; i++) {
    digitalWrite(yellow, ledOn); 
    delay(interval);
    digitalWrite(yellow, ledOff);
    delay(interval);
  }
  digitalWrite(green, ledOn);
}

void turnTotalOff (int yellow, int green, unsigned long interval, int blinks){
  digitalWrite(green, ledOff);

  for (int i = 0; i < blinks; i++) {
    digitalWrite(yellow, ledOn); 
    delay(interval);
    digitalWrite(yellow, ledOff);
    delay(interval);
  }
}
void buttonPressed (){
  buttonState = digitalRead(buttonPin);
 
  if(buttonState == HIGH ){
   if( digitalRead(ledGreenPin_1) == ledOff) {
      ledOnOff(ledYellowPin_1,ledGreenPin_1,standardInterval, 1);
  
      ledOnOff(ledYellowPin_2, ledGreenPin_2,standardInterval, 2);

      ledOnOff(ledYellowPin_3,ledGreenPin_3, standardInterval, 3);

   } else {
      turnTotalOff(ledYellowPin_3,ledGreenPin_3, endInterval, 1);
      turnTotalOff(ledYellowPin_2, ledGreenPin_2,endInterval, 2);
      turnTotalOff(ledYellowPin_1,ledGreenPin_1,endInterval, 3);
   }
  }
}
void setup() {
  // put your setup code here, to run once:
  // initialize the l
  pinMode(ledYellowPin_1, OUTPUT);
  pinMode(ledYellowPin_2, OUTPUT);
  pinMode(ledYellowPin_3, OUTPUT);
  pinMode(ledGreenPin_1, OUTPUT);
  pinMode(ledGreenPin_2, OUTPUT);
  pinMode(ledGreenPin_3, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

 buttonPressed ();
}
