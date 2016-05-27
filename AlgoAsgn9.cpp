/* 
| ----------------------------------------------
|  Purpose: Algorithms Program #9 - Travelling Salesman Problem - Branch and Bound
|  Author:  Kathy (Thy) Dai
| ----------------------------------------------
| Sources:
| http://www.sanfoundry.com/cpp-program-implement-traveling-salesman-nearest-neighbour-algorithm/
*/

#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int c;
int cost;

int graph[101][101];

// function to switch array x and array y
void swap (int *x, int *y){
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

void copy_array(int *a, int n){
   int sum = 0;

   for(int i = 0; i <= n; i++)
      sum += graph[a[i % (n+1)]][a[(i + 1) % (n+1)]];

   if (cost > sum)
      cost = sum;
}  

void permute(int *a, int i, int n) { 
   if (i == n)
      copy_array(a, n);
   else{
      for (int j = i; j <= n; j++){
         swap((a + i), (a + j));
         permute(a, i + 1, n);
         swap((a + i), (a + j));
      }
   }
}
 
int main(){
   int N;
   int cities;
   cin >> N;

   for(int input = 0; input < N; input++){
      cin >> cities;

      int a[cities];
      for(int i = 0; i < cities; i++){
         a[i] = i;
      }

      c = 0;
      cost = INT_MAX;

      for(int row = 0; row < cities; row++){
         for(int col = 0; col < cities; col++){
            cin >> graph[row][col];
         }
      }

      permute(a, 0, cities-1);
      cout << cost << endl;

      // output graph 2D array
      // for(int row = 0; row < cities; row++){
      //    for(int col = 0; col < cities; col++){
      //       cout << graph[row][col] << " ";
      //    }
      //    cout << endl;
      // }
      // cout << endl;

   }
   return 0;
}
