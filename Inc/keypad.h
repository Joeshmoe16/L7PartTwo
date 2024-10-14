#include "stm32f4xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef KEYPAD_H_
#define KEYPAD_H_
#define BIT(x)  ((uint32_t) (1<<x))
#define SHIFT(x,y)((uint32_t) (y<<x))

#define C	 (uint32_t) 2													  // Port C
#define R0 (uint32_t) 1														// Row bits 0
#define R1 (uint32_t) 0														// Row bits 1
#define R2 (uint32_t) 2														// Row bits 2
#define R3 (uint32_t) 3														// Row bits 3
#define C0 (uint32_t) 4														// Col bits 0
#define C1 (uint32_t) 5														// Col bits 1
#define C2 (uint32_t) 6														// Col bits 2

//uint8_t Hex2Bit (uint32_t hex_num);
void Keypad_Init (void);                                // Initialize Functions
void Print_Keys (uint16_t *numptr);                     // Print Keypress
void Print_Keys2 (uint16_t *numptr);
uint8_t Read_Keypad(uint16_t *numptr);                  // Keypad scan subroutine
uint16_t get2Pin(void);

#endif /* KEYPAD_H_ */