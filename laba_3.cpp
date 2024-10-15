#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <string>
using namespace std;

//тут я описал функции, которые использую

template <typename T>
void swapper(vector<T>& vec, size_t i1, size_t i2) {
	if (i1 >= vec.size() || i2 >= vec.size()) {
		cout << "Один из индексов выходит за пределы вектора." << endl;
		return;
	}
	T s = vec[i1];
	vec[i1] = vec[i2];
	vec[i2] = s;
}


string feya(string& str) {
	//ток если не кириллица на линуксе, там поломается из-за разного размера. можно было перевести в чар и по чару определить, что я и сделал в комментариях в 9 кейсе
	int length = str.length();
	string result = "";
	for (int i = 0; i < length; i++) {
		result += "*";
	}
	result += str;
	for (int i = 0; i < length; i++) {
		result += "*";
	}
	return result;
}



void findmaxmin(int a, int b, int c, int& max, int& min) {
	max = a;
	min = a;
	if (b > max) {
		max = b;
	}
	else if (b < min) {
		min = b;
	}
	if (c > max) {
		max = c;
	}
	else if (c < min) {
		min = c;
	}
}


template<class T>
vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
	random_device rd;
	mt19937 e2(rd());
	uniform_real_distribution<> dist(min, max);

	auto lambda = [&e2, &dist]() -> T { return dist(e2); };

	vector<T> result(num);
	generate_n(result.begin(), num, lambda);
	return result;
}




/*
это я выписал, чтобы просто показать как работает erase
template <typename T>
class vector {
public:
	// Удаление элемента по итератору
	iterator erase(iterator pos) {
		// Проверяем, что итератор находится в пределах контейнера
		if (pos < begin() || pos >= end()) {
			return end();
		}
		// Сдвигаем все элементы после удаляемого на одну позицию влево
		copy(pos + 1, end(), pos);
		// Уменьшаем размер вектора на 1
		--size_;
		// Возвращаем итератор на следующий после удаленного элемента
		return pos;
	}
	// Удаление элементов в диапазоне [first, last)
	iterator erase(iterator first, iterator last) {
		// Проверяем, что диапазон находится в пределах контейнера
		if (first < begin() || last > end() || first > last) {
			return end();
		}
		// Сдвигаем все элементы после удаляемых на соответствующее расстояние
		copy(last, end(), first);
		// Уменьшаем размер вектора на количество удаленных элементов
		size_ -= distance(first, last);
		// Возвращаем итератор на следующий после удаленных элементов
		return first;
	}

private:
	size_t size_; // Размер вектора
	T* data_; // Указатель на данные вектора
};
*/






