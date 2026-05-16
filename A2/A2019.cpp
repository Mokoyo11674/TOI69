#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[20];
    
    // รับข้อความเข้า 1 บรรทัด
    if (scanf("%s", str) != 1) {
        return 0;
    }
    
    int len = strlen(str);
    int has_buu = 0;
    int max_u_count = 0;
    int first_b_idx = -1;
    
    // วนลูปตรวจสอบทีละตัวอักษร
    for (int i = 0; i < len; i++) {
        // ตรวจหาตัวอักษร B หรือ b
        if (tolower(str[i]) == 'b') {
            // เก็บตำแหน่งของ B ตัวแรกที่พบ
            if (first_b_idx == -1) {
                first_b_idx = i;
            }
            
            // นับจำนวนตัวอักษร U หรือ u ที่ติดกันด้านหลัง
            int u_count = 0;
            int j = i + 1;
            while (j < len && tolower(str[j]) == 'u') {
                u_count++;
                j++;
            }
            
            // ถ้ามี U ติดกันตั้งแต่ 2 ตัวขึ้นไป แปลว่ามีคำว่า BUU
            if (u_count >= 2) {
                has_buu = 1;
            }
            
            // อัปเดตค่า U ที่มากที่สุด
            if (u_count > max_u_count) {
                max_u_count = u_count;
            }
        }
    }
    
    // แสดงผลลัพธ์ตามเงื่อนไข
    if (has_buu) {
        // กรณีที่ 1: มีข้อความย่อย BUU
        printf("Yes %d\n", max_u_count);
    } else if (first_b_idx != -1) {
        // กรณีที่ 2: ไม่มี BUU แต่มีตัวอักษร B
        for (int i = 0; i <= first_b_idx; i++) {
            printf("%c", str[i]); // พิมพ์ข้อความเดิมจนถึง B ตัวแรก
        }
        for (int i = first_b_idx + 1; i < len; i++) {
            printf("U"); // เปลี่ยนตัวอักษรที่เหลือเป็น U ทั้งหมด
        }
        printf("\n");
    } else {
        // กรณีที่ 3: ไม่มีตัวอักษร B เลย
        const char* pattern = "BUU";
        for (int i = 0; i < len; i++) {
            printf("%c", pattern[i % 3]); // วนลูปพิมพ์ BUU ต่อกัน
        }
        printf("\n");
    }
    
    return 0;
}