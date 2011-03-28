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


int poker_hand::rank() const
{
    std::map<int,int> dups;
    std::map<int,int> suits;
    for(size_t at = 0; at != 5; at++)
    {
        dups[cards[at].pips]++;
        suits[cards[at].suit]++;
    }

    typedef std::pair<int,int> my_pair;
    std::vector<my_pair> counts;
    for(size_t at = 0; at != 5; at++)
        counts.push_back(
            std::make_pair(
                dups[cards[at].pips], 
                cards[at].pips));
    std::sort(counts.begin(), counts.end(), std::greater<my_pair>());


    if (dups.size() == 4 && counts[0].first == 2)
        return pair;
    if (dups.size() == 3 && counts[0].first == 2 && counts[2].first == 2)
        return two_pair;
    if (dups.size() == 3 && counts[0].first == 3)
        return three_of_a_kind;
    if (dups.size() == 2 && counts[0].first == 3)
        return full_house;
    if (dups.size() == 2 && counts[0].first == 4)
        return four_of_a_kind;
    if (suits.size() == 1 && dups.size() == 5 && counts[0].second == counts[4].second + 4)
        return straight_flush;
    if (suits.size() == 1 && dups.size() == 5)
        return flush;
    if (suits.size() != 1 && dups.size() == 5 && counts[0].second == counts[4].second + 4)
        return straight;
    
    return high_card;
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
}

