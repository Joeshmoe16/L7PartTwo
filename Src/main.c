#include "config.h"
#include "stepper.h"
#include "keypad.h"

void set_ms_per_step(int ms);

int main(void){
	setup();
	stdout_init();
	Keypad_Init();

	int timeDelay = 3;
	uint16_t num=0;                                     
	uint16_t *numptr=&num;  

	set_ms_per_step(10);

	stepHalf(1, 0);
	for(;;){
		Read_Keypad(numptr);
		stdout_putchar(num+48);
		stdout_putchar('\n');
		
		if(num==1){
			set_ms_per_step(150);
		}
		else if(num==2){
			set_ms_per_step(125);
		}
		else if(num==3){
			set_ms_per_step(100);
		}
		else if(num==4){
			set_ms_per_step(50);
		}
		else if(num==5){
			set_ms_per_step(25);
		}

	}
}

void SysTick_Handler (void)
{
	stepHalf(0, 0);
	stdout_putchar('T');
}

void set_ms_per_step(int ms){
	SysTick -> LOAD = 16000*ms; //set for ms systick interrupt
}