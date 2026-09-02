import sys
from PyQt5.QtWidgets import QApplication
from Windows.login_window import LoginWindow
from utils.database import Database


if __name__ == "__main__":
    
    # Veritabanı bağlantısını oluştur
    db = Database()
    
    # Uygulamayı başlat
    app = QApplication(sys.argv)
    
    # Login penceresini oluştur ve göster
    login_window = LoginWindow(db)
    login_window.show()
    
    # Uygulama döngüsünü başlat
    sys.exit(app.exec_())
