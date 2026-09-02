from PyQt5.QtWidgets import (QWidget, QVBoxLayout, QHBoxLayout,
                             QLabel, QComboBox, QPushButton, QProgressBar)


DURUM_RENKLERI = {
    'Muayene Bekliyor': '#FFA07A',  # Açık mercan
    'Teşhis Konuldu': '#DDA0DD',    # Açık mor
    'Tedaviye Başlandı': '#87CEEB',  # Açık mavi
    'İyileşme Sürecinde': '#90EE90', # Açık yeşil
    'Kontrol Zamanı': '#FFB6C1',     # Açık pembe
    'Tedavi Tamamlandı': '#98FB98',  # Açık yeşil
    'Acil Durum': '#FF6B6B',         # Kırmızı
}

DURUM_ILERLEME = {
        'Muayene Bekliyor': 0,
        'Teşhis Konuldu': 20,
        'Tedaviye Başlandı': 40,
        'İyileşme Sürecinde': 60,
        'Kontrol Zamanı': 80,
        'Tedavi Tamamlandı': 100,
        'Acil Durum': 100
}


class DurumTakipWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setup_ui()

    def setup_ui(self):
        layout = QVBoxLayout(self)

        # Durum seçici
        durum_layout = QHBoxLayout()
        self.durum_label = QLabel("Hasta Durumu:")
        self.durum_combo = QComboBox()
        self.durum_combo.addItems(DURUM_RENKLERI.keys())
        self.durum_combo.currentTextChanged.connect(self.durum_degisti)

        # Renk göstergesi
        self.renk_gosterge = QLabel()
        self.renk_gosterge.setFixedSize(20, 20)
        self.renk_gosterge.setStyleSheet(f"""
            background-color: {DURUM_RENKLERI[self.durum_combo.currentText()]};
            border-radius: 10px;
            border: 1px solid #666;
        """)

        durum_layout.addWidget(self.durum_label)
        durum_layout.addWidget(self.durum_combo)
        durum_layout.addWidget(self.renk_gosterge)
        durum_layout.addStretch()

        # İlerleme çubuğu
        ilerleme_layout = QHBoxLayout()
        self.ilerleme_label = QLabel("Tedavi İlerlemesi:")
        self.ilerleme_bar = QProgressBar()
        self.ilerleme_bar.setRange(0, 100)
        self.ilerleme_bar.setTextVisible(True)
        self.ilerleme_bar.setFormat("%p%")

        ilerleme_layout.addWidget(self.ilerleme_label)
        ilerleme_layout.addWidget(self.ilerleme_bar)

        # Durum geçiş butonları
        buton_layout = QHBoxLayout()
        self.onceki_durum = QPushButton("← Önceki Durum")
        self.sonraki_durum = QPushButton("Sonraki Durum →")

        self.onceki_durum.clicked.connect(self.onceki_duruma_gec)
        self.sonraki_durum.clicked.connect(self.sonraki_duruma_gec)

        buton_layout.addWidget(self.onceki_durum)
        buton_layout.addWidget(self.sonraki_durum)

        # Layout'ları ana layout'a ekle
        layout.addLayout(durum_layout)
        layout.addLayout(ilerleme_layout)
        layout.addLayout(buton_layout)

        # İlk durum rengini ayarla
        self.durum_degisti(self.durum_combo.currentText())

    def durum_degisti(self, yeni_durum):
        """Durum değiştiğinde renk göstergesini güncelle"""
        renk = DURUM_RENKLERI[yeni_durum]
        self.renk_gosterge.setStyleSheet(f"""
            background-color: {renk};
            border-radius: 10px;
            border: 1px solid #666;
        """)

        # İlerleme çubuğunun rengini de güncelle
        self.ilerleme_bar.setStyleSheet(f"""
            QProgressBar {{
                border: 1px solid #ccc;
                border-radius: 5px;
                text-align: center;
            }}
            QProgressBar::chunk {{
                background-color: {renk};
                border-radius: 4px;
            }}
        """)

    def onceki_duruma_gec(self):
        """Bir önceki duruma geç"""
        current_idx = self.durum_combo.currentIndex()
        if current_idx > 0:
            self.durum_combo.setCurrentIndex(current_idx - 1)

    def sonraki_duruma_gec(self):
        """Bir sonraki duruma geç"""
        current_idx = self.durum_combo.currentIndex()
        if current_idx < self.durum_combo.count() - 1:
            self.durum_combo.setCurrentIndex(current_idx + 1)

    def get_durum(self):
        """Mevcut durumu döndür"""
        return {
            'durum': self.durum_combo.currentText(),
            'ilerleme': self.ilerleme_bar.value()
        }

    def set_durum(self, durum, ilerleme):
        """Durumu ve ilerlemeyi ayarla"""
        if durum in DURUM_RENKLERI:
            self.durum_combo.setCurrentText(durum)
        self.ilerleme_bar.setValue(ilerleme)

    def durum_degisti(self, yeni_durum):
        """Durum değiştiğinde renk göstergesini ve ilerlemeyi güncelle"""
        renk = DURUM_RENKLERI[yeni_durum]
        self.renk_gosterge.setStyleSheet(f"""
            background-color: {renk};
            border-radius: 10px;
            border: 1px solid #666;
        """)

        # İlerleme çubuğunu güncelle
        ilerleme = DURUM_ILERLEME[yeni_durum]
        self.ilerleme_bar.setValue(ilerleme)

        # İlerleme çubuğunun rengini güncelle
        self.ilerleme_bar.setStyleSheet(f"""
            QProgressBar {{
                border: 1px solid #d4c6e6;
                border-radius: 4px;
                text-align: center;
            }}
            QProgressBar::chunk {{
                background-color: {renk};
            }}
        """)

    def onceki_duruma_gec(self):
        """Bir önceki duruma geç"""
        current_idx = self.durum_combo.currentIndex()
        if current_idx > 0:
            self.durum_combo.setCurrentIndex(current_idx - 1)

    def sonraki_duruma_gec(self):
        """Bir sonraki duruma geç"""
        current_idx = self.durum_combo.currentIndex()
        if current_idx < self.durum_combo.count() - 1:
            self.durum_combo.setCurrentIndex(current_idx + 1)