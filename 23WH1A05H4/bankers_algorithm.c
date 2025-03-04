#include<stdio.h>
#include<stdbool.h>
int main()
{
int p,r,count=0,i,j;
printf("Enter number of processes: ");
scanf("%d",&p);
printf("Enter number of resources: ");
scanf("%d",&r);
int a[p][r],max[p][r],need[p][r],available[r],safe[p],finish[p],completed=0;
printf("Enter allocation matrix: ");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&a[i][j]);
}
}


printf("Enter max matrix: ");
for( i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
}

printf("Enter available instances of resources: ");
for(i=0;i<r;i++)
scanf("%d",&available[i]);


for( i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-a[i][j];
}
}

for( i=0;i<p;i++)
finish[i]=0;



while(count<p)
{

for( i=0;i<p;i++)
{
if(finish[i]==0)
{

for(j=0;j<r;j++)
{
if(need[i][j]>available[j])
break;
}
if(j==r)
{

safe[count]=i;
finish[i]=1;
for(j=0;j<r;j++)
{
available[j]+=a[i][j];
}
count++;
completed=0;
}
else
completed++;
}
}
if(completed==(p-1))
{
printf("Unsafe state");
break;
}
}
if(completed!=(p-1))
{

printf("Safe state\nSafe sequence is: ");
for(i=0;i<p;i++)
printf("%d-->",safe[i]);
}

return 0;
}
