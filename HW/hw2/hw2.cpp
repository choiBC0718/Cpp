#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {  //Player클래스 : 플레이어의 이름을 입력 및 리턴 할 수 있도록 설정
private:
	string name;
public:
	Player() {};  //매개변수 없는 Player생성자  -> 객체 배열을 위해 설정
	
	Player(string name) { //매개변수 있는 Player생성자    this를 이용하여 멤버변수에 매개변수 값 입력
		this->name = name;
	}
	string getName() {  //게임 시작 후 누구의 차례인지 나타내기 위한 이름 출력 함수
		return name;
	}
};

class GamblingGame {  //GamblingGame클래스 : 게임이 돌아가는 메인 파트
private:
	int turn=0;       //번갈아 가며 플레이 할 수 있도록 변수 설정
	Player players[2];//name 초기화가 되지 않은 객체 배열 생성
public:
	GamblingGame(string name1, string name2) { //main에서 매개변수를 받는 부분
		players[0] = Player(name1);  //매개변수 있는 생성자를 통해 name 멤버 변수 초기화
		players[1] = Player(name2);
	}

	void gameStart() {
		int randNum[3];//랜덤값이 들어갈 배열
		srand((unsigned)time(0));

		while (true) {
			if (turn > 1) { //turn값이 1보다 커지면 다시 0으로 설정
				turn = 0;
			}

			cout << players[turn].getName() << ":<ENTER>";
			cin.ignore();//엔터키 입력받을 때 까지 기다림
			for (int i = 0; i < 3; i++) {
				randNum[i] = rand() % 3;  //3으로 나눈 나머지를 배열에 입력
			}
			cout << "          " << randNum[0] << "   " << randNum[1] << "   " << randNum[2] << "   ";

			if (randNum[0] == randNum[1] && randNum[1] == randNum[2]) {  //랜덤한 3개의 수가 동일할 때의 출력
				cout << players[turn].getName() << "님 승리!!";
				break;
			}
			else {  //랜덤한 3개의 수가 동일하지 않을 때의 출력 및 다른사람 턴으로 변경
				cout << "아쉽군요!" << endl;
				turn++;
			}
		}
	}
};

int main() {  //시작 시 문구 출력 및 이름 입력, 이후 게임 시작할 수 있도록 GamblingGame 객체로 게임 시작할 수 있도록
	string name1, name2;

	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	cout << "첫번째 선수 이름>>";
	getline(cin, name1, '\n');
	cout << "두번째 선수 이름>>";
	getline(cin, name2, '\n');

	GamblingGame game(name1, name2); //입력한 이름을 GamblingGame생성자 매개변수로 전달

	game.gameStart();
}