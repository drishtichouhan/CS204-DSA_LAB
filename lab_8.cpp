#include<bits/stdc++.h>
using namespace std;

long double distance(long long int x,long long int y)
{
    long double d;
    d=(x*x)+(y*y);
    d=sqrt(d);
    return d;
}

int partition(long double arr[], int l, int r, long double x);


long double findMedian(long double str[], int n)
{
    sort(str, str+n);
    return str[n/2];
}


long double median_of_medians(long double arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int i;
        long double median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }


        int medOfMed = (i == 1)? median[i-1]: median_of_medians(median, 0, i-1, i/2);


        int pos = partition(arr, l, r, medOfMed);


        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return median_of_medians(arr, l, pos-1, k);

        return median_of_medians(arr, pos+1, r, k-pos+l-1);
    }

    return INT_MAX;
}

void swap(long double *a, long double *b)
{
    long double temp = *a;
    *a = *b;
    *b = temp;
}


int partition(long double arr[], int l, int r, long double x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
        break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        long long int x[n];
        long long int y[n];
        for(int i=0;i<n;++i)
        {
            cin>>x[i]>>y[i];
        }
        long double dist[n];
        for(int i=0;i<n;++i)
        {
            long double ld=distance(x[i], y[i]);
            dist[i]=ld;
        }
        cout<<median_of_medians(dist, 0, n-1, n/2)<<endl;
    }
    return 0;
}
