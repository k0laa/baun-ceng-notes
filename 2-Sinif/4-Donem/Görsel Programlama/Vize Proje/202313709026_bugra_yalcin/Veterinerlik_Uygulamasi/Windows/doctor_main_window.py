from PyQt5.QtWidgets import (QMainWindow, QMessageBox, QTableWidgetItem, QToolBar, QLabel, QTableWidget)
from PyQt5.QtCore import Qt, QDate, QTime
from ui.doctor_main_window_ui import setup_ui
from ui.widgets.hasta_karti import HastaKartiWidget
import os
from PyQt5.QtGui import QIcon


class DoctorWindow(QMainWindow):
    def __init__(self, database, user_data):
        super().__init__()
        self.database = database
        self.user_data = user_data
        self.setup_ui()

    def setup_ui(self):
        # Toolbar oluştur
        self.toolbar = QToolBar("Ana Araç Çubuğu")
        self.addToolBar(self.toolbar)

        # İkon yolları kurulumu
        self.setup_icons()

        # UI kurulumu
        setup_ui(self)

        self.update_ui_permissions()

        # Başlangıçta verileri yükle
        self.refresh_data()

        # Başlangıç sekmesini ayarla
        self.bekleyen_action.setChecked(True)
        self.stacked_widget.setCurrentIndex(1)

    def setup_icons(self):
        """İkonların doğru yüklenmesini sağlar"""
        base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        icons_dir = os.path.join(base_dir, "resources", "icons")

        # İkon yollarını kontrol et
        if not os.path.exists(icons_dir):
            os.makedirs(icons_dir, exist_ok=True)
            print(f"İkon dizini oluşturuldu: {icons_dir}")

        # Temel ikon yolunu ayarla
        self.icon_path = icons_dir

        # Uygulama ikonunu belirle
        app_icon_path = os.path.join(icons_dir, "app_icon.png")
        if os.path.exists(app_icon_path):
            self.setWindowIcon(QIcon(app_icon_path))
        else:
            print(f"Uyarı: Uygulama ikonu bulunamadı: {app_icon_path}")

    def update_ui_permissions(self):
        """Kullanıcı yetkilerine göre UI elementlerini günceller"""
        yetkiler = self.user_data['yetkiler']

        # Hasta kayıt sekmesi
        if not yetkiler['hasta_ekle']:
            self.hasta_kayit_action.setEnabled(False)
            if hasattr(self, 'form_elements'):
                for element in self.form_elements.values():
                    element.setEnabled(False)

        # Rapor sekmesi
        if not yetkiler['rapor_goruntule']:
            self.raporlar_action.setEnabled(False)

        # Tablo düzenleme
        if not yetkiler['hasta_duzenle']:
            self.rapor_table.setEditTriggers(QTableWidget.NoEditTriggers)

        # Silme butonu
        if hasattr(self, 'delete_button') and not yetkiler['hasta_sil']:
            self.delete_button.setEnabled(False)


    def refresh_data(self):
        """Rapor tablosunu ve istatistikleri günceller"""
        if hasattr(self, 'rapor_table'):
            records = self.database.get_all_patients()
            self.rapor_table.setRowCount(len(records))

            for i, record in enumerate(records):
                self.rapor_table.setItem(i, 0, QTableWidgetItem(str(record[0])))  # ID
                self.rapor_table.setItem(i, 1, QTableWidgetItem(record[1]))  # Hayvan Adı
                self.rapor_table.setItem(i, 2, QTableWidgetItem(record[2]))  # Sahip Adı
                self.rapor_table.setItem(i, 3, QTableWidgetItem(record[3]))  # Tür
                self.rapor_table.setItem(i, 4, QTableWidgetItem(record[4]))  # Cins
                self.rapor_table.setItem(i, 5, QTableWidgetItem(record[5]))  # Cinsiyet
                self.rapor_table.setItem(i, 6, QTableWidgetItem(str(record[6])))  # Yaş
                self.rapor_table.setItem(i, 7, QTableWidgetItem(record[7]))  # Durum
                self.rapor_table.setItem(i, 8, QTableWidgetItem(str(record[8])))  # İlerleme
                self.rapor_table.setItem(i, 9, QTableWidgetItem(record[9]))  # Açıklama
                self.rapor_table.setItem(i, 10, QTableWidgetItem(record[10]))  # İlaçlar
                self.rapor_table.setItem(i, 11, QTableWidgetItem(record[11]))  # Eklenme Tarihi

            # İstatistikleri güncelle
            stats = self.database.get_statistics()
            if hasattr(self, 'stat_cards'):
                self.stat_cards['total_patients'].findChild(QLabel, "value_label").setText(str(stats['total']))
                self.stat_cards['treatment_success'].findChild(QLabel, "value_label").setText(f"{stats['success_rate']:.1f}%")

        self.refresh_bekleyen_hastalar()

    def load_reports(self):
        """Raporları yükler"""
        try:
            # Tablo verilerini güncelle
            records = self.database.get_all_patients()
            self.rapor_table.setRowCount(0)

            for row_number, record in enumerate(records):
                self.rapor_table.insertRow(row_number)
                for column_number, data in enumerate(record):
                    item = QTableWidgetItem(str(data))
                    self.rapor_table.setItem(row_number, column_number, item)

            # İstatistikleri güncelle
            stats = self.database.get_statistics()
            total_label = self.stat_cards['total_patients'].findChild(QLabel, "value_label")
            success_label = self.stat_cards['treatment_success'].findChild(QLabel, "value_label")

            if total_label and success_label:
                total_label.setText(str(stats['total']))
                success_label.setText(f"%{stats['success_rate']:.1f}")

        except Exception as e:
            print(f"Rapor yükleme hatası: {e}")

    def delete_record(self):
        """Seçili kaydı siler"""
        if not self.user_data['yetkiler']['hasta_sil']:
            QMessageBox.warning(self, "Yetkisiz İşlem", "Bu işlem için yetkiniz bulunmamaktadır!")
            return

        try:
            current_row = self.rapor_table.currentRow()
            if current_row < 0:
                QMessageBox.warning(self, "Uyarı", "Lütfen silinecek bir kayıt seçin!")
                return

            record_id = self.rapor_table.item(current_row, 0).text()
            reply = QMessageBox.question(self, "Onay", "Bu kaydı silmek istediğinizden emin misiniz?", QMessageBox.Yes | QMessageBox.No)

            if reply == QMessageBox.Yes:
                if self.database.delete_patient(record_id):
                    self.refresh_data()
                    QMessageBox.information(self, "Başarılı", "Kayıt başarıyla silindi!")
                else:
                    QMessageBox.critical(self, "Hata", "Kayıt silinirken bir hata oluştu!")
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Kayıt silme hatası: {str(e)}")

    def filter_reports(self):
        """Raporları filtreler"""
        try:
            text = self.search_input.text().lower()
            for row in range(self.rapor_table.rowCount()):
                column = self.search_combo.currentIndex() + 1
                item = self.rapor_table.item(row, column)
                self.rapor_table.setRowHidden(row, text not in item.text().lower() if item else True)
        except Exception as e:
            print(f"Filtreleme hatası: {e}")

    def on_table_item_changed(self, item):
        """Tablo hücresi değiştiğinde veritabanını günceller"""
        try:
            if self._loading_reports:  # Yükleme sırasında güncelleme yapma
                return

            row = item.row()
            col = item.column()
            if col == 0:  # ID değiştirilemez
                return

            new_value = item.text()
            record_id = self.rapor_table.item(row, 0).text()
            column_names = ["id",  # 0
                            "hayvan_adi",  # 1
                            "sahip_adi",  # 2
                            "tur",  # 3
                            "cinsiyet",  # 4
                            "yas",  # 5
                            "durum",  # 6
                            "ilerleme",  # 7
                            "aciklama",  # 8
                            "ilaclar"  # 9
                            ]

            if self.database.update_patient(record_id, column_names[col], new_value):
                self.refresh_data()
            else:
                QMessageBox.critical(self, "Hata", "Güncelleme yapılırken bir hata oluştu!")
                self.refresh_data()
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Güncelleme hatası: {str(e)}")

    def edit_record(self):
        """Seçili kaydı hasta kayıt formuna aktarır"""
        try:
            current_row = self.rapor_table.currentRow()
            if current_row < 0:
                QMessageBox.warning(self, "Uyarı", "Lütfen düzenlenecek bir kayıt seçin!")
                return

            record_id = int(self.rapor_table.item(current_row, 0).text())

            from Windows.oppointment_window import OppointmentWindow
            self.oppointment_window = OppointmentWindow(self.database, self.user_data, record_id, self)
            self.oppointment_window.show()
            self.oppointment_window.edit_record()


        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Kayıt düzenleme hatası: {str(e)}")


    def refresh_bekleyen_hastalar(self):
        """Bekleyen hastaları günceller"""
        try:
            if not hasattr(self, 'bekleyen_content'):
                return

            records = self.database.get_waiting_patients()
            content_layout = self.bekleyen_content.layout()

            # Mevcut kartları temizle
            while content_layout.count():
                child = content_layout.takeAt(0)
                if child.widget():
                    child.widget().deleteLater()

            # Yeni kartları ekle
            if records:
                for record in records:
                    hasta_karti = HastaKartiWidget(record, self.bekleyen_content)
                    content_layout.addWidget(hasta_karti)
            else:
                no_patient_label = QLabel("Şu anda bekleyen hasta bulunmamaktadır.")
                no_patient_label.setStyleSheet("""
                     color: #666;
                     font-style: italic;
                     padding: 20px;
                 """)
                no_patient_label.setAlignment(Qt.AlignCenter)
                content_layout.addWidget(no_patient_label)

            content_layout.addStretch()

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Bekleyen hastalar güncellenirken hata: {str(e)}")

    def muayeneye_al(self, hasta_id):
        try:
            hasta = self.database.muayeneye_al(hasta_id)
            if hasta:
                from Windows.oppointment_window import OppointmentWindow
                self.oppointment_window = OppointmentWindow(self.database, self.user_data, hasta_id, self)
                self.oppointment_window.show()

            else:
                QMessageBox.warning(self, "Hata", "Hasta muayeneye alınamadı.")

        except Exception as e:
            print(f"Muayeneye alma hatası: {str(e)}")
            QMessageBox.critical(self, "Hata", f"Muayeneye alma işlemi sırasında hata: {str(e)}")

    def detay_goster(self, hasta_id):
        """Hasta detaylarını gösterir"""
        try:
            self.edit_record(hasta_id)
            self.stacked_widget.setCurrentIndex(0)
            self.hasta_kayit_action.setChecked(True)
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Detaylar gösterilirken hata: {str(e)}")


    def add_appointment(self):
        """Randevu ekler"""
        try:
            # Form verilerini al
            hasta_index = self.randevu_elements['hasta_combo'].currentIndex()
            hasta_id = self.randevu_elements['hasta_combo'].itemData(hasta_index)
            tarih = self.randevu_elements['tarih'].date().toString("yyyy-MM-dd")
            saat = self.randevu_elements['saat'].time().toString("HH:mm")
            tip = self.randevu_elements['tip'].currentText()
            notlar = self.randevu_elements['not'].text()

            # Hasta seçilip seçilmediğini kontrol et
            if hasta_id is None:
                QMessageBox.warning(self, "Uyarı", "Lütfen bir hasta seçin!")
                return

            data = {'hasta_id': hasta_id, 'tarih': tarih, 'saat': saat, 'tip': tip, 'not': notlar, 'durum': 'Bekliyor'}

            # Veritabanına kaydet ve tabloyu güncelle
            if self.database.add_appointment(data):
                self.clear_appointment_form()
                self.load_appointments()
                QMessageBox.information(self, "Başarılı", "Randevu başarıyla eklendi!")
            else:
                QMessageBox.critical(self, "Hata", "Randevu eklenirken bir hata oluştu!")

        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Randevu eklerken bir hata oluştu: {str(e)}")

    def clear_appointment_form(self):
        """Randevu formunu temizler"""
        try:
            self.randevu_elements['hasta_combo'].setCurrentIndex(0)
            self.randevu_elements['tarih'].setDate(QDate.currentDate())
            self.randevu_elements['saat'].setTime(QTime(9, 0))
            self.randevu_elements['tip'].setCurrentIndex(0)
            self.randevu_elements['not'].clear()
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Randevu formu temizlenirken hata: {str(e)}")

    def yeni_kayit_ekle(self):
        """Yeni kayıt eklemek için muayene penceresini açar"""
        try:
            from Windows.oppointment_window import OppointmentWindow
            self.oppointment_window = OppointmentWindow(self.database, self.user_data, None, self)
            self.oppointment_window.show()
        except Exception as e:
            QMessageBox.critical(self, "Hata", f"Yeni kayıt penceresi açılırken hata: {str(e)}")


"""
    def closeEvent(self, event):
        Pencere kapatıldığında onay sor
        reply = QMessageBox.question(self, 'Çıkış', 'Uygulamadan çıkmak istediğinizden emin misiniz?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)

        if reply == QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()
"""