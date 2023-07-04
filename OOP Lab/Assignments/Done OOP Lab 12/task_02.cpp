#include <iostream>
using namespace std;

template <typename S>
class Search
{
private:
    int length;
    S *arr;
    S req_element;

public:
    Search(S array[], int length, S element_req)
    {
        arr = new S[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = array[i];
        }
        length = length;
        req_element = element_req;
    }
    void Search_element()
    {
        cout << endl;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == req_element)
            {
                cout << endl
                     << "Element "<< req_element<<" found at position number " << i;
                break;
            }
            else
            {
                if (i + 1 == length)
                {
                    cout << endl
                         << req_element << " The element does not exist in the current array\n";
                }
                else
                {
                    continue;
                }
            }
        }
    }
};
int main()
{
    // int array[] = {1, 2, 3, 4};
    // int length = sizeof(array) / 4;
    // cout << endl
    //      << "Length of is: " << length;
    // Search<int> L(array, length, 4);
    // L.Search_element();
    // return 0;
    int n;
    cout<<"How many elements you want in the array\n";
    cin>>n;
    int array[n];
    cout<<"Enter the values in the array\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value for "<<i+1<<" element.\n";
        cin>>array[i];
    }
    int find;
    cout<<"Enter the element you want to find in the array\n";
    cin>>find;
    Search<int> L(array,n,find);
    L.Search_element();
    
}