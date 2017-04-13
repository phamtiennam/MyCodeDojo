
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's total cost.
//Author: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_13
#include <stdio.h>

float cal_percent(float a,int b){
	float result;
	result = (a*b)/100;
	return result;
}
int sum_all(float a,float b,float c){
	int sum;
	sum=a+b+c;
	return sum;
}
int main(){
	float meal_price,post_tip,post_tax;
	int tip_percent,tax_percent;

	scanf("%f", &meal_price);
	scanf("%d", &tip_percent);
	scanf("%d", &tax_percent);

	post_tip=cal_percent(meal_price,tip_percent);
	post_tax=cal_percent(meal_price,tax_percent);

	printf("The total meal cost is %d dollars.\n", sum_all(meal_price,post_tip,post_tax));
	return 0;
}
