#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 길이 비교 정렬 (1번 조건)
bool sortByLength(string a, string b) {
    return a.length() < b.length();
}

// 모든 자리수의 합 구하기
int addString(string s) {
    int result = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i])) {
            result += s[i] - 48;
        }
    }

    return result;
}

// 숫자 합 정렬 (2번 조건)
void sortByAdd(vector<string>& arr) {

    int least_sum = 0; // 가장 작은 원소의 합
    int comp_sum = 0; // 현재 비교할 원소의 합
    int least;

    // 선택 정렬 사용
    for (int i = 0; i < arr.size() - 1; i++)
    {
        least = i; // 합이 가장 작은 원소의 인덱스
        least_sum = addString(arr[i]); // 바깥 for문을 도는 원소로 최소 합 초기화

        for (int j = i + 1; j < arr.size(); j++) {

            // 문자열의 길이가 같은 경우에만 자리수 합 비교
            if(arr[i].length() == arr[j].length()) {
                // 비교 원소의 자리수 합 구하기
                comp_sum = addString(arr[j]);

                // 현재 비교하고 있는 원소(j)의 합이 더 작은 경우 최소값 변수 업데이트
                if(comp_sum < least_sum) {
                    least = j;
                    least_sum = comp_sum;
                }

            }
        }
        swap(arr[i], arr[least]); // 현재 원소와 가장 작은 자리수 원소 바꾸기
    }
    
}

int main()
{
    // 입력
    int n; // 기타의 개수
    cin >> n;
    vector<string> arr(n); // 시리얼 번호 저장 변수
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 오름차순 정렬 (사전순 정렬 먼저, 3번 조건)
    sort(arr.begin(), arr.end());

    // 길이 비교 정렬 (1번 조건)
    sort(arr.begin(), arr.end(), sortByLength);

    // 자리수 합이 작은 순으로 정렬 (2번 조건)
    sortByAdd(arr);
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
}