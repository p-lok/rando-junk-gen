#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>

char hex(int dec)
{
	if (dec > 9)
		return ('A' + 15 - dec);
	else
		return (48 + dec);
}

int main()
{
	srand(time(NULL));
	std::cout << "--Welcome--" << std::endl;
	std::cout << "How many lines would you like?" << std::endl << " : ";
	int count = 0;
	std::cin >> count;
	std::string junks;
	std::ofstream junk;
	junk.open("junks.txt");

	for (int i = 0; i <= count; i++)
	{
		char random_number1 = hex(rand() % 16);
		char random_number2 = hex(rand() % 16);

		junks.append("__asm _emit 0x").append(std::string(1, random_number1)).append(std::string(1, random_number2)).append(" \\\n");
	}
	std::cout << junks;
	junk << junks;
	junk.close();
}