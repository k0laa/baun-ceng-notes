from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QVBoxLayout, QLabel, QScrollArea, QWidget, QPushButton)


def setup_bekleyen_hastalar_tab(window, tab):
    """Bekleyen hastalar sekmesini oluşturur"""
    layout = QVBoxLayout()
    tab.setLayout(layout)

    # Başlık
    baslik = QLabel("Muayene Bekleyen Hastalar")
    baslik.setStyleSheet("""
            font-size: 20px;
            color: #4a3463;
            font-weight: bold;
            padding: 10px;
        """)
    layout.addWidget(baslik)
    
    
    # Yeni Kayıt Butonu
    yeni_kayit_btn = QPushButton("Yeni Kayıt")
    yeni_kayit_btn.setStyleSheet("""
        QPushButton {
            background-color: #4CAF50;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #45a049;
        }
    """)
    yeni_kayit_btn.clicked.connect(lambda: window.yeni_kayit_ekle())
    layout.addWidget(yeni_kayit_btn, alignment=Qt.AlignRight)
    
    layout.addLayout(layout)

    # Scroll alan
    scroll = QScrollArea()
    scroll.setWidgetResizable(True)
    scroll.setStyleSheet("""
            QScrollArea {
                border: none;
                background-color: transparent;
            }
            QScrollArea > QWidget > QWidget {
                background-color: transparent;
            }
        """)

    # İçerik widget'ı
    content_widget = QWidget()
    window.bekleyen_content = content_widget
    content_layout = QVBoxLayout(content_widget)
    content_layout.setSpacing(10)
    content_layout.setContentsMargins(10, 10, 10, 10)

    # Scroll alanına içerik widget'ını ekle
    scroll.setWidget(content_widget)
    layout.addWidget(scroll)

    # İlk yükleme
    window.refresh_bekleyen_hastalar()
