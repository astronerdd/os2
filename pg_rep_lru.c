#include <stdio.h>

int main() {
    int n, f, i, j, k, faults = 0;
    int pages[50], frame[10], time[10], t = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                time[j] = ++t;
                break;
            }
        }

        if(!found) {
            int min = time[0];
            k = 0;
            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    k = j;
                }
            }
            frame[k] = pages[i];
            time[k] = ++t;
            faults++;
        }
    }

    printf("%d", faults);
    return 0;
}