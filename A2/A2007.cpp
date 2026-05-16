#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

// โครงสร้างสำหรับเก็บข้อมูลถัง
typedef struct {
    int id, A, B;
} Bucket;

Bucket buckets[MAXN];
int A_arr[MAXN], B_arr[MAXN];
int up[MAXN][18]; // ตารางสำหรับ Binary Lifting (กระโดดทีละ 2^i)

// ฟังก์ชันเรียงลำดับ: เรียง A จากน้อยไปมาก ถ้า A เท่ากัน เรียง B จากมากไปน้อย
int cmp(const void *a, const void *b) {
    Bucket *ba = (Bucket *)a;
    Bucket *bb = (Bucket *)b;
    if (ba->A != bb->A) return ba->A - bb->A;
    return bb->B - ba->B;
}

// ข้อมูลสำหรับแต่ละตระกูล (Root)
int active[MAXN];
int minA[MAXN], maxB[MAXN], min_u[MAXN];
int ans[MAXN];
int ans_cnt = 0;

// ฟังก์ชันหา "ราก (Root)" ของต้นไม้
int find_root(int u) {
    int curr = u;
    // กระโดดขึ้นไปให้สูงที่สุดเท่าที่ทำได้
    for (int step = 17; step >= 0; step--) {
        if (up[curr][step] != 0) {
            curr = up[curr][step];
        }
    }
    return curr;
}

// ฟังก์ชันเรียงคำตอบ
int cmp_int(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int n, m;
    // 1. รับค่าจำนวนถัง (N) และ ถังเป้าหมาย (M)
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &A_arr[i], &B_arr[i]);
        buckets[i].id = i;
        buckets[i].A = A_arr[i];
        buckets[i].B = B_arr[i];
    }

    // 2. เรียงถังทั้งหมด เพื่อสร้างต้นไม้ (Forest)
    qsort(buckets + 1, n, sizeof(Bucket), cmp);

    // 3. ใช้ Stack เพื่อหาว่าใครเป็น "พ่อ" ของใคร (สร้างตารางก้าวแรก: up[i][0])
    int st[MAXN];
    int top = 0;
    for (int i = 1; i <= n; i++) {
        Bucket b = buckets[i];
        // ถ้าถังใน Stack เล็กกว่าถังปัจจุบัน (โดนครอบไม่ได้) ให้เอาออก
        while (top > 0 && B_arr[st[top]] < b.B) {
            top--;
        }
        if (top > 0) up[b.id][0] = st[top]; // เจอพ่อแล้ว!
        else up[b.id][0] = 0;               // ตัวนี้แหละคือ Root
        
        st[++top] = b.id;
    }

    // 4. สร้างตาราง Binary Lifting กระโดดทีละ 2^step
    for (int step = 1; step < 18; step++) {
        for (int i = 1; i <= n; i++) {
            up[i][step] = up[ up[i][step-1] ][step-1];
        }
    }

    // 5. เตรียมตัวแปรจัดกลุ่มถังเป้าหมายตาม "Root"
    for (int i = 1; i <= n; i++) {
        active[i] = 0;
        minA[i] = 2000000000;
        maxB[i] = -2000000000;
        min_u[i] = 0;
    }

    // 6. อ่านถังเป้าหมาย และจัดลงกลุ่ม Root
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        int r = find_root(t); // หาก่อนว่าอยู่ตระกูลไหน
        active[r] = 1;
        
        // อัปเดตขอบเขตซ้ายสุดและขวาสุดที่กลุ่มนี้ต้องการ
        if (A_arr[t] < minA[r]) {
            minA[r] = A_arr[t];
            min_u[r] = t; // จำคนซ้ายสุดไว้เป็นจุดเริ่มต้นการกระโดด
        }
        if (B_arr[t] > maxB[r]) {
            maxB[r] = B_arr[t];
        }
    }

    // 7. หาถัง LCA ที่ต้องยกสำหรับแต่ละตระกูล
    for (int r = 1; r <= n; r++) {
        if (active[r]) {
            int u = min_u[r];
            int mb = maxB[r];
            int curr = u;
            
            // กระโดดแบบ Binary Lifting เพื่อหาถังที่ใหญ่พอจะคลุม max B
            for (int step = 17; step >= 0; step--) {
                int nxt = up[curr][step];
                // ถ้ากระโดดไปแล้ว ขอบเขตยังไม่ถึง max B ให้กระโดดต่อไป
                if (nxt != 0 && B_arr[nxt] < mb) {
                    curr = nxt;
                }
            }
            // พอถึงจุดนี้ curr อาจจะยังคลุมไม่มิด (ขาดอีกแค่ 1 ก้าว)
            if (B_arr[curr] < mb) {
                curr = up[curr][0];
            }
            
            ans[ans_cnt++] = curr; // เก็บถังนี้เข้าคำตอบ
        }
    }

    // 8. เรียงคำตอบจากน้อยไปมากและแสดงผล
    qsort(ans, ans_cnt, sizeof(int), cmp_int);
    printf("%d\n", ans_cnt);
    for (int i = 0; i < ans_cnt; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}