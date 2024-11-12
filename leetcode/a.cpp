#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


bool isValid(string s) {
        int n= s.length(),i;
        if (n<2)
        return false;
        stack<char> brackets;
        char temp;
        for(i=0; i<n;i++){
            temp = s[i];
            if(temp=='(' || temp=='[' || temp=='{')
            brackets.push(temp);
            else if(temp==')' || temp==']' || temp=='}'){
                if (brackets.empty())
                return false;
                char c = brackets.top();
                brackets.pop();
                cout<<c<<endl;
                if(c == '(' && temp == ')' )
                continue;
                else if(c == '[' && temp == ']' )
                continue;
                else if(c == '{' && temp == '}' )
                continue;
                else
                return false;
            }


        }
        if(brackets.empty())
        return true;
        return false;
        
        
    }
int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1)
        return 1;
        int k =nums[0],count=1;
        for(int i=1;i<nums.size();i++){
            if(k != nums[i]){
                count++;
                k = nums[i];
            }
        }
        return count;
}
int main(){
    vector<int> n = {-259, -825, 459, 825, 221, 870, 626, 934, 205, 783, 850, 398};
    sort(n.begin(),n.end());
   for(auto i :n){
    cout<<i<<" ";
   }
   cout<<abs(-42);
    return 0;
}