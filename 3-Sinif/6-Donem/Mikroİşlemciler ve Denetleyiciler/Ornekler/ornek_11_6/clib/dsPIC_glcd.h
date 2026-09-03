// ------------ GLCD Functions Header -------------------
#ifndef GLCD_H
#define	GLCD_H

#include <MCHP_modelInclude.h>

/* Define Interface Pins */
/* Theses PORT must be defined as output */
/* Within the Simulink C Function Call block */

//Define Interface Pins
#define rst LATBbits.LATB0
#define cs1 LATBbits.LATB1
#define cs2 LATBbits.LATB2
#define di  LATBbits.LATB3
#define rw  LATBbits.LATB4
#define e   LATBbits.LATB5

#define port_glcd PORTC
#define tris_glcd TRISC

extern void ekrani_ac (void);
extern void ekrani_kapa (void);
extern void chip_sec (int chip);
extern void glcd_yaz (int chip, unsigned char veri);
extern unsigned char glcd_oku (unsigned char chip);
extern void glcd_hazirla (void);
extern void ekrana_yaz (int chip, int x, int y, unsigned char veri);

#endif