#include <iostream>
#include<conio.h>
using namespace std;

int P_HP = 100, P_AT = 12, P_DF = 6, P_SPEED = 5, P_COIN = 100, r_t = 0;
int M_HP = 0, M_AT = 0, M_DF = 0;
int choose, chose, escape, buy_chose = 0;
void creat_M() {
	int a;
	srand(time(NULL));
	M_HP = rand() % (70 - 20 + 1) + 20;
	M_AT = rand() % (35 - 0 + 1) + 0;
	M_DF = rand() % (10 - 0 + 1) + 0;
}
void display_P() {
	cout << "Your Health : " << P_HP << endl;
	cout << "Your Attack : " << P_AT << endl;
	cout << "Your Denfence : " << P_DF << endl;
	cout << "Your Speed : " << P_SPEED << endl;
	cout << "Your Coin : " << P_COIN << endl << endl;
}
void display_M() {
	cout << "Monster Health : " << M_HP << endl;
	cout << "Monster Attack : " << M_AT << endl;
	cout << "Monster Denfence : " << M_DF << endl << endl;
}
void display_PvsM(int chose) {
	int temp;
	if (chose == 1) {
		temp = 0;
		temp = M_AT - P_DF;
		if (temp <= 0) {
			;
		}
		else {
			P_HP -= temp;
		}
		temp = 0;
		temp = P_AT - M_DF;
		if (temp <= 0) {
			;
		}
		else {
			M_HP -= temp;
		}
	}
	else if (chose == 2) {
		temp = 0;
		temp = M_AT - P_DF;
		if (temp <= 0) {
			;
		}
		else {
			P_HP -= temp;
		}
	}
	if (P_HP <= 0) {
		P_HP = 0;
	}
	if (M_HP <= 0) {
		M_HP = 0;
	}
	cout << "Your Health: " << P_HP << endl;
	cout << "Monster Health: " << M_HP << endl;
}

int main()
{
	char key;
	int asciivalue;
	string player = "P";
	int x = 0, y = 0;
	cout << "w, a, s, d keys to control the character" << endl << endl;
	display_P();
	cout << "Shop		Monster		Hospital" << endl;
	cout << player;
	while (P_HP > 0) {
		key = _getch();
		asciivalue = key;
		//up
		if (asciivalue == 119) {
			if (y > 0) { y = y - 1; }
		}
		//down
		if (asciivalue == 115) {
			if (y < 10) { y = y + 1; }
		}
		//left
		if (asciivalue == 97) {
			if (x > 0) { x = x - 1; }
		}
		//right
		if (asciivalue == 100) {
			if (x < 39) { x = x + 1; }
		}
		//enter
		if (asciivalue == 13) {
			if (y == 0 && x >= 0 && x <= 3) {
				cout << endl;
				cout << "You can only buy one accessories" << endl;
				cout << "Sword + 2 Att 75coins (1)" << endl;
				cout << "Armor + 2 Def 75coins (2)" << endl;
				cout << "Health potion + 5 hp 75coins (3)" << endl;
				cout << "Quit (4)" << endl;
				cin >> buy_chose;
				do {
					switch (buy_chose)
					{
					case 1:
						if (P_COIN < 45) {
							cout << "You have not enough money!" << endl;
						}
						else {
							P_AT += 2;
							P_COIN -= 45;
						}
						break;
					case 2:
						if (P_COIN < 45) {
							cout << "You have not enough money!" << endl;
						}
						else {
							P_DF += 2;
							P_COIN -= 45;
						}
						break;
					case 3:
						if (P_COIN < 45) {
							cout << "You have not enough money!" << endl;
						}
						else {
							P_HP += 5;
							P_COIN -= 45;
						}
						break;
					case 4:
						break;
					}
					break;
				} while (buy_chose != 1 || buy_chose != 2 || buy_chose != 3 || buy_chose != 4);
			}
			if (y == 0 && x >= 16 && x <= 22) {
				display_P();
				creat_M();
				escape = 0;
				do {
					cout << endl;
					display_M();
					cout << "fight(1) or escape(2)" << endl;;
					cin >> chose;
					if (chose == 1) {
						display_PvsM(1);
					}
					else if (chose == 2) {
						if (M_HP < 30) {
							cout << "escape successfully" << endl << endl;;
							escape = 1;
						}
						else {
							display_PvsM(2);
						}
					}
				} while (escape == 0 && M_HP != 0 && P_HP != 0);
				if (M_HP == 0) {
					cout << "Monster dead, you win" << endl << endl;
					srand(time(NULL));
					P_COIN = P_COIN + rand() % (20 - 1 + 1) + 1;
				}
			}
			if (y == 0 && x >= 32 && x <= 39) {
				P_HP += 5;
				r_t++;
				if (r_t == 3) {
					display_P();
					creat_M();
					escape = 0;
					do {
						cout << endl;
						display_M();
						cout << "fight(1) or escape(2)" << endl;;
						cin >> chose;
						if (chose == 1) {
							display_PvsM(1);
						}
						else if (chose == 2) {
							if (M_HP < 30) {
								cout << "escape successfully" << endl << endl;;
								escape = 1;
							}
							else {
								display_PvsM(2);
							}
						}
					} while (escape == 0 && M_HP != 0 && P_HP != 0);
					if (M_HP == 0) {
						cout << "Monster dead, you win" << endl << endl;
						srand(time(NULL));
						P_COIN = P_COIN + rand() % (20 - 1 + 1) + 1;
					}
					r_t = 0;
				}
			}
		}
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		srand(time(NULL));
		int rd = rand() % 10 + 1;
		if (rd == 2) {
			int rdc = rand() % 5 + 1;
			P_COIN = P_COIN + rdc;
			cout << "You find $" << rdc << endl;
		}
		if (rd == 5) {
			int rdh = rand() % 5 + 1;
			P_HP = P_HP + rdh;
			cout << "You got heal HP:" << rdh << endl;
		}
		if (rd == 9) {
			P_AT++;
			cout << "You find a wweapon, AT+1" << endl;
		}
		if (rd == 7 || rd == 1) {
			cout << "You met a Monster" << endl;
			display_P();
			creat_M();
			escape = 0;
			do {
				cout << endl;
				display_M();
				cout << "fight(1) or escape(2)" << endl;;
				cin >> chose;
				if (chose == 1) {
					display_PvsM(1);
				}
				else if (chose == 2) {
					if (M_HP < 30) {
						cout << "escape successfully" << endl << endl;;
						escape = 1;
					}
					else {
						display_PvsM(2);
					}
				}
			} while (escape == 0 && M_HP != 0 && P_HP != 0);
			if (M_HP == 0) {
				cout << "Monster dead, you win" << endl << endl;
				srand(time(NULL));
				P_COIN = P_COIN + rand() % (20 - 1 + 1) + 1;
			}
		}
		display_P();
		cout << "Shop		Monster		Hospital" << endl;
		for (int i = y; i > 0; i--) {
			cout << endl;
		}
		for (int i = x; i > 0; i--) {
			cout << " ";
		}
		cout << player;
		for (int i = 15 - y; i > 0; i--) {
			cout << endl;
		}

		if (asciivalue == 27) {
			break;
		}
	}
	cout << endl;
	cout << "Game over" << endl;
	cout << "You dead" << endl;
	return 0;
}
