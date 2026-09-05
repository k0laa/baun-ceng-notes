/* Declaration of Global Variable for I2C 1 Peripheral */

#include "ornek_13_9.h"
#include "ornek_13_9_private.h"

/* I2C - Interrupt: <Root>/BUS I2C MASTER */
volatile uint16_T MCHP_I2C1_State = 0;
unsigned int volatile MCHP_I2C1_Request = 0;
volatile uint8_T I2C1_Buff8[1];
