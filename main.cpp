#include <vector>
#include <iostream>

int get_num_cycles(int n)
{
    int result;

    result = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            result++;
        }
        else
        {
            n = 3 * n + 1;
            result++;
        }
    }
    return ++result;
}

int main(int argc, char **argv) {

    int i;
    int j;
    int max_cycle;

    std::vector<std::pair<std::pair<int, int>, bool> > lines;

    while (std::cin >> i >> j)
    {
        if (i < j)
            lines.push_back(std::make_pair(std::make_pair(i, j), false));
        else
            lines.push_back(std::make_pair(std::make_pair(j, i), true));
    }

    for (auto i : lines)
    {
        max_cycle = 0;
        for (int j = i.first.first; j <= i.first.second; ++j)
        {
            if (get_num_cycles(j) > max_cycle)
            {
                max_cycle = get_num_cycles(j);
            }
        }
        if (i.second == false)
            std::cout << i.first.first << ' ' << i.first.second << ' ' << max_cycle << '\n';
        else
            std::cout << i.first.second << ' ' << i.first.first << ' ' << max_cycle << '\n';
    }

    return 0;
}
