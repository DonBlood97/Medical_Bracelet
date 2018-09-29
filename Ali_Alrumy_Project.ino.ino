class BoxM{
  const int buzer = 6, vPins[4] = {2,3,4,5};  
  int ledR, ledG, ledB;

  public:
  void pins(int ledR, int ledG, int ledB){

    this->ledR = ledR;
    this->ledG = ledG;
    this->ledB = ledB;
    
    int led[3] = {ledR,ledG,ledB};

    for(int i=0;i<3;i++)
      pinMode(led[i], OUTPUT);
    for(int i=0; i<4; i++)
      pinMode(vPins[i],OUTPUT);
    pinMode(buzer, OUTPUT);
  
  }
  void On(String Led){
    // Led Section
    int led[3] = {ledR,ledG,ledB};
    if(Led == "Red")
      digitalWrite(ledR,HIGH);
    else if(Led == "Green")
      digitalWrite(ledG,HIGH);
    else if(Led == "Blue")
      digitalWrite(ledB,HIGH);
    else{
      for(int i=0; i<3; i++)
        digitalWrite(led[i],HIGH); 
    }

    // V
    for(int i=0; i<4; i++)
      digitalWrite(vPins[i],HIGH);
    
    // Buzer
    digitalWrite(buzer,HIGH);
    delay(2000);
    digitalWrite(buzer,LOW);
  }

  void Off(){
    int led[3] = {ledR,ledG,ledB};
    for(int i=0; i<3; i++)
        digitalWrite(led[i],LOW);
    for(int i=0; i<4; i++)
        digitalWrite(vPins[i],LOW); 
  }
};
void delayTime(int hour, int minutes = 0, int second = 0){
  int Hour =  60 * 1000 * 60, Minutes = 60 * 1000, Second = 1000;
  int total = ( hour * Hour ) + ( minutes * Minutes ) + ( second * Second );
  delay( total );
}

BoxM Box1,Box2,Box3,Box4,Box5; 

void setup() {

  Box1.pins(7,A3,12);
  Box2.pins(8,A4,13);
  Box3.pins(9,A5,A0);
  Box4.pins(10,A6,A1);
  Box5.pins(11,A7,A2);

}

void loop() {

  Box1.On("Red");
  delayTime(0,0,3);
  Box1.Off();
  delayTime(0,0,1);

  Box2.On("Green");
  delayTime(0,0,3);
  Box2.Off();
  delayTime(0,0,1);

  Box3.On("Blue");
  delayTime(0,0,3);
  Box3.Off();
  delayTime(0,0,1);
  
  Box4.On("W");
  delayTime(0,0,3);
  Box4.Off();
  delayTime(0,0,1);
  
  Box5.On("Red");
  delayTime(0,0,3);
  Box5.Off();
  delayTime(0,0,1);

}
