#
# test_yatzy.py - model answer to the yatzy exercise
#
# Most of these test cases are copied right out of the instructions
#

import yatzy
import unittest


class TestYatzy(unittest.TestCase):

    def test_chance(self):
        self.assertEqual(14, yatzy.score_chance([1, 1, 3, 3, 6]))
        self.assertEqual(21, yatzy.score_chance([4, 5, 5, 6, 1]))

    def test_yatzy(self):
        self.assertEqual(50, yatzy.score_yatzy([1, 1, 1, 1, 1]))
        self.assertEqual(50, yatzy.score_yatzy([5, 5, 5, 5, 5]))
        self.assertEqual(0, yatzy.score_yatzy([1, 1, 1, 2, 1]))

    def test_score_ones(self):
        self.assertEqual(0, yatzy.score_ones([3, 3, 3, 4, 5]))
        self.assertEqual(5, yatzy.score_ones([1, 1, 1, 1, 1]))
        self.assertEqual(2, yatzy.score_ones([1, 3, 3, 1, 5]))

    def test_score_twos(self):
        self.assertEqual(0, yatzy.score_twos([1, 3, 4, 5, 1]))
        self.assertEqual(10, yatzy.score_twos([2, 2, 2, 2, 2]))
        self.assertEqual(4, yatzy.score_twos([2, 3, 2, 5, 1]))

    def test_score_threes(self):
        self.assertEqual(0, yatzy.score_threes([1, 2, 4, 5, 1]))
        self.assertEqual(15, yatzy.score_threes([3, 3, 3, 3, 3]))
        self.assertEqual(3, yatzy.score_threes([2, 3, 2, 5, 1]))

    def test_score_fours(self):
        self.assertEqual(0, yatzy.score_fours([1, 1, 2, 1, 1]))
        self.assertEqual(20, yatzy.score_fours([4, 4, 4, 4, 4]))
        self.assertEqual(8, yatzy.score_fours([1, 1, 2, 4, 4]))

    def test_score_fives(self):
        self.assertEqual(0, yatzy.score_fives([1, 2, 3, 4, 6]))
        self.assertEqual(25, yatzy.score_fives([5, 5, 5, 5, 5]))
        self.assertEqual(20, yatzy.score_fives([5, 5, 5, 4, 5]))

    def test_score_sixes(self):
        self.assertEqual(0, yatzy.score_sixes([3, 3, 3, 4, 5]))
        self.assertEqual(30, yatzy.score_sixes([6, 6, 6, 6, 6]))
        self.assertEqual(18, yatzy.score_sixes([6, 1, 1, 6, 6]))

    def test_pair(self):
        self.assertEqual(8, yatzy.score_pair([3, 3, 3, 4, 4]))
        self.assertEqual(12, yatzy.score_pair([1, 1, 6, 2, 6]))
        self.assertEqual(0, yatzy.score_pair([3, 3, 3, 4, 1]))
        self.assertEqual(0, yatzy.score_pair([3, 3, 3, 3, 0]))

    def test_two_pairs(self):
        self.assertEqual(8, yatzy.score_two_pairs([1, 1, 2, 3, 3]))
        self.assertEqual(0, yatzy.score_two_pairs([1, 1, 2, 3, 4]))
        self.assertEqual(0, yatzy.score_two_pairs([1, 1, 2, 2, 2]))
        self.assertEqual(16, yatzy.score_two_pairs([5, 3, 2, 3, 5]))

    def test_three_of_a_kind(self):
        self.assertEqual(9, yatzy.score_three_of_a_kind([3, 3, 3, 4, 5]))
        self.assertEqual(0, yatzy.score_three_of_a_kind([3, 3, 4, 5, 6]))
        self.assertEqual(0, yatzy.score_three_of_a_kind([3, 3, 3, 3, 1]))

    def test_four_of_a_kind(self):
        self.assertEqual(8, yatzy.score_four_of_a_kind([2, 2, 2, 2, 5]))
        self.assertEqual(0, yatzy.score_four_of_a_kind([2, 2, 2, 5, 5]))
        self.assertEqual(0, yatzy.score_four_of_a_kind([2, 2, 2, 2, 2]))

    def test_small_straight(self):
        self.assertEqual(0, yatzy.score_small_straight([1, 1, 2, 3, 3]))
        self.assertEqual(15, yatzy.score_small_straight([1, 2, 3, 4, 5]))
        self.assertEqual(15, yatzy.score_small_straight([3, 1, 2, 5, 4]))

    def test_large_straight(self):
        self.assertEqual(0, yatzy.score_large_straight([1, 1, 2, 3, 3]))
        self.assertEqual(20, yatzy.score_large_straight([2, 3, 4, 5, 6]))
        self.assertEqual(20, yatzy.score_large_straight([3, 6, 2, 5, 4]))

    def test_full_house(self):
        self.assertEqual(8, yatzy.score_full_house([1, 1, 2, 2, 2]))
        self.assertEqual(0, yatzy.score_full_house([2, 2, 3, 3, 4]))
        self.assertEqual(0, yatzy.score_full_house([4, 4, 4, 4, 4]))
        self.assertEqual(28, yatzy.score_full_house([6, 5, 5, 6, 6]))

if __name__ == '__main__':
    unittest.main()
