from isbn import *
import unittest


class Test_ISBN_13(unittest.TestCase):

    def test_valid_isbn(self):
        self.assertTrue(is_valid_isbn('9780470059029'))
        self.assertTrue(is_valid_isbn('978 0 471 48648 0'))
        self.assertTrue(is_valid_isbn('978-0596809485'))
        self.assertTrue(is_valid_isbn('978-0-13-149505-0'))
        self.assertTrue(is_valid_isbn('978-0-262-13472-9'))

    def test_invalid_length(self):
        self.assertFalse(is_valid_isbn('978047005902'))
        self.assertFalse(is_valid_isbn(''))
        self.assertFalse(is_valid_isbn('978-0596809485-123123'))

    def test_invalid_characters(self):
        self.assertFalse(is_valid_isbn('a780470059029'))
        self.assertFalse(is_valid_isbn('978047005902_'))
        self.assertFalse(is_valid_isbn('978+0470059029'))
        self.assertFalse(is_valid_isbn('978047005902_9'))

    def test_invalid_check_digit(self):
        self.assertFalse(is_valid_isbn('9780470059020'))
        self.assertFalse(is_valid_isbn('978 0 471 48648 1'))


class Test_ISBN_10(unittest.TestCase):

    def test_valid_isbn(self):
        self.assertTrue(is_valid_isbn('0471958697'))
        self.assertTrue(is_valid_isbn('0 471 60695 2'))
        self.assertTrue(is_valid_isbn('0-470-84525-2'))
        self.assertTrue(is_valid_isbn('0-321-14653-0'))
        self.assertTrue(is_valid_isbn('0-821-14653-X'))

    def test_invalid_length(self):
        self.assertFalse(is_valid_isbn('123123978047005902'))
        self.assertFalse(is_valid_isbn(''))
        self.assertFalse(is_valid_isbn('978'))

    def test_invalid_characters(self):
        self.assertFalse(is_valid_isbn('a471958697'))
        self.assertFalse(is_valid_isbn('047195869_'))
        self.assertFalse(is_valid_isbn('04719X8697'))

    def test_invalid_check_digit(self):
        self.assertFalse(is_valid_isbn('0471958698'))
        self.assertFalse(is_valid_isbn('0 471 60695 1'))
        self.assertFalse(is_valid_isbn('0-470-84525-X'))


if __name__ == '__main__':
    unittest.main()
