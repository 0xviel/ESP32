# Happy Birthday ESP32 Project

### Deskripsi
proyek ini menggunakan ESP32 untuk:
1. memutar nada "Happy Birthday" menggunakan 3 buzzer.
2. memainkan 3 led sesuai nada/note
3. menampilkan pesan "Happy Birthday [nama] yang ke [tahun]" di LCD 0.96 inch

### Komponen
- ESP32
- 3 Buzzer
- 3 LED 5mm
- oled 128 × 64 (0,96 inch)

### Pin
1. OLED
   - SDA > pin 21
   - SCL > pin 22
   - VCC > pin 3v3
   - GND > pin gnd
2. LED
   - LED MERAH(+) > pin 32
   - LED HIJAU(+) > pin 33
   - LED KUNING(+) > pin 25
   - All LED(-) > pin gnd(with resistor 220 Ohm)
     
3. BUZZER
   - Buzzer1(+) > pin 26
   - Buzzer2(+) > pin 27
   - Buzzer3(+) > pin 14
   - All Buzzer(-) > pin gnd

   
### Cara Menggunakan
1. sambungkan komponen sesuai pin yang telah ditentukan.
2. instal library `Adafruit SSD1306` & `Adafruit GFX` jika belum ada.
3. upload program ke ESP32 menggunakan Arduino IDE.
4. proyek siap dijalankan.
