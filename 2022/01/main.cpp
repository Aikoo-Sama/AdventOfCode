#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream input("list.txt");
    std::vector<int> sumOfAllElves;
    int sum = 0;
    int second = 0;
    int min = 0;

    for (std::string line; getline(input, line);)
    {
        if (line == "" || line == " ")
        {
            sumOfAllElves.push_back(sum);
            sum = 0;
        }
        else
        {
            sum += std::stoi(line);
        }
    }

    sumOfAllElves.push_back(sum);

    input.close();

    int max = *max_element(std::begin(sumOfAllElves), std::end(sumOfAllElves));

    for (int elem : sumOfAllElves)
    {
        if (elem > second && elem < max)
        {
            second = elem;
        }
        if (elem > min && elem < second)
        {
            min = elem;
        }
    }

    std::cout << "Max: " << max << std::endl;
    std::cout << "Second: " << second << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Sum : " << max + second + min << std::endl;

    return 0;
}
