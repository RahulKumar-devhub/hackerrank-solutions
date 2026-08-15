// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/hotel-prices/problem?isFullScreen=true
// Problem     Hotel Prices
// Difficulty  Medium
// Subdomain   Debugging
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-15, 10:27 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms)
        : bedrooms_(bedrooms), bathrooms_(bathrooms) {}

    int get_price() {
        return 50 * bedrooms_ + 100 * bathrooms_;
    }

private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms)
        : HotelRoom(bedrooms, bathrooms) {}

    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;

    int total_profit = 0;

    for (int i = 0; i < n; i++) {
        string room_type;
        int bedrooms, bathrooms;

        cin >> room_type >> bedrooms >> bathrooms;

        if (room_type == "standard") {
            HotelRoom room(bedrooms, bathrooms);
            total_profit += room.get_price();
        }
        else if (room_type == "apartment") {
            HotelApartment apartment(bedrooms, bathrooms);
            total_profit += apartment.get_price();
        }
    }

    cout << total_profit << endl;

    return 0;
}
