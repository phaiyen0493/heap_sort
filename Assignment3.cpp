/*Name: Yen Pham
CS3110
Assignment 3
*/


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

//swap 2 elements
void swap(double &a, double &b) 
{
	double t = a;
	a = b;
	b = t;
}

// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap 
void heapify(double array[], int count, int i)
{
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	// If left child is larger than root	
	if (left < count && array[left] > array[largest])
	{
		largest = left;
	}

	// If right child is larger than the largest so far
	if (right < count && array[right] > array[largest])
	{
		largest = right;
	}

	// If largest is not root
	if (largest != i)
	{
		swap(array[i], array[largest]);

		// Recursively heapify the affected sub-tree
		heapify(array, count, largest);
	}
}
void heap_sort(double array[], int count)
{
	//Build heap (rearrange array)
	for (int i = count/2 -1; i >=0; i--)
	{
		heapify(array, count, i);
	}

	for (int i = count -1; i>=0; i--)
	{
		//Move current root to end
		swap(array[0], array[i]);

		//Call max heapify on the reduced heap
		heapify(array, i, 0);
	}
}

int main()
{
	ifstream fin("data3.txt"); //input file
	ofstream fout("output3.txt"); //output file
	string line;
	int count;
	double number;

	//Read line
	while(getline(fin, line))
	{
		double array[100];
		count = 0;
		stringstream is(line);
		while(is >> number)
		{
			array[count] = number;
			count++;
		}
		heap_sort(array, count);

		for (int i = 0; i < count; i++)
		{
			fout << array[i] << " ";
		}
		fout << endl;
	}

	return 0;
}