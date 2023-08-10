#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define pino_pwm 18

int main(){
	int dcycle, ciclos;
	wiringPiSetup();
	pinMode(pino_pwm, PWM_OUTPUT);

	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(128);
	pwmSetClock(15);

	for (ciclos = 0; ciclos < 9; ciclos ++) {
		for  (dcycle = 0; dcycle < 128; dcycle ++){
			pwmWrite(pino_pwm, dcycle);
			usleep(10000);
		}
	}
	return 0;

}
