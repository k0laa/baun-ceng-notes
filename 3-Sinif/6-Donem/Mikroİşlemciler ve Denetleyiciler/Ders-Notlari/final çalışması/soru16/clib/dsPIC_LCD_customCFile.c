#include "dsPIC_lcd.h"


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

//void PrintVoltage(double v){
//    
//	char buffer[17];
//    sprintf(buffer, "GERILIM:%.2f V   ", v);
//    Lcd_Set_Cursor(2,1);
//    Lcd_Write_String(buffer);
//}

void PrintVoltage(double v){
    
	char buffer[17];
    sprintf(buffer, "GERILIM:%.2f V   ", v);
    Lcd_Set_Cursor(1,3);
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