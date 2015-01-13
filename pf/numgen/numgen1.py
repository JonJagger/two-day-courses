#!/usr/bin/env python3

#
# numgen1.py - a model answer to the numgen homework exercise
#
# This version demonstrates a functional way to write Python.
#

import random
import sys


def main():
    output = input = 'numgen.dat'
    digits = 8
    how_many = 1 if len(sys.argv) == 1 else int(sys.argv[1])

    existing_numbers = read_numbers_from(input)
    new_numbers = generate_new_numbers(how_many, existing_numbers, digits)
    append_numbers_to(new_numbers, output)


def read_numbers_from(filename):
    with open(filename) as source:
        return [line.strip() for line in source]


def append_numbers_to(numbers, filename):
    with open(filename, 'a') as sink:
        for number in numbers:
            print(number)
            print(number, file=sink)


def generate_new_numbers(requested, existing_numbers, digits):
    existing_numbers = set(existing_numbers)
    available = numbers_available(existing_numbers, digits)
    target_size = len(existing_numbers) + min(requested, available)

    while len(existing_numbers) < target_size:
        candidate = random_digit_sequence(digits)
        if can_add_to(candidate, existing_numbers):
            existing_numbers.add(candidate)
            yield candidate


def numbers_available(existing_numbers, digits):
    used = sum(10**(digits - len(number)) for number in existing_numbers)
    return 10**digits - used


def random_digit_sequence(length):
    return ''.join(random.choice('0123456789') for _ in range(length))


def can_add_to(candidate, existing_numbers):
    prefixes = {candidate[:length] for length in range(1, 1 + len(candidate))}
    return not existing_numbers & prefixes


if __name__ == '__main__':
    main()
