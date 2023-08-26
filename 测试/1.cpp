#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int k;
    string str;
    cin >> k;
    cin >> str;

    map<string, int> wordFrequency;
    string currentWord = "";

    for (char c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            currentWord += c;
        }
        else
        {
            if (currentWord.size() >= k)
            {
                wordFrequency[currentWord]++;
            }
            currentWord = "";
        }
    }

    if (currentWord.size() >= k)
    {
        wordFrequency[currentWord]++;
    }

    string mostFrequentWord = "-1";
    int maxFrequency = 0;

    for (const auto &entry : wordFrequency)
    {
        if (entry.second > maxFrequency)
        {
            mostFrequentWord = entry.first;
            maxFrequency = entry.second;
        }
        else if (entry.second == maxFrequency)
        {
            if (entry.first.size() < mostFrequentWord.size() ||
                (entry.first.size() == mostFrequentWord.size() && entry.first < mostFrequentWord))
            {
                mostFrequentWord = entry.first;
            }
        }
    }

    cout << mostFrequentWord << endl;

    return 0;
}
