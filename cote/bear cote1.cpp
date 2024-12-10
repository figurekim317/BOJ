#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <cctype>
#include <algorithm>

using namespace std;

// 조건 1: 대문자 포함 여부 검사
// [](parameters) -> return_type {
    // 함수 본문}
bool containsUpperCase(const string &str) {
    return any_of(str.begin(), str.end(), [](char c) { return isupper(c); });
}

// 조건 2: 숫자 포함 여부 검사
bool containsDigit(const string &str) {
    return any_of(str.begin(), str.end(), [](char c) { return isdigit(c); });
}

// 조건 3: 특수 문자 포함 여부 검사
bool containsSpecialCharacter(const string &str) {
    const string specialChars = "!@#$%^&*()_+=~`<>?/.,:;";
    return any_of(str.begin(), str.end(), [&specialChars](char c) {
        return specialChars.find(c) != string::npos;
    });
}

// 조건 4: "password" 포함 여부 검사
bool doesNotContainPassword(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr.find("password") == string::npos;
}

// 조건 5: 길이 검사
bool isLengthValid(const string &str) {
    return str.length() > 7 && str.length() < 31;
}

// 메인 검사 함수
string StringChallenge(const string &strParam) {
    // 조건 검사 함수 포인터 배열
    vector<function<bool(const string &)>> conditions = {
        containsUpperCase,
        containsDigit,
        containsSpecialCharacter,
        doesNotContainPassword,
        isLengthValid
    };

    // 조건 검사
    for (const auto &check : conditions) {
        if (!check(strParam)) {
            return "false"; // 하나라도 조건을 만족하지 않으면 false 반환
        }
    }
    return "true"; // 모든 조건을 만족하면 true 반환
}

// 메인 함수
int main() {
    string userInput;

    // 사용자 입력 받기
    cout << "Enter a string to check if it is a valid password: ";
    getline(cin, userInput); // 공백 포함 입력 처리

    // StringChallenge 함수 호출 및 결과 출력
    cout << StringChallenge(userInput) << endl;

    return 0;
}
