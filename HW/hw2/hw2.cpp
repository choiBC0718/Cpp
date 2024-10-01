#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {  //PlayerŬ���� : �÷��̾��� �̸��� �Է� �� ���� �� �� �ֵ��� ����
private:
	string name;
public:
	Player() {};  //�Ű����� ���� Player������  -> ��ü �迭�� ���� ����
	
	Player(string name) { //�Ű����� �ִ� Player������    this�� �̿��Ͽ� ��������� �Ű����� �� �Է�
		this->name = name;
	}
	string getName() {  //���� ���� �� ������ �������� ��Ÿ���� ���� �̸� ��� �Լ�
		return name;
	}
};

class GamblingGame {  //GamblingGameŬ���� : ������ ���ư��� ���� ��Ʈ
private:
	int turn=0;       //������ ���� �÷��� �� �� �ֵ��� ���� ����
	Player players[2];//name �ʱ�ȭ�� ���� ���� ��ü �迭 ����
public:
	GamblingGame(string name1, string name2) { //main���� �Ű������� �޴� �κ�
		players[0] = Player(name1);  //�Ű����� �ִ� �����ڸ� ���� name ��� ���� �ʱ�ȭ
		players[1] = Player(name2);
	}

	void gameStart() {
		int randNum[3];//�������� �� �迭
		srand((unsigned)time(0));

		while (true) {
			if (turn > 1) { //turn���� 1���� Ŀ���� �ٽ� 0���� ����
				turn = 0;
			}

			cout << players[turn].getName() << ":<ENTER>";
			cin.ignore();//����Ű �Է¹��� �� ���� ��ٸ�
			for (int i = 0; i < 3; i++) {
				randNum[i] = rand() % 3;  //3���� ���� �������� �迭�� �Է�
			}
			cout << "          " << randNum[0] << "   " << randNum[1] << "   " << randNum[2] << "   ";

			if (randNum[0] == randNum[1] && randNum[1] == randNum[2]) {  //������ 3���� ���� ������ ���� ���
				cout << players[turn].getName() << "�� �¸�!!";
				break;
			}
			else {  //������ 3���� ���� �������� ���� ���� ��� �� �ٸ���� ������ ����
				cout << "�ƽ�����!" << endl;
				turn++;
			}
		}
	}
};

int main() {  //���� �� ���� ��� �� �̸� �Է�, ���� ���� ������ �� �ֵ��� GamblingGame ��ü�� ���� ������ �� �ֵ���
	string name1, name2;

	cout << "***** ���� ������ �����մϴ�. *****" << endl;
	cout << "ù��° ���� �̸�>>";
	getline(cin, name1, '\n');
	cout << "�ι�° ���� �̸�>>";
	getline(cin, name2, '\n');

	GamblingGame game(name1, name2); //�Է��� �̸��� GamblingGame������ �Ű������� ����

	game.gameStart();
}