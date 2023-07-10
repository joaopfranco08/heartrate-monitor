#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define pin_pwm 18

int main(){
	int dcyle, cycles;
	float soundFrequency = 261.1 // Hz

	
	wiringPiSetupGpio();
	pinMode(pin_pwm, soundFrequency);

	pwmSetMode(PWM_MODE_MS);
	pwmSetRange();
	pwmSetClock();

	
}
