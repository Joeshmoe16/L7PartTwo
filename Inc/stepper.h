#ifndef stepper
#define stepper

#include "stm32f4xx.h"
#include "stdint.h"

#define BIT(x) (1<<(x)) 

//configurable, defines port and pins
#define PORT GPIOB
#define C1 5
#define C2 6
#define C3 7
#define C4 8

//Not configurable, used for GPIO Control
#define COILS_OFF (GPIOB -> ODR &= ~(BIT(C1) | BIT(C2) | BIT(C3) | BIT(C4)))

#define COIL1_ON (PORT -> ODR |= BIT(C1))
#define COIL2_ON (PORT -> ODR |= BIT(C2))
#define COIL3_ON (PORT -> ODR |= BIT(C3))
#define COIL4_ON (PORT -> ODR |= BIT(C4))

#define COIL1_OFF (PORT -> ODR &= ~BIT(C1))
#define COIL2_OFF (PORT -> ODR &= ~BIT(C2))
#define COIL3_OFF (PORT -> ODR &= ~BIT(C3))
#define COIL4_OFF (PORT -> ODR &= ~BIT(C4))


/// @brief Step motor with wave drive
void stepWave(char reset, char CounterC);

/// @brief Step motor with full step drive
void stepFull(char reset, char CounterC);

/// @brief Step motor with half step drive
void stepHalf(char reset, char CounterC);

#endif //end stepper