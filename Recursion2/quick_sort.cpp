#include<iostream>
/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/
int partition(int input[],int st, int end){
    int ele = input[st];
    int cnt=0;
    for(int i=st+1;i<=end;i++){
        if(input[i]<=ele)
            cnt++;
    }
    int temp = input[st + cnt];
    input[st + cnt]= input[st];
    input[st]=temp;
    int ans = st + cnt,i=st,j=end;
    while(i<ans & j>ans){
		if(input[i]<= input[ans]){
            i++;
        }else if(input[j]>input[ans]){
            j--;
        }else{
            int temp = input[j];
            input[j]=input[i],input[i]=temp;
            i++,j--;
        }
    }
    return ans;
}

void quick_sort(int input[],int st, int end){
    if(st>=end){
        return;
    }
    int x = partition(input,st,end);
    quick_sort(input,st,x-1);
    quick_sort(input,x+1,end);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quick_sort(input,0,size-1);

}
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


