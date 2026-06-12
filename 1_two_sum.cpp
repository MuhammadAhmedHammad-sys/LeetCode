#include <iostream>
#include <vector>
using namespace std;

#include <chrono>
#include <thread> // Required for std::this_thread::sleep_for for demonstration

// The function you want to measure
void function_to_time() {
    // Simulate a time-consuming operation
    std::this_thread::sleep_for(std::chrono::milliseconds(150)); 
}

vector<int> twoSum(vector<int> &nums, int target)
{
    int prev_a;
    int prev_sum;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (prev_sum < target && nums[i] < nums[prev_a])
            continue;
        else if (prev_sum > target && nums[i] > nums[prev_a])
            continue;

        for (int j = i + 1; j < n; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
            prev_sum = nums[i] + nums[j];
        }

        prev_a = i;
    }
    return {};
}

// vector<int> twoSum(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = i + 1; j < n; ++j)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }
//     return {}; // If no solution found
// }

int main()
{
    vector<int> a = {2, 7, 11, 15};

    auto start = std::chrono::steady_clock::now();
    for (auto x : twoSum(a, 9))
        cout << x;
     auto end = std::chrono::steady_clock::now();

    // 4. Calculate the duration and cast to desired units (e.g., milliseconds)
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // 5. Print the elapsed time
    std::cout << "Function execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;

}