/* 
----------------------------------------------
 Purpose: Algorihmshms Program #2 - Get In Line
 Author:  Kathy (Thy) Dai
----------------------------------------------
Sources:
http://faculty.cse.tamu.edu/djimenez/ut/utsa/cs3343/lecture20.html
http://www.cplusplus.com/reference/sstream/istringstream/istringstream/
http://www.sanfoundry.com/cpp-program-count-inversion-array/
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;
void printVec(const vector<int> &a);

vector<int> make_vec(int n){
   vector<int> r;
   while(n){
      r.push_back(n%10);
      n /= 10;
   }
   return r;
}

vector<int> make_vec2(string str){
   vector<int> r;
   for(int i =str.length() - 1; i>= 0; i--)
      r.push_back(str[i] - '0');
   return r;
}

int revert(const vector<int> &a){
   vector<int> b(a);
   int digit = 0;
   int temp = 0;
   int multiplier = 1;
   int size = a.size();
   // backwards, so go by ones, tens, etc.
   for(int i = size - 1; i >= 0; i--){
      temp = b.front() * multiplier;
      // adding zeroes to append to new digits
      digit = digit + temp;
      b.erase(b.begin());
      multiplier = multiplier * 10;
   }
   return digit;
}

vector<int> add(const vector<int>& a, vector<int> b){
   vector<int> c;
   vector<int> newvector1(a);
   vector<int> newvector2(b);
   int carry = 0;
   int sum = 0;
   int dif = a.size() - b.size();
   int dif2= b.size() - a.size();
   
   if(dif>0){
      for(int i = 0; i < dif; i++)
         newvector2.insert(newvector2.end(),0);
   }
   else if(dif2>0){
      for(int i = 0; i < dif2; i++)
         newvector1.insert(newvector1.end(),0);
   }
   
   for(size_t i = 0; i< newvector1.size(); i++){
      sum = newvector1.at(i) + newvector2.at(i) + carry;
      if(sum >= 10){
         carry = 1;
         sum -= 10;
      }
      else
         carry = 0;
      c.push_back(sum);
   }
   c.push_back(carry);
   while(c[c.size() - 1] == 0){
      c.pop_back();
   }
   return c;
}

// assume a > b
vector<int> subtract(const vector<int> &a, const vector<int> &b){
   vector<int> newvector1(a);
   vector<int> newvector2(b);
   int result;
   vector<int> c;
   int dif = a.size() - b.size();
   int dif2 = b.size() - a.size();   

   if(dif>0){
      for(int i = 0; i < dif; i++)
         newvector2.insert(newvector2.end(),0);
   }
   if(dif2>0){
      for(int i = 0; i<dif; i++)
         newvector1.insert(newvector1.end(),0);
   }
   
   for(size_t i = 0; i < newvector1.size(); i++){
      if(newvector1[i] - newvector2[i] >= 0)
         result = newvector1.at(i) - newvector2.at(i);
      else{
         i++;
         newvector1[i] = newvector1[i] - 1;
         i--;
         newvector1[i] = newvector1[i] + 10;
         result = newvector1.at(i) - newvector2.at(i);
      }
      c.push_back(result);
   }
   while(c[c.size()-1] == 0)
      c.pop_back();
   return c;
}

vector<int> mult(const vector<int> &a, int m){
   vector<int> newvector(a);
   for(int i = 0; i < m; i++)
      newvector.insert(newvector.begin(),0);
   return newvector;
}

vector<int> div(const vector<int> &a, int m){
   vector<int> newvector(a);
   vector<int> empty;
   int size = newvector.size();
   if(m>size)
      return empty;
   for(int i = 0; i < m; i++)
      newvector.erase(newvector.begin());
   return newvector;
}

vector<int> rem(const vector<int> &a, int m){
   vector<int> newvector(a);
   int size = newvector.size();
   if(m>size)
      return newvector;
   for(int i = a.size(); i >= m + 1; i--){
      newvector.pop_back();
   }
   return newvector;
}

void printVec(const vector<int>& n){
   for(int i = n.size() - 1; i>= 0; i--)
      cout << n[i];
}

vector<int> prod2 (const vector<int> U, const vector<int> V){
   vector<int> x, y, w, z, r, p, q;
   vector<int> u(U);
   vector<int> v(V);
   vector<int> prod, sub1, sub2, product2, add1, add2;
   vector<int> empty;
   int n, m;
   int num1 = 0;
   int num2 = 0;
   int result = 0;
   int threshold = 4;
   
   n = fmax(u.size(), v.size());
   if(u.empty() || v.empty())
      return empty;
   else if(n <= threshold){
      num1 = revert(u);
      num2 = revert(v);
      result = num1 * num2;
      return make_vec(result);
   }
   else{
      //if(u.size() > v.size());
      //   v.resize(u.size(),0);
      //if(u.size() < v.size())
      //   u.resize(v.size(),0);
      m = n/2;
      x = div(u, m);
      y = rem(u, m);
      w = div(v, m);
      z = rem(v, m);
      r = prod2(add(x, y), add(w, z));
      p = prod2(x, w);
      q = prod2(y, z);
      sub1 = subtract(r, p);
      sub2 = subtract(sub1, q);
      prod = mult(p, 2*m);
      product2 = mult(sub2, m);
      add1 = add(prod, product2);
      add2 = add(add1, q);
      return add2;
   }
}

int main(){
   string digit, digit2;
   vector<int> U, V, result;
   
   // take in input file
   while (cin){
      getline(cin, digit);
      getline(cin, digit2);
      U = make_vec2(digit);
      V = make_vec2(digit2);
      result = prod2(U, V);
      printVec(result);
      cout << endl;
   }
   return 0;
}
