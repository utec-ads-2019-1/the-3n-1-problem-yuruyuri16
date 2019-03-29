#include <iostream>
#include <vector>

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

    std::vector<std::pair<int, int> > lines;

    while (std::cin >> i >> j)
    {
        lines.push_back(std::make_pair(i, j));
    }

    for (auto i : lines)
    {
        max_cycle = 0;
        for (int j = i.first; j <= i.second; ++j)
        {
            if (get_num_cycles(j) > max_cycle)
            {
                max_cycle = get_num_cycles(j);
            }
        }
        std::cout << i.first << ' ' << i.second << ' ' << max_cycle << '\n';
    }

    return 0;
}
