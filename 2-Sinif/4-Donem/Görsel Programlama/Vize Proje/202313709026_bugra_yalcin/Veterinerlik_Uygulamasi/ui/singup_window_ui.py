from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import ( QVBoxLayout, QLabel, QLineEdit, QPushButton,  QFormLayout, QWidget, QHBoxLayout)
from PyQt5.QtCore import Qt
from ui.styles import SIGNUP_STYLE


def setup_ui(window):
    """Setup signup dialog UI"""
    window.setWindowTitle("Veteriner Takip Sistemi - Kayıt Ol")
    window.setFixedSize(700, 650)
    window.setStyleSheet(SIGNUP_STYLE)
    window.setWindowIcon(QIcon("resources/icons/app_icon.png"))

    # Ana widget konteynerini oluştur
    stacked_widget = QWidget()
    window.setCentralWidget(stacked_widget)

    # Main layout
    main_layout = QVBoxLayout()
    main_layout.setContentsMargins(30, 30, 30, 30)
    main_layout.setSpacing(20)

    # Title
    title = QLabel("Veteriner Takip Sistemi - Yeni Hasta Kaydı")
    title.setObjectName("title")
    title.setAlignment(Qt.AlignCenter)
    title.setStyleSheet("font-size: 24px; font-weight: bold; color: #4a3463; margin-bottom: 20px;")
    main_layout.addWidget(title)

    # Create two-column layout
    form_layout = QHBoxLayout()
    form_layout.setSpacing(30)

    # Left column - Personal Information
    left_widget = QWidget()
    left_form = QFormLayout(left_widget)
    left_form.setSpacing(15)
    left_form.setContentsMargins(0, 0, 0, 0)

    left_title = QLabel("Kişisel Bilgiler")
    left_title.setStyleSheet("font-size: 16px; font-weight: bold; color: #6b4c8c;")
    left_form.addRow(left_title)

    # First Name
    window.first_name = QLineEdit()
    window.first_name.setPlaceholderText("Adınız")
    window.first_name.setFixedHeight(40)
    left_form.addRow("İsim:", window.first_name)

    # Last Name
    window.last_name = QLineEdit()
    window.last_name.setPlaceholderText("Soyadınız")
    window.last_name.setFixedHeight(40)
    left_form.addRow("Soyisim:", window.last_name)

    # TC Identity Number
    window.tc_id = QLineEdit()
    window.tc_id.setPlaceholderText("TC Kimlik Numaranız")
    window.tc_id.setFixedHeight(40)
    window.tc_id.setMaxLength(11)
    left_form.addRow("TC Kimlik No:", window.tc_id)

    # Email
    window.email = QLineEdit()
    window.email.setPlaceholderText("E-posta adresiniz")
    window.email.setFixedHeight(40)
    left_form.addRow("E-posta:", window.email)

    # Phone
    window.phone = QLineEdit()
    window.phone.setPlaceholderText("05XX XXX XX XX")
    window.phone.setFixedHeight(40)
    left_form.addRow("Telefon:", window.phone)

    form_layout.addWidget(left_widget, 1)

    # Right column - Account Information
    right_widget = QWidget()
    right_form = QFormLayout(right_widget)
    right_form.setSpacing(15)
    right_form.setContentsMargins(0, 0, 0, 0)

    right_title = QLabel("Hesap Bilgileri")
    right_title.setStyleSheet("font-size: 16px; font-weight: bold; color: #6b4c8c;")
    right_form.addRow(right_title)

    # Username
    window.username = QLineEdit()
    window.username.setPlaceholderText("Kullanıcı adınız")
    window.username.setFixedHeight(40)
    right_form.addRow("Kullanıcı Adı:", window.username)

    # Password
    window.password = QLineEdit()
    window.password.setPlaceholderText("Şifreniz")
    window.password.setEchoMode(QLineEdit.Password)
    window.password.setFixedHeight(40)
    right_form.addRow("Şifre:", window.password)

    # Password Confirmation
    window.password_confirm = QLineEdit()
    window.password_confirm.setPlaceholderText("Şifrenizi tekrar girin")
    window.password_confirm.setEchoMode(QLineEdit.Password)
    window.password_confirm.setFixedHeight(40)
    right_form.addRow("Şifre Tekrar:", window.password_confirm)

    # Password Show Button
    window.show_password_button = QPushButton("Şifreyi Göster")
    window.show_password_button.setObjectName("showPass")
    window.show_password_button.setStyleSheet("""
        color: #9b7bb8;
        border: none;
        font-size: 13px;
    """)
    window.show_password_button.setCursor(Qt.PointingHandCursor)
    window.show_password_button.clicked.connect(window.toggle_password)
    right_form.addRow(window.show_password_button)

    form_layout.addWidget(right_widget, 1)
    main_layout.addLayout(form_layout)

    main_layout.addSpacing(20)

    # Note
    note = QLabel("Not: Tüm alanların doldurulması zorunludur.")
    note.setStyleSheet("font-size: 12px; font-style: italic; color: #666;")
    note.setAlignment(Qt.AlignCenter)
    main_layout.addWidget(note)

    # Buttons
    button_layout = QHBoxLayout()
    button_layout.setSpacing(20)

    # Cancel Button
    window.cancel_button = QPushButton("İptal")
    window.cancel_button.setObjectName("cancelBtn")
    window.cancel_button.setCursor(Qt.PointingHandCursor)
    window.cancel_button.setFixedHeight(45)
    window.cancel_button.clicked.connect(window.reject)
    button_layout.addWidget(window.cancel_button)

    # Register Button
    window.register_button = QPushButton("Kayıt Ol")
    window.register_button.setObjectName("loginBtn")
    window.register_button.setCursor(Qt.PointingHandCursor)
    window.register_button.setFixedHeight(45)
    window.register_button.clicked.connect(window.register_user)
    button_layout.addWidget(window.register_button)

    main_layout.addLayout(button_layout)
    stacked_widget.setLayout(main_layout)
