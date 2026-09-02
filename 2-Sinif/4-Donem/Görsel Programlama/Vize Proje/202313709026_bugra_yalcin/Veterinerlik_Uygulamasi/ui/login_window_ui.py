from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import (QVBoxLayout, QPushButton, QHBoxLayout, QLabel, QLineEdit, QWidget)

from ui.styles import LOGIN_STYLE


def setup_ui(window):
    """Login dialog arayüzünü oluşturur"""

    window.setWindowTitle("Veteriner Takip Sistemi - Giriş Yap")
    window.setStyleSheet(LOGIN_STYLE)
    window.setWindowIcon(QIcon("resources/icons/app_icon.png"))

    window.setFixedSize(500, 700)  # Increased size from 500x400

    # Ana widget konteynerini oluştur
    stacked_widget = QWidget()
    window.setCentralWidget(stacked_widget)

    layout = QVBoxLayout()
    layout.setSpacing(20)  # Increased spacing
    layout.setContentsMargins(30, 30, 30, 30)  # Added margins for better spacing

    # Title
    title = QLabel("Veteriner Takip Sistemi")
    title.setObjectName("title")
    title.setAlignment(Qt.AlignCenter)
    title.setStyleSheet("font-size: 28px; font-weight: bold; color: #4a3463; margin: 20px 0;")
    layout.addWidget(title)
    layout.addSpacing(50)  # More space after title

    # Button layout
    button_layout = QHBoxLayout()
    button_layout.setSpacing(15)  # Add spacing between buttons

    # Hasta Girişi Button
    window.patient_button = QPushButton("Hasta Sahibi Girişi")
    window.patient_button.setObjectName("loginBtn")
    window.patient_button.setCursor(Qt.PointingHandCursor)
    window.patient_button.setFixedHeight(45)  # Taller button
    button_layout.addWidget(window.patient_button)

    # Sekreter Girişi Button
    window.secretary_button = QPushButton("Sekreter Girişi")
    window.secretary_button.setObjectName("loginBtn")
    window.secretary_button.setCursor(Qt.PointingHandCursor)
    window.secretary_button.setFixedHeight(45)  # Taller button
    button_layout.addWidget(window.secretary_button)

    # Doktor Girişi Button
    window.doctor_button = QPushButton("Doktor Girişi")
    window.doctor_button.setObjectName("loginBtn")
    window.doctor_button.setCursor(Qt.PointingHandCursor)
    window.doctor_button.setFixedHeight(45)  # Taller button
    button_layout.addWidget(window.doctor_button)

    layout.addLayout(button_layout)
    layout.addSpacing(30)  # Increased spacing

    # Username
    username_label = QLabel("Kullanıcı Adı:")
    username_label.setStyleSheet("font-size: 16px;")  # Larger font
    layout.addWidget(username_label)

    window.username_input = QLineEdit()
    window.username_input.setPlaceholderText("Kullanıcı adınızı girin")
    window.username_input.setFixedHeight(45)  # Taller input
    window.username_input.setStyleSheet("font-size: 16px;")  # Larger font
    layout.addWidget(window.username_input)

    layout.addSpacing(15)  # Increased spacing

    # Password
    password_label = QLabel("Şifre:")
    password_label.setStyleSheet("font-size: 16px;")  # Larger font
    layout.addWidget(password_label)

    window.password_input = QLineEdit()
    window.password_input.setPlaceholderText("Şifrenizi girin")
    window.password_input.setEchoMode(QLineEdit.Password)
    window.password_input.setFixedHeight(45)  # Taller input
    window.password_input.setStyleSheet("font-size: 16px;")  # Larger font
    layout.addWidget(window.password_input)

    layout.addSpacing(10)  # Increased spacing

    # Show Password Button
    show_pass = QPushButton("Şifreyi Göster")
    show_pass.setObjectName("showPass")
    show_pass.setCursor(Qt.PointingHandCursor)
    show_pass.clicked.connect(window.toggle_password)
    layout.addWidget(show_pass)

    layout.addSpacing(25)  # Increased spacing

    # Login Button
    window.login_button = QPushButton("Giriş Yap")
    window.login_button.setObjectName("loginBtn")
    window.login_button.setCursor(Qt.PointingHandCursor)
    window.login_button.setFixedHeight(50)  # Taller login button
    window.login_button.setStyleSheet("font-size: 18px;")  # Larger font
    layout.addWidget(window.login_button)

    layout.addSpacing(10)

    # Sign Up Button
    window.signup_button = QPushButton("Kayıt Ol")
    window.signup_button.setObjectName("signupBtn")
    window.signup_button.setCursor(Qt.PointingHandCursor)
    window.signup_button.setFixedHeight(40)  # Slightly smaller than login button
    # Use a different style to distinguish it from the login button
    window.signup_button.setStyleSheet("""
        background-color: transparent;
        color: #6b4c8c;
        border: 2px solid #9b7bb8;
        border-radius: 5px;
        font-size: 16px;
        font-weight: bold;
    """)
    layout.addWidget(window.signup_button)

    layout.addSpacing(15)  # Increased spacing

    # Info Label
    info = QLabel("Varsayılan giriş: admin / admin")
    info.setObjectName("info")
    info.setAlignment(Qt.AlignCenter)
    layout.addWidget(info)

    window.username_input.returnPressed.connect(window.password_input.setFocus)
    window.password_input.returnPressed.connect(window.login_button.click)

    stacked_widget.setLayout(layout)

    window.signup_button.clicked.connect(window.show_signup)
    # Connect button signals to a single handler
    window.doctor_button.clicked.connect(lambda: window.set_role_type("doctor", window.doctor_button))
    window.secretary_button.clicked.connect(lambda: window.set_role_type("secretary", window.secretary_button))
    window.patient_button.clicked.connect(lambda: window.set_role_type("owner", window.patient_button))
    window.login_button.clicked.connect(window.login)
