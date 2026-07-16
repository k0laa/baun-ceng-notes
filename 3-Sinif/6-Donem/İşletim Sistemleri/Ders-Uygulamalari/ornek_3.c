#include <stdio.h>
#include <signal.h>
#include <process.h>
#include <windows.h>

volatile int calis = 1;

// Sinyal işleyici (handler)
void sinyal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nCtrl+C yakalandı! "
               "Temizlik yapılıyor...\n");
        calis = 0;    // döngüyü durdur
    }
}

int main() {
    // Handler kaydet
    signal(SIGINT,  sinyal_handler);

    printf("PID=%d  Ctrl+C bekliyor...\n",
           getpid());

    while (calis) {
        printf("Çalışıyor...\n");
        Sleep(1000);
    }

    printf("Proses düzgün sonlandı.\n");
    return 0;
}
