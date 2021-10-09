#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *a, int n){
  for(int j = 1; j < n; j++){
    int key = a[j];
    int i = j - 1;
    while(i >= 0 && a[i] > key){
      a[i+1] = a[i];
      i--;
    }
    a[i+1] = key;
  }
}

int main(){
  int n;
  cout<<"Enter size of array to be sorted: ";
  cin>>n;
  int *arrptr = new int[n];
  cout<<"Enter elements of array to be sorted: "<<endl;
  for(int i = 0; i < n; i++){
    cin>>(*(arrptr+i));
  }
  cout<<"Your array: "<<endl;
  for(int i = 0; i < n; i++){
    cout<<(*(arrptr+i))<<" ";
  }
  cout<<endl;
  insertion_sort(arrptr, n);
  cout<<"Sorted array: "<<endl;
  for(int i = 0; i < n; i++){
    cout<<(*(arrptr+i))<<" ";
  }
  return 0;
}
