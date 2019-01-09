#include <stdio.h>
#include <malloc.h>

int** threeSum(int* nums, int numsSize, int* returnSize);
int quick_sort(int *nums, int start, int end);
int find_third(int *nums, int numsSize, int start_pos, int n);

main()
{
    int i, j, n;
    int nums[10] = {1, 2, -2, -1, 3, 2, -2, 0, 1, 5};
    int returnSize;
    int **result_list = threeSum(nums, 10, &returnSize);
    for (i=0; i<returnSize; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d ", result_list[i][j]);
        }
        printf("\n");
    }
    scanf("%d", &n);
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int **result_list = (int**)malloc(numsSize*(numsSize-1)*(numsSize-2)*sizeof(int *));
    int nums_size = 0;
    int third_pos = -1;
    int i, j;
    quick_sort(nums, 0, numsSize-1);
    for (i=0; i<numsSize-2; i++)
    {
        if ((i != 0) && (nums[i] == nums[i-1]))
            continue;
        for (j=i+1; j<numsSize-1; j++)
        {
            if (nums[i] + 2*nums[j] > 0)
                break;
            if ((nums[j] == nums[j-1]) && (j != i+1))
                continue;
            third_pos = find_third(nums, numsSize, j+1, 0-nums[i]-nums[j]);
            if (third_pos != -1)
            {
                result_list[nums_size] = (int *)malloc(3*sizeof(int));
                result_list[nums_size][0] = nums[i];
                result_list[nums_size][1] = nums[j];
                result_list[nums_size][2] = nums[third_pos];
                nums_size++;
            }
        }
    }
    *returnSize = nums_size;
    return result_list;
}

int quick_sort(int *nums, int start, int end)
{
    int vacant = start;
    int pointer = end;
    int temp;
    if (start >= end)
        return 0;
    while (vacant != pointer)
    {
        while ((nums[vacant] <= nums[pointer]) && (vacant != pointer))
            pointer--;
        temp = nums[vacant];
        nums[vacant] = nums[pointer];
        nums[pointer] = temp;
        temp = vacant;
        vacant = pointer;
        pointer = temp;
        while ((nums[vacant] >= nums[pointer]) && (vacant != pointer))
            pointer++;
        temp = nums[vacant];
        nums[vacant] = nums[pointer];
        nums[pointer] = temp;
        temp = vacant;
        vacant = pointer;
        pointer = temp;
    }
    quick_sort(nums, start, pointer-1);
    quick_sort(nums, pointer+1, end);
    return 0;
}

int find_third(int *nums, int numsSize, int start_pos, int n)
{
    int low = start_pos;
    int high = numsSize-1;
    int pos = (low+high)/2;
    while ((nums[pos] != n) && (low <= high))
    {
        if (nums[pos] > n)
        {
            high = pos - 1;
            pos = (low+high)/2;
        }
        else
        {
            low = pos + 1;
            pos = (low+high)/2;
        }
    }
    if (low <= high)
        return pos;
    else
        return -1;
}