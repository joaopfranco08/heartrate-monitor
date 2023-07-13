#include <stdio.h>
#include <wiringPi.h>
//#include <unistd.h>
//#include <math.h>

#define pino_PWM0 18

int main(){
        int dc = 8;
        int ciclos;
        
        int range = 128;

        printf("Iniciando... Usando divisor\n");

        wiringPiSetupGpio();
        pinMode(pino_PWM0, PWM_OUTPUT);

        pwmSetMode(PWM_MODE_MS);
        pwmSetRange(range);
        pwmSetClock(574); // frequencia = 261.1 Hz calculado no alarme

	pwmWrite(pino_PWM0, dc);
	usleep(300000);
        pwmWrite(pino_PWM0, 0);

        printf("Fim.\n");
        return 0;
}
