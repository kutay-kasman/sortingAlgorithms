#include "tweet.h"
using namespace std;

std::vector<Tweet> readTweetsFromFile(const std::string& filename) {
    vector<Tweet> tweets; // it will be copied tweets in the file to this vector
    ifstream file(filename);

    if(!file) {
        cerr << "File cannot be opened!" << "\n";
    }
    string eachLine;

    getline(file, eachLine); // we skipped first line because it is description line

    while(getline(file, eachLine)) { // when ther is a line in the file didn't traversed
        stringstream ss(eachLine); // it parses the line
        Tweet tweet;
        string value;

        getline(ss, value, ',');
        tweet.tweetID = stoll(value);

        getline(ss, value, ',');
        tweet.retweetCount = stoi(value);

        getline(ss, value, ',');
        tweet.favoriteCount = stoi(value);
        
        tweets.push_back(tweet);
    }

    file.close();

    return tweets;
}

void writeTweetsToFile(const std::string& filename, const std::vector<Tweet>& tweets) {
    ofstream file(filename, ios::app);

    if(!file) {
        cerr << "Cannot be opened!" << "\n";
        return;
    }
    for(auto tweet : tweets) {
        file << tweet.tweetID << "," << tweet.retweetCount << "," << tweet.favoriteCount << "\n";
    }

    file.close();
}