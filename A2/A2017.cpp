#include <stdio.h>

int main() {
    char size, type, topping;
    int topping_amount = 0;
    int total_price = 0;

    // ใช้ " %c %c" เพื่อให้อ่านตัวอักษร 2 ตัวได้เสมอ ไม่ว่าข้อมูลเข้าจะติดกัน (SR) หรือเว้นวรรค (S R)
    scanf(" %c %c", &size, &type);
    
    // รับตัวอักษร Topping 
    scanf(" %c", &topping);
    
    // ถ้ามีการเพิ่ม Topping (P หรือ E) ให้รับค่าจำนวนชิ้นด้วย
    if (topping == 'P' || topping == 'E') {
        scanf("%d", &topping_amount);
    }

    // 1. คำนวณราคาราเมนพื้นฐาน
    if (size == 'S') {
        if (type == 'R') total_price = 60;
        else if (type == 'T') total_price = 80;
    } else if (size == 'M') {
        if (type == 'R') total_price = 80;
        else if (type == 'T') total_price = 100;
    } else if (size == 'L') {
        if (type == 'R') total_price = 100;
        else if (type == 'T') total_price = 120;
    }

    // 2. คำนวณราคา Topping เพิ่มเติม
    if (topping == 'P') {
        total_price += 15 * topping_amount;
    } else if (topping == 'E') {
        total_price += 10 * topping_amount;
    }

    // แสดงผลลัพธ์เป็นตัวเลขราคาตามตัวอย่าง
    printf("%d\n", total_price);

    return 0;
}