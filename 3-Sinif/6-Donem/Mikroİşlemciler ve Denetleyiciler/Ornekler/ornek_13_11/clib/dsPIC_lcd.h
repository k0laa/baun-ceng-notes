#ifndef LCD_H
#define LCD_H

#include <MCHP_modelInclude.h>

/* LCD Interface Pins */

#define RS LATBbits.LATB1
#define EN LATBbits.LATB3

#define D4 LATBbits.LATB4
#define D5 LATBbits.LATB5
#define D6 LATBbits.LATB6
#define D7 LATBbits.LATB7

/* LCD Function Prototypes */

void Lcd_Cmd(char a);
void Lcd_Init(void);
void Lcd_Clear(void);
void LCD_Return_Home(void);
void Lcd_Shift_Right(void);
void Lcd_Shift_Left(void);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);

#endif