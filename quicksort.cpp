#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e) {
	//Step 1 - Choose pivot element
	int pivotindex = s;
	int pivotelement = arr[s];

	//Step 2 - find right position for pivot element and place it there
	int count = 0;
	for(int i=s+1; i<=e; i++) {
		if(arr[i]<= pivotelement) 
			count++;
	}
	//Jab mai loop se bahar aaya tab pivot ki right position ki index ready hai
	int rightindex = s+count;
	swap(arr[pivotindex],arr[rightindex]);
	//updating pivot index
	pivotindex= rightindex;

	//Step 3 - left me chote , right me bade
	int i =s;
	int j =e;
	while(i<pivotindex && j>pivotindex) {
		while(arr[i]<=pivotelement)
			i++;
		while(arr[j]>pivotelement) 
			j--;

		//2 case ho skte hai
		//A-> you found the elements to swap
		//B-> No need to swap
		if(i<pivotindex && j>pivotindex) 
			swap(arr[i],arr[j]);
	}
	return pivotindex;


}

void quicksort(int arr[], int s, int e) {
	// s = e single element array sorted
	// s > e invalid array
	if(s>=e) {
		return;
	}

	//partition logic, return pivot index
	int p = partition(arr,s,e);

	//recursive call
	//left
	quicksort(arr ,s,p-1);

	//right
	quicksort(arr,p+1,e);

}
int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int arr[] = {8,1,3,4,20,50,50,50,50,5,1,1,1,1,2,2,2,2,30};
	int n=19;

	int s = 0;
	int e = n-1;

	quicksort(arr,s,e);

	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}