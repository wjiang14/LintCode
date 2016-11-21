#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /*
   * @param numbers : An array of Integer
   * @param target : target = numbers[index1] + numbers[index2]
   * @return : [index1+1, index2+1] (index1 < index2)
   */
  class elem {
   public:
    int val;
    int index;
    elem(int v, int i):val(v),index(i) {}
    bool operator < (const elem &e) const {
      return val < e.val;
    }
  };

  vector<int> twoSum(vector<int> &nums, int target) {

    vector<int> res(2,-1);
    vector<elem> arr;
    for(int i=0; i<nums.size(); i++)
      arr.push_back(elem(nums[i],i));

    sort(arr.begin(),arr.end());
    int left = 0, right = arr.size()-1;
    while(left<right) {
      if(arr[left].val+arr[right].val==target) {
        res[0] = min(arr[left].index,arr[right].index)+1;
        res[1] = max(arr[left].index,arr[right].index)+1;
        break;
      }
      else if(arr[left].val+arr[right].val<target)
        left++;
      else
        right--;
    }
    return res;
  }
};


int main() {
  vector<int> a({2, 7, 11, 15});
  Solution sol;
  vector<int> res = sol.twoSum(a, 9);
  for (int i = 0; i < res.size(); ++i) {
    cout<< res[i] << " ";
  }
  return 0;
}