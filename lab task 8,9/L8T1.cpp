#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target)
{
    int low=0,high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            low = mid + 1; 
        else
            high = mid - 1;
    }

    return -1; 
}

int main()
{
    int products[]={5, 8, 12, 15, 20, 25, 30};
    int n = 7;

    int target;
    cout << "Enter Product ID to search: ";
    cin >> target;

    int index = binarySearch(products, n, target);

    if (index != -1)
        cout << "Product Found at index: " << index << endl;
    else
        cout << "Product Not Found" << endl;

    return 0;
}
