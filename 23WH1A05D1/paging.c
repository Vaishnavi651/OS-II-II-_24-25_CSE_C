#include<stdio.h>
int main()
{
int pageTable[20];
int n;

printf("Enter number of pages:");
scanf("%d",&n);

printf("Enter the frame number of each page:");
for(int i=0;i<n;i++){
	printf("Page[%d]",i);
	scanf("%d",&pageTable[i]);
	}

int logicalAddress;
int pageSize;

printf("Enter page size:");
scanf("%d",&pageSize);
printf("Enter logical address");
scanf("%d",&logicalAddress);

int pageNumber=logicalAddress/pageSize;
int offSet=logicalAddress%pageSize;

int frameNumber=pageTable[pageNumber];
int physicalAddress=(frameNumber*pageSize)+offSet;

printf("Logical address:%d\n",logicalAddress);
printf("Page number:%d,Offset:%d\n",pageNumber,offSet);
printf("Frame number:%d\n",frameNumber);
printf("Physical Address is:%d",physicalAddress);

return 0;

}	
