#include <iostream>
using namespace std;
#include "Dept.h"

int countPass(Dept dept) {	//60점 이상으로 통과하는 학생 수 리턴
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) {
			count++;
		}
	}
	return count;
}

int main() {
	Dept com(10);			//size=10인 객체 com
	com.read();				//10명 학생들의 성적을 키보드로부터 읽어 socres배열에 저장
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명"<<endl;
}