#include <stdio.h>
#include <stdlib.h>

// ฟังก์ชันสำหรับสั่งให้ qsort เรียงตัวเลขจาก "มากไปหาน้อย" (Descending Order)
int cmp(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    return val_b - val_a; 
}

int main() {
    int w, h, m, n;
    
    // 1. รับค่าขนาดขนมปัง และจำนวนเส้นตัด
    if (scanf("%d %d %d %d", &w, &h, &m, &n) != 4) return 0;

    int x[1005], y[1005];
    
    // 2. รับตำแหน่งเส้นตัดแกน X
    for (int i = 0; i < m; i++) scanf("%d", &x[i]);
    // 3. รับตำแหน่งเส้นตัดแกน Y
    for (int i = 0; i < n; i++) scanf("%d", &y[i]);

    int w_gaps[1005], h_gaps[1005];

    // 4. คำนวณ "ระยะห่าง" ระหว่างเส้นตัดแกน X แต่ละเส้น
    w_gaps[0] = x[0] - 0; // ระยะจากขอบซ้ายถึงรอยตัดแรก
    for (int i = 1; i < m; i++) {
        w_gaps[i] = x[i] - x[i - 1]; // ระยะระหว่างรอยตัด
    }
    w_gaps[m] = w - x[m - 1]; // ระยะจากรอยตัดสุดท้ายถึงขอบขวา

    // 5. คำนวณ "ระยะห่าง" ระหว่างเส้นตัดแกน Y แต่ละเส้น
    h_gaps[0] = y[0] - 0;
    for (int i = 1; i < n; i++) {
        h_gaps[i] = y[i] - y[i - 1];
    }
    h_gaps[n] = h - y[n - 1];

    // 6. จัดเรียงความกว้างและความสูงจาก "มากไปน้อย"
    // จำนวนชิ้นความกว้างคือ m + 1 ชิ้น, ความสูงคือ n + 1 ชิ้น
    qsort(w_gaps, m + 1, sizeof(int), cmp);
    qsort(h_gaps, n + 1, sizeof(int), cmp);

    // 7. คำนวณพื้นที่ชิ้นที่ 1 และ 2 ตามสูตรลับของเรา
    // ใช้ long long กันไว้เผื่อพื้นที่ใหญ่เกินกว่า int จะรับไหว
    long long max1 = (long long)w_gaps[0] * h_gaps[0];
    
    long long cand1 = (long long)w_gaps[0] * h_gaps[1];
    long long cand2 = (long long)w_gaps[1] * h_gaps[0];
    
    long long max2 = (cand1 > cand2) ? cand1 : cand2;

    // 8. แสดงผล
    printf("%lld %lld\n", max1, max2);

    return 0;
}