#include<stdio.h>
#include<stdlib.h>
struct rectangle{
	float l;
	float w;
};
void area(float l,float w){
printf("The area is:%f\n",l*w);
}
void perimeter(float l,float w){
printf("The perimeter is:%f\n",2*l+2*w);
}
void check(float l,float w){
	if(l>0&&w>0&&l<20&&w<20){
		printf("Yes!!\n");
	}
	else{
		printf("No\n");
	}
}
int main(void){
	struct rectangle r;
		printf("Enter the length and the width:");
		scanf("%f %f",&r.l,&r.w);
	perimeter(r.l,r.w);
	area(r.l,r.w);
	check(r.l,r.w);
	
}