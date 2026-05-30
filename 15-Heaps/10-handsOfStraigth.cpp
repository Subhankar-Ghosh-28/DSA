#include <bits/stdc++.h>
using namespace std;

bool isHandsOfStragths(vector<int> &hands, int grpSize)
{
    if (hands.size() % grpSize != 0)
        return false;

    map<int, int> freq;

    for (auto it : hands)
    {
        freq[it]++;
    }

    auto it = freq.begin();

    while (it != freq.end())
    {
        if (it->second == 0)
        {
            it++;
            continue;
        }

        int start = it->first;
        int cnt = it->second;

        for (int i = 0; i < grpSize; i++)
        {
            if (freq[start + i] < cnt)
                return false;

            freq[start + i] -= cnt;
        }

        it++;
    }
    return true;

    // TC->O(n log n)
    // SC->O(n)
}

int main()
{
    // Test case 1
    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    cout << isHandsOfStragths(hand1, groupSize1) << endl;

    // Test case 2
    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;
    cout << isHandsOfStragths(hand2, groupSize2) << endl;
    return 0;
}