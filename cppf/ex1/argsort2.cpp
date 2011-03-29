#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, char * argv[])
{
    std::vector<std::string> args(argv, argv + argc);
    std::sort(args.begin(), args.end());
    std::ostream_iterator<std::string> out_it(std::cout,"\n");
    std::copy(args.begin(), args.end(), out_it);
}
