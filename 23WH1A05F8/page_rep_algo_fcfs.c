#include<stdio.h>
int fsize,frm[15];
void display();
int main(){
int pg[100],nPage,i,j,pf=0,top=0,flag=0;
printf("Enter frame size:");
scanf("%d",&fsize);
printf("Enter number of pages:");
scanf("%d",&nPage);
for(i=0;i<nPage;i++){
printf("Enter page[%d]:",i+1);
scanf("%d",&pg[i]);
}
for(i=0;i<fsize;i++)frm[i]=-1;
printf("\nPage\tFrames");
printf("\n------------------");
for(j=0;j<nPage;j++){
flag=0;
for(i=0;i<fsize;i++){
if(frm[i]==pg[j]){
flag=1;
break;
}
}
if(flag==0){
frm[top]=pg[j];
top=(top+1)%fsize;
pf++;
}
printf("\n%d\t",pg[j]);
display();
}
printf("\n------------------");
printf("\nTotal Page Faults: %d",pf);
return 0;
}
void display(){
int i;
for(i=0;i<fsize;i++)printf("%d ",frm[i]);
}

