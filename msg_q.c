#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    struct msg_buffer message;
    int msgid;

    key_t key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    message.msg_type = 1;

    printf("Enter message: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
    printf("Message sent\n");

    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
    printf("Message received: %s", message.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}