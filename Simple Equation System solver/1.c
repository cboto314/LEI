#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "our_ints.h"
#include "our_doubles.h"
#include "our_strings.h"
#include "our_doubles2.h"
#include "our_operators.h"

/////////////////////////////////////////////
//////Prob A

void get_system(int x, double **a);
void show_system(double **a, int n);

void get_system(int x,double **a){

  int cols = (x+1);
  doubles2_get(a,x,cols);

}

void show_system(double **a, int n){

 doubles2_printf("%12f",a,n,n+1);

}


void teste_A(){

  int rows;

  scanf("%d",&rows);
  double ** a = doubles2_new(rows,rows+1);

  get_system(rows,a);
  show_system(a,rows);


}
////////////////////////////////////////////
////////Prob B


/*
2
2 3 13
5 -1 7
0 0
1 2
2 3
3 2
5 1
*/


void mult(double **coefs, int rows, double * b, double *mults){
 
  int cols = rows;
  doubles2_multiply_by_array(coefs,rows,cols,b,mults);
  

}

void get_sols(double **a, int rows, double *sols){


  for(int i = 0; i < rows; i++)
    sols[i] = a[i][rows];


}

void get_coefs(double **a, int rows, double **coefs){

  doubles2_copy(a,rows,rows,coefs);

}

int is_solution(double **a, int rows, double *b){

  //double ** coefs = doubles2_new(rows,rows);
 // get_coefs(a,rows,coefs);

  double sols[rows];
  get_sols(a,rows,sols);


  double mults[rows];


    //mult(coefs,rows,b,mults);
    mult(a,rows,b,mults);
    int eq = doubles_equal(sols,rows,mults,rows);
    //printf("%d\n",eq);
    //free(coefs);
    return eq;
 
}

void teste_B(){

  int rows;

  scanf("%d",&rows);
  double ** a = doubles2_new(rows,rows+1);

  get_system(rows,a);

 
  double b[rows];

  while(doubles_get_some(b,rows)){

    printf("%d\n",is_solution(a,rows,b));

  }

 }
//////////////////////////////////////////////////////////////////////////

      ////////////////////////////////////////////
     //                                        //
    //            Prob C                      //
   //                                        //
  ////////////////////////////////////////////

int next_array(double *b, int n, int rows){

  double max_val = n;
  double min_val = -n;

      b[rows-1]++;
      for(int i = rows-1; i >= 0 ; i--){
        if(b[i] > max_val){
          if(i == 0){
            return -1;
          }
          else{
          b[i] = min_val;
          b[i-1]++;
          }
        }
        else
          break;
      }


  return 0;

}

void brute_force(double **a, int rows, int n){

 // int range = 2*abs(n)+1;
  //int t_tries = pow(rows,range);
  //double max_val = abs(n);
  double min_val = -1*abs(n);

  //double arr[range];
  //doubles_range(min_val,range,arr);

  double try[rows];
  doubles_fill(min_val,rows,try);
  int end = 0;

  /*
2
2 3 13
5 -1 7
3


  */

  while(!is_solution(a,rows,try) && end == 0){
      //printf("array ==> ");
      //doubles_println_special(try,rows);
      //printf("end ==> %d , i_s => %d \n",end,is_solution(a,rows,try));
      end = next_array(try,n,rows);

  }

  //printf("end ==> %d \n",end);


  if(end == 0)
    doubles_println(try,rows," ");
  else{
    printf("***\n");
  }

}


void teste_C(){


  int rows;

  scanf("%d",&rows);
  double ** a = doubles2_new(rows,rows+1);

  get_system(rows,a);
  //double *a[1000];

  int n;

  scanf("%d",&n);

  brute_force(a,rows,n);

}

/////////////////////////////////////////////

////////////////////////////////////////////
//                                       //
//              C 2                     //
//                                     //
////////////////////////////////////////

int next_array2(double *b, int n, int rows){

 // double max_val = 2*n+1;
 // double min_val = 0;

      b[rows-1]++;
      for(int i = rows-1; i >= 0 ; i--){
        if(b[i] > n){
          if(i == 0){
            return -1;
          }
          else{
          b[i] = 0-n;
          b[i-1]++;
          }
        }
        else
          break;
      }


  return 0;

}

void brute_force2(double **a, int rows, int n){

  //double min_val = -1*abs(n);

  double try[rows];
  doubles_fill(0-n,rows,try);
  int end = 0;

 /*
2
2 3 13
5 -1 7
3
*/



  while(!is_solution(a,rows,try) && end == 0){
  //while(end == 0){
      doubles_println_special(try,rows);
      end = next_array2(try,n,rows);
  }

      doubles_println_special(try,rows);

  if(end == 0)
    doubles_println(try,rows," ");
  else{
    printf("***\n");
  }

}


