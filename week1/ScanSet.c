#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
 int a;
 a = 0;
 while (true) {
        char reg1[50], r[1000], s[10000]="", Scanset[50] = "", first[50] = "%[";
    char second[50] = "]";
     char n[50];
        char sign[50]="%[^";
        char Scanset2[50]= "",t[10000]="", sign2[50] = "]";
  scanf("%s", reg1);
  if (reg1[0] =='*') {
   break;
  }
  strcpy(n,reg1);
  strcat(Scanset, first);
  strcat(Scanset, reg1);
  strcat(Scanset, second);
  scanf("%s",r);
  sscanf(r, Scanset, s);
  if (strcmp(s,"") == 0) {
   strcat(Scanset2, sign);
   strcat(Scanset2, n);
   strcat(Scanset2, sign2);
   sscanf(r, Scanset2, t);
   printf("%s\n", t);
  }else{
   printf("%s\n",s);

  }




 }






}