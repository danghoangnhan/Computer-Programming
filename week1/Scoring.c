#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int i;
	int count=0;
	while(1){
		int number;
		scanf("%d",&number);
		int i,j;
		if(number==0)
		break;
		int scor[101][3];
		double avg [5]={0.0},std[5]={0.0};
		double raw[101],adj[101];
		double avgs[5]={0.0};
		for(i=0;i<number;i++){
			for(j=0;j<3;j++){
				scanf("%d",&scor[i][j]);
			}
			raw[i]=(scor[i][0]*0.3+scor[i][1]*0.3+scor[i][2]*0.4);
			adj[i]=pow(raw[i],0.4)*12+25;
		}
		for(i=0;i<3;i++){
			for(j=0;j<number;j++){
			avg[i]+=scor[j][i];
			avgs[i]+=scor[j][i]*scor[j][i];
	    	}
		}
		//for(i=0;i<3;i++){
			for(j=0;j<number;j++){
			avg[3]+=raw[j];
			avg[4]+=adj[j];
			avgs[3]+=raw[j]*raw[j];
			avgs[4]+=adj[j]*adj[j];

	    	}

		//}
		for(i=0;i<5;i++){
			avg[i]/=number;
			avgs[i]/=number;
			std[i]=sqrt(avgs[i]-avg[i]*avg[i]);
		//std[i]=sqrt(avg[i]);
	}
		for(i=0;i<74;i++)
			printf("*");

		printf("\n%s%14s%15s%13s%12s%17s\n","Num","Assignments","Midterm Exam","Final Exam","Raw Score","Adjusted Score");

			for(i=0;i<74;i++)
			printf("*");

		for(i=1;i<=number;i++)
			printf("\n%d%d%d%14d%15d%13d%12lf%17lf\n",i/100,(i%100)/10,i%10,scor[i-1][0],scor[i-1][1],scor[i-1][2],raw[i-1],adj[i-1]);

		for(i=0;i<74;i++)
			printf("*");

			printf("\n%s%14lf%15lf%13lf%12lf%17lf\n","AVG",avg[0],avg[1],avg[2],avg[3],avg[4]);
			printf("%s%14lf%15lf%13lf%12lf%17lf\n","STD",std[0],std[1],std[2],std[3],std[4]);
			for(i=0;i<74;i++)
			printf("*");
			count++;
				printf("\n");
			if(count>1)
			printf("\n");
	}
	return 0;
}
