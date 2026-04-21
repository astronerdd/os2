#include<stdio.h>

int main(){
    int ms, np, ns, rem, offset, pa;
    int seg_count[10];
    int base[10][10];
    int limit[10][10];


    printf("Enter memory size : \n");
    scanf("%d", &ms);

    printf("Enter no of process\n");
    scanf("%d", &np);

    for(int i =0; i<np; i++){
        printf("Enter no of segements for p[%d]: ");
        scanf("%d", &ns);

        for(int j=0; j<ns; j++){
            printf("Enter base address of p[%d]", j);
            scanf("%d", &base[i][j]);

            printf("Enter limit of p[%d]", j);
            scanf("%d", &limit[i][j]);

            if(base[i][j]+limit[i][j]> ms){
                printf("memory full!");
            }

            rem -= limit[i][j];

            if(rem<0){
                printf("mem out of bound exp");
            }
        }

        
    }
    printf("Enter logical address:\n");

}