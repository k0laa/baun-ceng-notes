from PyQt5.QtWidgets import (QWidget, QVBoxLayout, QHBoxLayout, QLabel,
                             QLineEdit, QComboBox, QRadioButton, QSpinBox,
                              QTextEdit)

from ..styles import INPUT_STYLE, RADIO_STYLE, SLIDER_STYLE, PROGRESS_STYLE

class FormElementsWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.elements = {}
        self.setup_ui()

    def setup_ui(self):
        layout = QVBoxLayout(self)

        # Ad ve sahip bilgileri
        ad_layout = QHBoxLayout()
        ad_label = QLabel("Hayvan Adı:")
        self.elements['ad_input'] = QLineEdit()
        self.elements['ad_input'].setStyleSheet(INPUT_STYLE)
        ad_layout.addWidget(ad_label)
        ad_layout.addWidget(self.elements['ad_input'])
        layout.addLayout(ad_layout)

        sahip_layout = QHBoxLayout()
        sahip_label = QLabel("Sahip Adı:")
        self.elements['sahip_input'] = QLineEdit()
        self.elements['sahip_input'].setStyleSheet(INPUT_STYLE)
        sahip_layout.addWidget(sahip_label)
        sahip_layout.addWidget(self.elements['sahip_input'])
        layout.addLayout(sahip_layout)

        # Cins alanı eklendi
        cins_layout = QHBoxLayout()
        cins_label = QLabel("Cins:")
        self.elements['cins_input'] = QLineEdit()
        self.elements['cins_input'].setStyleSheet(INPUT_STYLE)
        cins_layout.addWidget(cins_label)
        cins_layout.addWidget(self.elements['cins_input'])
        layout.addLayout(cins_layout)

        # Tür seçimi
        tur_layout = QHBoxLayout()
        tur_label = QLabel("Tür:")
        self.elements['tur_combo'] = QComboBox()
        self.elements['tur_combo'].addItems(["Kedi", "Köpek", "Kuş", "Hamster", "Diğer"])
        self.elements['tur_combo'].setStyleSheet(INPUT_STYLE)
        tur_layout.addWidget(tur_label)
        tur_layout.addWidget(self.elements['tur_combo'])
        layout.addLayout(tur_layout)

        # Cinsiyet seçimi
        cinsiyet_layout = QHBoxLayout()
        cinsiyet_label = QLabel("Cinsiyet:")
        self.elements['erkek_radio'] = QRadioButton("Erkek")
        self.elements['disi_radio'] = QRadioButton("Dişi")
        self.elements['erkek_radio'].setStyleSheet(RADIO_STYLE)
        self.elements['disi_radio'].setStyleSheet(RADIO_STYLE)
        cinsiyet_layout.addWidget(cinsiyet_label)
        cinsiyet_layout.addWidget(self.elements['erkek_radio'])
        cinsiyet_layout.addWidget(self.elements['disi_radio'])
        layout.addLayout(cinsiyet_layout)

        # Yaş spinbox
        yas_layout = QHBoxLayout()
        yas_label = QLabel("Yaş:")
        self.elements['yas_spinbox'] = QSpinBox()
        self.elements['yas_spinbox'].setRange(0, 100)
        self.elements['yas_spinbox'].setStyleSheet(INPUT_STYLE)
        yas_layout.addWidget(yas_label)
        yas_layout.addWidget(self.elements['yas_spinbox'])
        layout.addLayout(yas_layout)

        # Şikayet alanı
        sikayet_label = QLabel("Şikayet:")
        self.elements['sikayet_text'] = QTextEdit()
        self.elements['sikayet_text'].setStyleSheet(INPUT_STYLE)
        self.elements['sikayet_text'].setMaximumHeight(100)
        layout.addWidget(sikayet_label)
        layout.addWidget(self.elements['sikayet_text'])

        # Açıklama text alanı
        aciklama_label = QLabel("Açıklama:")
        self.elements['aciklama_text'] = QTextEdit()
        self.elements['aciklama_text'].setStyleSheet(INPUT_STYLE)
        self.elements['aciklama_text'].setMaximumHeight(100)
        layout.addWidget(aciklama_label)
        layout.addWidget(self.elements['aciklama_text'])

def create_form_elements():
    """Form elemanlarını oluşturur ve döndürür"""
    widget = FormElementsWidget()
    return widget.elements