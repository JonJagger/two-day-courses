#!/usr/bin/env python3

#
# numgen0.py - a model answer to the numgen homework exercise
#
# This version attempts to look like a typical Unix script, and it
# demonstrates a "naive" and simple way to write Python.
#

import os
import random
import sys

# default configuration
n_digits = 8
numbers_to_generate = 1
dbfile = 'numgen.dat'
max_attempts = 1000

# command line argument
if len(sys.argv) == 2:
    numbers_to_generate = int(sys.argv[1])
if len(sys.argv) > 2 or numbers_to_generate < 0:
    sys.exit(sys.argv[0] + ": Invalid arguments\nusage: numgen [n]")

# open datafile, and load all numbers into memory
numdb = []
with open(dbfile, 'rt') as f:
    for n in f:
        numdb.append(n.strip())

# generate one or more valid numbers
new_numbers = []
while len(new_numbers) < numbers_to_generate:
    n_attempts = 0
    num = None
    while not num and n_attempts < max_attempts:
        n_attempts += 1
        # create a random number
        num = ''
        for _ in range(n_digits):
            num += random.choice('0123456789')
        # check if number is unique and reachable
        if any(num.startswith(n) for n in numdb + new_numbers):
            num = None
    # bail out if we failed to find a number
    if not num:
        sys.exit("unable to generate numbers")
    # we have a valid number, now add it
    new_numbers.append(num)

# append new numbers to datafile and print them to console
with open(dbfile, 'at') as f:
    for num in new_numbers:
        print(num, file=f)
        print(num)
