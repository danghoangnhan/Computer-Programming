#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum Background{Sunny1,Cloudy2,Rainy3,Dungeon4,Water5}background;
typedef enum Block{Item1,Obstacle2,Enemy3,Player4}block;
typedef enum Item {RedMusroom1,GreenMusroom2,FireFlower3}item;
typedef enum Obstacle{Empty1,Brick2,Question3,Pipe4}obstacle;
typedef enum Enemy{Goomba1,Troopa2,Koopa3}enemy;
typedef enum Player{Mario1,Luigi2}player;

typedef union objective {
	item     inputItem;
	obstacle inputObstacle;
	enemy    inputEnemy;
	player   inputPlayer;
}specifie;

typedef struct fff{
	background dataBackground;
	block Object;
	specifie dataSpecifie;	
}data;

int main (){
	FILE *readPtr=fopen("test_input_Mario.txt","rb");
	FILE *writePtr=fopen("test_output_Mario.txt","w");


	data dataInput[30000];
	int count=0;
	while(!feof(readPtr)&&count<30000){
		fread(&dataInput[count],sizeof(data),1,readPtr);
		switch(dataInput[count].Object){
			case 0 : switch (dataInput[count].dataSpecifie.inputItem){

					case 0 : fprintf(writePtr,"%s","Red Mushroom");break;
					case 1 : fprintf(writePtr,"%s","Green Mushroom");break;
					default : fprintf(writePtr,"%s","Fire Flower");break;
				};break;

			case 1 : switch (dataInput[count].dataSpecifie.inputObstacle){
					case 0 : fprintf(writePtr,"%s","Empty");break;
					case 1 : fprintf(writePtr,"%s","Brick");break;
					case 2 : fprintf(writePtr,"%s","Question");break;
					default : fprintf(writePtr,"%s","Pipe");break;
				};break;

			case 2  : switch (dataInput[count].dataSpecifie.inputEnemy){
					case 0 :fprintf(writePtr,"%s","Goomba");break;
					case 1 :fprintf(writePtr,"%s","Troopa");break;
					default :fprintf(writePtr,"%s","Koopa");break;
  				};break;

  			default  : switch (dataInput[count].dataSpecifie.inputPlayer){
					case 0 :fprintf(writePtr,"%s","Mario");break;
					default :fprintf(writePtr,"%s","Luigi");break;
  				};break;
		}
		fprintf(writePtr,"%s"," in ");
		switch(dataInput[count].dataBackground){
			 		case 0 :fprintf(writePtr,"%s","Sunny Block");break;
					case 1 :fprintf(writePtr,"%s","Cloudy Block");break;
					case 2 :fprintf(writePtr,"%s","Rainy Block");break;
                    case 3 :fprintf(writePtr,"%s","Dungeon Block");break;
					default:fprintf(writePtr,"%s","Water Block");break;

	}
	if(count<30000-1){
		fprintf(writePtr,"%s","\n");
		


	}
	count++;
}


    fclose(readPtr);
    fclose(writePtr);
    return 0;
}
