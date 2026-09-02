from PyQt5.QtWidgets import QMainWindow, QMessageBox
from ui.oppointment_window_ui import setup_ui


class OppointmentWindow(QMainWindow):
    def __init__(self, db, user_data, hasta_id, main_window):
        super().__init__()
        self.db = db
        self.user_data = user_data
        self.registration_successful = False
        self.hasta_id = hasta_id
        self.main_window = main_window

        self.setup_ui()

    def setup_ui(self):
        setup_ui(self)
        self.get_data()

    def get_data(self):
        if self.hasta_id:
            hasta = self.db.muayeneye_al(self.hasta_id)
            if hasta:
                # Fill form fields with patient data
                self.form_elements['ad_input'].setText(hasta[0])
                self.form_elements['sahip_input'].setText(hasta[1])
                self.form_elements['tur_combo'].setCurrentText(hasta[2])
                self.form_elements['cins_input'].setText(hasta[3])
                self.form_elements['erkek_radio'].setChecked(hasta[4] == "Erkek")
                self.form_elements['disi_radio'].setChecked(hasta[4] == "Dişi")
                self.form_elements['yas_spinbox'].setValue(hasta[5])
                self.form_elements['sikayet_text'].setText(hasta[6])
                self.form_elements['aciklama_text'].setText(hasta[7])

                # Update status
                if hasta[8] == "Muayeneye Alındı":
                    self.durum_takip.set_durum("Teşhis Konuldu", 20)

            else:
                QMessageBox.warning(self, "Hata", "Hasta muayeneye alınamadı.")

    def save_to_database(self):
        """Hasta kaydını veritabanına kaydeder veya günceller"""
        if not self.user_data['yetkiler']['hasta_ekle']:
            QMessageBox.warning(self, "Yetkisiz İşlem", "Hasta kaydı ekleme yetkiniz yok!")
            return

        try:
            # Form verilerini al
            data = {'hayvan_adi': self.form_elements['ad_input'].text().strip(), 'sahip_adi': self.form_elements['sahip_input'].text().strip(), 'tur': self.form_elements['tur_combo'].currentText(),
                    'cins': self.form_elements['cins_input'].text().strip(), 'yas': self.form_elements['yas_spinbox'].value(), 'sikayet': self.form_elements['sikayet_text'].toPlainText().strip(),
                    'aciklama': self.form_elements['aciklama_text'].toPlainText().strip(), 'ekleyen_id': self.user_data['user_id']}

            # Boş alanları kontrol et
            empty_fields = []
            if not data['hayvan_adi']:
                empty_fields.append("Hayvan Adı")
            if not data['sahip_adi']:
                empty_fields.append("Sahip Adı")
            if not data['cins']:
                empty_fields.append("Cins")
            if not data['yas']:
                empty_fields.append("Yaş")
            if not (self.form_elements['erkek_radio'].isChecked() or self.form_elements['disi_radio'].isChecked()):
                empty_fields.append("Cinsiyet")
            if not data['sikayet']:
                empty_fields.append("Şikayet")

            # Boş alan varsa uyarı ver
            if empty_fields:
                msg = QMessageBox()
                msg.setIcon(QMessageBox.Warning)
                msg.setWindowTitle("Eksik Bilgi")
                msg.setText("Aşağıdaki alanlar boş:")
                msg.setInformativeText("\n".join(empty_fields))
                msg.setStandardButtons(QMessageBox.Yes | QMessageBox.Cancel)
                msg.setDefaultButton(QMessageBox.Cancel)
                msg.button(QMessageBox.Yes).setText("Devam Et")
                msg.button(QMessageBox.Cancel).setText("İptal")

                reply = msg.exec_()
                if reply == QMessageBox.Cancel:
                    return

            # Cinsiyet kontrolü
            data['cinsiyet'] = 'Erkek' if self.form_elements['erkek_radio'].isChecked() else 'Dişi'

            # Durum ve ilerleme bilgilerini al
            durum_data = self.durum_takip.get_durum()
            data.update(durum_data)

            # Seçili ilaçları al
            ilaclar = []
            for i in range(self.ilac_listesi.count()):
                if self.ilac_listesi.item(i).isSelected():
                    ilaclar.append(self.ilac_listesi.item(i).text())
            data['ilaclar'] = ', '.join(ilaclar)

            # Kaydet veya güncelle
            if self.hasta_id:
                success = self.db.update_patient_full(self.hasta_id, data)
                message = "Kayıt başarıyla güncellendi."
            else:
                success = self.db.add_patient(data)
                message = "Yeni kayıt başarıyla eklendi."

            if success:
                # self.clear_form()
                QMessageBox.information(self, "Başarılı", message)
            else:
                QMessageBox.warning(self, "Hata", "Kayıt işlemi başarısız oldu!")


            self.close_win()

        except Exception as e:
            print(f"Kayıt işlemi sırasında hata: {str(e)}")  # Hata ayıklama için
            QMessageBox.critical(self, "Hata", f"Kayıt işlemi sırasında bir hata oluştu: {str(e)}")

    # def clear_form(self):
    #     """Form alanlarını temizler"""
    #     try:
    #         # Form elemanlarını temizle
    #         self.form_elements['ad_input'].clear()
    #         self.form_elements['sahip_input'].clear()
    #         self.form_elements['tur_combo'].setCurrentIndex(0)
    #         self.form_elements['cins_input'].clear()
    #         self.form_elements['erkek_radio'].setChecked(True)
    #         self.form_elements['yas_spinbox'].setValue(0)
    #         self.form_elements['sikayet_text'].clear()
    #         self.form_elements['aciklama_text'].clear()
    #
    #         # İlaç listesindeki seçimleri kaldır
    #         for i in range(self.ilac_listesi.count()):
    #             self.ilac_listesi.item(i).setSelected(False)
    #
    #         # Durum ve ilerlemeyi sıfırla
    #         self.durum_takip.durum_combo.setCurrentIndex(0)
    #         self.durum_takip.ilerleme_bar.setValue(0)
    #
    #         # Düzenleme modunu sıfırla
    #         self.current_edit_id = None
    #
    #     except Exception as e:
    #         QMessageBox.critical(self, "Hata", f"Form temizleme hatası: {str(e)}")

    def edit_record(self):
        QMessageBox.information(self, "Bilgi", "Kayıt düzenleme moduna geçildi. Değişiklikleri yaptıktan sonra 'Kaydet' butonuna tıklayın.")

    def close_win(self):
        self.main_window.refresh_bekleyen_hastalar()
        self.main_window.refresh_data()
        self.close()
