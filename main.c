/*
변수 x_length    y_length   map  alphabet   x   y


함수
int lCheck(x,y){}   mCheck   nCheck    :map[y][x]에 ㅣ이 들어갈 수 있는지 없는지 체크.  되면 1반환 안되면-1반환
setting:  맵을 만드는 함수. (입력받은 좌표가 1~20범위인지 확인)
isWinner:     승자가 나오는지 안 나오는지 확인. 승자가 나오면 0반환 아니면 1반환
input:   변수 alphabet, x, y에 값 대입. (입력받은 알파벳이 l,m,n중 하나인지, 좌표가 맵크기보다 작거나 같은지, 해당 칸이 NULL인지 확인)   결과의 x와 y는 0~19의 수



*/

#include <stdio.h>
#include <Windows.h>


int chk;
char map[200][200] = { 0 };
int x_length, y_length;
char alphabet;
int x, y;
int l = 0, m = 0, n = 0;

void showMap();
void setting();
int isWinner();
void input();
int lCheck();
int mCheck();
int nCheck();

int tempWinner = 0;

int main() {
	setting();                //가로 세로 몇 칸할지 입력받음
	system("cls");

	for (int i = 0;; i++) {
		tempWinner = i;             //tempWinner는 이전 플레이어 넘버
		if (!isWinner()) {    //승자 나올 때
			tempWinner = i % 2 == 0 ? 2 : 1;
			printf("승자는 %dP 입니다.\n", tempWinner);
			return 0;
		}
		else {             //승자 안 나올 때, (알파벳,좌표)입력 후, 배치 후 while문 빠져나옴
			while (1) {
				showMap();
				input();					 //해당 좌표에 알파벳 배치
				if (alphabet == 'l') {
					if (lCheck() == 1) {
						map[y][x] = alphabet;
						l = 1;
						break;
					}
					else {
						system("cls");
						printf("규칙에 어긋나는 배치입니다. 다시 \n");
						continue;
					}
				}

				if (alphabet == 'm') {
					if (mCheck() == 1) {
						map[y][x] = alphabet;
						m = 1;
						break;
					}
					else {
						system("cls");
						printf("규칙에 어긋나는 배치입니다. 다시 \n");
						continue;
					}
				}

				if (alphabet == 'n') {
					if (nCheck() == 1) {
						map[y][x] = alphabet;
						n = 1;
						break;
					}
					else {
						system("cls");
						printf("규칙에 어긋나는 배치입니다. 다시 \n");
						continue;
					}
				}

			}

			system("cls");
		}
	}
	return 0;
}

void setting() {
	while (1) {
		printf("칸의 수를 다음과 같이 설정하시오.   (가로 칸 수*세로 칸 수)\n단, 각각은 1~20의 정수\n ");

		scanf("(%d*%d)", &x_length, &y_length);
		if ((x_length >= 1 && x_length <= 20) && (y_length >= 1 && y_length <= 20)) {
			break;
		}
		else {
			printf("다시 ");
		}
	}
}
int isWinner() {
	chk = 0;
	if (tempWinner == x_length*y_length)
		return 0;
	for (x = 1; x <= x_length; x++) {
		for (y = 1; y <= y_length; y++) {
			if (lCheck() + mCheck() + nCheck() == -3) {
				chk++;
			}
		}
	}                                    //chk가 1이면 승자 안나옴 chk가 0이면 이전 사람이 승자
	if (chk == x_length * y_length)
		return 0;
	else
		return 1;
}

void input() {
	printf("알파벳 소문자와 좌표를 다음과 같이 입력하시오.   ex(m,1,12)\n");
	while (1) {
		scanf(" (%c,%d,%d)", &alphabet, &x, &y);
		if (!(alphabet == 'l' || alphabet == 'm' || alphabet == 'n')) continue;                               //l,m,n 아닌 문자 입력받으면
		if ((x >= 1 && x <= x_length) && (y >= 1 && y <= y_length)) break;                      //setting 범위 안의, NULL이 들어가 있는 좌표 입력 받으면
	}
}

int lCheck() {
	if (map[y][x] != NULL)
		return -1;

	if (l == 0) //l을 한번도 두지 않았을 때
		return 1;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (map[y + (-1 + 2 * i)][x + (-1 + 2 * j)] == 'l')
				return 1;
		}
	}

	return -1;
}

int mCheck() {
	if (map[y][x] != NULL)
		return -1;

	if (m == 0) //l을 한번도 두지 않았을 때
		return 1;

	if (map[y - 1][x] == 'm' || map[y + 1][x] == 'm' || map[y][x - 1] == 'm' || map[y][x + 1] == 'm')
		return 1;

	return -1;
}

int nCheck() {
	if (map[y][x] != NULL)
		return -1;

	if (n == 0) //l을 한번도 두지 않았을 때
		return 1;

	if (x - 2 < 0) {
		if (y - 2 < 0) {
			if (map[y + 2][x] == 'n' || map[y][x + 2] == 'n')
				return 1;
		}
		else {
			if (map[y + 2][x] == 'n' || map[y][x + 2] == 'n' || map[y - 2][x] == 'n')
				return 1;
		}
	}
	else if (y - 2 < 0) {
		if (map[y + 2][x] == 'n' || map[y][x + 2] == 'n' || map[y][x - 2] == 'n')
			return 1;
	}
	else
		if (map[y + 2][x] == 'n' || map[y][x + 2] == 'n' || map[y][x - 2] == 'n' || map[y - 2][x] == 'n')
			return 1;

	return -1;
}

void showMap() {
	printf("    ");   for (int x = 1; x <= x_length; x++)   printf(" %d  ", x);   printf("\n");
	for (int y = 1; y <= y_length; y++) {
		printf("   ");   for (int x = 1; x <= x_length; x++)   printf(" ---");   printf("\n");
		printf(" %d ", y);   for (int x = 1; x <= x_length; x++) { printf("l %c ", (map[y][x] == 0) ? ' ' : map[y][x]); }   printf("l");   printf("\n");
	}
	printf("   ");   for (int x = 1; x <= x_length; x++)   printf(" ---");   printf("\n");
}