
int RPin = 3;
int GPin = 5;
int BPin = 6;

int RData = 0;
int GData = 0;
int BData = 0;

int state = 0; //0 = off 1 = red. 2 = to orange. 3 = to blue

int dataRoof = 200;

void setup() {
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  switch (state) {
  case 0:
    RData = 0;
    GData = 0;
    BData = 0;
    
    state = 1;
    break;
    
  case 1:
    RData = 200;
    GData = 0;
    BData = 0;
    
    state = 2;
    break;
    
  case 2:
    if(GData < 200){
      GData++;
    }
    else{
      state = 3;
    }
    break;
    
  case 3:
    if(BData < 200){
      RData--;
      GData--;
      BData++;
    }
    else{
      delay(1000);
      state = 0;
    }
    break;
    
  default:
    // statements
    break;
  }
  delay(50);
  RGB();
}

void RGB(){
  Serial.println("RGB data");
  Serial.println(RData);
  Serial.println(GData);
  Serial.println(BData);
  
  analogWrite(RPin, RData);
  analogWrite(GPin, GData);
  analogWrite(BPin, BData);
}
