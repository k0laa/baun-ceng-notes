#include <stdio.h>
#include <string.h>

// C'de struct (C#'daki class gibi)
typedef struct {
    char isim[50];  // char dizisi!
    int  yas;
    float maas;
} Calisan;

int topla(int a, int b) {
    return a + b;
}

int main() {
    // Değişken tanımlama
    int sayi = 42;
    float pi  = 3.14f;
    char harf = 'A';

    // String (C#'dan farklı!)
    char ad[20] = "Ahmet";
    printf("Ad: %s, Yas: %d\n", ad, sayi);

    // Struct kullanımı
    Calisan c;
    strcpy(c.isim, "Fatma");   // string kopyalama
    c.yas  = 30;
    c.isim[52] = '+';
    c.maas = 5000.0f;

    Calisan c2;
    strcpy(c2.isim, "deneme");   // string kopyalama
    c2.yas  = 22;
    c2.maas = 3200.0f;

    printf("Calisan: %s, %d\n", c.isim, c.yas);
    printf("Calisan: %s, %d\n", c2.isim, c2.yas);
    return 0;          // 0 = başarı
}