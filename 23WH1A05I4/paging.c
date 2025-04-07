#include<stdio.h>
#define PAGE_SIZE 4
#define TOTAL_PAGES 4
int main(){
	int pageTable[TOTAL_PAGES]={3,1,2,0};
	int la,pageNo,offset,pa;
	printf("enter logical address (page number*PAGE_SIZE+offset):");
	scanf("%d",&la);
	pageNo=la/PAGE_SIZE;
	offset=la%PAGE_SIZE;
	if(pageNo>=TOTAL_PAGES){
	printf("Error: Inavlid page number!\n");
	return 1;
	}
	int frameNo=pageTable[pageNo];
	pa=(frameNo*PAGE_SIZE)+offset;
	printf("logical address:%d\n",la);
	printf("page number:%d,offset:%d\n",pageNo,offset);
	printf("Frame number:%d\n",frameNo);
	printf("physical address:%d\n",pa);
	return 0;
	}
	
	
