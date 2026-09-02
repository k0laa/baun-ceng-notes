from PyQt5.QtWidgets import QGroupBox, QVBoxLayout, QLabel, QHBoxLayout
from PyQt5.QtCore import Qt
from ..styles import GROUP_STYLE, STAT_TITLE_STYLE, STAT_VALUE_STYLE

def create_stat_card(title, value):
    """İstatistik kartı oluşturur"""
    group = QGroupBox()
    group.setStyleSheet(GROUP_STYLE)
    
    layout = QVBoxLayout()
    
    title_label = QLabel(title)
    title_label.setStyleSheet(STAT_TITLE_STYLE)
    title_label.setAlignment(Qt.AlignCenter)
    
    value_label = QLabel(value)
    value_label.setObjectName("value_label")
    value_label.setStyleSheet(STAT_VALUE_STYLE)
    value_label.setAlignment(Qt.AlignCenter)
    
    layout.addWidget(title_label)
    layout.addWidget(value_label)
    group.setLayout(layout)
    
    return group

def create_statistics():
    """İstatistik kartlarını oluşturur"""
    container = QHBoxLayout()
    
    total_patients_card = create_stat_card("Toplam Hasta", "0")        
    treatment_success_card = create_stat_card("Tedavi Başarısı", "0%")
    
    container.addWidget(total_patients_card)
    container.addWidget(treatment_success_card)
    
    stat_cards = {
        'total_patients': total_patients_card,
        'treatment_success': treatment_success_card
    }
    
    return container, stat_cards 