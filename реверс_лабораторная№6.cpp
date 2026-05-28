#include <iostream>
#include <regex>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
 std::ifstream file("test.txt");

 if (!file.is_open()) {
  std::cerr << "Ошибка открытия файла!" << std::endl;
  return 1;
 }
 std::stringstream buffer;
 buffer << file.rdbuf();
 std::string content = buffer.str();

 regex phone_number_pattern(R"(\+\d{1,3}[\s-]?\(?\d{1,4}\)?[\s-]?\d{1,4}[\s-]?\d{1,4})");

 auto begin = std::sregex_iterator(content.begin(), content.end(), phone_number_pattern);
 auto end = std::sregex_iterator();
 int amount = 0;
 for (auto it = begin; it != end; ++it)
 {
  std::cout << it->str() << std::endl;
  amount++;
 }
 cout << "Total amount: " << amount << endl;

 return 0;
}