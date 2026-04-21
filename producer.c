#include <stdio.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0, count = 0;

void produce(int item) {
    if(count == SIZE) {
        printf("Buffer Full\n");
        return;
    }

    buffer[in] = item;
    in = (in + 1) % SIZE;
    count++;

    printf("Produced: %d\n", item);
}

void consume() {
    if(count == 0) {
        printf("Buffer Empty\n");
        return;
    }

    int item = buffer[out];
    out = (out + 1) % SIZE;
    count--;

    printf("Consumed: %d\n", item);
}

int main() {
    produce(1);
    produce(2);
    produce(3);

    consume();
    consume();

    produce(4);
    consume();

    return 0;
}