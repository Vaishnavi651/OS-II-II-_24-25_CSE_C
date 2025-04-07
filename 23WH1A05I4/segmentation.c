#include<stdio.h>
#define TOTAL_SEGMENTS 3
struct segment{
	int base;
	int limit;
	};
int main(){
	struct segment segTable[TOTAL_SEGMENTS]={
	{100,500},{700,300},{1200,200}};
	int segNo,offset,pa;
	printf("enter segment number and offset:");
	scanf("%d %d",&segNo,&offset);
	if(segNo>=TOTAL_SEGMENTS||segNo<0){
	printf("Error:invalid segment number!\n");
	return 1;
	}
	if(offset>=segTable[segNo].limit){
	printf("segmentation fault! offset out of bounds.\n");
	return 1;
	}
pa=segTable[segNo].base+offset;
printf("segment number:%d,offset:%d\n",segNo,offset);
printf("Base address:%d,limit:%d\n",segTable[segNo].base,segTable[segNo].limit);
printf("physical address:%d\n",pa);
return 0;
}
