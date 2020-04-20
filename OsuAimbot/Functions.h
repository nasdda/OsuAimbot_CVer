#pragma once
#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


constexpr auto SX = 322;
constexpr auto SY = 150;

constexpr auto scaleX = 1.75;
constexpr auto scaleY = 1.55;

vector<int> substring(string s, string delim, int times) {
	vector<int> result;
	int pos;
	for (int i = 0; i < times; i++) {
		pos = s.find(delim);
		result.push_back(stoi(s.substr(0, pos)));
		s.erase(0, pos + delim.length());
	}
	return result;
}

void Start(string fileName) {
	ifstream inputFile;
	inputFile.open(fileName); // read hitobject coordinates and timing from file
	string s;
	string delim = ",";
	vector<vector<int>> timings;
	long index = 0;

	while (getline(inputFile, s)) {
		// extract x,y,timing
		timings.push_back(substring(s, delim, 3));
	}
	inputFile.close(); // close file after reading

	int offset = timings[0][2]; // offset all timings
	int temp; // temporarily store previous offset
	timings[0][2] = 0;

	for (int i = 1; i < timings.size(); i++) {
		temp = timings[i][2];
		timings[i][2] -= offset;
		offset = temp;
	}

	for (int i = 0; i < timings.size(); i++) {
		// adds x and y offset to every coordinate
		timings[i][0] *= scaleX;
		timings[i][1] *= scaleY;
		timings[i][0] += SX;
		timings[i][1] += SY;
		timings[i][1] -= 3;
	}

	for (vector<int> v : timings) {
		for (int x : v) {
			cout << x << "    ";
		}
		cout << endl;
	}

	//while (true) {
	//	if (GetAsyncKeyState(0x51) < 0) {
	//		/*cout << timings[index][0] << " | " << timings[index][1] << endl;*/
	//		SetCursorPos(timings[index][0], timings[index][1]);
	//		index++;
	//		Sleep(100);
	//	}
	//}
	bool started = false;
	while (true) {
		if (GetAsyncKeyState(0x51) < 0 and !started) {
			started = true;
			for (int i = 0; i < timings.size(); i++) {
				Sleep(timings[i][2]);
				SetCursorPos(timings[i][0], timings[i][1]);
			}
		}
	}

}
