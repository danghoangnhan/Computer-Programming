#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	char *last;
	char *first;
	char *nick;
	char *age;
	char *gender;
	char *uni;
	char *dep;
};
typedef struct student Student;

	Student students[1000];
int main(){


printf("%-13s%-12s%-12s%-6s%-9s%-30s%s\n",
	"First Name",
	"Last Name",
	"Nick Name",
	"Age",
	"Gender",
	"University",
	"Department");

 for(int j=0;j<112;j++)
  printf("-");
  printf("\n");
  int count=0;
  char com[2]=",";
//char str[1000]="";
while(1){
	char str[1000]="";
	gets(str);
	if(str[0]=='\0')
		break;
	
 students[count].last = strtok(str, com);
 students[count].first = strtok(NULL, com);
 students[count].nick = strtok(NULL, com);
 students[count].age = strtok(NULL, com);
 students[count].gender = strtok(NULL, com);
 students[count].uni = strtok(NULL, com);
 students[count].dep = strtok(NULL, com);

 printf( "%-13s%-12s%-13s%-7s%-7c%-30s%s\n",
 	students[count].last,
 	students[count].first,
 	students[count].nick,
 	students[count].age,
 	students[count].gender[0],
 	students[count].uni,
 	students[count].dep);

count++;
 }
   for(int j=0;j<112;j++)
  printf("-");
     printf("\n");




}
