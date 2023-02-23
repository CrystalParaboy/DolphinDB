#include <iostream>
#include <vector>
using namespace std;
class Solution3{
public:
    Solution3(){}
    vector<int> vec;
    int search(int target){
        int low = 0;
        int high = vec.size()-1;
        int mid = (low + high) /2;
        while(low <= high){
            mid= (low + high) / 2;
            if (vec[mid] == target)
                return mid;
            else if (target < vec[mid])
                high = mid-1;
            else
                low = mid + 1;
            
        }
        return mid;
       
    }
    int mrank(int num){
        if(vec.size()==0) {vec.push_back(num); return 0;}
        if(vec[0] > num) {vec.insert(vec.begin(), num); return 0;}
        if(vec[vec.size()-1] < num ) {vec.push_back(num); return vec.size()-1;}
        int pos = search(num);
        if(vec[pos] == num) return pos;
        else {
            auto it = vec.begin();
            vec.insert(it + pos + 1, num);
            return pos+1;
        }
        
    }
    
};

int main()
{
    Solution3 sol;
    int a = sol.mrank(1);
    int b = sol.mrank(5);
    int c = sol.mrank(8);
    int d = sol.mrank(2);
    int e = sol.mrank(10);
    cout<<a<<b<<c<<d<<e;

    return 0;
}
