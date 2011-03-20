#include "date1.hpp"
#include <stdio.h>

const char * to_string(const mylib_date * date)
{
    static char str[sizeof("yyyy/mm/dd")+1];
    sprintf(str,"%d/%d/%d", date->year, date->month, date->day);
    return str;
}

int main(void)
{
    mylib_date pi_day = {2011,3,14};
    mylib_date pi_approx_day = {2011,7,22};
    int days_apart = mylib_date_diff(&pi_approx_day, &pi_day);
    mylib_date just_another_day = pi_day;
    mylib_date_offset(&just_another_day, -42);
    mylib_date last_day_of_january = {2011,1,31};
    bool is_same = mylib_date_is_equal(&just_another_day, &last_day_of_january);

    printf("Pi day is %s\n", to_string(&pi_day));
    printf("Pi approximation day is %s (hint, %d/%d ~= Pi)\n",
           to_string(&pi_approx_day),           
           pi_approx_day.day, pi_approx_day.month);
    printf("Pi day and Pi approximation day are always %d days apart\n", days_apart);
    printf("%s is 42 days before Pi day, which is%sthe last day of january\n",
           to_string(&just_another_day), (is_same?" ":" not "));
}
