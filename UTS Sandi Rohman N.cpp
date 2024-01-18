#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Fungsi untuk mengatur motor listrik utama
void aturMotorUtama(int kecepatan, int waktu) {
    printf("Motor listrik utama berputar dengan kecepatan %d rpm selama %d menit\n", kecepatan, waktu);
    sleep(waktu * 60);
    printf("Motor listrik utama berhenti.\n");
}

// Fungsi untuk mengatur motor listrik pembuka klep
void aturMotorPembukaKlep(int waktu) {
    printf("Motor listrik pembuka klep aktif selama %d menit\n", waktu);
    sleep(waktu * 60);
    printf("Motor listrik pembuka klep berhenti.\n");
}

// Fungsi utama
int main() {
    // Array untuk level kekeruhan air (NTU)
    int levels[] = {6, 8, 12, 18, 24, 30, 36, 42, 49};
    int jumlahLevel = sizeof(levels) / sizeof(levels[0]);

    // Sensor turbidimeter mendeteksi level kekeruhan air
    int levelRataRata = 0;
    for (int i = 0; i < jumlahLevel; ++i) {
        levelRataRata += levels[i];
    }
    levelRataRata /= jumlahLevel;

    // Tombol start ditekan
    printf("Tombol start ditekan.\n");

    // Motor listrik pembuka klep pengisian air aktif selama 2 menit sampai air penuh
    aturMotorPembukaKlep(2);

    // Sensor turbidimeter aktif hanya satu kali untuk mendeteksi level kekeruhan air
    printf("Sensor turbidimeter mendeteksi level kekeruhan air: %d NTU\n", levelRataRata);

    // Motor listrik utama berputar sesuai level kekeruhan air = level rata-rata kekeruhan air
    aturMotorUtama(1000, 60);

    // Motor listrik utama berhenti pada setiap pertengahan waktu
    printf("Motor listrik utama berhenti.\n");
    sleep(2 * 60); // Jeda 2 menit untuk membuang air kotor

    // Motor listrik pembuka klep pembuangan air kotor aktif selama 2 menit sampai air kotor habis
    aturMotorPembukaKlep(2);

    // Motor listrik utama berputar dengan kecepatan 2000 rpm untuk mengeringkan cucian selama 3 menit
    aturMotorUtama(2000, 3);

    // Motor listrik pembuka klep pengisian air aktif selama 2 menit sampai air penuh
    aturMotorPembukaKlep(2);

    // Motor listrik utama berputar selama sisa waktu mencuci
    aturMotorUtama(1000, 60);

    // Motor listrik pembuka klep pembuangan air kotor aktif selama 2 menit sampai air habis
    aturMotorPembukaKlep(2);

    // Motor listrik utama berputar dengan kecepatan 2000 rpm untuk mengeringkan cucian selama 3 menit
    aturMotorUtama(2000, 3);

    // Program selesai
    printf("Proses mencuci selesai.\n");

    return 0;
}
