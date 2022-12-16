#include <stdio.h>
#include <stdlib.h>

void bitDisplay(unsigned int n);

int main()
{
    unsigned int a,b,c,d,m,ip,*A,*B,*C,*D,am,bm,cm,dm,mask;
    int N,cnt;
    int flag=0;
    FILE *r=fopen("test_input_Subnetwork.txt","r+");

    while(scanf("%d",&N)!=EOF)
    {

        if(N==0) break;
        if(flag==1) printf("\n");
        flag=1;
        A=(unsigned int *)malloc(N*sizeof(unsigned int));
        B=(unsigned int *)malloc(N*sizeof(unsigned int));
        C=(unsigned int *)malloc(N*sizeof(unsigned int));
        D=(unsigned int *)malloc(N*sizeof(unsigned int));

        scanf("%u.%u.%u.%u/%u",&am,&bm,&cm,&dm,&m);
        ip=(am<<24)+(bm<<16)+(cm<<8)+dm;
       mask=0;
        for(int i=31;i>=0;i--){
        	mask+=(1<<i);
        }
        //bitDisplay(mask);
        mask=mask<<(32-m);
        //bitDisplay(mask);
        cnt=0;
        for(int i=0;i<N;i++)
        {
            scanf("%u.%u.%u.%u",&a,&b,&c,&d);
            if((((a<<24)+(b<<16)+(c<<8)+d)&mask)==ip)
            {
            	 bitDisplay((((a<<24)+(b<<16)+(c<<8)+d)&mask));
            	  bitDisplay(ip);
                A[cnt]=a;
                B[cnt]=b;
                C[cnt]=c;
                D[cnt]=d;
                cnt++;
            }
        }


        for(int i=1;i<=80;i++) printf("-");
        printf("\n");

        printf("The following addresses are within the subnetwork %u.%u.%u.%u/%u:\n",am,bm,cm,dm,m);

        for(int i=0;i<cnt;i++)
        {
            printf("%u.%u.%u.%u\n",A[i],B[i],C[i],D[i]);
        }

        for(int i=1;i<=80;i++) printf("-");
        printf("\n");
    }

    free(A);
    free(B);
    free(C);
    free(D);

}
void bitDisplay(unsigned int n){

    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
    puts("\n");
} 

