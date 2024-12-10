Write code for a simple ATM. It doesn't need any UI (either graphical or console), but a controller should be implemented and tested.

Requirements
At least the following flow should be implemented:
Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

For simplification, there are only 1 dollar bills in this world, no cents. Thus account balance can be represented in integer.

Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code. Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing the controller part (not including bank system, cash bin etc) is within the scope.

A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.

Based on your work, another engineer should be able to implement the user interface. You don't need to implement any REST API, RPC, network communication etc, but just functions/classes/methods, etc.

You can simplify some complex real world problems if you think it's not worth illustrating in the project.

How to submit
Please upload the code for this project to GitHub or anywhere, and post a link to your repository below. Please attach the instruction to clone your project, build and run tests in README.md file in the root directory of the repository. Please attach the test code(or Test Case), too.

요구사항
다음의 흐름을 구현해야 합니다:

카드 삽입 → PIN 번호 입력 → 계좌 선택 → 잔액 확인/입금/출금
단순화 조건:
이 세상에는 오직 1달러 지폐만 존재합니다(센트 없음).
따라서 계좌 잔액은 정수형으로 표현합니다.
은행 시스템 및 ATM 하드웨어:
실제 은행 시스템과의 연동은 필요하지 않습니다.
실제 ATM의 현금 입출금 장치와의 연동도 필요하지 않습니다.
그러나 이러한 시스템과 연동할 수 있는 가능성을 고려해 코드를 설계해야 합니다.
PIN 번호 확인:
ATM은 PIN 번호를 직접 확인하지 않고, 은행 API가 PIN 번호가 올바른지 여부만 알려줍니다.
UI는 구현하지 않아도 됩니다:
하지만 코드가 UI 개발자가 연동하기 쉽게 설계되어야 합니다.

구현해야 할 사항
1. ATM 컨트롤러 설계
ATM의 핵심 로직을 포함한 컨트롤러 클래스를 설계합니다.
은행 API와 현금 입출금 장치가 추가될 가능성을 고려하여 인터페이스를 설계합니다.

2. 기능 구현
다음 기능을 포함해야 합니다:
카드 삽입
PIN 번호 확인
계좌 선택
잔액 확인
입금
출금

3. 테스트 작성
컨트롤러 클래스의 로직을 검증하는 테스트 코드를 작성해야 합니다.
실제 은행 시스템 및 ATM 하드웨어 없이도 로직이 제대로 작동하는지 확인해야 합니다.
주의사항
확장 가능성:
은행 시스템과 ATM 하드웨어(현금 입출금 장치)와 통합하기 쉽게 설계해야 합니다.
REST API, RPC, 네트워크 통신 등의 구현은 필요하지 않지만, 추후 통합을 고려해야 합니다.

단순화:
복잡한 실제 문제를 단순화하여 구현합니다.

코드 재사용성:
UI를 다른 엔지니어가 구현할 수 있도록 모듈화하고 재사용 가능하게 작성해야 합니다.

테스트 가능성:
코드는 UI 없이도 테스트가 가능해야 하며, 테스트 코드를 제공해야 합니다.

4. 프로그램의 흐름 (Flow)
카드 삽입: 사용자가 카드를 삽입합니다. 특정 계좌(사용자의 카드에 연결된 계좌)를 선택합니다.
PIN 번호 확인: 사용자가 PIN 번호를 입력합니다. 은행 API를 호출하여 PIN 번호가 올바른지 확인합니다.
계좌 선택: 사용자는 연결된 계좌 중 하나를 선택합니다(단일 계좌일 경우 바로 진행).

기능 선택:
    잔액 확인: 계좌 잔액을 확인합니다.
    입금: 입금 금액을 입력합니다. 계좌 잔액이 증가합니다.
    출금: 출금 금액을 입력합니다. 잔액이 충분하면 계좌 잔액이 감소합니다. 잔액이 부족하면 에러를 반환합니다.

구현 방향
클래스 설계
    ATMController: ATM의 메인 로직을 포함.
    BankAPI: 은행 시스템과의 통신을 모사하는 클래스(테스트 가능성을 위해 Mock 구현).
    Account: 계좌 정보를 관리하는 클래스.

테스트 설계
    테스트 환경에서 실제 하드웨어나 은행 시스템 없이 모든 기능을 검증 가능하게 작성.

ATM 구현 코드
아래는 요구사항을 충족하는 Python 코드입니다. 컨트롤러와 은행 시스템(Mock), 계좌(Account) 클래스를 설계했으며, 테스트 가능하도록 작성했습니다.