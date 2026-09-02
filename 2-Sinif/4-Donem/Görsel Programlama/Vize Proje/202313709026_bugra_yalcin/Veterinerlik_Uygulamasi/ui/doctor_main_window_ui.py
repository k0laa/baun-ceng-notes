from PyQt5.QtWidgets import QWidget, QStackedWidget
from PyQt5.QtGui import QIcon
from ui.widgets.menu import setup_menu
from .styles import TOOLBAR_STYLE
from .tabs.raporlar_tab import setup_raporlar_tab
from .tabs.bekleyen_hastalar_tab import setup_bekleyen_hastalar_tab



def setup_ui(window):
    """Ana pencere arayüzünü oluşturur"""
    # Pencere özelliklerini ayarla
    window.setWindowTitle("Veteriner Takip Sistemi")
    window.setGeometry(100, 100, 1200, 800)
    window.setWindowIcon(QIcon("resources/icons/app_icon.png"))

    # Menü çubuğunu oluştur
    setup_menu(window)

    # Ana widget konteynerini oluştur
    stacked_widget = QStackedWidget()
    window.setCentralWidget(stacked_widget)

    # Hasta Kayıt sekmesi
    # hasta_kayit_widget = QWidget()
    # setup_hasta_kayit_tab(window, hasta_kayit_widget)
    # stacked_widget.addWidget(hasta_kayit_widget)

    # Raporlar sekmesi
    raporlar_widget = QWidget()
    setup_raporlar_tab(window, raporlar_widget)
    stacked_widget.addWidget(raporlar_widget)

    # Bekleyen Hastalar sekmesi
    bekleyen_widget = QWidget()
    setup_bekleyen_hastalar_tab(window, bekleyen_widget)
    stacked_widget.addWidget(bekleyen_widget)

    # Toolbar butonları
    window.toolbar.setStyleSheet(TOOLBAR_STYLE)

    # # Sekme butonlarını oluştur
    # window.hasta_kayit_action = window.toolbar.addAction(QIcon("resources/icons/add_patient.png"), "Hasta Kayıt")
    # window.hasta_kayit_action.setCheckable(True)

    window.raporlar_action = window.toolbar.addAction(QIcon("resources/icons/reports.png"), "Raporlar")
    window.raporlar_action.setCheckable(True)

    window.bekleyen_action = window.toolbar.addAction(QIcon("resources/icons/waiting.png"), "Bekleyen Hastalar")
    window.bekleyen_action.setCheckable(True)

    # Buton tıklama olaylarını bağla
    def switch_to_tab(index):
        #window.hasta_kayit_action.setChecked(index == 0)
        window.raporlar_action.setChecked(index == 0)
        window.bekleyen_action.setChecked(index == 1)
        stacked_widget.setCurrentIndex(index)


    #window.hasta_kayit_action.triggered.connect(lambda: switch_to_tab(0))
    window.raporlar_action.triggered.connect(lambda: switch_to_tab(0))
    window.raporlar_action.triggered.connect(window.refresh_data)
    window.bekleyen_action.triggered.connect(lambda: switch_to_tab(1))
    window.bekleyen_action.triggered.connect(window.refresh_bekleyen_hastalar)

    # Stacked widget'ı window'a ekle
    window.stacked_widget = stacked_widget
