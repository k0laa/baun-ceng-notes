#include <stdio.h>
#include <windows.h>

#define THREAD_SAYISI 4
#define ARTIS         100000

long sayac = 0;
CRITICAL_SECTION kilit;

void *thread_gorevi(void *arg) {
    int id = *(int *)arg;

    for (int i = 0; i < ARTIS; i++) {
        //EnterCriticalSection(&kilit);    // kritik bölge başla
        sayac++;                        // race condition yok!
        //LeaveCriticalSection(&kilit);  // kritik bölge bitti
    }

    printf("Thread %d tamamlandı\n", id);
    return NULL;
}

int main() {
    HANDLE tids[THREAD_SAYISI];
    int idler[THREAD_SAYISI];

    InitializeCriticalSection(&kilit);

    for (int i = 0; i < THREAD_SAYISI; i++) {
        idler[i] = i;
        tids[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_gorevi, &idler[i], 0, NULL);
    }

    WaitForMultipleObjects(THREAD_SAYISI, tids, TRUE, INFINITE);  // bekle

    DeleteCriticalSection(&kilit);

    printf("Beklenen: %d\n", THREAD_SAYISI * ARTIS);
    printf("Sonuc   : %ld\n", sayac);
    // Mutex ile: her zaman eşit!
    return 0;
}
// Derleme: gcc -o prog prog.c -lpthread
