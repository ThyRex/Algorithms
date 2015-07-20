/* 
| ----------------------------------------------
|  Purpose: Algorithms Program #6 - Quicker Emails
|  Author:  Kathy (Thy) Dai
| ----------------------------------------------
| Sources:
| http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
| Recycled parts Algorithms Program #5
*/

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits.h>

using namespace std;
int map[101][101];

int minDistance(int dist[], bool sptSet[]);
int dijkstra(int map[101][101], int start, int end);

// Find the point with the minimum weight from set of points
// not included in shortest path tree
int minDistance(int dist[], bool sptSet[]){
   // We initialize min to a high number so that way it can be
   // easily compared to the minimum value:
   // 2 < 100000 i.e.
   int min = INT_MAX;
   int min_index;

   // If we have not visited the point yet, and the weight
   // is less than the extremely high value,
   // replace the minimum value with the new one
   // and replace the minimum index with the new index
   for(int v = 0; v < 101; v++){
      if(sptSet[v] == false && dist[v] <= min){
         min = dist[v];
         min_index = v;
      }
   }
   return min_index;
}

int dijkstra(int map[101][101], int start, int end){
   // dist is the shortest path tree (keeps track
   // of the shortest distance)
   int dist[101];
   // sptSet keeps track if we've visited that point or
   // that the shortest distance has been found
   bool sptSet[101];
   int answer = 0;

   // Initialize all weights in dist to an extremely high number
   // sptSet is false because we haven't visited any points yet!
   for(int i = 0; i < 101; i++){
      dist[i] = INT_MAX;
      sptSet[i] = false;
   }

   // From point A to point A, the distance is 0.
   dist[start] = 0;

   for(int count = 0; count < 101; count++){
      int u = minDistance(dist, sptSet);
      sptSet[u] = true;

      // !sptSet[v]        : if we haven't visited the point
      // map[u][v]         : it has a weight
      // dist[u] != INT_MAX: there is an edge/has weight
      // dist[u] + ...     : the total weight of path from
      //             start to end is smaller than the current value 
      // Update the short path tree
      for(int v = 0; v < 101; v++){
         if(!sptSet[v] && map[u][v] && dist[u] != INT_MAX && dist[u] + map[u][v] < dist[v]){
            dist[v] = dist[u] + map[u][v];
         }
      }
   }
   // if there isn't an edge, it is unreachable
   if(dist[end] == INT_MAX)
      answer = 999;
   else
      answer = dist[end];
   return answer;
}


int main(){
   int N;
   int n, m, S, T;
   int comp1, comp2, w;
   int result;

   cin >> N;
   for(int i = 0; i < N; i++){
      cin >> n >> m >> S >> T;
      // creates a map of the weights to keep track
      for(int j = 0; j < m; j++){
         cin >> comp1 >> comp2 >> w;
         // cout << "Comp1: " << comp1 <<"\nComp2: " << comp2 << "\nLatency: " << w << endl;
         map[comp1][comp2] = w;
         map[comp2][comp1] = w;
      }
      result = dijkstra(map, S, T);

      if(result == 999){
         cout << "Case #" << i+1 << ": "<< "unreachable\n";
      }
      else{
         cout << "Case #" << i+1 << ": " << result << "\n";
      }
      // Reset the entire map to 0 to work with the new data
      for(int row = 0; row < 101; row++){
         for(int col = 0; col < 101; col++)
            map[row][col] = 0;
      }
   }
   

   return 0;
}
