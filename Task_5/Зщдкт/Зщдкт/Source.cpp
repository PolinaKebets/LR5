#include <iostream>

bool IsEvenNum(char a) {
	return (a == '2' || a == '4' || a == '6' || a == '8' || a == '0');
}

int main() {
	char* arr = new char[80];
	std::cin;
	int n = 0;
	while (std::cin.peek() != '\n') {
		arr[n] = std::cin.get();
		n++;
	}
	arr[n] = '\0';

	for (int i = n - 1; i > 0; i--) {
		if (i != 0 && arr[i] == ' ' && IsEvenNum(arr[i - 1])) {
			std::cout << arr[i] << std::endl;
			while(i > 0 && arr[i] != ' ') i--;
		}
		arr[i] = ' ';
	}
	for (int i = 0; i < n; i++) std::cout << arr[i];
	std::cout << std::endl;
	return 0;
}