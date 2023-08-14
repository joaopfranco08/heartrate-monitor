unsigned long start = 0, finish = 0;
float delta, bpm, deltaS, frequencia, cond, bpmMed, acum;
int flag = 0;
int SensorIn = 0, x = 1, i = 0;
int led_pin = 8, buzz_pin = 10, buzz_freq = 262, buzz_time = 400;
int ciclos, picos, tempo_anterior, tempo_atual, tempo_final, tempo_total, max_leituras = 150;
int leituras[250];


void setup(){
  Serial.begin(9600);
}

void loop() {
  SensorIn = analogRead(A0);
  Serial.write(SensorIn);
  int tensao = 0;
  i = 0;
  picos = 0;
  ciclos = 0;
  tempo_anterior = millis();
  
  if(SensorIn < 300){
    for(int i = 0; i<250; i++){
      tensao = SensorIn*5/1023;
      tempo_atual = millis();
      if(SensorIn > 500){
        picos++;
      }
      else if(SensorIn <= 300 && picos > 0){
        ciclos++;
        picos = 0;
      }
    };
  };
  tempo_final = millis();
  tempo_total = tempo_final - tempo_anterior;
  
  int batidas = ciclos/2;

  tempo_total = tempo_total/60000;
  int bpm = batidas/tempo_total;
  if (bpm < 40){
    tone(buzz_pin, buzz_freq, 200);
  };
  delay(50);
}
