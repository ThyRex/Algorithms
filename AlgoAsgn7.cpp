/* 
| ----------------------------------------------
|  Purpose: Algorithms Program #7 - Knapsack Shopping
|  Author:  Kathy (Thy) Dai
| ----------------------------------------------
| Sources:
| http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
| Recycled parts Algorithms Program #5
*/

#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int knapSack(int W, int wt[], int val[], int n){
   int i, w;
   // create the 2D table which has rows: num of Objects incl 0
   // and columns: max Weight + incl 0
   int P[n+1][W+1];

   for (i = 0; i <= n; i++){
      for (w = 0; w <= W; w++){
         if (i==0 || w==0)
            P[i][w] = 0;
         // wi < w
         else if (wt[i-1] <= w)
            // maximum(P[i-1][w], pi + P[i-1][w-wi])
            P[i][w] = max(P[i-1][w], val[i-1] + P[i-1][w-wt[i-1]]);
         else
            // if item weights more than it can hold
            P[i][w] = P[i-1][w];
      }
   }
   return P[n][W];
}

int main() {
   int T;      // number of test cases
   int N;      // number of objects
   int P, W;   // P - price of object; W - weight
   int G;      // Number of people going shopping
   int M;      // max weight the i-th member of the group can carry
   int result = 0;
   int total = 0;
   
   // Number of test cases
   cin >> T;
   for(int i = 0; i<T; i++){
      // for every test case, take in the number of objects
      cin >> N;
      int wt[N+1];
      int val[N+1];

      wt[0] = 0;
      val[0] = 0;

      for(int j = 0; j< N; j++){
         // for every object, take in the price and weight
         cin >> P >> W;
         wt[j] = W;
         val[j] = P;
         // cout  << "val[" << j << "]: " << val[j] << ", wt[" << j;
         // cout << "]: " << wt[j] << endl;
      }

      // after taking the objects, take in the number of people shopping
      cin >> G;
      for(int k = 0; k<G; k++){
         // for every shopper, take in the max weight each can carry
         cin >> M;
         result = knapSack(M, wt, val, N);
         total += result;
      }
      cout << total << endl;
      total = 0;
   }
   
   return 0;
}
