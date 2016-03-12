#include<iostream>
#include"time.h"
#include<fstream>
#define SUM 1000
#define SUMS 300
using namespace std;
int Results[SUM][SUMS] = { 0 };


void Input(int &base, int &top){
	cout << "\n请输入下限（正数） ";
	cin >> base;
	cout << "\n请输入上限（正数） ";
	cin >> top;
}
//生成四则运算公式
void Combination1(int time, int base,int top,int add,int dec,int mul,int div,int equ){
	int choose;
	int amount;
	amount = 2 + rand() % 9;
	Results[time][0] = 1 + rand() % top;
	while (Results[time][0] <= base){
		Results[time][0] = 1 + rand() % top;
	}
	amount--;
	int count = 1;
	while (true){
		choose = 1 + rand() % 4;
		if (choose == 1){
			Results[time][count] = add;
		}
		if (choose == 2){
			Results[time][count] = dec;
		}
		if (choose == 3){
			Results[time][count] = mul;
		}
		if (choose == 4){
			Results[time][count] = div;
		}
		count++;
		Results[time][count] = 1 + rand() % top;
		while (Results[time][count] <= base){
			Results[time][count] = 1 + rand() % top;
		}
		count++;
		amount--;
		if (amount == 0){
			break;
		}
	}
	Results[time][count] = equ;
	
}
//生成二则运算公式
void Combination2(int time, int base, int top, int add, int dec, int mul, int div, int equ){
	int choose;
	int amount;
	amount = 2 + rand() % 9;
	Results[time][0] = 1 + rand() % top;
	while (Results[time][0] <= base){
		Results[time][0] = 1 + rand() % top;
	}
	amount--;
	int count = 1;
	while (true){
		choose = 1 + rand() % 2;
		if (choose == 1){
			Results[time][count] = add;
		}
		if (choose == 2){
			Results[time][count] = dec;
		}
		count++;
		Results[time][count] = 1 + rand() % top;
		while (Results[time][count] <= base){
			Results[time][count] = 1 + rand() % top;
		}
		count++;
		amount--;
		if (amount == 0){
			break;
		}
	}
	Results[time][count] = equ;
}
//cmd
void Output(int time, int top,int add, int dec, int mul, int div, int equ,int LBra,int RBra){
	int count = 0;
	while (true){
		if (Results[time][count] <= top){
			cout << Results[time][count];
		}
		if (Results[time][count] == add){
			cout << "+";
		}
		if (Results[time][count] == dec){
			cout << "-";
		}
		if (Results[time][count] == mul){
			cout << "*";
		}
		if (Results[time][count] == div){
			cout << "/";
		}
		if (Results[time][count] == LBra){
			cout << "(";
		}
		if (Results[time][count] == RBra){
			cout << ")";
		}
		if (Results[time][count] == equ){
			cout << "=";
			break;
		}
		count++;
	}
}
//文件流
void OutputFile(int time, int top, int add, int dec, int mul, int div, int equ, int LBra, int RBra){
	ofstream out("1.txt", ios::out);
	int count;
		for (int i = 0; i < time; i++){
			count = 0;
			while (true){
				
		if (Results[i][count] <= top){
			out << Results[i][count];
		}
		if (Results[i][count] == add){
			out << "+";
		}
		if (Results[i][count] == dec){
			out << "-";
		}
		if (Results[i][count] == mul){
			out << "*";
		}
		if (Results[i][count] == div){
			out << "/";
		}
		if (Results[i][count] == LBra){
			out << "(";
		}
		if (Results[i][count] == RBra){
			out << ")";
		}
		if (Results[i][count] == equ){
			out << "=";
			break;

		}
		count++;
		}
			out << endl;
	}
		out.close();
	
}
//添加括号
void AddBrackets(int time, int add, int dec, int mul, int div, int equ, int LBra,int RBra){
	int place;
	int level=0;
	int sumNum,sumNum1;
	int count;
	int BracketNum;
	BracketNum = 1 + rand() % 2;
	for (int i = 0; i < SUMS; i++){
		if (Results[time][i] >= add&&Results[time][i] <= div){
			level++;
		}
		if (Results[time][i] == equ){
			sumNum = i;
			break;
		}
	}
	int BracketNum1;
	BracketNum1 = BracketNum;
	//随机在运算公式中生成左括号
	for (int j = 0; j < BracketNum; j++){
		sumNum1 = sumNum;
		if (level == 1){
			break;
		}
		place = 1 + rand() % (level - 1);
		count = 0;
		while (true){
			if (Results[time][count] >= add&&Results[time][count] <= div){
				place = place - 1;
				if (place == 0){
					break;
				}
			}
			count++;
		}
		if (Results[time][count + 1] == LBra){
			BracketNum1--;
			break;
		}
		while (true){
			Results[time][sumNum + 1] = Results[time][sumNum];
			if (sumNum - 1 == count){
				Results[time][sumNum] = LBra;
				break;
			}
			sumNum--;
		}
		sumNum = sumNum1 + 1;
	}
	//直接在等式右边生成相同数量的有括号
	for (int k = 0; k < BracketNum1; k++){
		if (level == 1){
			break;
		}
			Results[time][sumNum + 1] = Results[time][sumNum];
			Results[time][sumNum] = RBra;
			sumNum++;
	}
	if (Results[time][sumNum] != equ){
		AddBrackets(time, add, dec, mul, div, equ, LBra, RBra);
	}
	sumNum1 = sumNum-1;
	count = 0;
	while (true){
		if (Results[time][sumNum1] == RBra){
			count++;
		}
		sumNum1--;
		if (sumNum1 == sumNum - 3){
			break;
		}
	}
	sumNum1 = 0;
	while (true){
		if (Results[time][sumNum1] == LBra){
			count--;
		}
		if (sumNum1 == sumNum){
			break;
		}
		sumNum1++;
	}
	if (count < 0){
		AddBrackets(time, add, dec, mul, div, equ, LBra, RBra);
	}
}
//判断有误重复
int Replay(){
	int i, j,k;
	int charge;
	for (i = 0; i < SUM; i++){
		charge = 0;
		for (j = i+1; j < SUM; j++){
			for (k = 0; k < SUMS; k++){
				if (Results[i][k] != Results[j][k]){
					charge = 1;
					break;
				}	
			}
			if (charge == 0){
				return 1;
			}
		}
	}
	return 0;
}

