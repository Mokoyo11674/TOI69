#include <stdio.h>

int main() {
    char pearl_type, tea_type;
    int pearl_amount, sweetness, tea_amount;
    int total_energy = 0;
    int pearl_energy = 0;
    int tea_energy_per_cc = 0;

    // รับข้อมูลเข้าบรรทัดแรก: ประเภทไข่มุก และปริมาณ (กรัม)
    scanf("%c %d", &pearl_type, &pearl_amount);
    
    // รับข้อมูลเข้าบรรทัดที่สอง: ประเภทชา ระดับความหวาน และปริมาตร (cc.)
    // เว้นวรรคหน้า %c เพื่อข้ามตัวอักษรขึ้นบรรทัดใหม่ (newline)
    scanf(" %c %d %d", &tea_type, &sweetness, &tea_amount);

    // คำนวณพลังงานจากไข่มุก
    if (pearl_type == 'H') {
        pearl_energy = 5 * pearl_amount;
    } else if (pearl_type == 'O') {
        pearl_energy = 3 * pearl_amount;
    } else if (pearl_type == 'J') {
        pearl_energy = 2 * pearl_amount;
    }

    // คำนวณพลังงานจากชา (ต่อ 1 cc.)
    if (tea_type == 'R') {
        if (sweetness == 1) tea_energy_per_cc = 12;
        else if (sweetness == 2) tea_energy_per_cc = 18;
        else if (sweetness == 3) tea_energy_per_cc = 25;
    } else if (tea_type == 'T') {
        if (sweetness == 1) tea_energy_per_cc = 15;
        else if (sweetness == 2) tea_energy_per_cc = 20;
        else if (sweetness == 3) tea_energy_per_cc = 30;
    } else if (tea_type == 'M') {
        if (sweetness == 1) tea_energy_per_cc = 10;
        else if (sweetness == 2) tea_energy_per_cc = 15; // อนุมานแทนค่าที่ผิดพลาดในโจทย์
        else if (sweetness == 3) tea_energy_per_cc = 20;
    }

    // คำนวณพลังงานรวมทั้งหมด
    total_energy = pearl_energy + (tea_energy_per_cc * tea_amount);

    // แสดงผลลัพธ์
    printf("%d\n", total_energy);

    return 0;
}