int flag = 0, SensorIn = 0, led_pin = 8, buzz_pin = 10, buzz_freq = 262, buzz_time = 100;



void setup(){
  Serial.begin(9600);
}

void loop() {
  SensorIn = analogRead(A0);
  Serial.write(SensorIn);
  
  if(SensorIn < 500){
    flag = 1;
    digitalWrite(led_pin, HIGH);
  }
  else if (flag == 1){
    digitalWrite(led_pin, LOW);
    tone(buzz_pin, buzz_freq, buzz_time);
  };
  
  delay(10);
}
