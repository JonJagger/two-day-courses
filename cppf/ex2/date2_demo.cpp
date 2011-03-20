#include "date2.hpp"
#include <stdio.h>

const char * to_string(const mylib::date & date)
{
    static char str[sizeof("yyyy/mm/dd")+1];
    sprintf(str,"%d/%d/%d", date.year, date.month, date.day);
    return str;
}

int main()
{
    mylib::date pi_day = {2011,3,14};
    mylib::date pi_approx_day = {2011,7,22};
    int days_apart = pi_approx_day.diff(pi_day);
    mylib::date just_another_day(pi_day);
    just_another_day.offset(-42);
    mylib::date last_day_of_january = {2011,1,31};
    bool is_same = just_another_day.is_equal(last_day_of_january);
    
    printf("Pi day is %s\n", to_string(pi_day));
    printf("Pi approximation day is %s (hint, %d/%d ~= Pi)\n",
           to_string(pi_approx_day),           
           pi_approx_day.day, pi_approx_day.month);
    printf("Pi day and Pi approximation day are always %d days apart\n", days_apart);
    printf("%s is 42 days before Pi day, which is%sthe last day of january\n",
           to_string(just_another_day), (is_same?" ":" not "));
}
