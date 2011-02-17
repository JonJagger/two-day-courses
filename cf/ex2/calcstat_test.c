#include "calcstat.h"
#include <assert.h>
#include <stdio.h>

void require_reset_zeros_all_fields(void)
{
    struct calcstat stat;
    calcstat_reset(&stat);
    assert(stat.n == 0);
    assert(stat.min == 0);
    assert(stat.max == 0);
    assert(stat.sum == 0);
}

void require_n_field_holds_number_of_updates(void)
{
    struct calcstat stat;
    calcstat_reset(&stat);
    calcstat_update(&stat, 5);
    assert(stat.n == 1);
    calcstat_update(&stat, 5);
    assert(stat.n == 2);
    calcstat_update(&stat, 5);
    assert(stat.n == 3);
}

void require_sum_field_holds_running_total(void)
{
    struct calcstat stat;
    calcstat_reset(&stat);
    calcstat_update(&stat, 5);
    assert(stat.sum == 5);
    calcstat_update(&stat, 6);
    assert(stat.sum == 11);
    calcstat_update(&stat, -2);
    assert(stat.sum == 9);
}

void require_min_field_holds_running_min(void)
{
    struct calcstat stat;
    calcstat_reset(&stat);
    calcstat_update(&stat, 5);
    assert(stat.min == 5);
    calcstat_update(&stat, 54);
    assert(stat.min == 5);
    calcstat_update(&stat, 0);
    assert(stat.min == 0);
    calcstat_update(&stat, 6);
    assert(stat.min == 0);
    calcstat_update(&stat, -2);
    assert(stat.min == -2);
}

void require_max_field_holds_running_max(void)
{
    struct calcstat stat;
    calcstat_reset(&stat);
    calcstat_update(&stat, 5);
    assert(stat.max == 5);
    calcstat_update(&stat, 54);
    assert(stat.max == 54);
    calcstat_update(&stat, 0);
    assert(stat.max == 54);
    calcstat_update(&stat, -65);
    assert(stat.max == 54);
    calcstat_update(&stat, 120);
    assert(stat.max == 120);
}

int main(void)
{
    require_reset_zeros_all_fields();
    require_n_field_holds_number_of_updates();
    require_sum_field_holds_running_total();
    require_min_field_holds_running_min();
    require_max_field_holds_running_max();
    
    puts("calcstat unittest OK");
    
    return 0;
}
