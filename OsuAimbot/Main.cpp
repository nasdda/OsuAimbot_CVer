#include "Functions.h"
#include <string>
using namespace std;

int main() {
	string fileName = R"(C:\Users\Xin\source\repos\OsuAimbot\OsuAimbot\Timings.txt)";
	cout << fileName << endl;

	Start(fileName);

	//SetCursorPos(SX, SY);

	cin.get();

}