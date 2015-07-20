/* 
| ----------------------------------------------
|  Purpose: Algorithms Program #5 - Prim's Algorithm
|  Author:  Kathy (Thy) Dai
| ----------------------------------------------
| Sources:
| http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
*/

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <cfloat>
#include <limits.h>

using namespace std;
double map[101][101];

double getDistance(double x0, double y0, double x1, double y1);
int minKey(double key[], bool mstSet[], int pts);
double prim(double map[101][101], int pts);

double getDistance(double x0, double y0, double x1, double y1){
   double distance = sqrt( pow( (x1-x0), 2) + pow( (y1-y0), 2) );
   return distance;
}

int minKey(double key[], bool mstSet[], int pts){
   double min = DBL_MAX;
   int min_index;

   for (int i = 0; i< pts; i++){
      // if we haven't visited the point yet and the edge weight is less than min
      // set the new min to the edge weight
      // update the min index to that number
      if(mstSet[i] == false && key[i] < min){
         min = key[i];
         min_index = i;
      }
   }
   return min_index;
}

double prim(double map[101][101], int pts){
   int parent[pts]; // keeps track of points being used
   double key[pts]; // keeps track of edge weights
   bool mstSet[pts]; // marks if visited
   double answer = 0.0;

   // initialize all the edge weights to an extremely high number
   // we haven't visited any points!
   for(int i = 0; i<pts; i++){
      key[i] = DBL_MAX;
      mstSet[i] = false;
   }

   // set edge weight of first point to 0 (can't have weight from the same point)
   key[0] = 0.0;
   // starting point of points
   parent[0] = -1;

   for(int count = 0; count < pts - 1; count++){
      int u = minKey(key, mstSet, pts);
      mstSet[u] = true;

      for(int j = 0; j<pts; j++){
         if(map[u][j] && mstSet[j] == false && map[u][j] < key[j]){
            parent[j] = u;
            key[j] = map[u][j];
         }
      }
   }
   for(int i = 1; i<pts; i++){
      // already know what points using to get to the other points
      answer = answer + map[i][parent[i]];
   }

   return answer;
}


int main(){
   int numOfIn, numOfCoord;
   double result;

   cin >> numOfIn;
   for(int i = 0; i < numOfIn; i++){
      cin >> numOfCoord;
      double listOfX[numOfCoord];
      double listOfY[numOfCoord];
      for(int j = 0; j < numOfCoord; j++)
         cin >> listOfX[j] >> listOfY[j];

         // completed map
         for(int u = 0; u < numOfCoord; u++){
            for(int v = u; v < numOfCoord; v++){
               map[u][v] = getDistance(listOfX[u], listOfY[u], listOfX[v], listOfY[v]);
               //cout << "Distances from: " << listOfX[u] << ", " << listOfY[u];
               //cout << " to " << listOfX[v] << ", " << listOfY[v] << ": ";
               //cout << map[u][v] << endl;
               map[v][u] = map[u][v];
            }
         }
      
      result = prim(map, numOfCoord);
      cout << setprecision(2) << fixed << result << endl;
   }
   
   return 0;
}

