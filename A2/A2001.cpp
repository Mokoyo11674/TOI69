#include <stdio.h>
#include <stdlib.h>

// ฟังก์ชันสำหรับเรียงลำดับจุดบนแกน X (จากน้อยไปมาก)
int cmp(const void *a, const void *b) {
    long long la = *(const long long *)a;
    long long lb = *(const long long *)b;
    if (la < lb) return -1;
    if (la > lb) return 1;
    return 0;
}

int main() {
    int n, m;
    // รับค่า N (จำนวนสะท้อนแสงแดง) และ M (จำนวนสะท้อนแสงน้ำเงิน)
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // จองอาร์เรย์ขนาด 505 (โจทย์กำหนด N, M ไม่เกิน 500)
    long long R[505], B[505];
    
    R[0] = 0; // จุดเริ่มต้นของแสงสีแดง
    for (int i = 1; i <= n; i++) scanf("%lld", &R[i]);

    B[0] = 0; // จุดเริ่มต้นของแสงสีน้ำเงิน
    for (int i = 1; i <= m; i++) scanf("%lld", &B[i]);

    // หาจุดที่เลเซอร์อันใดอันหนึ่งสิ้นสุดก่อน (หลังจากจุดนี้ไปจะไม่เกิดการตัดกันแล้ว)
    long long max_X = R[n] < B[m] ? R[n] : B[m];

    // รวบรวม "จุดกระทบ" ทั้งหมดลงในแกน X เพื่อกวาดเส้น (Sweep)
    long long X[1010];
    int k = 0;
    X[k++] = 0;
    for (int i = 1; i <= n; i++) if (R[i] <= max_X) X[k++] = R[i];
    for (int i = 1; i <= m; i++) if (B[i] <= max_X) X[k++] = B[i];

    // เรียงลำดับจุดกระทบจากซ้ายไปขวา
    qsort(X, k, sizeof(long long), cmp);

    // ลบจุดกระทบที่มีค่าซ้ำกัน (เพื่อไม่ให้เช็คซ้อน)
    int unique_k = 1;
    for (int i = 1; i < k; i++) {
        if (X[i] != X[i - 1]) X[unique_k++] = X[i];
    }
    k = unique_k;

    int ans = 0;      // ตัวแปรเก็บคำตอบ (จำนวนจุดตัด)
    int prev_S = 0;   // เก็บเครื่องหมาย (ใครสูงกว่า) ในจุดก่อนหน้า
    int i = 1, j = 1; // ตัวชี้ช่วงเลเซอร์ของ แดง(i) และ น้ำเงิน(j)

    // วนลูปเช็คความสูงของเลเซอร์ที่ละจุด X
    for (int idx = 0; idx < k; idx++) {
        long long x = X[idx];

        // เลื่อนช่วงเลเซอร์ให้ครอบคลุมพิกัด x ปัจจุบัน
        while (i <= n && R[i] < x) i++;
        while (j <= m && B[j] < x) j++;

        // คำนวณความสูงเลเซอร์แดง ณ จุด x (เก็บในรูป เศษ/ส่วน)
        long long num_R = 0, den_R = 1;
        if (i <= n) {
            den_R = R[i] - R[i - 1];
            if (i % 2 == 1) num_R = x - R[i - 1]; // ท่อนคี่: เลเซอร์พุ่งขึ้น
            else            num_R = R[i] - x;     // ท่อนคู่: เลเซอร์พุ่งลง
        }

        // คำนวณความสูงเลเซอร์น้ำเงิน ณ จุด x (เก็บในรูป เศษ/ส่วน)
        long long num_B = 0, den_B = 1;
        if (j <= m) {
            den_B = B[j] - B[j - 1];
            if (j % 2 == 1) num_B = x - B[j - 1]; // ท่อนคี่: เลเซอร์พุ่งขึ้น
            else            num_B = B[j] - x;     // ท่อนคู่: เลเซอร์พุ่งลง
        }

        // เทียบความสูงว่าใครสูงกว่า ด้วยการคูณไขว้ (ลบกันต้องมากกว่าหรือน้อยกว่า 0)
        long long diff = num_R * den_B - num_B * den_R;
        
        int current_S = 0; // 0 = เท่ากัน, 1 = แดงสูงกว่า, -1 = น้ำเงินสูงกว่า
        if (diff > 0) current_S = 1;
        else if (diff < 0) current_S = -1;

        // --- วิเคราะห์จุดตัด ---
        // 1. ถ้า current_S เป็น 0 แสดงว่าชนกันพอดีที่จุดพิกัดนี้! นับ 1
        if (current_S == 0) {
            ans++;
        } 
        // 2. ถ้าไม่เป็น 0 แต่เครื่องหมายกลับด้านกับจุด X ที่แล้ว แสดงว่ามันต้องไขว้ตัดกันกลางทาง! นับ 1
        else if (idx > 0 && prev_S != 0 && prev_S != current_S) {
            ans++;
        }
        
        // จำค่าว่าจุดนี้ใครอยู่บน ไว้ไปเทียบกับจุดถัดไป
        prev_S = current_S;
    }

    // พิมพ์ผลลัพธ์สุดท้าย
    printf("%d\n", ans);

    return 0;
}