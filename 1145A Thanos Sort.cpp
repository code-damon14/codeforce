#include<bits/stdc++.h>
using namespace std;

int maxlen = 1;

int isSorted(int *arr,int r,int l)
{
    if(r>=l)
        return 1;
    for(int i=r;i<=l-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            return 0;
        }
    }
    return 1;
}

int divide_arr(int *arr, int r ,int l)
{

    if(r<l)
    {

    int len=l-r+1;
    if(isSorted(arr,r,l))
    {
        if(maxlen<len)
            maxlen=len;
        return len;
    }

    else
    {
    int mid=(l+r)/2;
    divide_arr(arr,r,mid);
    divide_arr(arr,mid+1,l);
    }
    }
}

int main()
{
    int n;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int t=divide_arr(a,0,n-1);
    cout<<maxlen;
    return 0;
}
