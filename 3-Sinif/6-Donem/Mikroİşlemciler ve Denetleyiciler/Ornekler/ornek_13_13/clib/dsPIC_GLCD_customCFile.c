#include "dsPIC_glcd.h"

void chip_sec (int chip)
{
    if (chip == 0) {cs1 = 0; cs2 = 0;}
    else if (chip == 1) {cs1 = 1; cs2 = 0;}
    else if (chip == 2) {cs1 = 0; cs2 = 1;}
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

void ekrani_ac (void)
{
    di = 0;
    glcd_yaz(1, 0x3F);
    glcd_yaz(2, 0x3F);
}

void ekrani_kapa (void)
{
    di = 0;
    glcd_yaz(1, 0x3E);
    glcd_yaz(2, 0x3E);
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
    tris_glcd = 0;
    rst = 1;
    chip_sec(0);
    di = 0;
    
    glcd_yaz(1, 0xC0); // Start line 0
    glcd_yaz(2, 0xC0);
    glcd_yaz(1, 0x40); // Y address 0
    glcd_yaz(2, 0x40);
    glcd_yaz(1, 0xB8); // Page 0
    glcd_yaz(2, 0xB8);
    
    ekrani_ac();
}

void ekrana_yaz (int chip, int x, int y, unsigned char veri)
{
    if(x > 63) { x = 63; }
    if(y > 7)  { y = 7; }

    x = (x & 0x7F) | 0x40; // Set Y address komutu (KS0108 sütun)
    y = (y & 0xBF) | 0xB8; // Set Page komutu (KS0108 satır/sayfa)

    di = 0;
    glcd_yaz(chip, x);
    glcd_yaz(chip, y);

    // Veriyi yazma
    chip_sec(chip);
    di = 1;
    rw = 0;
    port_glcd = veri;
    __delay_us(10);
    e = 1;
    __delay_us(10);
    e = 0;
    chip_sec(0);
}