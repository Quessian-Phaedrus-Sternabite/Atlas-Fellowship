/// Code of Ian Kelley for the Atlas Fellowship Problems
#include <stdio.h>
#include <stdlib.h>

#define SIZE 312500000

typedef struct {
    int You;
    int A;
    int B;
    int C;
    int D;
} Row;

int main() {
    Row* out = (Row*)malloc(SIZE * sizeof(Row));
    if (out == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Init\n");
    printf("DF Init\n");

    int count = 0;
    long long sumScore[50] = {0};
    int maxScore[50] = {0};
    double avgScore[50] = {0.0};

    for (int i = 0; i < 50; i++) {
        for (int i2 = 0; i2 < 50; i2++) {
            for (int i3 = 0; i3 < 50; i3++) {
                for (int i4 = 0; i4 < 50; i4++) {
                    for (int i5 = 0; i5 < 50; i5++) {
                        int p = 50 - (i + i2 + i3 + i4 + i5);
                        if (p >= 0) {
                            long long score = (long long)p * (long long)i;
                            count++;
                            out[count].You = i;
                            out[count].A = i2;
                            out[count].B = i3;
                            out[count].C = i4;
                            out[count].D = i5;
                            sumScore[i] += score;
                            if (score > maxScore[i]) {
                                maxScore[i] = score;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 50; i++) {
        avgScore[i] = (double)sumScore[i] / (double)count;
    }

    for (int i = 0; i < 50; i++) {
        printf("Average highest score for You = %d: %f\n", i, avgScore[i]);
    }

    free(out);

    return 0;
}