int main(){
	setlocale(LC_ALL, "Russian");
	vector<int> v = generate_random_vector<int>(20, 1, 50);
	vector<int> v1 = generate_random_vector<int>(20, 1, 50);
	vector<int> v2 = generate_random_vector<int>(19, 1, 50);
	string str,str1,str2,str3;
	int N;
	int count11 = 0, count21 = 0, count31 = 0;
	int a;
	int summ = 0;
	int k2, k1;
	int count = 0;
	int i = 0;
	string test;
	char m, n;

	while (true) {
		cout << "Введите число N" << endl;
		cin >> N; //выбор для свича
		cout << "Чтобы выйти, введите 0" << endl;
		
		switch (N) {

		case 1:
			
			cout << "Введите число а." << endl;
			cin >> a;

			cout << "Массив" << endl;
			for (int i = 0; i < v.size(); ++i) {
				cout << v.at(i) << ' ';
			}
			cout << endl;
			cout << "Массив помноженный на 2" << endl;
			for (int i = 0; i < v.size(); ++i) {
				cout << v.at(i) * 2 << ' ';
			}
			cout << endl;
			cout << "Массив + а" << endl;
			for (int i = 0; i < v.size(); ++i) {
				cout << v.at(i) + a << ' ';
			}
			cout << endl;
			cout << "Массив деленный на 1 элемент" << endl;
			for (int i = 0; i < v.size(); ++i) {
				cout << (double)v.at(i) / v.at(0) << ' ';
			}
			cout << endl;

		case 2:
			
			cout << "Сумма массив" << endl;
			for (int i = 0; i < v.size(); ++i) {
				summ += v.at(i);
			}
			cout << summ << endl;
			summ = 0;
			cout << "Сумма квадратов массив" << endl;
			for (int i = 0; i < v.size(); ++i) {
				summ += v.at(i) * v.at(i);
			}
			cout << summ << endl;
			summ = 0;
			cout << "Сумма первых 6 элементов массив" << endl;
			for (int i = 0; i < 6; ++i) {
				summ += v.at(i);
			}
			cout << summ << endl;
			summ = 0;
			cout << "Сумма первых k2 - k1 элементов массив" << endl;
			cin >> k2 >> k1;
			for (int i = k1 - 1; i < k2; ++i) {
				summ += v.at(i);
			}
			cout << summ << endl;
			summ = 0;
			cout << "Среднее арифметическое массива" << endl;
			for (int i = 0; i < v.size(); ++i) {
				summ += v.at(i);
			}
			cout << (double)summ / v.size() << endl;
			summ = 0;
			cout << "Среднее арифметическое первых s2 - s1 элементов массив" << endl;
			cin >> k2 >> k1;
			for (int i = k1 - 1; i < k2; ++i) {
				summ += v.at(i);
			}
			cout << summ / (k2 - k1 + 1) << endl;

		case 3:
			cout << "Введите кол-во первых чисек, которые нужно свапнуть" << endl;
			int g = 2; //количество первых чисел, которые нужно свапнуть
			//cin >> g;
			cout << "Массив 1" << endl;
			for (int i = 0; i < v.size(); ++i) {
				cout << v.at(i) << ' ';
			}

			for (int i = 0; i < g; ++i) {
				swapper(v.at(i), v.at(v.size() - i));
			}
			cout << "Массив 2" << endl;
			for (int i = 0; i < v.size(); ++i) {
				cout << v.at(i) << ' ';
			}

		case 4:
			//гоняю по массиву, ищу отрицательное и удаляю его. Можно было через find_if, но вы сказали, что не нужно использовать шаблон

			cout << "Массив 1" << endl;
			int iterat = -1;
			for (int i = 0; i < v.size(); ++i) {
				if (v.at(i) < 0) {
					iterat = i;
					break;
				}
			}

			if (iterat == -1) {
				cout << "Массив 2" << endl;
				for (int i = 0; i < v.size(); ++i) 
				{
					cout << v.at(i) << ' ';
				}
			}
			else {

				cout << "Массив 2" << endl;
				for (int i = 0; i < v2.size(); ++i) {
					if (i != iterat) v2.at(i) = v.at(i);
				}

				for (int i = 0; i < v2.size(); ++i) {
					cout << v2.at(i) << ' ';
				}
			}

			iterat = 0;
			for (int i = 0; i < v.size(); ++i) {
				if ( v.at(i) % 2 == 0) iterat = i;
			}

			cout << "Массив 3" << endl;
			for (int i = 0; i < v2.size(); ++i) {
				if (i != iterat) v2.at(i) = v.at(i);
			}

			for (int i = 0; i < v2.size(); ++i) {
				cout << v2.at(i) << ' ';
			}


		case 5: 
			cout << "Введите строку" << endl;
				cin >> str;
				while (str[i++] != '\0') {
					++count;
				}
				if (count % 2 == 0) {
					cout << "odd" << endl;
				}
				else cout << "even" << endl;

		case 6:
				cout << "Введите две фамилии" << endl;
				int count1 = 0,count2 = 0;
				i = 0;
				cin >> str1>>str2;
				while (str1[i++] != '\0') {
					++count1;
				}
				while (str2[i++] != '\0') {
					++count2;
				}
				if (count1 > count2) {
					cout << "Первая фамилия длиннее" << endl;
				}
				else cout << "Вторая фамилия длиннее" << endl;

		case 7:
			cout << "Введите три слова" << endl;
				
				i = 0;
				cin >> str1 >> str2 >> str3;
				while (str1[i++] != '\0') {
					++count11;
				}
				while (str2[i++] != '\0') {
					++count21;
				}
				while (str3[i++] != '\0') {
					++count31;
				}
				int maxslovo = 0, minslovo = 0;
				findmaxmin(count11, count21, count31, maxslovo, minslovo);
				if (maxslovo == count11) cout << "Самая длинная строка " << str1 << endl;
				if (maxslovo == count21) cout << "Самая длинная строка " << str2 << endl;
				if (maxslovo == count31) cout << "Самая длинная строка " << str3 << endl;
				if (minslovo == count11) cout << "Самая короткая строка " << str1 << endl;
				if (minslovo == count21) cout << "Самая короткая строка " << str2 << endl;
				if (minslovo == count31) cout << "Самая короткая строка " << str3 << endl;

		case 8:

				cout << "Введите строку" << endl;
				char detection[100];
				for (int i = 0; i < 100; i++) {
					detection[i] = 0;
				}
				cin.getline(detection, 100);
				/*for (int i = 0; i < 100; i++) {    //проверял просто
					cout << detection[i];
				}*/
				cout << "Введите m и n" << endl;
				cin >> m >> n;
				cout << "Слово измененное" << endl;
				for (int i = 0; i < 100; i++) {
					if (detection[i] == m) {
						while (detection[i] != n) {
							cout << detection[i];
							i++;
						}
					}
				}
				cout << n << endl;

		case 9:
			    cout << "Введите строку" << endl;
				cin >> str;
				cout << feya(str) << endl;  //описана функция 
				/*
					string test;
				char detection[100];
				for (int i = 0; i < 100; i++) {
					detection[i] = 0;
				}
				cin.getline(detection, 100);
				for (int i = 0; i < 100; i++) {
					cout << detection[i];
				}
				
				cout << endl<<"Слово измененное" << endl;
				iterat = 0;
				
				for (int i = 0; i < 100; i++) {
					if(detection[i]!=0) iterat++;
				}
				char detection_save[200];
				for(int i = 0; i < iterat; i++) detection_save[i] = '*';
				for(int i = iterat; i < 2*iterat; i++) detection_save[i] = detection[i-iterat];
				for(int i = 2*iterat; i < 3*iterat; i++) detection_save[i] = '*';
			
			    for(int i = 0; i < 3*iterat; i++){
				cout<<detection_save[i];
			    }
				//это если делать без строк, переводя в символы. тут уже работает на всех платформах и на всех компиляторах...
				*/

		case 10:
				//ну если говорить о том, что мы просто не можем методы поиска в строке использовать, то возвращаемся к нашему переводу строки в чары
				//но вообще, нааааааааамного легче было бы через строки
				string test;
				cout << "Введите строку" << endl;
				char a;
				char detection[100];
				for (int i = 0; i < 100; i++) {
					detection[i] = 0;
				}
				cin.getline(detection, 100);
				cout << "Элемент, процентное содержание которого нужно найти" << endl;
				cin >> a;
				iterat = 0;
				int iterat_save = 0;
				for (int i = 0; i < 100; i++) {
					if (detection[i] == a) iterat++;
				}
				for (int i = 0; i < 100; i++){
					if (detection[i] != 0) iterat_save++;
				}
				if (iterat == 0)  cout << "Нема таких букв в слове вашем, сударь" << endl;
				else cout << ((double)iterat / iterat_save) * 100 << "%" << endl;
		case 11:



		case 0:
				return 0;
			}
	}
	return 0;
}


