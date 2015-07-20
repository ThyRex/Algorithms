/* 
| ----------------------------------------------
|  Purpose: Algorithms Program #10 - RadixSort using LinkedLists
|  Author:  Kathy (Thy) Dai
| ----------------------------------------------
| Sources:
| http://runnable.com/Us52yozciVFWAAbW/how-to-add-a-node-into-a-linked-list-for-c%2B%2B
| http://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
*/
#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <stdio.h>

using namespace std;

int counter = 0;
int maximum = 0;
/* definition of the list node class */
class Node
{
	friend class LinkedList;
private:
	int _value; /* data, can be any data type, but use integer for easiness */
	int endDig;
	Node *_pNext; /* pointer to the next node */

public:
	/* Constructors with No Arguments */
	Node()
		: _pNext(NULL)
	{ }

	/* Constructors with a given value */
	Node(int val, int rem)
		: _value(val), endDig(rem), _pNext(NULL)
	{ }

};

/* definition of the linked list class */
class LinkedList
{
private:
	/* pointer of head node */
	Node *_pHead;
	/* pointer of tail node */
	Node *_pTail;

public:
	/* Constructors with No Arguments */
	LinkedList();

	/* Function to append a node to the end of a linked list */
	void tailAppend(int val, int rem);

	/* Traversing the list and printing the value of each node */
	void traverse_and_print(FILE *file);
	LinkedList radixSort(LinkedList list);

};

LinkedList::LinkedList()
{
	/* Initialize the head and tail node */
	_pTail = NULL;
	_pHead = NULL;
}


void LinkedList::tailAppend(int val, int rem)
{
	/* The list is empty? */
	if (_pHead == NULL) {
		/* the same to create a new list with a given value */
		_pHead = new Node(val, rem);
		_pTail = _pHead;
	}
	else
	{
		/* Append the new node to the tail */
		_pTail->_pNext = new Node(val, rem);
		/* Update the tail pointer */
		_pTail = _pTail->_pNext;
	}
}

void LinkedList::traverse_and_print(FILE *file)
{
	Node *p = _pHead;

	/* The list is empty? */
	if (_pHead == NULL) {
		cout << "The list is empty" << endl;
		return;
	}

	/* A basic way of traversing a linked list */
	while (p != NULL) { /* while there are some more nodes left */
		/* output the value */
		fprintf(file, "%d\n", p->_value);
		// cout << p->endDig << " " << endl;
		/* The pointer moves along to the next one */
		p = p->_pNext;
	}
}

LinkedList LinkedList::radixSort(LinkedList list){
	LinkedList large;
	counter++;
	int s = pow(10, counter);
	LinkedList total[10];


	Node *p = list._pHead;

	while (p != NULL){
		for(int i = 0; i<10; i++){
			if(p->endDig == i){
				total[i].tailAppend(p->_value, p->endDig);
			}
		}
		p = p->_pNext;

	}


	for(int i = 0; i < 10; i++){
		Node *p = total[i]._pHead;
		while(p != NULL){
			int x = p->_value;
			x = x/s;
			// cout << x << " ";
			// cout << endl;
			large.tailAppend(p->_value, x%10);
			p = p->_pNext;
		}
	}

	if(counter == maximum){
		return large;
	}

	radixSort(large);
}

int numDigits(int number){
	int digits = 0;
	while(number){
		number = number/10;
		digits++;
	}
	return digits;
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual position of
    // this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to curent digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead of passing digit
    // number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(int arr[], int n, FILE *file)
{
    for (int i = 0; i < n; i++)
        fprintf(file, "%d\n", arr[i]);
}

int main(int argc, const char * argv[])
{
	/* Create a list with only one node */
	FILE *linkedfile;
	FILE *countfile;
	int n;
	int someN;
	LinkedList list, final;
	int entry;
	cin >> n;
	int arr[n];

	for (int i = 0; i<n; i++){
		cin >> entry;
		someN = numDigits(entry);
		if(someN > maximum)
			maximum = someN;
		//entry = n - i;
		// 1 for ones digit
		// 10 for tens digit...
		list.tailAppend(entry, entry % 10);
		// cout << "max: " << maximum;
		arr[i] = entry;
	}
	
	clock_t startLL = clock();
	
	final = list.radixSort(list);
	
	clock_t endLL = clock();
	double clockTicksLL = endLL - startLL;
	double timeLL = clockTicksLL / (double)CLOCKS_PER_SEC;
	cout << "LinkedList sort: " << timeLL << endl;

	linkedfile = fopen("outputLL.txt", "w");
	final.traverse_and_print(linkedfile);
	fclose(linkedfile);

	clock_t startCS = clock();

	radixsort(arr, n);
	
	clock_t endCS = clock();
	double clockTicksCS = endCS - startCS;
	double timeCS = clockTicksCS / (double)CLOCKS_PER_SEC;
	cout << "Counting sort: " << timeCS << endl;

	countfile = fopen("outputCS.txt", "w");
    print(arr, n, countfile);
    fclose(countfile);
	return 0;
}
