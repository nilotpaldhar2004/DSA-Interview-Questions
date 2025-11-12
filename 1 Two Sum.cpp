//LeetCode 1 – Two Sum
#include<bits/stdc++.h>
using namespace std;
class solution{
	public:
		vector<int> twoSum(vector<int>& nums, int target){
			unordered_map<int,int>mp;
			for(int i=0;i<nums.size();i++){
				int complement = target-nums[i];
				if(mp.find(complement) !=mp.end()){
					return {mp[complement], i};
				}
				mp[nums[i]]=i;
			}
			return {};
		}
		
	
};

int main(){
	int n;
	cout<<"Enter the number of element \n";
	cin>>n;
	vector<int>nums(n);
	cout<<"Enter the element :";
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<"\n";
	int target;
	cout<<"Enter the target : ";
	cin>>target;
	solution obj;
	vector<int>result = obj.twoSum(nums,target);
	cout<<"indices : ";
	for(int i : result) cout<<i<<" ";
	cout << endl;
	
	return 0;
	
}

//Asked In: Amazon, Google, Microsoft, Facebook, Apple
//Time Complexity: O(n)
//Space Complexity: O(n)
