#include "dsPIC_lcd.h"
#include <stdio.h>


void Lcd_Cmd(char a)
{
    EN = 0;
    RS = 0;

    D4 = (a & 1) >> 0;
    D5 = (a & 2) >> 1;
    D6 = (a & 4) >> 2;
    D7 = (a & 8) >> 3;

    EN = 1;
    __delay_us(1);

    EN = 0;
    __delay_us(1);
}


void Lcd_Init(void)
{
    EN = 0;
    RS = 0;

    D4 = 0;
    D5 = 0;
    D6 = 0;
    D7 = 0;

    /* New Raystar LCD init routine */

    __delay_ms(100);

    Lcd_Cmd(0b0011);
    __delay_ms(5);

    Lcd_Cmd(0b0011);
    __delay_us(100);

    Lcd_Cmd(0b0011);
    __delay_us(100);

    Lcd_Cmd(0b0010);
    __delay_us(100);

    Lcd_Cmd(0b0010);
    Lcd_Cmd(0b1000);
    __delay_us(60);

    Lcd_Cmd(0b0000);
    Lcd_Cmd(0b1000);
    __delay_us(60);

    Lcd_Cmd(0b0000);
    Lcd_Cmd(0b0001);
    __delay_ms(4);

    Lcd_Cmd(0b0000);
    Lcd_Cmd(0b0110);
    __delay_us(60);

    Lcd_Cmd(0b0000);
    Lcd_Cmd(0b1100);
    __delay_us(60);
}


void Lcd_Clear(void)
{
    Lcd_Cmd(0x0);
    Lcd_Cmd(0x1);
    __delay_us(2000);
}


void LCD_Return_Home(void)
{
    Lcd_Cmd(0x0);
    Lcd_Cmd(0x2);
    __delay_us(2000);
}


void Lcd_Shift_Right(void)
{
    Lcd_Cmd(0x01);
    Lcd_Cmd(0x0C);
    __delay_us(60);
}


void Lcd_Shift_Left(void)
{
    Lcd_Cmd(0x01);
    Lcd_Cmd(0x08);
    __delay_us(60);
}


void Lcd_Set_Cursor(char a, char b)
{
    char temp, z, y;

    if(a == 1)
    {
        temp = 0x80 + b - 1;

        z = temp >> 4;
        y = temp & 0x0F;

        Lcd_Cmd(z);
        Lcd_Cmd(y);

        __delay_us(60);
    }
    else if(a == 2)
    {
        temp = 0xC0 + b - 1;

        z = temp >> 4;
        y = temp & 0x0F;

        Lcd_Cmd(z);
        Lcd_Cmd(y);

        __delay_us(60);
    }
    else if(a == 3)
    {
        temp = 0x94 + b - 1;

        z = temp >> 4;
        y = temp & 0x0F;

        Lcd_Cmd(z);
        Lcd_Cmd(y);

        __delay_us(60);
    }
    else if(a == 4)
    {
        temp = 0xD4 + b - 1;

        z = temp >> 4;
        y = temp & 0x0F;

        Lcd_Cmd(z);
        Lcd_Cmd(y);

        __delay_us(60);
    }
}


void Lcd_Write_Char(char a)
{
    char temp;
    char y;

    temp = a & 0x0F;
    y = a & 0xF0;

    RS = 1;
    EN = 0;

    D4 = ((y >> 4) & 1) >> 0;
    D5 = ((y >> 4) & 2) >> 1;
    D6 = ((y >> 4) & 4) >> 2;
    D7 = ((y >> 4) & 8) >> 3;

    EN = 1;
    __delay_us(50);

    EN = 0;
    __delay_us(50);

    D4 = (temp & 1) >> 0;
    D5 = (temp & 2) >> 1;
    D6 = (temp & 4) >> 2;
    D7 = (temp & 8) >> 3;

    EN = 1;
    __delay_us(50);

    EN = 0;
    __delay_us(50);
}


void Lcd_Write_String(char *a)
{
    int i;

    for(i = 0; a[i] != '\0'; i++)
    {
        Lcd_Write_Char(a[i]);
    }
}

