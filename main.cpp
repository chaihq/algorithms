#include <iostream>
#include <vector>

using namespace std;

//二分查找
template <typename T>
int binary_seach(const std::vector<T>& vec, const T& item) {
    int low = 0;
    int high = vec.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        T guess = vec[mid];

        if(guess == item) {
            return mid;
        }

        if(guess < item) {
            low = mid + 1;
        } else {
            low = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
