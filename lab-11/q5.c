#include<stdio.h>
#include<string.h>
typedef struct{
	char area[6];
	char exchange[6];
	char number[8];
	char phone1[20];
	char phone2[15];
}phone;

phone p;
void display(){
	printf("Enter display area:");
	scanf("%5s",p.area);
		printf("Enter display exchange:");
	scanf("%5s",p.exchange);
		printf("Enter display number:");
	scanf("%7s",p.number);
	 strcpy(p.phone1, "(212) 767-8900");
	printf("My phone number is : %s\n",p.phone1);
	printf("Your phone number is: (%s) %s-%s\n",p.area,p.exchange,p.number);
	
}
int main(){
	display();
	return 0;
}
