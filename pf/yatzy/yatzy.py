#
# yatzy.py - model answer to the yatzy exercise
#
# The idea is to show a mix of ways to write code in Python
#


def score_chance(dice):
    return sum(dice)


def score_yatzy(dice):
    return 50 if dice[0] == dice[1] == dice[2] == dice[3] == dice[4] else 0


def score_ones(dice):
    s = 0
    for i in dice:
        if i == 1:
            s += 1
    return s


def score_twos(dice):
    return sum([d for d in dice if d == 2])


def score_threes(dice):
    return dice.count(3) * 3


def score_fours(dice):
    tally = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0}
    for d in dice:
        tally[d] += d
    return tally[4]


def score_fives(dice):
    import collections
    c = collections.Counter(dice)
    return c[5] * 5


def score_sixes(dice):
    s = 0
    for x in reversed(sorted(dice)):
        if x == 6:
            s += x
        else:
            break
    return s


def score_pair(dice):
    for x in [6, 5, 4, 3, 2, 1]:
        if dice.count(x) == 2:
            return 2*x
    return 0


def score_two_pairs(dice):
    from collections import Counter
    pairs = [x for x, y in Counter(dice).items() if y == 2]
    return pairs[0]*2 + pairs[1]*2 if len(pairs) == 2 else 0


def score_small_straight(dice):
    return 15 if set(dice) == {1, 2, 3, 4, 5} else 0


def score_large_straight(dice):
    if len(set(dice)) == 5 and min(dice) == 2:
        return 20
    return 0


def _score_n_of_a_kind(dice, n):
    for f in [6, 5, 4, 3, 2, 1]:
        if dice.count(f) == n:
            return f*n
    return 0


def score_three_of_a_kind(dice):
    return _score_n_of_a_kind(dice, 3)


def score_four_of_a_kind(dice):
    return _score_n_of_a_kind(dice, 4)


def score_full_house(dice):
    score_two_of_a_kind = lambda dice: _score_n_of_a_kind(dice, 2)
    parts = score_two_of_a_kind(dice), score_three_of_a_kind(dice)
    return sum(parts) if all(parts) else 0
