#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {

    int result = 0;

    // 입력
    int n, m;
    cin >> n;   cin >> m;


    /*
    !!!!! 아래 코드로 했을 때 백준에서 틀렸다고 나오는데 이유를 모르겠습니다ㅠㅠㅠ !!!!!

    // 집합 하나에 주어진 모든 문자열을 저장할 경우
    // 중복되는 문자열은 저장되지 않음
    // 따라서 n+m과 저장된 집합 s의 길이의 차가 중복된 (집합 s에 포함되는 문자열)의 개수가 됨
    set<string> s;
    string input = "";

    for (int i = 0; i < n + m; i++) {
        cin >> input;
        s.insert(input);
    }

    cout << n + m - s.size() << '\n';

    */


    // hashmap을 이용해 집합에 포함되어 있는 문자열을 key값으로 하고
    // 비교해야 하는 문자열을 조회해 map에 있는 경우
    // result를 1 증가시킨다

    string set_input = "";
    string find = "";

    map<string, int> set;
    for (int i = 0; i < n; i++) {
       cin >> set_input;
       set[set_input] = 0; // 모두 0으로 초기화
    }

    for (int i = 0; i < m; i++) {
        // 검색할 문자열 입력 받기
        cin >> find;

        // map에 찾고자 하는 문자열이 있는 경우 +1
        if(set.find(find) != set.end()) {
            result += 1;
        }
    }

    // 최종 결과 출력

    cout << result;

    return 0;
}