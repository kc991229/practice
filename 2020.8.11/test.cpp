void rotate_help(int *left,int *right)
{
        while (left<right)
        {
                    *left^=*right;
                            *right^=*left;
                                    *left^=*right;
                                            left++;
                                                    right--;
                                                        
        }

}
void rotate(int* nums, int numsSize, int k){
        if (nums==NULL||numsSize==1)
        {
                    return;
                        
        }
            k=k%numsSize;
                rotate_help(nums,nums+numsSize-k-1);
                    rotate_help(nums+numsSize-k,nums+numsSize-1);
                        rotate_help(nums,nums+numsSize-1);

}
