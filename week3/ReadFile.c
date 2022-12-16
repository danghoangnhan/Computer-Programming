#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
 char  *last;
 char *first;
 char   *age;
 char  *nick;
 char *gender;
 char *university;
 char *department;

};

typedef struct student Student;

int main(){
 Student students; 
 int i=0;
 FILE *cfPtr;
 char str[100];
 char com[2] = ",";
if((cfPtr = fopen("test_input_ReadFile.txt","r")) == NULL ){
 puts("cough not input file ");
}
else {
 printf("%-13s%-12s%-12s%-6s%-9s%-30s%s\n","First Name","Last Name","Nick Name" ,"Age","Gender","University","Department");
 for(int j=0;j<112;j++)
  printf("-");
  printf("\n");
 
 while(!feof(cfPtr)){
 fgets(str, 100, cfPtr);
 students.last = strtok(str, com);
 students.first = strtok(NULL, com);
 students.nick = strtok(NULL, com);
 students.age = strtok(NULL, com);
 students.gender = strtok(NULL, com);
 students.university = strtok(NULL, com);
 students.department = strtok(NULL, com);

 printf( "%-13s%-12s%-13s%-7s%-7c%-30s%s\n",students.last,
 	students.first,
    students.nick,
    students.age,
    students.gender[0],
    students.university,
    students.department);

 }
   }
   fclose(cfPtr);
  for(int j=0;j<112;j++)
  printf("-");
     printf("\n");
}