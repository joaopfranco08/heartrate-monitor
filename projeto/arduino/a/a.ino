unsigned long start = 0, finish = 0;
float delta, bpm, deltaS, frequencia, cond, bpmMed, acum;
int flag = 0;
int SensorIn = 0, x = 1, i = 0;
int led_pin = 8, buzz_pin = 10, buzz_freq = 262, buzz_time = 400;

void setup(){
  Serial.begin(9600);
}

void loop() {
  SensorIn = analogRead(A0);
  
  cond = SensorIn * x;
  
  if(cond > 150 && flag ==0){
    start = millis();
    flag = 1;
    x = 0.01;
  }
  
  SensorIn = analogRead(A0);
  
  if(SensorIn < 890){
    x = 1;
  }
  
  cond = SensorIn*x;
  
  if (cond > 150 && flag == 1){
    finish = millis();
    flag = 0;
    delta = float(finish - start);
    frequencia = 1000/delta;
    
    bpm = frequencia *60;

    if(bpm > 60){
      Serial.print("Batimentos por minuto: ");
      Serial.println(bpmMed);
      
      if(bpm > 100){
        tone(buzz_pin, buzz_freq, 200);
      }
      
      acum = 0;
      i = 0;
    }
    digitalWrite(led_pin, HIGH);
  }
  else{
    digitalWrite(led_pin, LOW);
  }

}
