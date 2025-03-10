#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int mutex = 1;
int empty;
int full=0;
int x=0;
void producer(){
        --mutex;
        ++full;
        --empty;
        x++;
        printf("Producer produces item :%d\n",x);
        ++mutex;
}
void consumer(){
        --mutex;
        ++empty;
        --full;
        printf("Consumer consumes item:%d\n",x);
        x--;
        ++mutex;
}
int main(){
        int n,i;
        printf("Enter the buffer size");
        scanf("%d",&empty);
        while(1){
        printf("\nthe options are:");
        printf("\n1.produce\n2.consume\n3.exit\n");
                printf("Enter the choice:");
                scanf("%d",&n);
                switch(n){
                        case 1:
                                if((mutex==1) && (empty !=0)){
                                        producer();
                                }
                                else{
                                        printf("\nbuffer is full\n");
                                }
                                break;
                        case 2:
                                if((mutex ==1) && (full!=0)){
                                                consumer();
                                }
                                else{
                                        printf("\nbuffer is empty\n");
                                }
                                break;
                        case 3:
                                exit(0);
                                break;
                        default:
                                printf("Invalid input");

                }
        }
}
