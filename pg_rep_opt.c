#include <stdio.h>

int main() {
    int n, f, i, j, k, faults = 0;
    int pages[50], frame[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check hit
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page fault → apply Optimal
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

                // If page never used again → best to replace
                if(next == -1) {
                    pos = j;
                    break;
                }

                // Choose farthest future use
                if(next > farthest) {
                    farthest = next;
                    pos = j;
                }
            }

            if(pos == -1) pos = 0;

            frame[pos] = pages[i];
            faults++;
        }

        // Print current step
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