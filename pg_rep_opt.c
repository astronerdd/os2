#include <stdio.h>

int main() {
    int n, f, i, j, k, faults = 0;
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
            int pos = -1, farthest = i + 1;

            for(j = 0; j < f; j++) {
                int next = -1;
                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        next = k;
                        break;
                    }
                }
                if(next == -1) {
                    pos = j;
                    break;
                }
                if(next > farthest) {
                    farthest = next;
                    pos = j;
                }
            }

            if(pos == -1) pos = 0;

            frame[pos] = pages[i];
            faults++;
        }
    }

    printf("%d", faults);
    return 0;
}