#include<iostream>
#include<limits>
using namespace std;


int find_max_crossing_subarry(int low, int mid, int high, int arr[]){
  int left_sum = numeric_limits<int>::min();
  int right_sum = numeric_limits<int>::min();
  int sum = 0;
  for(int i = mid; i >= low; i--){
    sum += arr[i];
    left_sum = (sum > left_sum) ? sum : left_sum;
  }

  sum = 0;
  for(int i = mid + 1; i <= high; i++){
    sum += arr[i];
    right_sum = (sum > right_sum) ? sum : right_sum;
  }

  return (right_sum + left_sum);

}

int find_max_subarry(int low, int high, int arr[]){
  if (low == high){
    return arr[low];
  }
  int mid = (low + high)/2;
  int left_sum = find_max_subarry(low, mid, arr);
  int cross_sum  = find_max_crossing_subarry(low, mid, high, arr);
  int right_sum = find_max_subarry(mid + 1, high, arr);

  if(left_sum >= cross_sum && left_sum >= right_sum){
    return left_sum;
  }
  if(right_sum >= cross_sum && right_sum >= left_sum){
    return right_sum;
  }
  return cross_sum;
}


int main(){
  int n = 4;
  int arr[] = { 2, 3, 4, 5, 7 };

  cout<<(find_max_subarry(0, n, arr))<<endl;

}
