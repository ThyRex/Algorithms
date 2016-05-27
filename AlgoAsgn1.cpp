/* 
----------------------------------------------
 Purpose: Bad Encryption: Algorithms 1st Program Assignment
 Author:  Kathy (Thy) Dai
----------------------------------------------
Sources:
http://www.programmingsimplified.com/java/source-code/java-program-reverse-string
And an old programming homework from Foundations II
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
   string shift, word, base = "";
   int digit, length;
   int abc_length = 0;
   
   string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
   abc_length = alphabet.length();
   
   while(cin >> shift >> word){
      digit = atoi(shift.c_str());
   
      if(digit == 0)
         return 0;
      
      length = word.length();
      string reverse = "";
   
      for(int i = length -1; i>= 0; i--)
         reverse = reverse + word.at(i);
      
      int rlength = reverse.length();
      int rIndex[rlength];
      int decodeNum[rlength];
      string final = "";
      
      for(int rLetter = 0; rLetter<rlength; rLetter++){
         for(int abc = 0; abc < abc_length; abc++){
            if(reverse[rLetter] == alphabet[abc])
               rIndex[rLetter] = abc;
         }
      }
      
      for(int i = 0; i<rlength; i++){
         decodeNum[i]=rIndex[i] + digit;
         int index = decodeNum[i] % 28;
         final = final + alphabet.at(index);
        
      }
      cout << final << endl;
   }

   return 0;
}
