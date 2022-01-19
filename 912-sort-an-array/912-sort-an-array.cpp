class Solution {
public:
    void Merge(vector<int> &arr, int left, int mid, int right)
    {
        int n1=mid-left+1, n2=right-mid, i,j,k;
        int leftArr[n1], rightArr[n2];
        
        for(int i=0; i<n1; i++)
        {
            leftArr[i] = arr[left+i];
        }
        
        for(int i=0; i<n2; i++)
        {
            rightArr[i] = arr[mid+i+1];
        }
        
        i=0, j=0, k=left;
        
        while(i<n1 && j<n2)
        {
            if(leftArr[i]<=rightArr[j])
            {
                arr[k++] = leftArr[i++];
            }
            else
            {
                arr[k++] = rightArr[j++];
            }
        }
        
        while(i<n1)
        {
            arr[k++] = leftArr[i++];
        }
        
        while(j<n2)
        {
            arr[k++] = rightArr[j++];
        }
    }
    
    void MergeSort(vector<int> &arr, int left, int right)
    {
        if(left>=right) return;
        
        int mid = left + (right-left)/2;
        
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        MergeSort(nums, 0, n-1);
        
        return nums;
    }
};