#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//проверяем, является ли числом
bool is_digit(char a){
	 return a >= '0' && a <= '9';
}

int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string input;//слово
	stringstream ss;	//строковый поток
	while(getline(in, input)){//считываем по предложению
		 if(input.size() < 2){//если меньше 2 симвлов в строке
			ss << input << '\n';
		 }
		 else if(input.size() == 2 && !is_digit(input[0]) && !is_digit(input[1])){
			 ss << input << '\n';
		 }
		 else if(input.size() > 2 && !(is_digit(input[0]) && is_digit(input[1]) && !is_digit(input[1]))){ //обрабатываем пограничные случаи
			 if(!(is_digit(input[input.size() - 1]) && is_digit(input[input.size() - 2]) && !is_digit(input[input.size() - 3]))){
				 bool flag = false;//поиск двузначных чисел в строке
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
	cout << ss.str();// выводим предложения
	in.close();//закрываем файл										   
	system("pause>>void");
}