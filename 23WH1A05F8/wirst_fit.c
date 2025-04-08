#include<stdio.h>
#define max 25
void main(){
int frag[max],b[max],f[max],i,j,nb,nf,temp;
static int bf[max],ff[max];
printf("\n\tMemory Management Scheme - Worst Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of files:");
scanf("%d",&nf);
printf("Enter the size of the blocks:-\n");
for(i=0;i<nb;i++){
printf("Block %d:",i+1);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n");
for(i=0;i<nf;i++){
printf("File %d:",i+1);
scanf("%d",&f[i]);
}
for(i=0;i<nf;i++){
int highest=-1;
for(j=0;j<nb;j++){
if(bf[j]!=1){
temp=b[j]-f[i];
if(temp>=0&&temp>highest){
ff[i]=j;
highest=temp;
}
}
}
frag[i]=highest;
bf[ff[i]]=1;
}
printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
for(i=0;i<nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,f[i],ff[i]+1,b[ff[i]],frag[i]);
}

