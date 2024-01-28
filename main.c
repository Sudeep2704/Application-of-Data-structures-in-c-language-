#include <stdio.h>
int main()
{

int marks[6]= {20,30,40,50,60,70};
float avg;
int i;
for(i=0; i<6; i++){
avg=avg + marks[i];
}
avg=avg/6.0;
printf("%f" avg);
return 0;


}