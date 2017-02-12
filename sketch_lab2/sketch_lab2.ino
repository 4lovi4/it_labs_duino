
const int analogInPin = A0;
int sensorValue = 0;
int outputValue = 0;

// Определение изображения цифр 0 - 9 на индикаторе
// Данные массивы определены для подключения индикатора с общим катодом (контакт)
// В случае общего анода - все 1 меняются местами с 0
// 1 = LED вкл, 0 = LED выкл
//                    Arduino pin: 2,3,4,5,6,7,8
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
};                     //Сегменты: A,B,C,D,E,F,G  

void setup() 
{                
  for (int pin = 2; pin < 10; pin++) {
  pinMode(pin, OUTPUT);
  }  
  Serial.begin(9600);  // Может понадобиться для отладки
}
  
void writeDot(byte dot) 
{  
  digitalWrite(9, dot);
}
    
void sevenSegWrite(byte digit) 
{
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 9);
  sevenSegWrite((byte)outputValue); 
}

