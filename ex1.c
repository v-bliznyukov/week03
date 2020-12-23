#include <stdio.h> 
int main(){
//creates a pointer to integer
int* pc;
//create integer
int c;
//assign integer
c=22;
//print out address of c using '&' operator
printf("Address of c:%d\n",&c); 
//print out
printf("Value of c:%d\n\n",c); 
//store the address of c in pc
pc=&c;
//prints out addres of pointer pc
printf("Address of pointer pc:%d\n",&pc); 
//prints out addres c with using pointer
printf("Address of c:%d\n",pc);
//prints the value pc is pointing to
printf("Content of pointer pc:%d\n\n",*pc); 
//change value of c
c=11;
//prints out addres of pointer pc
printf("Address of pointer pc:%d\n",&pc); 
//prints out addres c with using pointer
printf("Address of c:%d\n",pc); 
//now the value pointed by pointer changes
printf("Content of pointer pc:%d\n\n",*pc); 
//using * operator change the value with adress pc
*pc=2;
//address of c is unchanged
printf("Address of c:%d\n",&c);
//value is 2 now
 printf("Value of c:%d\n\n",c); 
 return 0;}