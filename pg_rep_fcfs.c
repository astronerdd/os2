#include <stdio.h>

int main() {
    int n, f, i, j, k = 0, faults = 0;
    int pages[50], frame[10];

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    scanf("%d", &f);

    for(i = 0; i < f; i++) frame[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }
    }

    printf("%d", faults);
    return 0;
}