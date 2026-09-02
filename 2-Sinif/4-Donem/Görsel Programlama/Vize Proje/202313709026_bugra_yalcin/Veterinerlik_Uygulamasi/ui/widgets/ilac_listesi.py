from PyQt5.QtWidgets import QListWidget
from ..styles import LIST_STYLE

def create_ilac_listesi():
    """İlaç listesi widget'ını oluşturur"""
    ilac_listesi = QListWidget()
    ilac_listesi.addItems([
        "Antibiyotikler",
        "Ağrı Kesiciler",
        "Antiparaziter İlaçlar",
        "Vitaminler ve Mineraller",
        "Deri ve Tüy İlaçları",
        "Göz Damlaları",
        "Kulak Damlaları",
        "Probiyotikler",
        "Aşılar"
    ])
    ilac_listesi.setSelectionMode(QListWidget.MultiSelection)
    ilac_listesi.setStyleSheet(LIST_STYLE)
    return ilac_listesi 