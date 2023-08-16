unsigned long start = 0, finish = 0;
float delta, deltaS, frequencia, cond, bpmMed, acum;
int bpm;
int flag = 0;
int SensorIn = 0, x = 1, i = 0;

const int buzzer = 10;
int alerta = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
const long interval = 500;  // Buzzer on-off interval in milliseconds
int acum_old;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);  // set arduino pin to output mode
  pinMode(7, OUTPUT);
}

void ativarAlerta() {
  digitalWrite(buzzer, HIGH);
  digitalWrite(buzzer, LOW);
  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  SensorIn = analogRead(A0);
  //Serial.println(SensorIn);

  cond = SensorIn * x;
  if (cond > 990 && flag == 0) {
    start = millis();
    flag = 1;
    //Serial.print("Time ");
    //Serial.println(start);
    x = 0.01;
  }

  SensorIn = analogRead(A0);

  if (SensorIn < 989) {
    x = 1;
  }

  cond = SensorIn * x;

  if (cond > 990 && flag == 1) {
    finish = millis();
    flag = 0;
    //Serial.print("Time2 ");
    //Serial.println(finish);

    delta = float(finish - start);
    frequencia = 1000 / delta;
    //Serial.print("freq");
    //Serial.println(frequencia);

    bpm = frequencia * 60;
    Serial.println(bpm);
    if (bpm > 60 && bpm <= 150) {
      //Serial.write(bpm);
      //delay(500);
      acum = acum + bpm;
      i++;
      x = 0.01;
    } else {
      //Serial.println(bpm);
      acum = acum + bpm;
      i++;
      x = 0.01;
    }
  }
  if (i >= 5) {
    bpmMed = acum / 5;
    //Serial.print("Batimentos por minuto: ");
    //Serial.println(bpmMed);
    acum = 0;
    i = 0;
  }

  if (bpmMed > 120) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;  // Save the last time the buzzer was toggled
      if (digitalRead(buzzer) == LOW) {
        digitalWrite(7, HIGH);
        digitalWrite(buzzer, HIGH);
      } else {
        digitalWrite(buzzer, LOW);
        digitalWrite(7, LOW);
      }
      acum = 0;
      //bpmMed = bpm/(currentMillis - previousMillis);
      if (bpm > 150) {
        bpm = bpm / currentMillis * 60;
        bpmMed = acum + bpm;
        //Serial.println(bpmMed);
      } else if (isinf(bpmMed)) {
        bpmMed = 120;
      }
    }
  } else {
    digitalWrite(buzzer, LOW);  // Turn off the buzzer when alerta is 0
    digitalWrite(7, LOW);
  }
  delay(50);
}
