from PyQt5.QtWidgets import (QVBoxLayout, QHBoxLayout, QLineEdit, QComboBox, QTableWidget, QPushButton, QLabel)
from ..widgets.statistics import create_statistics
from ..styles import INPUT_STYLE, BUTTON_STYLE, TABLE_STYLE


def setup_raporlar_tab(window, tab):
    """Raporlar sekmesini oluşturur"""
    layout = QVBoxLayout()
    tab.setLayout(layout)

    # İstatistikler
    stats_container, stat_cards = create_statistics()
    layout.addLayout(stats_container)
    window.stat_cards = stat_cards

    # Arama alanı
    search_layout = QHBoxLayout()
    search_input = QLineEdit()
    search_input.setPlaceholderText("Ara...")
    search_input.setStyleSheet(INPUT_STYLE)

    search_combo = QComboBox()
    search_combo.addItems(["Hayvan Adı", "Sahip Adı", "Tür"])
    search_combo.setStyleSheet(INPUT_STYLE)

    search_layout.addWidget(search_input)
    search_layout.addWidget(search_combo)
    layout.addLayout(search_layout)

    # Rapor tablosu
    table = QTableWidget()
    table.setColumnCount(12)  # Sütun sayısını 12 olarak güncelle
    table.setHorizontalHeaderLabels(["ID", "Hayvan Adı", "Sahip Adı", "Tür", "Cins", "Cinsiyet", "Yaş", "Durum", "İlerleme",  "Şikayet", "Açıklama", "İlaçlar", "Eklenme Tarihi"])

    # Tabloyu salt okunur yap
    table.setEditTriggers(QTableWidget.NoEditTriggers)

    # Tablo özelliklerini ayarla
    table.setStyleSheet(TABLE_STYLE)
    table.setAlternatingRowColors(True)
    table.horizontalHeader().setStretchLastSection(True)
    table.setSelectionBehavior(QTableWidget.SelectRows)

    # Sütun genişliklerini ayarla
    table.setColumnWidth(0, 50)  # ID
    table.setColumnWidth(1, 120)  # Hayvan Adı
    table.setColumnWidth(2, 120)  # Sahip Adı
    table.setColumnWidth(3, 80)  # Tür
    table.setColumnWidth(4, 100)  # Cins
    table.setColumnWidth(5, 80)  # Cinsiyet
    table.setColumnWidth(6, 50)  # Yaş
    table.setColumnWidth(7, 120)  # Durum
    table.setColumnWidth(8, 80)  # İlerleme
    table.setColumnWidth(9, 150)  # Şikayet
    table.setColumnWidth(10, 150)  # Açıklama
    table.setColumnWidth(11, 150)  # İlaçlar
    table.setColumnWidth(12, 120)  # Eklenme Tarihi

    layout.addWidget(QLabel("Hasta Raporları"))
    layout.addWidget(table)

    # Buton container
    button_layout = QHBoxLayout()

    # Düzenle butonu
    edit_button = QPushButton("Seçili Kaydı Düzenle")
    edit_button.setStyleSheet(BUTTON_STYLE)
    button_layout.addWidget(edit_button)

    # Silme butonu
    delete_button = QPushButton("Seçili Kaydı Sil")
    delete_button.setStyleSheet(BUTTON_STYLE)
    button_layout.addWidget(delete_button)

    layout.addLayout(button_layout)

    # Window'a elementleri ekle
    window.rapor_table = table
    window.search_input = search_input
    window.search_combo = search_combo
    window.delete_button = delete_button

    # Sinyal bağlantıları
    search_input.textChanged.connect(window.filter_reports)
    delete_button.clicked.connect(window.delete_record)
    edit_button.clicked.connect(window.edit_record)
