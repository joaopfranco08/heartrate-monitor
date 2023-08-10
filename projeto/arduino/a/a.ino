unsigned long start = 0, finish = 0;
float delta, bpm, deltaS, frequencia, cond,bpmMed, acum;
int flag = 0;
int SensorIn = 0, x = 1, i = 0;

void setup(){
  Serial.begin(9600);
}

void loop() {
  SensorIn = analogRead(A0);
  Serial.println(SensorIn);
  
  cond = SensorIn = x;
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
      acum = 0;
      i = 0;
    }
  }    
}
