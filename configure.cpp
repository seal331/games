#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

bool isnumber(std::string x){
    std::regex e ("^-?\\d+");
    if (std::regex_match (x,e)) return true;
    else return false;}

void minesconfigure() {
	cout << "Configuring mines..." << endl;
	ofstream mineconfig;
	mineconfig.open("mines/config.h");
	if (!mineconfig.is_open() || mineconfig.fail())
	{
		mineconfig.close();
		cout << "ERR: unable to write to mines config file!" << endl;
		exit(1);
	}
	mineconfig << "#pragma once" << endl << endl;
	mineconfig << "// AUTOMATICALLY GENERATED - DO NOT MODIFY" << endl;
	string ans;
	int check = 1;
	while (check) {
		cout << "What is your desired minefield height (cannot be negative or 0)?" << endl;
		cin >> ans;
		if (!isnumber(ans)) {
			cout << "This is not a valid number." << endl;
		} else {
			if (stoi(ans) < 1) {
				cout << "This number is negative or 0." << endl;
			} else {
				mineconfig << "#define Y " << ans << endl;
				check = 0;
			}
		}
	}
	string ans2;
        int check2 = 1;
        while (check2) {
                cout << "What is your desired minefield width (cannot be negative or 0)?" << endl;
                cin >> ans2;
                if (!isnumber(ans2)) {
                        cout << "This is not a valid number." << endl;
                } else {
                        if (stoi(ans2) < 1) {
                                cout << "This number is negative or 0." << endl;
                        } else {
                                mineconfig << "#define X " << ans2 << endl;
                                check2 = 0;
                        }
                }
        }
	string ans3;
        int check3 = 1;
        while (check3) {
                cout << "What is your desired mine amount (cannot be more than the board area)?" << endl;
                cin >> ans3;
                if (!isnumber(ans3)) {
                        cout << "This is not a valid number." << endl;
                } else {
                        if (stoi(ans3) < 1) {
                                cout << "This number is negative or 0." << endl;
                        } else {
				if (stoi(ans3) > stoi(ans) * stoi(ans2)) {
					cout << "You have added way too many mines." << endl;
				} else {
                                	mineconfig << "#define MINES " << ans3 << endl;
                                	check3 = 0;
				}
                        }
                }
        }
	string ans4;
	int check4 = 1;
	while (check4) {
		cout << "Do you want to highlight the number squares (true/false)?" << endl;
		cin >> ans4;
		if ((ans4 != "true") && (ans4 != "false")) {
			cout << "Incorrect input." << endl;
		} else {
			mineconfig << "#define HIGHLIGHT_SQUARES " << ans4 << endl;
			check4 = 0;
		}
	}
	mineconfig.close();
}

void snakeconfigure() {
        cout << "Configuring snake..." << endl;
        ofstream snakeconfig;
        snakeconfig.open("snake/config.h");
        if (!snakeconfig.is_open() || snakeconfig.fail())
        {
                snakeconfig.close();
                cout << "ERR: unable to write to snake config file!" << endl;
                exit(1);
        }
        snakeconfig << "#pragma once" << endl << endl;
        snakeconfig << "// AUTOMATICALLY GENERATED - DO NOT MODIFY" << endl;
        string ans;
        int check = 1;
        while (check) {
                cout << "What is your desired play area height (cannot be negative or less than 2)?" << endl;
                cin >> ans;
                if (!isnumber(ans)) {
                        cout << "This is not a valid number." << endl;
                } else {
                        if (stoi(ans) < 2) {
                                cout << "This number is negative or less than 2." << endl;
                        } else {
                                snakeconfig << "#define Y " << ans << endl;
                                check = 0;
                        }
                }
        }
        string ans2;
        int check2 = 1;
        while (check2) {
                cout << "What is your desired play area width (cannot be negative or less than 2)?" << endl;
                cin >> ans2;
                if (!isnumber(ans2)) {
                        cout << "This is not a valid number." << endl;
                } else {
                        if (stoi(ans2) < 2) {
                                cout << "This number is negative or less than 2." << endl;
                        } else {
                                snakeconfig << "#define X " << ans2 << endl;
                                check2 = 0;
                        }
                }
        }
        string ans3;
        int check3 = 1;
        while (check3) {
                cout << "What is your desired movement delay in milliseconds (cannot be negative or 0)?" << endl;
                cin >> ans3;
                if (!isnumber(ans3)) {
                        cout << "This is not a valid number." << endl;
                } else {
                        if (stoi(ans3) < 1) {
                                cout << "This number is negative or 0." << endl;
                        } else {
                                snakeconfig << "#define DELAY " << ans3 << endl;
                                check3 = 0;
                        }
                }
        }
        string ans4;
        int check4 = 1;
        while (check4) {
                cout << "Do you want to enable solid walls (check documentation for more details) (true/false)?" << endl;
                cin >> ans4;
                if ((ans4 != "true") && (ans4 != "false")) {
                        cout << "Incorrect input." << endl;
                } else {
                        snakeconfig << "#define WALLS " << ans4 << endl;
                        check4 = 0;
                }
        }
        snakeconfig.close();
}

void menu() {
	#warning "GCC may issue a "infinite recursion" warning here."
	#warning "This is a bogus warning as recursion is an integral part of the design of this function and may be broken out of without terminating the program."
	cout << "Please choose the game you want to configure, or press 9 to exit." << endl;
	cout << "1. mines" << endl;
	cout << "2. snake" << endl;
	string ans; // not an int since this is cpp and it doesn't care about memory or type safety
	cin >> ans;
	if (ans == "1") {
		minesconfigure();
		menu();
	} else if (ans == "2") {
                snakeconfigure();
                menu();
        } else if (ans == "9") {
                exit(0);
        } else {
		cout << "Unrecognized input!" << endl;
		menu();
	}
}

int main() {
	cout << "Raniconduh games configure utility" << endl;
	cout << "Written by seal331" << endl;
	cout << "Release 1.0.0" << endl;
	menu();
}
