#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	FILE *file;
	FILE *copy;
	file=fopen("file.txt","r");
	copy=fopen("copy.txt","w");
	if(file==NULL||copy==NULL){
		printf("Error in opening file\n");
		return 1;
	}
	char c;
	while((c=fgetc(file))!= EOF){
	        fputc(islower(c) ? toupper(c) : c, copy);
	}
	fclose(file);
	fclose(copy);
}
