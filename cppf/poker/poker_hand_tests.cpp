#include "untitled.hpp"
#include <cassert>
#include <vector>

enum { 
    straight_flush, four_of_a_kind, full_house, flush, straight, 
    three_of_a_kind, two_pair, pair, high_card 
};

enum suit { clubs, diamonds, hearts, spades };

struct card
{
    card(int pips, int suit) : pips(pips), suit(suit) {}
    int pips;
    int suit;
};

class poker_hand
{
public:
    poker_hand(card c1, card c2, card c3, card c4, card c5)
    {
        cards.push_back(c1);
        cards.push_back(c2);
        cards.push_back(c3);
        cards.push_back(c4);
        cards.push_back(c5);
    }

    int rank() const;

private:
    std::vector<card> cards;
};

#include <map>
#include <utility>
#include <algorithm>
#include <functional>

typedef std::pair<int,int> my_pair;

bool is_straight(const std::vector<my_pair> & counts)
{
    return counts[0].second == counts[4].second + 4;
}

int poker_hand::rank() const
{
    std::map<int,int> dups;
    std::map<int,int> suits;
    for(size_t at = 0; at != 5; at++)
    {
        dups[cards[at].pips]++;
        suits[cards[at].suit]++;
    }

    std::vector<my_pair> counts;
    for(size_t at = 0; at != 5; at++)
        counts.push_back(
            std::make_pair(dups[cards[at].pips], cards[at].pips)
        );
    std::sort(counts.begin(), counts.end(), std::greater<my_pair>());

    switch (counts[0].first)
    {
    case 4: return four_of_a_kind;
    case 3: return counts[3].first == 2 ? full_house : three_of_a_kind;
    case 2: return counts[2].first == 2 ? two_pair : pair;
    }

    if (suits.size() == 1)
        return is_straight(counts) ? straight_flush : flush;
    else 
        return is_straight(counts) ? straight : high_card;
}

int main(void)
{
    poker_hand h1(card(5,hearts), card(2,hearts), card(3,hearts), card(5,clubs), card(6,spades));
    assert(h1.rank() == pair);

    poker_hand h2(card(5,hearts), card(2,hearts), card(3,hearts), card(5,clubs), card(2,spades));
    assert(h2.rank() == two_pair);

    poker_hand h3(card(5,hearts), card(2,hearts), card(3,hearts), card(5,clubs), card(5,spades));
    assert(h3.rank() == three_of_a_kind);

    poker_hand h4(card(5,hearts), card(2,hearts), card(2,diamonds), card(5,clubs), card(5,spades));
    assert(h4.rank() == full_house);

    poker_hand h5(card(5,hearts), card(5,diamonds), card(2,diamonds), card(5,clubs), card(5,spades));
    assert(h5.rank() == four_of_a_kind);

    poker_hand h6(card(5,hearts), card(6,hearts), card(7,hearts), card(8,hearts), card(9,hearts));
    assert(h6.rank() == straight_flush);

    poker_hand h7(card(5,hearts), card(6,hearts), card(2,hearts), card(8,hearts), card(9,hearts));
    assert(h7.rank() == flush);

    poker_hand h8(card(5,hearts), card(6,hearts), card(7,diamonds), card(8,hearts), card(9,hearts));
    assert(h8.rank() == straight);

    poker_hand h9(card(5,hearts), card(6,hearts), card(7,diamonds), card(8,hearts), card(3,hearts));
    assert(h9.rank() == high_card);

    const int jack = 11, queen = 12, king = 13, ace = 14;

    poker_hand h10(card(ace,hearts), card(king,hearts), card(queen,hearts), card(jack,hearts), card(10,hearts));
    assert(h10.rank() == straight_flush);

}
