#include <stdio.h>

int main() {
    int width, length, layers;
    int price_per_meter;
    int total_length, total_cost;

    // รับข้อมูลเข้าบรรทัดแรก: ความกว้าง ความยาว และจำนวนชั้นของรั้ว
    scanf("%d %d %d", &width, &length, &layers);
    
    // รับข้อมูลเข้าบรรทัดที่สอง: ราคาลวดหนามต่อ 1 เมตร
    scanf("%d", &price_per_meter);

    // คำนวณความยาวลวดหนามที่ต้องใช้ทั้งหมด
    // เส้นรอบรูปสี่เหลี่ยมผืนผ้า = 2 * (กว้าง + ยาว)
    int perimeter = 2 * (width + length);
    total_length = perimeter * layers;

    // คำนวณราคาลวดหนามที่ต้องจ่าย
    total_cost = total_length * price_per_meter;

    // แสดงผลลัพธ์
    printf("%d\n", total_length);
    printf("%d\n", total_cost);

    return 0;
}