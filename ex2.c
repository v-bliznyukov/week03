#include <stdio.h>
//function to swap two elements uses passing by reference
void swap(int* x, int* y){
  //cheate temp variable
  int t;
  t=*x;
  *x=*y;
  *y=t;
}
//main function
void bubble_sort(int array[], int n){
  int i;
  int j;
  //pops the biggest element in the array to the end, reduces the 'size' by one and performs the same operation again (finding the biggest element)
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++){
      if (array[j]>array[j+1]){
        swap(&array[j], &array[j+1]);
      }
    }
  }
  //prints sorted array 
  printf("Sorted array is:\n");
  for (int k=0; k<n;k++){
    printf("%d", array[k]);
    printf("\t");
  }
}
int main(void) {
  //asks user to type in the size
  printf("What's the size of the array:\n");
  int n;
  scanf("%d", &n);
  //create an array of size n
  int array[n];
  //scans n elements from user input
  printf("What are the elements of the array:\n");
  for (int i=0; i<n; i++){
    scanf("%d", &array[i]);
  }
  //call the function
  bubble_sort(array, n);
  return 0;
}