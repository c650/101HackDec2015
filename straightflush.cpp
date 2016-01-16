#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;
/*
    Checks if straight

    @param cards the vector of cards

    @return true if straight, otherwise false
*/
bool check_if_straight(vector<string>& cards) {
    vector<int> card_ranks;
    
    for (string& card : cards) {
        switch (card[0]) {
            case 'T':
                card_ranks.push_back(10);
                break;
            case 'J':
                card_ranks.push_back(11);
                break;
            case 'Q':
                card_ranks.push_back(12);
                break;
            case 'K':
                card_ranks.push_back(13);
                break;
            case 'A':
                card_ranks.push_back(14);
                break;
            default:
                card_ranks.push_back((int)card[0] - '0');
                break;
        }
    }
    // sort cards to be in order
    sort(card_ranks.begin(), card_ranks.end());
    
    // save location of ace, if there is one
    vector<int>::iterator ace_spot, king_spot, two_spot;
    ace_spot = find(card_ranks.begin(),card_ranks.end(),14);
    king_spot = find(card_ranks.begin(), card_ranks.end(), 13);
    two_spot = find(card_ranks.begin(), card_ranks.end(), 2);
    // when there isn't an ace, or there is a king
    if (ace_spot == card_ranks.end() || king_spot != card_ranks.end()) {
        
        for (int i = 1, n = card_ranks.size() - 1; i < n; i++) {
            if (card_ranks[i] + 1 != card_ranks[i+1]
                || card_ranks[i] - 1 != card_ranks[i-1]) {
                return false;
                break;
            }
        }
    } else {
        // if there is a two,
        if (two_spot != card_ranks.end()) {
            /*
                the last term will be the ace, which we know exists.
                the ace will pose as a 1.
                we only check the first 4 cards.
            */
            for (int i = 1, n = card_ranks.size() - 2; i < n; i++) {
                if (card_ranks[i] + 1 != card_ranks[i+1]
                    || card_ranks[i] - 1 != card_ranks[i-1]) {
                    return false;
                    break;
                }
            }
        } else {
            return false;
            /*
            because if there is an ace, but no two and no king
            the ace ruins the straight
            */
        }
    }
    return true;
}
/*
    Checks if flush

    @param cards the vector of cards

    @return true if flush, otherwise false
*/
bool check_if_flush(vector<string>& cards) {    
    for (int i = 1, n = cards.size(); i < n; i++) {
        if (cards[0][1] != cards[i][1]) {
            return false;
        }
    }
    return true;
}

int main(){
    vector<string> cards(5);
    for(int cards_i = 0;cards_i < 5;cards_i++){
       cin >> cards[cards_i];
    }
    if (check_if_straight(cards) && check_if_flush(cards)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}