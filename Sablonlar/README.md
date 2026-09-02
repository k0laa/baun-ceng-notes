# 📋 Katkıda Bulunma Şablonları (README Templates)

Bu klasör, Balıkesir Üniversitesi Bilgisayar Mühendisliği ders notları deposuna yeni sınıf, dönem, ders veya not kategorisi eklemek isteyen katkıcılar için hazırlanmış standart README şablonlarını içerir.

Depo düzeninin sürdürülebilir, estetik ve anlaşılır kalması için tüm yeni eklemelerin aşağıdaki şablon standartlarına uygun şekilde yapılması gerekmektedir.

---

## 📂 Şablon Dosyaları

| Şablon Dosyası | Kullanım Yeri | Açıklama |
| :--- | :--- | :--- |
| [Sinif-README-Template.md](Sinif-README-Template.md) | `[X]-Sinif/README.md` | Sınıf düzeyindeki ana dizinler için |
| [Donem-README-Template.md](Donem-README-Template.md) | `[X]-Donem/README.md` | Dönem düzeyindeki dizinler için |
| [Ders-README-Template.md](Ders-README-Template.md) | `[Ders_Adi]/README.md` | Her bir dersin ana klasörü için |
| [Kategori-README-Template.md](Kategori-README-Template.md) | `[Ders_Adi]/[Kategori]/README.md` | `Ders-Notlari`, `Odevler` vb. alt klasörler için |

---

## 🛠️ Nasıl Kullanılır?

1. Ekleyeceğiniz klasör seviyesine uygun şablon dosyasını açın.
2. Dosya içeriğini kopyalayın ve hedef klasörünüzde bir `README.md` oluşturarak yapıştırın.
3. Köşeli parantez içindeki `[Ders_Adi]`, `[Ogretim_Elemani]`, `[Donem]` gibi yer tutucuları kendi içeriğinize göre doldurun.
4. Bağlantıların (relative links) doğru çalıştığından ve klasör seviyenize denk geldiğinden emin olun.
5. GitHub Pull Request açarak katkınızı gönderin.

---

## 🎨 Temel Tasarım Kuralları

- **Ekmek Kırıntısı (Breadcrumb):** Sayfa başında üst dizinlere kolay dönüş bağlantısı olmalıdır.
- **Alert Kutuları:** Uyarılarda GitHub markdown alert `> [!NOTE]` veya `> [!WARNING]` kullanılmalıdır.
- **Tablo Formatı:** Ders ve dosya listeleri düzenli Markdown tabloları halinde sunulmalıdır.
- **Kod Blokları:** Dizin yapıları ````text ... ```` bloğu içinde verilmelidir.
