#include "dsPIC_glcd.h"

void ekrani_ac (void)
{
    e = 1;
    di = 0;
    rw = 0;
    port_glcd = 0X3F;
    chip_sec(1);
    __delay_us(40);
    chip_sec(2);
    __delay_us(40);
    e = 0;
}

void ekrani_kapa (void)
{
    e = 1;
    di = 0;
    rw = 0;
    port_glcd = 0X3E;
    chip_sec(1);
    __delay_us(40);
    chip_sec(2);
    __delay_us(40);
    e = 0;
}

void chip_sec (int chip)
{
    e = 1;
    if (chip == 0) {cs1 = 0; cs2 = 0;};
    if (chip == 1) {cs1 = 1; cs2 = 0;};
    if (chip == 2) {cs1 = 0; cs2 = 1;};
    e = 0;
}

void glcd_yaz (int chip, unsigned char veri)
{
    chip_sec (chip);
    rw = 0;
    port_glcd = veri;
    __delay_us(10);
    e = 1;
    __delay_us(10);
    e = 0;
    chip_sec(0);
}

unsigned char glcd_oku (unsigned char chip)
{
    unsigned char veri;
    tris_glcd = 255;
    rw = 1;
    chip_sec (chip);
    __delay_us(10);
    e = 1;
    __delay_us(10);
    veri = port_glcd;
    e = 0;
    tris_glcd = 0;
    chip_sec (0);
    return(veri);
}

void glcd_hazirla (void)
{
    e = 1;
    tris_glcd = 0;
    rst = 1;
    e = 0;
    chip_sec(0);
    di = 0;
    glcd_yaz(1,0XC0);
    glcd_yaz(2,0XC0);
    glcd_yaz(1,0X40);
    glcd_yaz(2,0X40);
    glcd_yaz(1,0XB8);
    glcd_yaz(2,0XB8);
    ekrani_ac();
}

void ekrana_yaz (int chip, int x, int y, unsigned char veri)
{
    chip_sec(chip);
    di = 0;
    rw = 0;
    if(x>63){x = 63;}
    if(y>7) {y = 8;}
    x = x & 0X7F;
    x = x | 0X40;
    y = y & 0XBF;
    y = y | 0XB8;
    glcd_yaz(chip,x);
    glcd_yaz(chip,y);
    di = 1;
    rw = 0;
    port_glcd = veri;
}