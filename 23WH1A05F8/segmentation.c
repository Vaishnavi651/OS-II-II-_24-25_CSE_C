#include<stdio.h>
int main(){
int n,nm,p,x=0,y=1,t=300,of,i;
printf("Enter the memory size:\n");
scanf("%d",&nm);
printf("Enter the number of segments:\n");
scanf("%d",&n);
int s[n],base[n];
for(i=0;i<n;i++){
printf("Enter the segment size of %d: ",i+1);
scanf("%d",&s[i]);
if(x+s[i]>nm){
printf("Memory full. Segment %d is not allocated.\n",i+1);
s[i]=0;
base[i]=-1;
}else{
base[i]=t+x;
x+=s[i];
}
}
printf("-----OPERATIONS------\n");
while(y==1){
printf("Enter the segment number:\n");
scanf("%d",&p);
if(p<1||p>n){
printf("Invalid segment number.\n");
}else if(s[p-1]==0){
printf("Segment %d is not allocated.\n",p);
}else{
printf("Enter the offset:\n");
scanf("%d",&of);
if(of>=s[p-1]){
printf("Offset out of range!\n");
}else{
printf("Segment %d physical address range: %d to %d\n",p,base[p-1],base[p-1]+s[p-1]-1);
printf("Address of operation: %d\n",base[p-1]+of);
}
}
printf("Press 1 to continue, 0 to exit:\n");
scanf("%d",&y);
}
return 0;
}

