#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct OurDataType
{
public:
    int frequency;
    string word;
    OurDataType(string word)
    {
        this->word = word;
        frequency = 1;
    }
};

//constant
bool operator < (const OurDataType& a, const OurDataType& b)
{
    return b.frequency < a.frequency;
}

class Counter
{
private:
    vector<OurDataType> words;
public:
    //linulegt
    void incr(string word)
    {
        for(unsigned int i = 0; i < words.size(); i++)
        {
            if(words[i].word == word)
            {
                words[i].frequency++;
                return;
            }
        }
        //We didn't find the word in the vector so we create it
        OurDataType w(word);
        words.push_back(w);
    }
    //linulegt
    void get_by_freq()
    {
        //We can do this so easily because we made a custom < operator for OurDataType
        sort(words.begin(), words.end());
        for(unsigned int i = 0; i < words.size(); i++)
        {
            cout << words[i].word << " " << words[i].frequency << endl;
        }
    }
};

int main()
{
    Counter counter;
    while(true)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "add")
        {
            string word;
            cin >> word;
            counter.incr(word);
        }
        if(cmd == "print")
        {
            counter.get_by_freq();
        }
    }
    return 0;
}