//判断有无余数和是否正数
//把公式化成float型，有利于进行判断有无余数，而且计算更准确
void Judge(int time, int equ, int add, int dec, int mul, int div, int LBra, int RBra, int &pos, int &integer){
	float calculate[SUMS];
	int Bracket[2] = { 0 };  //用于记录括号位置
	int count = 0;
	int sumNum, sumNum1, sumNum2;
	for (int i = 0; i < SUMS; i++){
		if (Results[time][i] == LBra){
			Bracket[count] = i;
			count++;
		}
		if (count == 2){
			break;
		}
		if (Results[time][i] == RBra){
			break;
		}
	}
	for (int i = 0; i < SUMS; i++){
		if (Results[time][i] == RBra){
			sumNum = i;
			break;
		}
	}
	for (int i = 0; i < sumNum; i++){
		calculate[i] = float(Results[time][i]);
	}
	int Has = 0;
	int place;
	//双括号
	if (count == 2){
		sumNum1 = Bracket[1];

		//sumNum2 = sumNum1;
		while (true){
			Has = 0;
			for (int i = sumNum1 + 1; i < sumNum; i++){
				if (calculate[i] == mul)
				{
					calculate[i - 1] = calculate[i - 1] * calculate[i + 1];
					Has = 1;
					place = i;
					break;
				}
				if (calculate[i] == div)
				{
					calculate[i - 1] = calculate[i - 1] / calculate[i + 1];
					Has = 1;
					place = i;
					break;
				}
			}
			if (Has == 1){
				while (true){
					if ((place + 2) == sumNum){
						break;
					}
					calculate[place] = calculate[place + 2];
					place++;


				}
				sumNum -= 2;
			}
			if (Has == 0){
				break;
			}
		}
		sumNum1 += 1;
		sumNum2 = sumNum1;
		while (true){
			if (sumNum1 + 1 >= sumNum){
				break;
			}
			if (calculate[sumNum1 + 1] == add){
				calculate[sumNum2] = calculate[sumNum2] + calculate[sumNum1 + 2];
				sumNum1 += 2;
			}
			if (calculate[sumNum1 + 1] == dec){
				calculate[sumNum2] = calculate[sumNum2] - calculate[sumNum1 + 2];
				sumNum1 += 2;
			}
		}
		calculate[sumNum2 - 1] = calculate[sumNum2];
		sumNum = sumNum2;
		count = count - 1;
	}
	if (count == 1){  //单括号
		sumNum1 = Bracket[0];
		while (true){
			Has = 0;
			for (int i = sumNum1 + 1; i < sumNum; i++){
				if (calculate[i] == mul)
				{
					calculate[i - 1] = calculate[i - 1] * calculate[i + 1];
					Has = 1;
					place = i;
					break;
				}
				if (calculate[i] == div)
				{
					calculate[i - 1] = calculate[i - 1] / calculate[i + 1];
					Has = 1;
					place = i;
					break;
				}
			}
			if (Has == 1){
				while (true){
					if ((place + 2) == sumNum){
						break;
					}
					calculate[place] = calculate[place + 2];
					place++;


				}
				sumNum -= 2;
			}
			if (Has == 0){
				break;
			}
		}
		sumNum1 += 1;
		sumNum2 = sumNum1;
		while (true){
			if (sumNum1 + 1 >= sumNum){
				break;
			}
			if (calculate[sumNum1 + 1] == add){
				calculate[sumNum2] = calculate[sumNum2] + calculate[sumNum1 + 2];
				sumNum1 += 2;
			}
			if (calculate[sumNum1 + 1] == dec){
				calculate[sumNum2] = calculate[sumNum2] - calculate[sumNum1 + 2];
				sumNum1 += 2;
			}
		}
		calculate[sumNum2 - 1] = calculate[sumNum2];
		sumNum = sumNum2;
	}
	for (int i = 0; i < sumNum; i++){
		if (calculate[i] == mul){
			calculate[i - 1] *= calculate[i + 1];
			place = i;
			while (true){
				if (place + 2 >= sumNum){
					sumNum -= 2;
					break;
				}
				calculate[place] = calculate[place + 2];
				place += 1;
			}
		}
		if (calculate[i] == div){
			calculate[i - 1] /= calculate[i + 1];
			place = i;
			while (true){
				
				if (place + 2 >= sumNum){
					sumNum -= 2;
					break;
				}
				calculate[place] = calculate[place + 2];
				place += 1;
			}
		}
	}
	for (int i = 0; i < sumNum; i++){
		if (calculate[i] == add){
			calculate[0] = calculate[0] + calculate[i + 1];
		}
		if (calculate[i] == dec){
			calculate[0] = calculate[0] + calculate[i + 1];
		}
	}
	//结果判断
	if (calculate[0] >= 0){
		pos = 1;
	}
	else{
		pos = 0;
	}
	if ((calculate[0]-int(calculate[0]))!=0)
	{
		integer = 0;
	}
	else{
		integer = 1;
	}
		
}
int main(){
	srand((unsigned)time(NULL));
	int add;
	int dec;
	int mul;
	int div;
	int equ;
	int base;
	int top;
	int LBra;
	int RBra;
	int MulAndDiv;
	int HaveBracket;
	int AboveZero;
	int Isint;
	int Isrepeat;
	int Isfile;
	int sum;
	int integer;
	int pos;
	cout << "是否使用乘除？1表示是，0表示不是： ";
	cin >> MulAndDiv;
	cout << "\n是否有括号？1表示是，0表示不是： ";
	cin >> HaveBracket;
	cout << "\n结果能否有负数？1表示能，0表示不能： ";
	cin >> AboveZero;
	cout << "\n结果能否有余数？ 1表示能，0表示不能： ";
	cin >> Isint;
	cout << "请输入题目数量：";
	cin >> sum;
	cout << "是否输出到文件？ 1表示是，0表示否： ";
	cin >> Isfile;
	Input(base, top);
	add = top + 1;
	dec = top + 2;
	mul = top + 3;
	div = top + 4;
	equ = top + 5;
	LBra = top + 6;
	RBra = top + 7;
	//判断乘除和有无括号
	for (int j = 0; j < sum; j++){
		if (MulAndDiv == 0){
			Combination2(j, base, top, add, dec, mul, div, equ);
		}
		else
			Combination1(j, base, top, add, dec, mul, div, equ);
		if (HaveBracket == 1){
			AddBrackets(j, add, dec, mul, div, equ, LBra, RBra);
		}
		
	}
	//判断有无负数和余数
	for (int j = 0; j < sum; j++){
		pos = 0;
		integer = 0;
		Judge(j, equ, add, dec, mul, div, LBra, RBra, pos, integer);
		if (Isint == 0){
			while (integer == 0){
				if (MulAndDiv == 0){
					Combination2(j, base, top, add, dec, mul, div, equ);
				}
				else
					Combination1(j, base, top, add, dec, mul, div, equ);
				if (HaveBracket == 1){
					AddBrackets(j, add, dec, mul, div, equ, LBra, RBra);
				}
				Judge(j, equ, add, dec, mul, div, LBra, RBra, pos, integer);
			}
		}
		if (AboveZero == 0){
			while (pos == 0){
				if (MulAndDiv == 0){
					Combination2(j, base, top, add, dec, mul, div, equ);
				}
				else
					Combination1(j, base, top, add, dec, mul, div, equ);
				if (HaveBracket == 1){
					AddBrackets(j, add, dec, mul, div, equ, LBra, RBra);
				}
				Judge(j, equ, add, dec, mul, div, LBra, RBra, pos, integer);
			}
		}
	}
		//查重
	while(true){    
		if (Replay() == 1){
			if (Isfile == 1){
				OutputFile(sum, top, add, dec, mul, div, equ, LBra, RBra);
			}
			else{
				for (int j = 0; j < sum; j++){
					Output(j, top, add, dec, mul, div, equ, LBra, RBra);
					cout << endl;
				}
			}
			break;
		}
		else
		{
			for (int j = 0; j < sum; j++){
				if (MulAndDiv == 0){
					Combination2(j, base, top, add, dec, mul, div, equ);
				}
				else
					Combination1(j, base, top, add, dec, mul, div, equ);
				if (HaveBracket == 1){
					AddBrackets(j, add, dec, mul, div, equ, LBra, RBra);
				}

			}
		}
	}
	return 0;
}