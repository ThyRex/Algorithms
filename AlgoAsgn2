/* 
----------------------------------------------
 Purpose: AlgoAsgn2 - MergeSort
 Author:  Kathy (Thy) Dai
----------------------------------------------
Sources:
http://bytes.com/topic/c/answers/134284-reading-file-redirect
http://www.cplusplus.com/reference/sstream/istringstream/istringstream/
http://www.sanfoundry.com/cpp-program-count-inversion-array/
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;
int mergesort(int array[], int left, int right);
int merge(int array[], int left, int mid, int right);

int mergesort(int array[], int low, int high){
   int mid;
   int count = 0;
   if(low < high){
      mid = (low+high)/2;
      count  = mergesort(array, low, mid);
      count += mergesort(array, mid+1, high);
      // mid+1 so that we don't have to do it in merge where j = mid+1
      count += merge(array, low, mid+1, high);
   }
   
   return count;
}

int merge(int S[], int low, int mid, int high){
   int count = 0;
   int U[high];
   int i = low;
   int j = mid;
   int k = low;
   
   while ((i <= mid - 1) && (j<=high)){
   // pseudocode comibned
      if(S[i] <= S[j])
         U[k++] = S[i++];
      else{
         U[k++] = S[j++];
         count = count + (mid-i);
      }
   }
   
   // reverse of pseudocode
   while (i <= mid -1)
      U[k++] = S[i++];
   while (j <= high)
      U[k++] = S[j++];
   
   // move U[low] through U[high] to S[low] through S[high]
   for(i = low; i <= high; i++)
      S[i] = U[i];
      
   return count;
}

int main(){
   string line, line2;
   int size;
   // take in input file
   while (cin){
      getline(cin, line);
      getline(cin, line2);
      // change first digit to array size
      size = atoi(line.c_str());
      // if an input of 0 is read, quit program
      if (size == 0) 
         return 0;
      // initialize array of size given
      int array[size];
      // input values of next line into array
      istringstream ss (line2);
      for(int n=0; n<size; n++){
         int val;
         ss >> val;
         array[n] = val;
      }
      
      cout << mergesort(array, 0, size-1) << endl;    
   }
   return 0;
}

