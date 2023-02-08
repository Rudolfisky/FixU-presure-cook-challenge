
int datapPin = 3;
int data = 0;
int dataRoof = 200;
bool forward = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(datapPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(data >= dataRoof) forward = false;
  if(data <= 0) forward = true;
  if(forward){
    Serial.println("up");
    data++;
  }
  if(!forward) {
    Serial.println("down");
    data-=1;
  }
//  data = 0;
  analogWrite(datapPin, data);
  Serial.print("data: ");
  Serial.println(data);
  Serial.print("datapin: ");
  Serial.println();
  delay(25);
}
