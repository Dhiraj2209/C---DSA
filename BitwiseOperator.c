//Hackerrank C probelm
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int andmax = 0 , ormax = 0 , xormax = 0;
  for(int i = 1 ; i <= n; i++){
      for(int b = i+1 ; b<= n ;b++){
          
          if(((i & b) < k) && andmax < (i & b)){
              andmax = (i&b);
          }
          if(((i | b) < k) && ormax < (i | b)){
              ormax = (i|b);
          }
          if(((i ^ b) < k) && xormax < (i ^ b)){
              xormax = (i ^ b);
          }
      }
  }
  printf("%d\n%d\n%d", andmax, ormax,xormax);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
