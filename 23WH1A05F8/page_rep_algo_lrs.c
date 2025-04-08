#include<stdio.h>
int main(){
int n,f,i,j,k,p[50],a[10],count=0,used[10],min,pos;
printf("Enter number of pages: ");
scanf("%d",&n);
printf("Enter the reference string:\n");
for(i=0;i<n;i++)scanf("%d",&p[i]);
printf("Enter number of frames: ");
scanf("%d",&f);
for(i=0;i<f;i++)a[i]=-1;
printf("\nPage\tFrames\n");
for(i=0;i<n;i++){
int found=0;
for(j=0;j<f;j++){
if(a[j]==p[i]){
found=1;
break;
}
}
if(!found){
if(count<f){
a[count++]=p[i];
}else{
for(j=0;j<f;j++){
used[j]=0;
for(k=i-1;k>=0;k--){
if(a[j]==p[k]){
used[j]=k;
break;
}
}
}
min=used[0];pos=0;
for(j=1;j<f;j++){
if(used[j]<min){
min=used[j];
pos=j;
}
}
a[pos]=p[i];
}
}
printf("%d\t",p[i]);
for(j=0;j<f;j++)printf("%d ",a[j]);
printf("\n");
}
return 0;
}

