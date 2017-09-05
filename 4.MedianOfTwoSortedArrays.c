#include <stdio.h>


int min(int a,int b){
    return a>b?b:a;
}

int findK(int a[],int n,int b[],int m,int k){
    if(m>n) return findK(b,m,a,n,k);
    if(m==0) return a[k-1];
    if(k==1) return min(a[0],b[0]);
        
    int i = min(m,k/2);
    int j = k - i;
    if(b[i-1]<a[j-1])
        return findK(a,n,b+i,m-i,k-i);
    else if(b[i-1]>a[j-1])
        return findK(a+j,n-j,b,m,k-j);
    else
        return a[i-1];
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = nums1Size + nums2Size;
    int mid = sum/2;
    int m_sum1 = findK(nums1,nums1Size,nums2,nums2Size,mid+1);
    int m_sum2 = m_sum1;
    if(sum % 2 == 0)
        m_sum2 = findK(nums1,nums1Size,nums2,nums2Size,mid);
    return (m_sum1+m_sum2)/2.0;
}


int main(){
    int a[1] = {1};
    int b[3] = {3,7,9};

    double mid = findMedianSortedArrays(a,1,b,3);

    printf("mid %f\n",mid);

}
