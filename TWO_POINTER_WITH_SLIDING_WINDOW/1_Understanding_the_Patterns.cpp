/*

Sliding Window Pattern
The Sliding Window Pattern is an efficient technique used to solve problems involving linear data structures, such as arrays or strings, by maintaining a subset of elements that satisfies certain conditions.


*/

/*
1. Fixed Window Size (Constant Window)
Problem: Find the maximum sum of a subarray of size k.

Approach:

Use a sliding window of fixed size k to calculate the sum of subarrays.
Initialize l = 0 (left pointer), r = k - 1 (right pointer), and sum = 0.
Calculate the initial sum of the first window (arr[0] to arr[k-1]).
Slide the window by moving both pointers to the right, updating the sum by subtracting the element at l and adding the element at r + 1.


int l = 0, r = k - 1, sum = 0;
for (int i = l; i <= r; i++) sum += arr[i];  // Calculate the sum of the first window

int maxSum = sum;

while (r < n - 1) {
    sum = sum - arr[l];  // Remove the left element from the sum
    l++;
    r++;
    sum = sum + arr[r];  // Add the new right element to the sum
    maxSum = max(maxSum, sum);  // Update the maximum sum
}

Time Complexity: O(N)

*/

/*
2. Longest Subarray with Sum ≤ k
Problem: Find the longest subarray with a sum that does not exceed k.

Brute Force Approach:
Use two nested loops to check every subarray.
Track the maximum length of subarrays where the sum is ≤ k.
Time Complexity: O(N^2)

int maxLen = 0;
for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
        sum += arr[j];
        if (sum <= k) {
            maxLen = max(maxLen, j - i + 1);
        } else if (sum > k) {
            break;
        }
    }
}



Optimized Approach:
Use a sliding window technique.
Initialize l = 0, r = 0, sum = 0, maxLen = 0.
Expand the window by moving r until the sum exceeds k.
Shrink the window from the left (l++) until the sum is ≤ k.
Time Complexity: O(2N) ≈ O(N)

int l = 0, r = 0, sum = 0, maxLen = 0;

while (r < n) {
    sum += arr[r];
    while (sum > k) {
        sum -= arr[l];
        l++;
    }

    if (sum <= k) {
        maxLen = max(maxLen, r - l + 1);
    }
    r++;
}



Further Optimized Approach:
The optimal solution simplifies by checking if the sum exceeds k in one pass.
If so, adjust by moving l to maintain a valid window.
Time Complexity: O(N)

int l = 0, r = 0, sum = 0, maxLen = 0;

while (r < n) {
    sum += arr[r];
    if (sum > k) {
        sum -= arr[l];
        l++;
    }

    if (sum <= k) {
        maxLen = max(maxLen, r - l + 1);
    }
    r++;
}

*/

/*
3. Number of Subarrays with Sum = k
Problem: Find the number of subarrays where the sum is exactly k.

Approach:

Instead of a straightforward sliding window approach (where deciding when to expand or shrink is difficult), use the concept of finding:
The number of subarrays with a sum ≤ k (let's call it x).
The number of subarrays with a sum ≤ k - 1 (let's call it y).
The difference between x and y will give the count of subarrays with an exact sum of k.
Template:


// Function to find the number of subarrays with sum <= k
int countSubarraysWithSumLE(int arr[], int n, int k) {
    int l = 0, r = 0, sum = 0, count = 0;

    while (r < n) {
        sum += arr[r];

        // Adjust window to ensure sum is <= k
        while (sum > k) {
            sum -= arr[l];
            l++;
        }

        // All subarrays ending at 'r' with start from 'l' to 'r' have sum <= k
        count += (r - l + 1);
        r++;
    }

    return count;
}

// Main function to find the number of subarrays with sum exactly equal to k
int countSubarraysWithSumEqualK(int arr[], int n, int k) {
    int countWithSumLEK = countSubarraysWithSumLE(arr, n, k);
    int countWithSumLEKMinus1 = countSubarraysWithSumLE(arr, n, k - 1);

    // Difference gives the count of subarrays with exact sum equal to k
    return countWithSumLEK - countWithSumLEKMinus1;
}


Time Complexity: O(N)


*/

/*
4. Minimum Window Subarray Meeting a Condition
Problem: Find the shortest subarray that meets a specific condition (like sum ≥ k or a similar requirement).

Approach:

Use a sliding window to expand (r moves right) until a valid window is found (the condition is satisfied).
Once a valid window is found, try to shrink it from the left (l moves right) to find the smallest window that still meets the condition.
Keep updating the minimum window size whenever a smaller valid window is found.
Template:

// Function to find the minimum length of subarray with sum >= k
int minWindowSubarrayWithCondition(int arr[], int n, int k) {
    int l = 0, r = 0, sum = 0, minLength = INT_MAX;

    while (r < n) {
        sum += arr[r];  // Expand the window by including the current element

        // When a valid window is found (sum >= k)
        while (sum >= k) {
            minLength = min(minLength, r - l + 1);  // Update minimum length
            sum -= arr[l];  // Shrink the window from the left
            l++;
        }

        r++;  // Move right pointer to expand the window further
    }

    // If no valid window was found, minLength will remain INT_MAX
    return (minLength == INT_MAX) ? 0 : minLength;
}


Time Complexity: O(N)
*/