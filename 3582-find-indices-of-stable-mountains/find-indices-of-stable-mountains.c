/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int* ans = malloc(heightSize*sizeof(int));
    int count = 0;

    for(int i = 1;i<heightSize;i++){
        if(height[i-1] > threshold){
            ans[count++] = i;
        }
    }
    *returnSize = count;
    return ans;
}