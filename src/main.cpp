#include <iostream>
#include <vector>

int range(int min, int max) {
	int range = max - min;
	return std::rand() % range + min;
}

int main()
{
	std::vector<int> arr;
	size_t size;

	std::cin >> size;

	if (size <= 0) {
		std::cout << "Размер массива не может быть меньше 0" << std::endl;
		return 1;
	}

	for (int i = 0; i < size; i++) {
		arr.push_back(range(0, 20));
	}

	for (auto i = arr.begin(); i != arr.end(); ++i) {
		std::cout << *i << " ";
	}

	std::cout << std::endl;

	int search;
	bool found = false;

	std::cin >> search;

	for (auto i = arr.begin(); i != arr.end(); ++i) {
		if (*i == search) {
			std::cout << "Найдено число " << *i << std::endl;
			found = true;
			break;
		}
	}

	if (!found) {
		std::cout << "Нет числа " << search << std::endl;
	}

	return 0;

}
