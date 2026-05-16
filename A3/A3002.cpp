#include <stdio.h>

int main() {
    long long N;
    
    // รับหมายเลขห้องเริ่มต้น
    if (scanf("%lld", &N) != 1) return 0;
    
    // กรณีที่อยู่ที่ห้อง 1 อยู่แล้ว ไม่ต้องพังกำแพง
    if (N == 1) {
        printf("0\n");
        return 0;
    }

    // 1. หาแถว (r) ที่ห้อง N อยู่
    long long r = 1;
    while (r * r < N) {
        r++;
    }

    // 2. หาตำแหน่ง (c) ของห้อง N ภายในแถวที่ r
    // แถวที่ r จะเริ่มที่ (r-1)^2 + 1 
    long long c = N - ((r - 1) * (r - 1));

    long long min_walls = 0;

    // 3. คำนวณจำนวนกำแพงตามทิศทางของสามเหลี่ยม
    if (c % 2 != 0) {
        // สามเหลี่ยมชี้ขึ้น (ตำแหน่งคี่)
        min_walls = (2 * r) - 2;
    } else {
        // สามเหลี่ยมชี้ลง (ตำแหน่งคู่)
        min_walls = (2 * r) - 3;
    }

    // แสดงผลลัพธ์
    printf("%lld\n", min_walls);

    return 0;
}