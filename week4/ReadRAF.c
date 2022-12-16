#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Information{
	char firstName[20];
	char lastName[20];
	char nickName[20];
	unsigned int  age;
	char gender;
	char university[50];
	char department[50];
}profile;

int main(){
	FILE *readPtr;
	puts("file not yet");
	if((readPtr=fopen("test_input_ReadRAF.txt","rb"))==NULL)
		puts("file not found");
	
	else{
		puts("file found");

		int count=0;
		profile student[30000];

		printf("%s%s%s%d%s%s%s\n",
			"First Name",
			"Last Name",
			"Nick Name",
			"Age","Gender",
			"University",
			"Department");

		for(int i=0;i<112;i++)
			printf("-");
		    printf("\n");

		while(!feof(readPtr)&&count<30000){
			fread(&student[count],sizeof(profile),1,readPtr);

			printf("%s%s%s%d%s%s%s",
				student[count].firstName,
				student[count].lastName,
				student[count].nickName,
				student[count].age,
				student[count].gender,
				student[count].university,
				student[count].department);

			count++;

		}
		 printf("\n");
		for(int i=0;i<112;i++)
			printf("-");

		 printf("\n");



	}
	fclose(readPtr);
	return 0;
}