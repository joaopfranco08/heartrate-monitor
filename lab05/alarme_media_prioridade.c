#include <stdio.h>
#include <wiringPi.h>
//#include <unistd.h>
//#include <math.h>

#define pino_PWM0 18

int main(){
	int dc = 64;
	int ciclos;
	float soundFrequency = 261.1; // Hz
	int range = 128;

	int divisor = ((19.2 * (1000000.0))/(soundFrequency*(float)range));

	printf("Iniciando... Usando divisor = %d\n",divisor);

	wiringPiSetupGpio();
	pinMode(pino_PWM0, PWM_OUTPUT);

	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(range);
	pwmSetClock(divisor);


	for(ciclos=0; ciclos < 3; ciclos++){
		pwmWrite(pino_PWM0, dc);
		usleep(300000);
		pwmWrite(pino_PWM0, 0);
		usleep(150000);
	}
        
	printf("Fim.\n");
	return 0;
}
