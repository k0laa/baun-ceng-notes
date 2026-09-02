from PyQt5.QtWidgets import (QMainWindow, QMessageBox, QLineEdit,)
from utils.database import Database
from ui.login_window_ui import setup_ui
from ui.styles import LOGIN_STYLE, BUTTON_STYLE_LOGIN


class LoginWindow(QMainWindow):
    def __init__(self, db: Database):
        super().__init__()
        self.db = db
        self.user_data = None
        self.role_type = None
        self.selected_button = None  # Keep track of the selected button


        self.setup_ui()

    def setup_ui(self):
        setup_ui(self)

    def set_role_type(self, role_type, button):
        """Sets the role type based on the button clicked."""
        self.role_type = role_type

        # Reset style for previously selected button
        if self.selected_button:
            self.selected_button.setStyleSheet(LOGIN_STYLE)

        # Highlight the selected button
        button.setStyleSheet(BUTTON_STYLE_LOGIN)
        self.selected_button = button

    def login(self):
        """Kullanıcı girişini rol tipine göre kontrol eder"""
        try:
            username = self.username_input.text().strip()
            password = self.password_input.text().strip()

            # Validate inputs
            if not username or not password:
                QMessageBox.warning(self, "Hata", "Kullanıcı adı ve şifre alanları boş olamaz!")
                return

            if username == "admin" and password == "admin":
                self.role_type = "admin"

            if username == "123" and password == "123":
                self.role_type = "admin"

            # Perform login with proper role type
            result = self.db.login(username, password, self.role_type)

            if result['success']:
                self.user_data = result
                self.accept()
            else:
                QMessageBox.warning(self, "Giriş Başarısız", "Kullanıcı adı veya şifre hatalı! \n Giriş türünü kontrol edin")

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Giriş sırasında bir hata oluştu: {str(e)}")

    def toggle_password(self):
        try:
            if self.password_input.echoMode() == QLineEdit.Password:
                self.password_input.setEchoMode(QLineEdit.Normal)
                self.sender().setText("Şifreyi Gizle")
            else:
                self.password_input.setEchoMode(QLineEdit.Password)
                self.sender().setText("Şifreyi Göster")

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Giriş sırasında bir hata oluştu: {str(e)}")

    def show_signup(self):
        """Opens the signup window"""
        try:
            from Windows.signup_window import SignupWindow
            self.signup_window = SignupWindow(self.db)  # Instance'ı sınıf değişkeni olarak sakla
            self.signup_window.show()

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Kayıt formunu açarken bir hata oluştu: {str(e)}")

    def accept(self):
        try:

            from Windows.doctor_main_window import DoctorWindow
            self.doctor_window = DoctorWindow(self.db, self.user_data)

            self.close()

            self.doctor_window.show()

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Uygulama pencerisi açılırken bir hata oluştu: {str(e)}")
