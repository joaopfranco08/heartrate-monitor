const int pin = A0;

void setup() {
  Serial.begin(115200, SERIAL_8N1);
  
  delay(2000);

}

float notch_60hz(double volt){
  float f_notch = 60.0; // 60Hz notch frequency
  float fs = 200.0; // Sampling frequency (adjust this as needed)
  float Q = 10.0; // Quality factor for the notch filter

  float omega = 2.0 * PI * f_notch / fs;
  float alpha = sin(omega) / (2.0 * Q);
  float a0 = 1.0 + alpha;
  float a1 = -2.0 * cos(omega);
  float a2 = 1.0 - alpha;

  float prev_input = 0.0;
  float prev_output = 0.0;
  float prev_output1 = 0.0;

  float output = (volt - 2.0 * prev_input + prev_output1) * (a0 / a0);

  output += a1 / a0 * prev_output;
  output += a2 / a0 * prev_output1;

  prev_input = volt;
  prev_output1 = prev_output;
  prev_output = output;
  
  return output;
}

void loop(){
  int sensorVal = analogRead(pin);
  float volt = sensorVal*(100.0f/1023.0f);
  
  long sinal_filtrado = notch_60hz(volt); //doubletoLong
  
  float absorbancia = log10(5.0/sinal_filtrado);
  
  Serial.write(sinal_filtrado);
  
  //Serial.print(sinal_filtrado);
  //Serial.print("\n");
  
  delay(5);
}


