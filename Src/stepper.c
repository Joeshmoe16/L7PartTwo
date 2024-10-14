/*******************************************************************************
* Name:             Joseph Shotts
* Course:           EGR 326 Embedded System Design
* Project:          Designed for 28BYJ-48 Stepper Control.
* File:             stepper.c
* Description:      Includes functions to initialize GPIO pins and systick.
********************************************************************************/

#include "stepper.h"

/***| stepWave() |***************************//*
*Brief: 
*	Steps the motor 1 step forward or backward with wave drive.
*Params:
*           reset: bool to reset stepper control
*           CounterC: bool to control direction, 1 is CC
*Returns:
*           None
**********************************************/
void stepWave(char reset, char CounterC){
	static char curStep = 0;

	if(reset){
        //reset function
		curStep = 0;
		COILS_OFF;
	}
	else{
        //incriment step
		if(CounterC==1){
			curStep++;
		}
		else{
			curStep--;
		}
		curStep %= 4;
	}

    //control coils based on step
	switch(curStep){
		case 0:{
			COILS_OFF;
			COIL1_ON;
			break;
		}
		case 1:{
			COILS_OFF;
			COIL2_ON;
			break;
		}
		case 2:{
			COILS_OFF;
			COIL3_ON;
			break;
		}
		case 3:{
			COILS_OFF;
			COIL4_ON;
			break;
		}
	}
}

/***| stepFull() |***************************//*
*Brief: 
*	Steps the motor 1 step forward or backward with 
*   full step drive.
*Params:
*           reset: bool to reset stepper control
*           CounterC: bool to control direction, 1 is CC
*Returns:
*           None
**********************************************/
void stepFull(char reset, char CounterC){
	static char curStep = 0;

	if(reset){
        //reset function
		curStep = 0;
		COILS_OFF;
	}
	else{
        //incriment step
		if(CounterC==1){
			curStep++;
		}
		else{
			curStep--;
		}
		curStep %= 4;
	}

    //control coils based on step
	switch(curStep){
		case 0:{
			COILS_OFF;
			COIL1_ON;
			COIL4_ON;
			break;
		}
		case 1:{
			COILS_OFF;
			COIL1_ON;
			COIL2_ON;
			break;
		}
		case 2:{
			COILS_OFF;
			COIL2_ON;
			COIL3_ON;
			break;
		}
		case 3:{
			COILS_OFF;
			COIL3_ON;
			COIL4_ON;
			break;
		}
	}
}

/***| stepHalf() |***************************//*
*Brief: 
*	Steps the motor 1 step forward or backward with 
*   half step drive.
*Params:
*           reset: bool to reset stepper control
*           CounterC: bool to control direction, 1 is CC
*Returns:
*           None
**********************************************/
void stepHalf(char reset, char CounterC){
	static char curStep = 0;

	if(reset){
        //reset function
		curStep = 0;
		COILS_OFF;
	}
	else{
        //incriment step
		if(CounterC==1){
			curStep++;
		}
		else{
			curStep--;
		}
		curStep %= 8;

		stdout_putchar (curStep+48);

	}

    //control coils based on step
	switch(curStep){
		case 0:{
			COILS_OFF;
			COIL1_ON;
			COIL4_ON;
			break;
		}
		case 1:{
			COILS_OFF;
			COIL1_ON;
			break;
		}
		case 2:{
			COILS_OFF;
			COIL1_ON;
			COIL2_ON;
			break;
		}
		case 3:{
			COILS_OFF;
			COIL2_ON;
			break;
		}
		case 4:{
			COILS_OFF;
			COIL2_ON;
			COIL3_ON;
			break;
		}
		case 5:{
			COILS_OFF;
			COIL3_ON;
			break;
		}
		case 6:{
			COILS_OFF;
			COIL3_ON;
			COIL4_ON;
			break;
		}
		case 7:{
			COILS_OFF;
			COIL4_ON;
			break;
		}
	}
}