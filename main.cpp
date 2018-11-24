#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//���������, �������� �� ������
bool is_digit(char a){
	 return a >= '0' && a <= '9';
}

int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string input;//�����
	stringstream ss;	//��������� �����
	while(getline(in, input)){//��������� �� �����������
		 if(input.size() < 2){//���� ������ 2 ������� � ������
			ss << input << '\n';
		 }
		 else if(input.size() == 2 && !is_digit(input[0]) && !is_digit(input[1])){
			 ss << input << '\n';
		 }
		 else if(input.size() > 2 && !(is_digit(input[0]) && is_digit(input[1]) && !is_digit(input[1]))){ //������������ ����������� ������
			 if(!(is_digit(input[input.size() - 1]) && is_digit(input[input.size() - 2]) && !is_digit(input[input.size() - 3]))){
				 bool flag = false;//����� ���������� ����� � ������
				 for(int i = 1; i < input.size() - 2; ++i){
					if(is_digit(input[i]) && is_digit(input[i + 1]) && !is_digit(input[i - 1]) && !is_digit(input[i + 2])){
						flag = true;
						break;
					}
				}
				if(!flag){
					ss << input << '\n';
				}
			 }
		 }

	}
	cout << ss.str();// ������� �����������
	in.close();//��������� ����										   
	system("pause>>void");
}