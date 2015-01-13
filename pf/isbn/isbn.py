def _is_valid_isbn13(str):
    if not str.isdigit():
        return False
    *digits, checkdigit = map(int, str)
    res = 10 - sum(a*b for a, b in zip(digits, [1, 3]*6)) % 10
    return checkdigit == res % 10


def _is_valid_isbn10(str):
    chars = str[0:-1]
    checkchar = str[-1]
    if not chars.isdigit() or checkchar not in set('0123456789X'):
        return False
    res = sum(a*int(b) for a, b in enumerate(chars, 1)) % 11
    print(checkchar, res)
    if checkchar == 'X':
        return True if res == 10 else False
    return True if int(checkchar) == res else False


def is_valid_isbn(str):
    str = str.replace(' ', '').replace('-', '')
    if len(str) == 13:
        return _is_valid_isbn13(str)
    elif len(str) == 10:
        return _is_valid_isbn10(str)
    return False
