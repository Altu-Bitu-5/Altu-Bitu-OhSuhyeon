#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    // 입력
    int n;
    cin >> n;

    stack<int> s;
    vector<int> nums(n);
    vector<int> result(n);

    // 숫자 입력
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 역순으로 저장된 값 크기 비교
    for (int i = n - 1; i >= 0; i--) {
        // 현재 비교 숫자보다 작은 값들이 스택에 저장되어 있으면 모두 삭제
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(nums[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }
    
    return 0;
}