#include <iostream>
#include <fstream>
#include <list>

int main()
{
    std::ifstream input("list.txt");
    std::list<int> sumOfAllElves;
    int sum = 0;
    int max = 0;
    int second = 0;
    int min = 0;

    for (std::string line; getline(input, line);)
    {
        std::cout << line << std::endl;
        if (line == "")
        {
            sumOfAllElves.push_back(sum);
            sum = 0;
        }
        else
        {
            sum += std::stoi(line);
        }
    }

    input.close();

    for (int elem : sumOfAllElves)
    {
        std::cout << "Elem : " << elem << std::endl;
        if (elem > max)
        {
            max = elem;
        }
        if (elem < second)
        {
            second = elem;
        }
        if (elem < min)
        {
            min = elem;
        }
    }

    std::cout << "Max: " << max << std::endl;
    std::cout << "Second: " << second << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "\n";

    return 0;
}
