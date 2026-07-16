#include <stdio.h>
#include <stdlib.h>

int main() {
    int  x = 10;
    int *p = &x;       // p, x'in adresini tutar

    printf("Değer : %d\n", *p);    // *p = dereference = 10
    printf("Adres : %p\n",  p);    // bellek adresi

    *p = 99;           // x artık 99
    printf("x = %d\n", x);

    // ── Dinamik bellek (C#'da new = GC yönetir) ──
    int *dizi = (int *) malloc(5 * sizeof(int));
    if (dizi == NULL) {        // MUTLAKA kontrol et!
        perror("malloc hata");
        return 1;
    }

    for (int i = 0; i < 5; i++)
        dizi[i] = i * 10;

    printf("dizi[3] = %d\n", dizi[3]);

    free(dizi);        // MUTLAKA serbest bırak!
    dizi = NULL;       // dangling pointer engelle

    return 0;
}
