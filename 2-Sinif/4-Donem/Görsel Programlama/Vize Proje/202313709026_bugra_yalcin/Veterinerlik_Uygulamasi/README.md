# Veteriner Takip Sistemi

Veteriner Takip Sistemi, veteriner klinikleri için hasta kayıt, randevu yönetimi ve raporlama işlemlerini kolaylaştıran bir uygulamadır.

## Özellikler

- Hasta kayıt ve yönetimi
- Randevu oluşturma ve takip
- Kullanıcı yetkilendirme ve yönetimi
- Raporlama ve istatistikler

## Kurulum

### Gereksinimler

- Python 3.8+
- PyQt5
- SQLite3

### Adımlar

1. Depoyu klonlayın:

    ```bash
    git clone https://github.com/k0laa/veteriner-takip-sistemi.git
    cd veteriner-takip-sistemi
    ```

2. Gerekli Python paketlerini yükleyin:

    ```bash
    pip install -r requirements.txt
    ```

3. Veritabanını oluşturun ve gerekli tabloları ekleyin:

    ```bash
    python -c "from utils.database import Database; Database()"
    ```

4. Uygulamayı başlatın:

    ```bash
    python main.py
    ```

## Kullanım

1. Uygulamayı başlattıktan sonra giriş ekranı gelecektir.
2. Varsayılan yönetici hesabı ile giriş yapabilirsiniz:
    - Kullanıcı Adı: `admin`
    - Şifre: `admin`
3. Giriş yaptıktan sonra hasta kayıt, randevu ve raporlama işlemlerini gerçekleştirebilirsiniz.

## Katkıda Bulunma

Katkıda bulunmak için lütfen bir `fork` oluşturun, değişikliklerinizi yapın ve bir `pull request` gönderin.

## Lisans

Bu proje MIT Lisansı ile lisanslanmıştır. Daha fazla bilgi için `LICENSE` dosyasına bakın.