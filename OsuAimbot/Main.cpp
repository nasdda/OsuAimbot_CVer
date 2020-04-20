#include "Functions.h"
#include <string>
using namespace std;

int main() {
	string fileName = R"(PATH/TO/Timings.txt)";
	cout << fileName << endl;

	Start(fileName);

	//SetCursorPos(SX, SY);

	cin.get();

}
