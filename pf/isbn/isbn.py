#
# isbn.py - model answer for the isbn exercise
#


def _is_valid_isbn13(str):
    if len(str) != 13 or not str.isdigit():
        return False
    *digits, checkdigit = map(int, str)
    res = 10 - sum(a * b for a, b in zip(digits, [1, 3] * 6)) % 10
    return checkdigit == res % 10


def _is_valid_isbn10(str):
    if len(str) != 10:
        return False
    chars = str[0:-1]
    checkchar = str[-1]
    if not chars.isdigit() or checkchar not in set('0123456789X'):
        return False
    res = sum(a * int(b) for a, b in enumerate(chars, 1)) % 11
    if checkchar == 'X':
        return res == 10
    return int(checkchar) == res


def is_valid_isbn(str):
    str = str.replace(' ', '').replace('-', '')
    return _is_valid_isbn13(str) or _is_valid_isbn10(str)
