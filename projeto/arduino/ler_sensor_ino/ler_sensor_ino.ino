const int pin = A1;
//const int buzz_freq = 262;
//const int buzz_time = 400;

void setup() {
  Serial.begin(115200, SERIAL_8N1);
//  pinMode(10, OUTPUT);
  
  delay(2000);
}


void loop(){
  int sensorVal = analogRead(pin);
  long volt = sensorVal*(5.0f/1023.0f);
  
  Serial.write(volt);
  
  
  
  //Serial.print(sinal_filtrado);
  //Serial.print("\n");

//  buzzer de alarme
//  if (frequencia_cardiaca > 100){
//    tone(10, buzz_freq, buzz_time);
//  };
  
  delay(50);
}


