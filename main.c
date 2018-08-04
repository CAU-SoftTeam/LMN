/*
���� x_length    y_length   map  alphabet   x   y


�Լ�
int lCheck(x,y){}   mCheck   nCheck    :map[y][x]�� ���� �� �� �ִ��� ������ üũ.  �Ǹ� 1��ȯ �ȵǸ�-1��ȯ
setting:  ���� ����� �Լ�. (�Է¹��� ��ǥ�� 1~20�������� Ȯ��)
isWinner:     ���ڰ� �������� �� �������� Ȯ��. ���ڰ� ������ 0��ȯ �ƴϸ� 1��ȯ
input:   ���� alphabet, x, y�� �� ����. (�Է¹��� ���ĺ��� l,m,n�� �ϳ�����, ��ǥ�� ��ũ�⺸�� �۰ų� ������, �ش� ĭ�� NULL���� Ȯ��)   ����� x�� y�� 0~19�� ��



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
	setting();                //���� ���� �� ĭ���� �Է¹���
	system("cls");

	for (int i = 0;; i++) {
		tempWinner = i;             //tempWinner�� ���� �÷��̾� �ѹ�
		if (!isWinner()) {    //���� ���� ��
			tempWinner = i % 2 == 0 ? 2 : 1;
			printf("���ڴ� %dP �Դϴ�.\n", tempWinner);
			return 0;
		}
		else {             //���� �� ���� ��, (���ĺ�,��ǥ)�Է� ��, ��ġ �� while�� ��������
			while (1) {
				showMap();
				input();					 //�ش� ��ǥ�� ���ĺ� ��ġ
				if (alphabet == 'l') {
					if (lCheck() == 1) {
						map[y][x] = alphabet;
						l = 1;
						break;
					}
					else {
						system("cls");
						printf("��Ģ�� ��߳��� ��ġ�Դϴ�. �ٽ� \n");
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
						printf("��Ģ�� ��߳��� ��ġ�Դϴ�. �ٽ� \n");
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
						printf("��Ģ�� ��߳��� ��ġ�Դϴ�. �ٽ� \n");
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
		printf("ĭ�� ���� ������ ���� �����Ͻÿ�.   (���� ĭ ��*���� ĭ ��)\n��, ������ 1~20�� ����\n ");

		scanf("(%d*%d)", &x_length, &y_length);
		if ((x_length >= 1 && x_length <= 20) && (y_length >= 1 && y_length <= 20)) {
			break;
		}
		else {
			printf("�ٽ� ");
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
	}                                    //chk�� 1�̸� ���� �ȳ��� chk�� 0�̸� ���� ����� ����
	if (chk == x_length * y_length)
		return 0;
	else
		return 1;
}

void input() {
	printf("���ĺ� �ҹ��ڿ� ��ǥ�� ������ ���� �Է��Ͻÿ�.   ex(m,1,12)\n");
	while (1) {
		scanf(" (%c,%d,%d)", &alphabet, &x, &y);
		if (!(alphabet == 'l' || alphabet == 'm' || alphabet == 'n')) continue;                               //l,m,n �ƴ� ���� �Է¹�����
		if ((x >= 1 && x <= x_length) && (y >= 1 && y <= y_length)) break;                      //setting ���� ����, NULL�� �� �ִ� ��ǥ �Է� ������
	}
}

int lCheck() {
	if (map[y][x] != NULL)
		return -1;

	if (l == 0) //l�� �ѹ��� ���� �ʾ��� ��
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

	if (m == 0) //l�� �ѹ��� ���� �ʾ��� ��
		return 1;

	if (map[y - 1][x] == 'm' || map[y + 1][x] == 'm' || map[y][x - 1] == 'm' || map[y][x + 1] == 'm')
		return 1;

	return -1;
}

int nCheck() {
	if (map[y][x] != NULL)
		return -1;

	if (n == 0) //l�� �ѹ��� ���� �ʾ��� ��
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