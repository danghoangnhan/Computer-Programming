#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int p,y;
	while(1){
		scanf("%d%d",&p,&y);
		if(p==-1||y==-1)
		break;
	 int x=1<<p;
	 int z=(x-1)&y;
	 if(z==0){
	 	printf("%d is a multiple of %d\n",y,x);
	 }
	 else{
	 	 	printf("%d is not a multiple of %d\n",y,x);
	 }
	}
	return 0;


}