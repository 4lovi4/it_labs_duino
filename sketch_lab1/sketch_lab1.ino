// Светодиод led1 мигает 1 раз с интервалом 5 сек
// Светодиод led2 мигает 3 раза за цикл мигания led1
const int led1 = 2,
          led2 = 3;
unsigned int deltat1, 
             deltat2;         
unsigned long t1 = 0, 
              t2 = 0,
              prevt1,
              prevt2;
int state1, state2;          

void blink_func(const int led,       //Функция мигания светодиодом без delay()
                int *state, 
                unsigned long *prevt,
                unsigned long t, 
                unsigned int delta
                )
{ 
    if (((t - *prevt) >= delta)) {
          switch(*state) {
          case LOW:
                  *state = HIGH;
                  break;
          case HIGH:
                  *state = LOW;
                  break;
          }
    digitalWrite(led, *state);
    *prevt = t;
    }
}
void setup() 
{
  Serial.begin(9600);
  state1 = HIGH;
  state2 = HIGH;
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, state1);
  digitalWrite(led2, state2);
  prevt1 = 0;
  prevt2 = 0;
  deltat1 = 5000;
  deltat2 = (deltat1) / 3; 
}

void loop() 
{
  t1 = millis();
  blink_func(led1, &state1, &prevt1, t1, deltat1);
  //Serial.print("state1 = "); // Для отладки
  //Serial.println(state1, DEC);
  t2 = millis();
  blink_func(led2, &state2, &prevt2, t2, deltat2);
}
