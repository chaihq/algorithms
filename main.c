#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

///二分查找
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

///选择排序
template <typename T>
int find_smallest(const std::vector<T>& arr) {
    int temp = 0;
    for(size_t i = 0; i < arr.size(); i++) {
        if(arr[temp] > arr[i]) {
            temp = i;
        }
    }
    return temp;
}
template <typename T>
std::vector<T> select_sort(std::vector<T>& arr) {
    std::vector<T> sort_arr;
    while(!arr.empty()) {
        int small_index = find_smallest<T>(arr);
        sort_arr.push_back(arr[small_index]);
        //删除该元素
        arr.erase(arr.begin() + small_index);
    }
    return sort_arr;
}
void select_sort_c(int *arr, int len) {
    for(int i = 0; i < len-1; i++) {
        //查找最小元素
        int small_index = i;
        for(int j = i; j < len; j++) {
            if(arr[small_index] > arr[j]) {
                small_index = j;
            }
        }
        //最小元素和第一个元素替换
        int temp = arr[i];
        arr[i] = arr[small_index];
        arr[small_index] = temp;
    }
}

//递归计算数组和
template <typename T>
T sum(std::vector<T> & arr) {
    if(arr.empty()) {
        return 0;
    }
    T last_num = arr.back();
    arr.pop_back();
    return last_num + sum(arr);
}

//递归求和
template <typename T>
T count(std::vector<T> & arr) {
    if(arr.empty()) {
        return 0;
    }
    arr.pop_back();
    return 1 + count(arr);
}

//递归查找列表中最大的数字
template <typename T>
T largest_num(std::vector<T> & arr) {
    if(arr.empty()) {
        throw std::invalid_argument("Cannot select max value from empty sequence");
    }
    if(arr.size() == 1) {
        return arr.at(0);
    }
    T temp = arr.back();
    arr.pop_back();
    T sub_max = largest_num(arr);
    return temp > sub_max ? temp : sub_max;

}

//快速排序
template <typename T>
std::vector<T> quick_sort(std::vector<T>& arr) {
    if(arr.size() < 2) {
        return arr;
    }
    const T * pivat = &arr.front() + arr.size()/2 - 1;
    std::vector<T> small;
    std::vector<T> big;

    for(T * item = &arr.front(); item <= &arr.back(); item++) {
        if(*item == *pivat) {
            continue;
        }
        if(*item < *pivat) {
            small.push_back(*item);
        } else {
            big.push_back(*item);
        }
    }
    std::vector<T> small_sort = quick_sort(small);
    std::vector<T> big_sort = quick_sort(big);

    small_sort.push_back(*pivat);
    small_sort.insert(small_sort.end(), big_sort.begin(), big_sort.end());
    return small_sort;
}

//快速排序，c语言实现
//void quick_sort_c(int arr[], int start, int end) {

//}

//广度优先搜索
bool is_seller(const std::string & name) {
    return name.back() == 'm';
}
template <typename T>
bool search(const T & name, const std::unordered_map<T, std::vector<T>>& graph) {
    std::queue<std::string> search_queue;
    std::unordered_set<T> searched;

    for(auto & friend_name : graph.find(name)->second) {
        search_queue.push(friend_name);
    }

    while(!search_queue.empty()) {
        T & person = search_queue.front();
        search_queue.pop();
        //查看是否已经检查过
        if(searched.find(person) == searched.end()) {
            //查看是否为销售商
            if(is_seller(person)) {
                std::cout << person << " is a mango seller!" << std::endl;
                return true;
            }
            for(auto & friend_name : graph.find(person)->second) {
                search_queue.push(friend_name);
            }
            searched.insert(person);
        }
    }
    return false;
}

int main()
{
//    std::vector<float> arr = {1.2, 1.0, 3, 0, -1, 0.5, 100, -99, 2, 1 ,23};
//    std::vector<float> res = quick_sort(arr);
//    for(size_t i = 0; i < res.size(); i++) {
//        std::cout << res.at(i) << " ";
//    }


    //std::vector<float> sorted = select_sort(arr);

//    int array[] = {3,2,4,5,6,7,6,7,8,1,3,2,9};
//    select_sort_c(array, 13);
//    for(size_t i = 0; i < sorted.size(); i++) {

//    }
    //std::cout << sum(arr);
    //std::cout << count(arr);
    //std::cout << largest_num(arr);

    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph.insert({"you", {"alice", "bob", "claire"}});
    graph.insert({"bob", {"aunj", "peggy"}});
    graph.insert({"alice", {"peggy"}});
    graph.insert({"claire", {"thom", "jonny"}});
    graph.insert({"aunj", {}});
    graph.insert({"peggy", {}});
    graph.insert({"thom", {}});
    graph.insert({"jonny", {}});

    search(std::string("you"), graph);

    return 0;
}
