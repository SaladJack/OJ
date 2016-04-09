class Finder {
public:
    int partition(vector<int> &nums, int begin, int end) {
        int pivot = nums[begin];
        int pivot_index = begin;
        for(int i=begin+1; i!=end;i++){
            if(nums[i] >= pivot){
                pivot_index+=1;
                if(pivot_index != i){
                    swap(nums[i], nums[pivot_index]);
                }
            }
        }
        swap(nums[begin], nums[pivot_index]);
        return pivot_index;
    }
 
    int findKth(vector<int> &nums, int n, int k) {
        return find_k(nums, 0, nums.size(), k);
    }
 
    int find_k(vector<int> &nums, int begin, int end, int k){
        if( k<=0 || begin>end-1){
            return -1;
        }
        int position = partition(nums, begin, end);
        int left_length = position-begin;
        if(left_length== k-1){
            return nums[position];
        }
        else if(left_length > k-1){
            return find_k(nums, begin, position, k);
        }
        else{
            return find_k(nums, position+1, end, k-left_length-1);
        }
    }
};