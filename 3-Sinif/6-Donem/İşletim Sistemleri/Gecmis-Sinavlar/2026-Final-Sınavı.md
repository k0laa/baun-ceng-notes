📘 İşletim Sistemleri – 2026 Final Klasik Soruları
==================================================

> **Not:** Bu belge, 2026 final sınavında çıkan klasik soruların hatırlanabildiği kadarıyla düzenlenmiş halidir.

* * *

Soru 1 – Disk Zamanlama Algoritmaları
=====================================

### Verilenler

* Disk adres aralığı: **0 – 180**

* Örnek istek sırası:
    70 85 120 5 10

(Sınavda farklı sayılar verilmişti.)

### İstenenler

1. **SSTF (Shortest Seek Time First)** algoritmasına göre kafanın toplam hareket mesafesini hesaplayınız.

2. **C-SCAN (Circular SCAN)** algoritmasına göre kafanın toplam hareket mesafesini hesaplayınız.

3. Aşağıdaki soruyu açıklayarak cevaplayınız:

> **C-SCAN mı daha adildir, SSTF mi daha adildir? Neden?**

* * *

Soru 2 – Banker's Algorithm
===========================

Sınavda, **Slayt 8 – Sayfa 11** ile aynı yapıda bir tablo verilmiştir.

* Tablo üzerindeki **Need** sütunu boş bırakılmıştır.

* Sayısal değerler slayttakinden farklıdır.

### İstenenler

1. **Need** sütununu hesaplayınız.
    Need = Max - Allocation

2. Sistemin **güvenli (safe)** veya **güvensiz (unsafe)** olduğunu belirleyiniz.

3. Eğer sistem güvenliyse **Safe Sequence (Güvenli İşlem Sırası)** yazınız.

4. Güvenli değilse neden güvenli olmadığını gösteriniz.

* * *

Soru 3 – Producer – Consumer Problemi
=====================================

Sınavda aşağıdaki kod verilmiş olup bazı kısımlar boş bırakılmıştır.
    semaphore mutex = 1;      // binary semaphore for mutual exclusion
    semaphore full = ......;       // initially no filled slots
    semaphore empty = ......;      // buffer size
    void Producer(){
        do {
            // Produce an item

            wait(......);
            wait(......);

            // Place item in buffer

            signal(......);
            signal(......);

        } while (true);

    }

    void Consumer(){

        do {

            wait(......);
            wait(......);

            // Remove item from buffer

            signal(......);
            signal(......);

        } while (true);

    }

### Doldurulması Gereken Cevaplar

    full  = 0
    empty = n
    
    wait(empty)
    wait(mutex)
    
    signal(mutex)
    signal(full)
    
    wait(full)
    wait(mutex)
    
    signal(mutex)
    signal(empty)

* * *

Boşluk Doldurma
===============

Hatırlanabilen cevaplar:

* **Priority Inversion (Öncelik Tersinmesi)**

* **Thrashing**

* **Heap**

* **(?)** Bir kavram daha vardı ancak hatırlanmıyor.
  
  

bu kavramların ne demek olduğunu araştırarak çalışabilirsiniz. boşluk doldurma cümlelerini hatırlamıyorum.

* * *

# Diğer Bölümler

Fazlasıyla **Doğru Yanlış** ve az miktarda **Çoktan Seçmeli** soru vardı. Vize öncesi konuşarın hepsini nerdeyse doğru yanlışta sorumuştu.


