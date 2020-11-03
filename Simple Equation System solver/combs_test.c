#include <stdio.h>
int main() {
 

        char a[] = "4321";  //array
           int i, j;
           int f=24;        //factorial
           char c;          //buffer
          while (f--) {
          printf("%s\n", a);
          i=1;
          while(a[i] > a[i-1]) i++;
          j=0;
          while(a[j] < a[i])j++;
      c=a[j];
      a[j]=a[i];
      a[i]=c;
i--;
for (j = 0; j < i; i--, j++) {
  c = a[i];
  a[i] = a[j];
  a[j] = c;
      }
   }
}

int main() 
{ 
    int arr[] = {-3,-2,-1,0,1, 2, 3}; 
 //   int r = 2; 
 
    int r;
    scanf("%d",&r);

    //int num;
    //scanf("%d",&num);

    //int arr[1000];
    //int n = gen_arr(arr,num);

   int n = sizeof(arr)/sizeof(arr[0]); 
    
 //   printf("n==> %d\n",n);
    printCombination(arr, n, r); 
} 
