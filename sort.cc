
template <class T>
void sortArray(T a[], int n)
{ 
	//Add your code here.
	sort(a,a+n);
}

template <class T>
void printArray(T a[], int n)
{
	//Add your code here.
	for (int i =0;i<n;i++){
	    cout<< a[i];
	    if (i < n -1)
	        cout<<" ";
	}
	cout<<endl;
}
