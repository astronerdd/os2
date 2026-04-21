#include <stdio.h>

int main() {
    int n, f, i, j, k, faults = 0;
    int pages[50], frame[10], time[10], t = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in frame
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                time[j] = ++t;   // update recent use
                break;
            }
        }

        // If not found → replace LRU
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

        // Print current state
        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }

        if(found)
            printf("\tHit\n");
        else
            printf("\tFault\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}