#!/usr/bin/env python3
#
# numgen2.py - a model answer to the numgen homework exercise
#
# This version demonstrates a trie-based solution to check for
# reachability. It also uses argparse to parse arguments, and
# doctest to write unittests.
#
# Test with python -m doctest -v numgen.py
#

from random import random
from string import digits


class PrefixSet:
    """Simple prefix-rejecting set implementation, based on a trie.

    The items added must be non-empty, immutable and iterable, yielding a
    sequence of hashable atoms when iterated (e.g. like strings). The sequence
    of atoms is used as successive dict keys to locate the item in the nested
    dicts that comprise the trie. Each node in the trie is a dict that contains
    atoms referencing dicts (i.e. children nodes) or True (which is the
    sentinel value used to indicate the existence of a set item).

    The set is prefix-rejecting, meaning that it cannot contain items that are
    prefixes of each other, e.g. "foo" and "food" cannot both be in the same
    set. The add() method will reject any item that is either a prefix or
    suffix of an existing item.

    >>> s = PrefixSet()
    >>> s.add('')
    False
    >>> '' in s
    False
    >>> 'foo' in s
    False
    >>> s.add('foo')
    True
    >>> 'foo' in s
    True
    >>> s.add('foo')
    False
    >>> s.add('bar')
    True
    >>> s.add('barf')
    False
    >>> 'barf' in s
    False
    >>> s.add('ba')
    False
    >>> 'ba' in s
    False
    >>> s.add('bah')
    True
    >>> 'bah' in s
    True
    """
    def __init__(self):
        self._root = {}

    @classmethod
    def _search(cls, node, item):
        """Recursively search for 'item' in 'node' and return (leaf, tail).

        'leaf' is the leaf-most node found by traversing from 'node' by
        successive atoms yielded from 'item', and 'tail' is the suffix of
        'item' that remains when 'leaf' was reached.
        Thus the following holds for the returned pair:

        #1 If 'leaf' is True and 'tail' is empty, then 'item' was found
           exactly at 'leaf'.
        #2 If 'leaf' is True and 'tail' is non-empty, then a prefix of 'item'
           was found at 'leaf'.
        #3 If 'leaf' is a dict and 'tail' is empty, then 'item' is a prefix of
           one or more other items contained in 'leaf'.
        #4 If 'leaf' is a dict and 'tail' is non-empty, then 'item' is not
           currently in this set, but can be inserted by creating nested dict
           entries under 'leaf', for each remaining atom in 'tail'.
        """
        try:
            # This raises ValueError when item is exhausted:
            atom, *tail = item
            # This raises TypeError when node is not a dict, or KeyError when
            # atom is not found in node:
            child = node[atom]
        except (ValueError, KeyError, TypeError):
            # In all cases, we return the current node and what remains of item
            return (node, item)
        return cls._search(child, tail)

    def __contains__(self, item):
        """Return True iff 'item' is present in this set."""
        leaf, tail = self._search(self._root, item)
        return leaf is True and not tail  # case #1 above

    def add(self, item):
        """Add the given item to this set.

        Return True iff the item was successfully added, else return False.
        """
        leaf, tail = self._search(self._root, item)
        if isinstance(leaf, dict) and tail:  # case #4 above
            *item, last = tail
            for atom in item:
                leaf[atom] = {}
                leaf = leaf[atom]
            leaf[last] = True  # insert item
            return True
        return False


class Phonebook:
    """Phonebook storing and creating reachable phone numbers.

    The phone numbers are of length 'num_digits' (although shorter phone
    numbers are accepted) and comprise characters from the given 'alphabet'.
    """

    def __init__(self, filename, num_digits, alphabet):
        self.filename = filename
        self.num_digits = num_digits
        self.alphabet = alphabet
        self._numbers = PrefixSet()
        self._new_numbers = []

        self._import(filename)

    @staticmethod
    def _parse_nums(f):
        """Parse and return phone numbers in the given iterable.

        Ignore blank lines and leading/trailing whitespace. The given object
        can be any object that generates phone number strings when iterated,
        e.g. a file object or a list of strings.

        >>> lines = [
        ... '\t911',
        ... '111  ',
        ... '999\t',
        ... '   44338',
        ... '',
        ... '9834593212',
        ... '65291',
        ... '',
        ... ]
        >>> list(Phonebook._parse_nums(lines))
        ['911', '111', '999', '44338', '9834593212', '65291']
        """
        return (line for line in (line.strip() for line in f) if line)

    def _import(self, filename):
        try:
            with open(filename) as f:
                for num in self._parse_nums(iter(f)):
                    assert len(num) <= self.num_digits
                    assert all(digit in self.alphabet for digit in num)
                    assert num not in self._numbers
                    self._numbers.add(num)
                    assert num in self._numbers
        except FileNotFoundError:
            pass

    def create_num(self):
        """Generate a new, unique, N-digit phone number and return it.

        The generated number is guaranteed to be unique and reachable (i.e. the
        number is not a prefix of - or prefixed by - any other number in this
        phone book. The generated number is added to the phone book, and will
        be written to disk on the next call to self.save().
        Raise RuntimeError if the phone book has no room for new numbers.
        """
        def generate_available_number(digits):
            if len(digits) == self.num_digits:  # done!
                return digits

            for digit in sorted(self.alphabet, key=lambda k: random()):
                candidate = digits + [digit]
                if candidate not in self._numbers:
                    ans = generate_available_number(candidate)
                    if ans is not None:  # found a free number
                        return ans
            return None  # zero available numbers with 'digits' as prefix

        try:
            num = "".join(generate_available_number([]))
        except TypeError:  # no number found
            raise RuntimeError("Phonebook is full!") from None

        assert len(num) == self.num_digits
        assert all(digit in self.alphabet for digit in num)
        assert num not in self._numbers
        self._numbers.add(num)
        assert num in self._numbers

        self._new_numbers.append(num)
        return num

    def save(self):
        """Save this phonebook to disk.

        Append the phone numbers created by this object to self.filename.
        """
        with open(self.filename, "a") as f:
            for nun in self._new_numbers:
                print(nun, file=f)
        self._new_numbers = []


def numgen(*, count, db, dry_run=False):
    # import existing nums
    phonebook = Phonebook(filename=db, num_digits=8, alphabet=digits)

    # generate new nums
    for _ in range(count):
        print(phonebook.create_num())

    # store updated phonebook
    if not dry_run:
        phonebook.save()


def main():
    import argparse

    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
        description='Create random, unique, and reachable 8-digit phone '
                    'numbers.')
    parser.add_argument(
        'count', metavar='N', type=int, nargs='?', default=1,
        help='How many numbers to generate')
    parser.add_argument(
        '-n', '--dry-run', action='store_true',
        help='Do not actually update the database')
    parser.add_argument(
        '--db', metavar='FILE', default='numgen.dat',
        help='Specify data file')
    args = parser.parse_args()

    numgen(count=args.count, db=args.db, dry_run=args.dry_run)


if __name__ == '__main__':
    main()
