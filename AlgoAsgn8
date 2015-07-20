/* 
| ----------------------------------------------
|  Purpose: Algorithms Program #8 - 8 Queens Problem (Backtracking)
|  Author:  Kathy (Thy) Dai
| ----------------------------------------------
| Sources:
| http://www.programminggeek.in/2013/08/solution-of-n-queen-problem-and-8queen-problem-using-backtracking-in-c.html#.VQCWWI7F8xK
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;
int count;

int place(int k,int i,int *x)
{
   for(int j=0; j<k; j++) //checkattack  as old queen is placed at jth position
   {
        //old queen is placed at jth row of x[j] column
        //new queen to be placed at kth row of ith column
      if(i==x[j] || abs(k-j)==abs(i-x[j]))
         return 0;
   }
   return 1;
}

void Nqueen(int k, int xPos, int yPos)
{
   int i,j;
   static int x[8];  //solution vector contains column number of queen
   for(i=0;i<8;i++)  //determines appropriate column number of the kth queen to be placed
   {
      if(place(k,i,x))
      {
         x[k]=i;
         if(k==8-1)
         {
            // count++;
            for(j=0;j<=k;j++){ // column -- 
               // printf("%d  ",x[j]);
               if (x[j] == xPos - 1 && j == yPos - 1) 
                  count++;
            }
            // printf("\n");
         }
         else
            Nqueen(k+1, xPos, yPos);
      }
   }

}

int main()
{
    int input;
    int xPos, yPos;
    cin >> input;
    for(int i = 0; i < input; i++){
        cin >> xPos >> yPos;
        Nqueen(0, xPos, yPos);
        cout << count << endl << endl;
        count = 0;
        // cout << "x: " << xPos[i] << " y: " << yPos[i] << endl;
    }
   
   // printf("Total %d solutions are possible\n",count);
   // printf("%d\n", count);
   return 0;
}
