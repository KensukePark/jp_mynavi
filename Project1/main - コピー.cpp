using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <vector>

template <typename t>
void print(t val) {
	cout << val << endl;
}

vector<string> line_num;
vector<string> line_name;
vector<string> pref_list;

vector<string> split(string str, char Delimiter) { //python split function
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer); 
	}
	return result;
}

void csv_read_location() {
	string str_temp;
	vector<string> vec_temp;
	fstream fs;
	fs.open("location_data.csv", ios::in);
	int cnt = 0;
	while (!fs.eof()) {
		getline(fs, str_temp);
		vec_temp = split(str_temp, ',');
		if (cnt == 0) {
			cnt++;
			continue;
		}
		pref_list.push_back(vec_temp[1]);
		//cout << vec_temp[1] << endl;
		if (cnt == 48) break;
		cnt++;
	}
	fs.close();
}

void csv_read_line() {
	string str_temp;
	vector<string> vec_temp;
	fstream fs;
	fs.open("line_data.csv", ios::in);
	int cnt = 0;
	while (!fs.eof()) {
		getline(fs, str_temp);
		vec_temp = split(str_temp, ',');
		if (cnt == 0) {
			cnt++;
			continue;
		}
		line_num.push_back(vec_temp[0]);
		line_name.push_back(vec_temp[2]);
		if (cnt == 622) break;
		cnt++;
	}
	fs.close();
}

void csv_read_station() {
	string str_temp;
	string line_name_temp;
	vector<string> vec_temp;
	fstream fs;
	string zero = "0";
	fs.open("station_data.csv", ios::in);
	int cnt = 0;
	while (!fs.eof()) {
		getline(fs, str_temp);
		vec_temp = split(str_temp, ',');
		if (cnt == 0) {
			cnt++;
			continue;
		}
		else if (cnt == 10936) break;
		else {
			if (vec_temp[13] == zero) {
				line_name_temp = vec_temp[0].substr(0, vec_temp[0].length() - 2);
				auto it = find(line_num.begin(), line_num.end(), line_name_temp);
				//cout << "line : " << line_name[distance(line_num.begin(), it)] << ", station name : " << vec_temp[2] << endl;
			}
			cnt++;
		}
	}
	fs.close();
}

void searchStationLoc() {

}

void searchStationMain() {
	string temp;
	char command;
	bool _check = false;
	while (true) {
		print("*****************************");
		print("1. 都道府県で探す");
		print("2. 事業者名で探す");
		print("3. 路線名で探す");
		print("4. ホームに戻る");
		print("*****************************");
		if (_check == true) {
			cout << "[ Error! Please write 1 ~ 3 ] " << endl;
		}
		cout << "command : ";
		getline(cin, temp);
		if (temp.length() == 1) {
			command = temp[0];
			switch (command) {
			case '1':
				system("cls");
				print("test");
				_check = false;
				break;
			case '2':
				system("cls");
				print("test");
				_check = false;
				break;
			case '3':
				system("cls");
				print("test");
				_check = false;
				break;
			case '4':
				system("cls");
				_check = false;
				return;
			default:
				system("cls");
				_check = true;
			}
		}
		else {
			system("cls");
			_check = true;
		}
	}
}

void showMain() {
	string temp;
	char command;
	bool _check = false;
	while (true) {
		print("*****************************");
		print("1. 経路探し");
		print("2. 路線情報探し");
		print("3. 終了");
		print("*****************************");
		if (_check == true) {
			cout << "[ Error! Please write 1 ~ 3 ] " << endl;
		}
		cout << "command : ";
		getline(cin, temp);
		if (temp.length() == 1) {
			command = temp[0];
			switch (command) {
			case '1':
				system("cls");
				print("test");
				_check = false;
				break;
			case '2':
				system("cls");
				searchStationMain();
				_check = false;
				break;
			case '3':
				system("cls");
				_check = false;
				return;
			default:
				system("cls");
				_check = true;
			}
		}
		else {
			system("cls");
			_check = true;
		}
	}
}



int main() {
	csv_read_location();
	csv_read_line();
	csv_read_station();
	cout << "read end" << endl;
	showMain();
	return 0;
}
