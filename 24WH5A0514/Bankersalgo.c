#include<stdio.h>

int main(){
int np, nr;
printf("Enter the no.of processes:");
scanf("%d", &np);

printf("Enter the no.of resources:");
scanf("%d" , &nr);


 int r[nr], p[np],a[np][nr], m[np][nr], n[np][nr],av[nr],com[np],ans[np],k=0;
 
 
printf("Enter the processes :");
for(int i=0;i<np;i++)
scanf("%d" , &p[i]);





printf("Enter the instances of each resource:");
for(int i=0;i<nr;i++)
scanf("%d" , &r[i] );

printf("Allocation matrix: \n");
for(int i=0;i<np;i++){
 printf("Enter the allocates resources for process %d :",i+1);
 for(int j=0;j<nr;j++){
  scanf("%d", &a[i][j] );
  }
 }

printf("Max matrix:\n ");
for(int i=0;i<np;i++){
 printf("Enter the maximum resources that can be allocated for process %d :",i+1);
 for(int j=0;j<nr;j++){
  scanf("%d", &m[i][j] );
  }
 }
 
 /*
 for(int i=0;i<np;i++)
 printf("%d ",p[i]);
 printf("\n");

  for(int i=0;i<nr;i++)
 printf("%d ",r[i]);
 printf("\n");
 
 for(int i=0;i<np;i++){
 for(int j=0;j<nr;j++){
  printf("%d ", a[i][j] );
  }
  printf("\n");
 }
 
 for(int i=0;i<np;i++){
 for(int j=0;j<nr;j++){
  printf("%d ", m[i][j] );
  }
  printf("\n");
 } */
 
 for(int i=0;i<np;i++){
   for(int j=0;j<nr;j++){
    n[i][j] = m[i][j] - a[i][j];
    }
   }
   
  for( int j=0;j<nr;j++){
   int sum=0;
   for(int i=0;i<np;i++){
    sum+= a[i][j];
    }
    av[j] = r[j] - sum;
   }

printf("\n");

 /*for(int i=0;i<nr;i++)
 printf("%d ",av[i]);
 printf("\n");
 
  for(int i=0;i<np;i++){
 for(int j=0;j<nr;j++){
  printf("%d ", n[i][j] );
  }
  printf("\n");
 }*/
 
 for(int i=0;i<np;i++)
 com[i]=0;
for(int x=0;x<np;x++){ 
for(int i=0;i<np;i++){
 int c=0;
 for(int j=0;j<nr;j++){
  if(n[i][j] <= av[j] && com[i] ==0){
    c++;
    }
  }
  if(c== nr){
   com[i]=1;
   ans[k] = p[i];
   k++;
   for(int j=0;j<nr;j++){
     av[j] += a[i][j];
    }
   }
   }
  }
  /*printf("available:");
  for(int i=0;i<nr;i++)
 printf("%d ",av[i]);
 printf("\n");
 
 printf("seq:");
 for(int i=0;i<np;i++)
 printf("%d ",ans[i]);
 printf("\n"); */
 int var=1;
 for(int i=0;i<np;i++){
  if(com[i] ==0)
   var=0;
 
 }
 if(var == 1){
  printf("Safe state:");
  for(int i=0;i<np;i++)
   printf("%d " ,ans[i]);
 }
 
else{
 printf("Deadlock");
}
  
  }