void LCD_StartUp(){
	
	unsigned int a;
	
	// TRISB &= ~(1 << 15);	// RS
	// TRISD &= ~(1 <<  4);	// EN
	
	// TRISE &= ~(1 <<  4);	// D4
	// TRISE &= ~(1 <<  5);	// D5
	// TRISE &= ~(1 <<  6);	// D6
	// TRISE &= ~(1 <<  7);	// D7
	
	Lcd_Init();				  
	Lcd_Clear();
	Lcd_Set_Cursor(1,1);
    Lcd_Write_String("TEST");

    Lcd_Set_Cursor(2,1);
    Lcd_Write_String("LCD CALISIYOR");
	
//	Lcd_Set_Cursor(1,1);
//	Lcd_Write_String("    LCD DEMO");
//	Lcd_Set_Cursor(2,1);
//	Lcd_Write_String(" Explorer 16/32");
//	__delay_ms(3000);
//	Lcd_Clear();
//    Lcd_Set_Cursor(1,1);
//	Lcd_Write_String("Press S4 button");
//	Lcd_Set_Cursor(2,1);
//	Lcd_Write_String("to switch mode");
//	__delay_ms(5000);
//    Lcd_Clear();
//    Lcd_Set_Cursor(1,1);
//	Lcd_Write_String("Move POT slider");
//	Lcd_Set_Cursor(2,1);
//	Lcd_Write_String("to inc. voltage");
//	__delay_ms(5000);

}

void PrintMinutes(unsigned int minutes){
    
    char buffer[17];
    sprintf(buffer, "Up time:%02u:", minutes);	
	Lcd_Set_Cursor(1,1);
	Lcd_Write_String(buffer);
}

void PrintSeconds(unsigned int seconds){
    
    char buffer[17];
    sprintf(buffer, "%02u   ", seconds);	
	Lcd_Set_Cursor(1,12);
	Lcd_Write_String(buffer);
}

void PrintVoltage(double v){
    
	char buffer[17];
    sprintf(buffer, "GERILIM:%.2f V   ", v);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(buffer);
}


void PrintCO(unsigned int ppm){
    
	char buffer[17];
    sprintf(buffer, "CO:%3u ppm   ", ppm);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}

void PrintTemperature(double temp){
    
	char buffer[17];
    sprintf(buffer, "SICAKLIK:%.2f\xDF%C   ", temp);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}


void PrintCPU(double CPU_Load){
    
	char buffer[17];
    sprintf(buffer, "%CPU load: %.2f%% ", CPU_Load);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(buffer);
}





void PrintDigital(unsigned int digi){
    
	char buffer[17];
    sprintf(buffer, "DIGITAL:%02u   ", digi);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}

void PrintKarakter(unsigned int karakter){
    
	char buffer[17];
    sprintf(buffer, "BASILAN TUS:%c   ", karakter);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}

void PrintSicaklik(unsigned int derece){
    
	char buffer[17];
    sprintf(buffer, "SICAKLIK:%.2u\xDF%C   ", derece);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}

void PrintNem(double nem){
    
	char buffer[17];
    sprintf(buffer, "NEM:%.2f %%RH   ", nem);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(buffer);
}

void PrintTus(unsigned int tus){
    
	char buffer[17];
    sprintf(buffer, "BASILAN TUS:%01u   ", tus);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}

void PrintT1(unsigned int T1){
    
	char buffer[17];
    sprintf(buffer, "T1:%.2u\xDF%C   ", T1);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}

void PrintT2(unsigned int T2){
    
	char buffer[17];
    sprintf(buffer, "T2:%.2u\xDF%C   ", T2);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(buffer);
}

void PrintV1(double v1){
    
	char buffer[17];
    sprintf(buffer, "V1:%.2f V   ", v1);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
}

void PrintV2(double v2){
    
	char buffer[17];
    sprintf(buffer, "V2:%.2f V   ", v2);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(buffer);
}

void PrintV3(double v3){
    
	char buffer[17];
    sprintf(buffer, "V3:%.2f V   ", v3);
    Lcd_Set_Cursor(3,1);
    Lcd_Write_String(buffer);
}

void PrintV4(double v4){
    
	char buffer[17];
    sprintf(buffer, "V4:%.2f V   ", v4);
    Lcd_Set_Cursor(4,1);
    Lcd_Write_String(buffer);
}

void PrintNem2(unsigned int nem2){
    
	char buffer[17];
    sprintf(buffer, "NEM:%.2u %%RH   ", nem2);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(buffer);
}