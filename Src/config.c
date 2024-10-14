/*******************************************************************************
* Name:             Joseph Shotts
* Course:           EGR 326 Embedded System Design
* Project:          Lab7PartTwo
* File:             config.c
* Description:      Includes functions to initialize GPIO pins and systick.
********************************************************************************/

#include "config.h"

/***| setup() |*****************************//*
*Brief: 
*	Runs Setup Functions
*Params:
*            None
*Returns:
*           None
********************************************************/
void setup(void){
	gpio_setup();
	__disable_irq();
	SysTick_Init();
	__enable_irq();
}

/***| gpio_setup() |*****************************//*
*Brief: 
*	Initializes LEDs and Buttons
*Params:
*            None
*Returns:
*           None
********************************************************/
void gpio_setup(void)
{
	//Enable GPIO B
	RCC -> AHB1ENR |= BIT(1);

	//MODERx[0:1} (x is pins 5, 6, 7, 8)
	GPIOB -> MODER |= BIT(5*2);
	GPIOB -> MODER |= BIT(6*2);
	GPIOB -> MODER |= BIT(7*2);
	GPIOB -> MODER |= BIT(8*2);
	
}

/***| Systick_Init() |*****************************//*
*Brief: 
*	Initializes and resets Systick
*Params:
*            None
*Returns:
*           None
********************************************************/
void SysTick_Init (void)
{                                                    // initialization of SysTick timer
    SysTick -> CTRL     = 0;                         // disable SysTick during step
    SysTick -> LOAD     = 0xFFFFFF;                  // max reload value
    SysTick -> VAL      = 0;                         // any write to current clears it
    SysTick -> CTRL     = 0x0007;                    // enable SysTick, 16MHz, No Interrupts
}


/***| msDelay(uint16_t n) |*****************************//*
*Brief: msDelay Function, generates a delay using a for loop
*				the delays are not timed, eye balled for debouncing
*Params:
*           uint16_t n
*Returns:
*           None
********************************************************/
void SysTick_msdelay (uint32_t msdelay)                 // SysTick delay function
{
	SysTick -> LOAD = ((msdelay * 16000) - 1);          // delay for 1 ms* delay value
	SysTick -> VAL  = 0;                                // any write to CVR clears it

	while (!(SysTick -> CTRL  &  0x00010000));
	
}


/***|debounce(uint16_t delay) |*****************************//*
*Brief: 
*	Denounces the button: If button is on after ~10 cycles return true. 
* If button is off after ~10 cycles return false. 
* Works same as above, but does it explicitly.
*Params:
*          
*Returns:
*           True/False if button is on
********************************************************/
/*#define DEBOUNCE_LVL 10
unsigned char debounce(){
  static char     output = 0;
  static uint32_t  debounce = 0;
	
	char BTN = !(GPIOB->IDR & IDR8);
	
	if(!output){
		//debounced button input
		if(BTN){
			debounce += 1;
			if(debounce >= DEBOUNCE_LVL){
				output = 1;
				debounce = DEBOUNCE_LVL;
			}
		}
		else{
			debounce = 0;
			output = 0;
		}
	}
	else{
		if(!BTN)
		{
			debounce -= 1;
			if(debounce == 0){
				output = 0;
				debounce = DEBOUNCE_LVL;
			}
		}
		else{
			debounce = DEBOUNCE_LVL;
			output = 1;
		}
	}

  return output;
}*/