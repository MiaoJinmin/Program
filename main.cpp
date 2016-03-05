#include<iostream>
#include"time.h"
using namespace std;


//运算符两边都是整数
void IntegerCount(){
	int first, second, work;       //work表示运算规则，first表示第一个数，second表示第二个数
		first = rand() % 100;
		work = 1 + rand() % 4;
		if (1 == work){                                  //1表示+，2表示-，3表示*，4表示/
			second = rand() % 100;
			cout << first << " + " << second << endl;
		}
		if (2 == work){
			second = rand() % 100;
			cout << first << " - " << second << endl;
		}
		if (3 == work){
			second = rand() % 100;
			cout << first << " * " << second << endl;
		}
		if (4 == work){
			second = rand() % 100;
			while (0 == second){
				second = rand() % 100;
			}
			cout << first << " / " << second << endl;
		}
}
//运算符左边是整数右边是真分数
void LeftIntegerAndDecimal(){
	int first;
	int secondTop, secondBase;
	int work;
	first = rand()%100;
	secondTop = rand();
	secondBase =1+ rand();
	while (secondTop > secondBase){
		secondTop = rand();
		secondBase = rand();
	}
	work = 1+rand() % 4;
	if (1 == work){
		cout << first << " + " << double(secondTop) / secondBase << endl;
	}
	if (2 == work){
		cout << first << " - " << double(secondTop) / secondBase << endl;
	}
	if (3 == work){
		cout << first << " * " << double(secondTop) / secondBase << endl;
	}
	if (4 == work){
		cout << first << " / " << double(secondTop) / secondBase << endl;
	}
}
//运算符左边是真分数左边是整数
void RightIntegerAndDecimal(){
	int second;
	int firstTop, firstBase;
	int work;
	second =1+ rand() % 100;
	firstTop = rand();
	firstBase = 1 + rand();
	while (firstTop > firstBase){
		firstTop = rand();
		firstBase = rand();
	}
	work =1+ rand() % 4;
	if (1 == work){
		cout << double(firstTop) / firstBase << " + " << second<< endl;
	}
	if (2 == work){
		cout << double(firstTop) / firstBase << " - " << second << endl;
	}
	if (3 == work){
		cout << double(firstTop) / firstBase << " * " << second << endl;
	}
	if (4 == work){
		cout << double(firstTop) / firstBase << " / " << second << endl;
	}
}
//运算符两边都是真分数
void DecimalCount(){
	int fTop, fBase;
	int sTop, sBase;
	int work;
	fTop = 1+rand();
	fBase = fTop + rand();
	sTop = 1+rand();
	sBase = sTop + rand();
	work = 1 + rand() % 4;
	if (1 == work){
		cout << double(fTop) / fBase << " + " << double(sTop) / sBase << endl;
	}
	if (2 == work){
		cout << double(fTop) / fBase << " - " << double(sTop) / sBase << endl;
	}
	if (3 == work){
		cout << double(fTop) / fBase << " * " << double(sTop) / sBase << endl;
	}
	if (4 == work){
		cout << double(fTop) / fBase << " / " << double(sTop) / sBase << endl;
	}
}
int main(){
	int choose; //表示运算的四种种方式1、整数之间2、整数和真分数其中该方式有2种3、真分数和真分数
	srand((unsigned)time(NULL));

	int i=0;
	//四种情况的运算
	while (true){
		choose = rand() % 4;   
		if (choose == 1){
			IntegerCount();
			i = i + 1;
			//循环30次
			if (i == 30){
				break;
			}
		}
		if (choose == 2){
			LeftIntegerAndDecimal();
			i = i + 1;
			if (i == 30){
				break;
			}
		}
		if (choose == 3){
			RightIntegerAndDecimal();
			i = i + 1;
			if (i == 30){
				break;
			}
		}
		if (choose == 4){
			DecimalCount();
			i = i + 1;
			if (i == 30){
				break;
			}
		}
	}
	return 0;
}