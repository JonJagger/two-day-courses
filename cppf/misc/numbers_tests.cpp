#include <string>
#include <stdexcept>
#include <cassert>
#include <iostream>

const std::string low_numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

const std::string tens[] = { "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

//namespace {
//    int my_strip_rem(int num, int denom) {
//        return num/denom * denom;
//    }
//}

std::string numbers(int num)
{
    if ( ! (num >= 0 && num < 1000000000) )
        throw std::out_of_range("num should be [0,1000000000)");
        
    if (num < 20 )
        return low_numbers[num];
    
    if (num < 100)
    {
        int quot = num / 10;
        int rem = num % 10;
        if (rem == 0)
            return tens[quot - 1];
        else 
            return numbers(quot * 10) + ' ' + numbers(rem);
    }

    if (num < 1000)
    {
        int quot = num / 100;
        int rem = num % 100;
        
        if (rem == 0)
            return numbers(quot) + ' ' + "hundred";
        else 
            return numbers(quot * 100) + " and " + numbers(rem);
    }
    
    if (num < 1000000)
    {
        int quot = num / 1000;
        int rem = num % 1000;

        if (rem == 0)
            return numbers(quot) + ' ' + "thousand";
        else 
            return numbers(quot * 1000) + ' ' + numbers(rem);
    }

    //if (num % 1000000 == 0)
    //    return numbers(num/1000000) + ' ' + "million";
    //
    //return numbers((num/1000000) * 1000000) + ' ' + numbers(num%1000000);
    //if (num % 1000 == 0)
    //    return numbers(num/1000) + ' ' + "thousand";
    //
    //return numbers((num/1000) * 1000) + ' ' + numbers(num%1000);
        
    return "huh?";
}

int main()
{
    assert( numbers(1) == "one" );
    assert( numbers(2) == "two" );
    assert( numbers(12) == "twelve" );
    assert( numbers(50) == "fifty" );
    assert( numbers(52) == "fifty two" );
    assert( numbers(20) == "twenty" );
    assert( numbers(99) == "ninety nine" );
    assert( numbers(100) == "one hundred" );
    assert( numbers(102) == "one hundred and two" );
    assert( numbers(152) == "one hundred and fifty two" );
    assert( numbers(999) == "nine hundred and ninety nine" );
    assert( numbers(1000) == "one thousand" );
    std::cout << numbers(1002) << std::endl;
    assert( numbers(1002) == "one thousand and two" );
    std::cout << numbers(3479) << std::endl;
    assert( numbers(3479) == "three thousand four hundred and seventy nine" );
    assert( numbers(99289) == "ninety nine thousand two hundred and eighty nine" );
    assert( numbers(100000) == "one hundred thousand" );
    assert( numbers(987654) == "nine hundred and eighty seven thousand six hundred and fifty four" );
    
    //assert( numbers(1000001) == "one million and one" );
    
    //assert( numbers(22) == "twentytwo" );
}