void teste_C2(){


  int rows;

  scanf("%d",&rows);
  double ** a = doubles2_new(rows,rows+1);

  get_system(rows,a);

  int n;

  scanf("%d",&n);

  brute_force2(a,rows,n);

}

////////////////////////////////////////////

     ///////////////////////////////////////////
    //                                       //
   //           Prob D                      //
  //                                       //
 ///////////////////////////////////////////


void columnize(double **a, int n, int x); 
void subtract_row(double **a, int n, int x);

void columnize(double **a, int n, int x){

  int rows = n;
  int cols = rows + 1;



  for(int i = 0; i < rows; i++){
    double div;
    if(a[i][x])
      div = a[i][x];

    
    else
      div = 1;
    //printf("**div = > %f, i ==> %d\n",div,i);
    for(int j = 0; j < cols; j++){
      a[i][j] = a[i][j] / div;
    }
    }
  
}

void subtract_row(double **a, int n, int x){

  int rows = n;
  int cols = rows+1;

    for(int i = 0; i < rows; i++){
      if(a[i][x]!=0)
      for(int j = 0; j < cols; j++){
        if((i != x))
          a[i][j] = (-1)*a[x][j] + a[i][j];
      }
    }

}

void get_coefs_array(double **a, int rows, double *coefs){

  for(int i = 0; i < rows; i++)
    coefs[i] = a[i][rows];

}

void teste_D(){


  int rows;

  scanf("%d",&rows);

  double ** a = doubles2_new(rows,rows+1);

  get_system(rows,a);

  for(int x = 0; x < rows; x++){
    columnize(a,rows,x);
      //  show_system(a,rows);
   // printf("\n");
    if(a[x][x]!=0)
    subtract_row(a,rows,x);
   // show_system(a,rows);
   //printf("\n");
  }

   for(int x = 0; x < rows; x++)
    columnize(a,rows,x);
  

  double s[rows];
  get_coefs_array(a,rows,s);

  doubles_println(s,rows," ");

}

////////////////////////////////////////////
///////////////////////////////////////////

      //////////////////////////////////////////
     //                                      //
    //             Prob E                   //
   //                                      //
  //////////////////////////////////////////

void epsilonify(double **a, int n, double epsilon);

void epsilonify(double **a, int n, double epsilon){

//  printf("epsilon = %16f\n",epsilon);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n+1; j++)
      if(fabs(a[i][j]) < epsilon)
        a[i][j] = 0;
}

//10^-13

// error: print an error message and die. From K&R, page 174. 

void error() {
  
   fprintf(stdout, "System is impossible or indeterminate. Computation halted.\n");   
   exit(0); 
 }
/*
int verificar(double **a, int rows){

  for(int j = 0; j < rows+1; j++){
    int check = 0;
    for(int i = 0; i < rows; i++){
     if(a[i][j] == 0)
      check++;
    }
    if(check == rows+1)
      return 1;
  }
  return 0;

}*/

 int scan(double **a, int rows, int x){

  if(a[x][x]==0){
    for(int i = x+1; i < rows; i++)
      if(a[i][x] != 0){
        doubles2_exchange_rows(a,x,i);
      //  printf("exchange:\n");
        //show_system(a,rows);
        //printf("\n");
        return 0;
      }
    error();
    }

  //error();
  return 0;

 }

int procurar_linha(double **a, int rows, int x){
  for(int i = 0; i < rows; i++)
    if(a[i][x]!=0)
      return i;
  return -1;
}

/*void trocar_linha(double **a, int rows, int x){

 // for(int i = x; i < rows; i++)
  int k = procurar_linha(a,rows,x);

  doubles2_exchange_rows(a,x,k);

}*/

void teste_E(void){

  int rows;

  scanf("%d",&rows);

  double ** a = doubles2_new(rows,rows+1);

  get_system(rows,a);

  int cols = rows;

  for(int x = 0; x < cols; x++){
    //if(verificar(a,cols))
      //error();
       scan(a,rows,x);
    columnize(a,cols,x);
    //falta: trocar a linha subrativa
      //    show_system(a,rows);
      //printf("\n");
    //if(a[x][x] == 0)
     //trocar_linha(a,rows,x);
    subtract_row(a,rows,x);
    epsilonify(a,rows,1e-13);
    //  show_system(a,rows);
      //printf("\n");

  }

   for(int x = 0; x < rows; x++)
    columnize(a,rows,x);

  //show_system(a,rows);

  double s[rows];
  get_coefs_array(a,rows,s);

  doubles_println(s,rows," ");


}

////////////////////////////////////////////

int main(int argc, char ** argv){
	
 char x = 'A';
  if (argc > 1)
    x = *argv[1];


  if (x == 'A')
    teste_A();
  else if (x == 'B')
  	teste_B(argc,argv);
  else if (x == 'C')
  	teste_C(argc,argv);
  else if (x == 'D')
  	teste_D(argc,argv);
  else if (x == 'E')
    teste_E();


  return 0;
	

}