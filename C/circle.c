#include<stdio.h>
#include<assert.h>
float calArea(int radius);
float calVolume(int radius);
void menu();
int main()
{
	int no,radi;
	float area2,volume2;
	assert(calArea(7) == 154.0);
	assert(calVolume(21) == 38808.0);
	menu();
	printf("*****What do you want to calculate..*****\n");
	printf("please enter no( 1 or 2):-");
	scanf("%d",&no);
	if(no == 1)
	{
		printf("please enter radius");
		scanf("%d",&radi);
		area2 = calArea(radi);
		printf("Area of circle is %.1f",area2);
	}
	else if(no == 2)
	{
		printf("please enter radius");
		scanf("%d",&radi);
		volume2 = calVolume(radi);
		printf("volume of sphere is %.1f",volume2);
	}
	else
	{
		printf("wrong choice\n");
	}
	return 0;
}
float calArea(int radius)
{
	float area;
	area = (radius * radius * 22.0)/7.0;
	return area;
}
float calVolume(int radius)
{
	float volume;
	volume = (4 * radius * radius * radius * 22.0)/(3.0 * 7.0);
	return volume;
}
void menu()
{
	printf("1.Calculate the area of circle\n");
	printf("2.Calculate the volume of sphere\n");
	return;	
}
