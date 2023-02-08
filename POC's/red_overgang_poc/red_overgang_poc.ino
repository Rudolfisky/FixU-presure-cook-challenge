
int ledPin = 3;
int led = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(led > 0){
    led--;
    delay(10);
  }
  else{
    resetRed(); //remove this
  }
  analogWrite(ledPin, led);
  Serial.print("data: ");
  Serial.println(led);
}

// used to reset back to 0
void resetRed(){
  delay(1000);
  led = 150;
}
