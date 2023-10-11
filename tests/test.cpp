#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

int range(int min, int max) {
	int range = max - min;
	return std::rand() % range + min;
}

class Test {
private:
	std::stringbuf sbuf;
	std::streambuf* oldbuf;
	int n;

	void update_state() {
		this->n += 1;
		this->sbuf = std::stringbuf(std::ios::out);
		this->oldbuf = std::cout.rdbuf(std::addressof(this->sbuf));
	}
public:
	Test() {
		this->update_state();
	};
	void out_stream_to_be(std::string expect) {

		std::cout.rdbuf(this->oldbuf);

		std::string output = this->sbuf.str();

		if (output == expect) {
			std::cout << "Тест " << this->n << " пройден\n";
		}
		else {
			std::cout << "Тест " << this->n << " не пройден.\n" << "Ожидаемый результат: " << expect << "\n" << "Полученный результат: " << output << "\n";
		}
		this->update_state();
	}
};


int task(size_t size, std::vector<int> arr, int search)
{
	if (size <= 0) {
		std::cout << "Размер массива не может быть меньше 0" << std::endl;
		return 1;
	}

	bool found = false;

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

int main() {
	Test test = Test();
	setlocale(LC_ALL, "Russian");
	task(0, {}, 0);
	test.out_stream_to_be("Размер массива не может быть меньше 0\n");
	task(5, { 1,2,3,4,5 }, 2);
	test.out_stream_to_be("Найдено число 2\n");
	task(5, { 1,2,3,4,5 }, 10);
	test.out_stream_to_be("Нет числа 10\n");
}
