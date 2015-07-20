/* 
| ----------------------------------------------
|  Purpose: Algorithms Program #4 - Subset Sum
|  Author:  Kathy (Thy) Dai
| ----------------------------------------------
| Sources:
| http://www.cplusplus.com/reference/vector/vector/
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <math.h>

using namespace std;

bool subsetSum(int size, int numbers[], int target){
   // array of pointers that point to other arrays
   bool** hit;
   bool answer;
   hit = new bool*[target+1];
   for(int i = 0; i<target+1; i++)
      hit[i] = new bool[size+1];

   // every set can get to 0, so if target = 0, return true
   for(int i = 0; i<=size; i++)
      hit[0][i] = true;
      
   for(int i = 1; i<=target; i++)
      hit[i][0] = false;
   
   for(int col = 1; col <= target; col++){
      for(int row = 1; row <= size; row++){
         hit[col][row] = hit[col][row-1];
         if(col >= numbers[row-1])
            hit[col][row] = hit[col][row] || hit[col-numbers[row-1]][row-1];
      }
   }
   answer = hit[target][size];

   for(int i =0; i<target+1; i++)
      delete[] hit[i];
   delete[] hit;
   
   return answer;
}


int main(){
   string sSize, sArray, sTarget;
   int size, target;
   
   // take in input file
   while (cin){
      getline(cin, sSize);
      getline(cin, sArray);
      getline(cin, sTarget);
      if(sSize.empty() || sArray.empty() || sTarget.empty())
         break;   
      size = atoi(sSize.c_str());
      
      int array[size];
      istringstream ss (sArray);
      for(int i=0; i<size; i++){
         int val;
         ss >> val;
         array[i] = val;
      }  
      
      target = atoi(sTarget.c_str());
         
      if(subsetSum(size, array, target))
         cout << "True" << endl;
      else
         cout << "False" << endl;
      
   }
   return 0;
}
