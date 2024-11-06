#include "tweet.h"

int binarySearch(const std::vector<Tweet>& tweets, long long key, const std::string& sortBy) {
    int size = tweets.size();
    int l = 0, h = size - 1;

    while(l <= h) {
        int mid = (l + h) / 2;
        
        if(sortBy == "tweetID") {
            if(tweets[mid].tweetID == key) {
                return mid;
            }
            else if(tweets[mid].tweetID < key) {
                l = mid + 1;
            } 
            else {
                h = mid - 1;
            }  
        }
        else if(sortBy == "retweetCount") {
            if(tweets[mid].retweetCount == key) {
                return mid;
            }
            else if(tweets[mid].retweetCount < key) {
                l = mid + 1;
            } 
            else {
                h = mid - 1;
            }         
        }
        else if(sortBy == "favoriteCount") {
            if(tweets[mid].favoriteCount == key) {
                return mid;
            }
            else if(tweets[mid].favoriteCount < key) {
                l = mid + 1;
            } 
            else {
                h = mid - 1;
            }
        }
    }
    return -1;
}

int countAboveThreshold(const std::vector<Tweet>& tweets, const std::string& metric, int threshold) {
    std::vector<Tweet> sortedTweets = tweets;  // copy
    mergeSort(sortedTweets, 0, sortedTweets.size() - 1, metric, false); // sort descending order
    
    int i = 0;
    if(metric == "favoriteCount") {
        int favTweets = 0;
        while(sortedTweets[i].favoriteCount > threshold) {
            favTweets++;
            i++;
        }
        return favTweets;
    }
    else if(metric == "retweetCount") {
        int retweet = 0;
        while(sortedTweets[i].retweetCount > threshold) {
            retweet++;
            i++;
        }
        return retweet;
    }
    else {
        return -1;
    }
}   
