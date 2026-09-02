from PyQt5.QtWidgets import QMainWindow, QMessageBox, QLineEdit
from utils.database import Database
from ui.singup_window_ui import setup_ui


class SignupWindow(QMainWindow):
    def __init__(self, db: Database):
        super().__init__()
        self.db = db
        self.registration_successful = False  # Kayıt durumunu takip et

        self.setup_ui()

    def setup_ui(self):


        setup_ui(self)

    def register_user(self):
        """Kullanıcı kaydını gerçekleştirir"""
        try:
            # Form alanlarını kontrol et
            if not self.validate_form():
                return

            # Form verilerini al
            data = {'ad_soyad': f"{self.first_name.text().strip()} " f"{self.last_name.text().strip()}",
                    'tc_kimlik': self.tc_id.text().strip(),
                    'email': self.email.text().strip(),
                    'telefon': self.phone.text().strip(),
                    'kullanici_adi': self.username.text().strip(),
                    'sifre': self.password.text(), 'rol': 'owner'}

            # Veritabanına kaydet
            if self.db.register_user(data):
                QMessageBox.information(self, "Başarılı", "Kayıt işlemi başarıyla tamamlandı!")
                self.registration_successful = True  # Kayıt başarılı olduğunu işaretle
                self.close()
            else:
                QMessageBox.warning(self, "Hata", "Kayıt işlemi sırasında bir hata oluştu.")

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Kayıt işlemi sırasında bir hata oluştu: {str(e)}")

    def validate_form(self):
        """Form alanlarını doğrular"""
        # Boş alan kontrolü
        empty_fields = []
        if not self.first_name.text().strip(): empty_fields.append("İsim")
        if not self.last_name.text().strip(): empty_fields.append("Soyisim")
        if not self.tc_id.text().strip(): empty_fields.append("TC Kimlik No")
        if not self.email.text().strip(): empty_fields.append("E-posta")
        if not self.phone.text().strip(): empty_fields.append("Telefon")
        if not self.username.text().strip(): empty_fields.append("Kullanıcı Adı")
        if not self.password.text(): empty_fields.append("Şifre")
        if not self.password_confirm.text(): empty_fields.append("Şifre Tekrar")

        if empty_fields:
            QMessageBox.warning(self, "Eksik Bilgi", "Lütfen aşağıdaki alanları doldurun:\n• " + "\n• ".join(empty_fields))
            return False

        # TC Kimlik kontrolü
        if len(self.tc_id.text()) != 11:
            QMessageBox.warning(self, "Geçersiz TC Kimlik", "TC Kimlik numarası 11 haneli olmalıdır.")
            return False

        # E-posta format kontrolü
        if "@" not in self.email.text() or "." not in self.email.text():
            QMessageBox.warning(self, "Geçersiz E-posta", "Lütfen geçerli bir e-posta adresi girin.")
            return False

        # Telefon kontrolü
        if len(self.phone.text()) < 10:
            QMessageBox.warning(self, "Geçersiz Telefon", "Lütfen geçerli bir telefon numarası girin.")
            return False

        # Şifre eşleşme kontrolü
        if self.password.text() != self.password_confirm.text():
            QMessageBox.warning(self, "Şifre Uyuşmazlığı", "Girdiğiniz şifreler birbiriyle eşleşmiyor.")
            return False

        # Şifre uzunluğu kontrolü
        if len(self.password.text()) < 6:
            QMessageBox.warning(self, "Zayıf Şifre", "Şifreniz en az 6 karakter olmalıdır.")
            return False

        return True

    def get_style(self):
        """Signup dialog stilini döndürür"""
        from ui.styles import SIGNUP_STYLE
        return SIGNUP_STYLE

    def toggle_password(self):
        """Şifre görünürlüğünü değiştirir."""
        if  self.password.echoMode() == QLineEdit.Password:
            self.password.setEchoMode(QLineEdit.Normal)
            self.password_confirm.setEchoMode(QLineEdit.Normal)
            self.show_password_button.setText("Şifreyi Gizle")
        else:
            self.password.setEchoMode(QLineEdit.Password)
            self.password_confirm.setEchoMode(QLineEdit.Password)
            self.show_password_button.setText("Şifreyi Göster")

    def accept(self):
        self.close()

    def reject(self):
        self.close()
