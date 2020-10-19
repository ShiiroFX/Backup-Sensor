int trigPin = 6;
int echoPin = 7;
int buzzerPin = 4;
int redLight = 11;
int greenLight = 10;
int blueLight = 9;

void setup() {
  Serial.begin(9600);
  // Setup the sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Setup the buzzer
  pinMode(buzzerPin, INPUT);
  // Setup the RGB LED
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(blueLight, OUTPUT);
}

void loop() {
  // Sensor loop
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/5) / 29.1;
  
  if(distance >= 20){
    RGBColor(0, 255, 0); // GREEN
  }
  else if(distance < 20 && distance >= 10){
    RGBColor(0, 0, 255); // BLUE
    tone(buzzerPin, 500);
  }
  else if(distance < 10){
    RGBColor(255, 0, 0); // RED
    tone(buzzerPin, 1500);
  }

  delay(250);
  RGBColor(0, 0, 0); // TURN OFF LED
  noTone(buzzerPin);
  delay(250);
}

// Method to set the color
void RGBColor(int redValue, int greenValue, int blueValue){
  analogWrite(redLight, redValue);
  analogWrite(greenLight, greenValue);
  analogWrite(blueLight, blueValue);
}
