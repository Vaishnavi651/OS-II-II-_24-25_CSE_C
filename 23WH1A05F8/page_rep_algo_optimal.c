#include<stdio.h>
int main(){
int n,f,p[50],a[10],i,j,k,pos,max,count=0,next[10];
printf("Enter number of pages: ");
scanf("%d",&n);
printf("Enter reference string:\n");
for(i=0;i<n;i++)scanf("%d",&p[i]);
printf("Enter number of frames: ");
scanf("%d",&f);
for(i=0;i<f;i++)a[i]=-1;
printf("\nPage\tFrames\n");
for(i=0;i<n;i++){
int hit=0;
for(j=0;j<f;j++){
if(a[j]==p[i]){
hit=1;
break;
}
}
if(!hit){
if(count<f)a[count++]=p[i];
else{
for(j=0;j<f;j++){
next[j]=1000;
for(k=i+1;k<n;k++){
if(a[j]==p[k]){
next[j]=k;
break;
}
}
}
max=next[0];pos=0;
for(j=1;j<f;j++)if(next[j]>max){max=next[j];pos=j;}
a[pos]=p[i];
}
}
printf("%d\t",p[i]);
for(j=0;j<f;j++)printf("%d ",a[j]);
printf("\n");
}
return 0;
}

