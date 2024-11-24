#include<stdio.h>
#include<string.h>
typedef struct{
	char partnum[20];
	char description[50];
	int quantity;
	float price;
}invoice;
invoice i;
void display(){
strcpy(i.partnum,"ABc123");
strcpy(i.description,"This is my favourite item");
i.price=20.50;
i.quantity=5;
float invoice_amount=i.price*i.quantity;
if(invoice_amount<0){
	invoice_amount=0;
}	
if(i.quantity<0){
	i.quantity=0;
}
printf("Invoice includes the following:\n");
printf("part number:%s , description: %s , quantity: %i , price:%.3f , invoice amount: %.3f\n",i.partnum,i.description,i.quantity,i.price,invoice_amount);

}
int main(){
	display();
	
	
	return 0;
}
