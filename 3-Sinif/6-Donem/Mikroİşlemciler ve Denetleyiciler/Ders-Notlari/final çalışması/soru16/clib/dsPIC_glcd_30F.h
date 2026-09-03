// ------------ GLCD Functions Header -------------------
#ifndef GLCD_H
#define	GLCD_H

#include <MCHP_modelInclude.h>

/* Define Interface Pins */
/* Theses PORT must be defined as output */
/* Within the Simulink C Function Call block */

//Define Interface Pins
#define rst LATEbits.LATE0
#define cs1 LATEbits.LATE1
#define cs2 LATEbits.LATE2
#define di  LATEbits.LATE3
#define rw  LATEbits.LATE4
#define e   LATEbits.LATE5

#define port_glcd PORTB
#define tris_glcd TRISB

//#define D4 LATBbits.LATB4
//#define D5 LATBbits.LATB5
//#define D6 LATBbits.LATB6
//#define D7 LATBbits.LATB7

extern void ekrani_ac (void);
extern void ekrani_kapa (void);
extern void chip_sec (int chip);
extern void glcd_yaz (int chip, unsigned char veri);
extern unsigned char glcd_oku (unsigned char chip);
extern void glcd_hazirla (void);
extern void ekrana_yaz (int chip, int x, int y, unsigned char veri);

#endif