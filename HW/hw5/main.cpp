#include <iostream>
#include "GraphicEditor.h"
using namespace std;

int main() {
	GraphicEditor* editor = new GraphicEditor();

	while (true) {
		int choieMenu=UI::menu();
		switch (choieMenu) {
		case 1:
			editor->insertShape();
			break;
		case 2:
			editor->deleteShape();
			break;
		case 3:
			editor->showShape();
			break;
		case 4:
			editor->~GraphicEditor();
			return 0;
		default:
			cout << "�߸��� �� �Է�" << endl<<endl;
			break;
		}
	}
}