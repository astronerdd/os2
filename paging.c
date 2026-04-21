#include<stdio.h>

int main(){
    int ms, ps, nop, np, rempg;
    int pa, offset;
    int x, y;
    int s[10], fno[10][20];

    printf("Enter memory size: \n");
    scanf("%d", &ms);
    printf("Enter paging size: \n");
    scanf("%d", &ps);

    nop = ms/ps;
    printf("The number of pages avail are: %d\n", nop);

    printf("Enter no of process: \n");
    scanf("%d", &np);

    rempg = nop;

    for(int i = 0; i< np; i++){
        printf("Enter no of pages for process p[%d]\n", i);
        scanf("%d", &s[i]);

        if(s[i]>rempg){
            printf("Memory Full\n");
            break;
        }

        rempg -= s[i];

        printf("Enter page table:\n");
        for(int j = 0; j<s[i]; j++){
            scanf("%d", &fno[i][j]);
        }
    }

    printf("Enter logical address: \n");
    printf("Enter p_no, pg_no and offset: ");
    scanf("%d %d %d", &x, &y, &offset);

    if(x>= np || y>=s[x] || offset>ps){
        printf("INVALID!");
    }
    else{
        pa = fno[x][y]*ps + offset;
        printf("Physical address is :", pa);
    }
}