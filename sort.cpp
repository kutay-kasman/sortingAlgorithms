#include "tweet.h"

void bubbleSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) { // not a ideal algorithm, I wil improve it
    if(sortBy == "tweetID") {
        if(ascending) {
            for(int i = 0; i < tweets.size() - 1; i++) {
                for(int j = 0; j < tweets.size() - i - 1; j++) {
                    if(tweets[j].tweetID > tweets[j + 1].tweetID) {
                        std::swap(tweets[j], tweets[j + 1]);
                    }
                }
            }
            return;
        }
        else {
            for(int i = 0; i < tweets.size() - 1; i++) {
                for(int j = 0; j < tweets.size() - i - 1; j++) {
                    if(tweets[j].tweetID < tweets[j + 1].tweetID) {
                        std::swap(tweets[j], tweets[j + 1]);
                    }
                }
            }
            return;
        }
    }
    else if(sortBy == "retweetCount") {
        if(ascending) {
            for(int i = 0; i < tweets.size() - 1; i++) {
                for(int j = 0; j < tweets.size() - i - 1; j++) {
                    if(tweets[j].retweetCount > tweets[j + 1].retweetCount) {
                        std::swap(tweets[j], tweets[j + 1]);
                    }
                }
            }
            return;
        }
        else {
            for(int i = 0; i < tweets.size() - 1; i++) {
                for(int j = 0; j < tweets.size() - i - 1; j++) {
                    if(tweets[j].retweetCount < tweets[j + 1].retweetCount) {
                        std::swap(tweets[j], tweets[j + 1]);
                    }
                }
            }
            return;
        }
    }
    else if(sortBy == "favoriteCount") {
        if(ascending) {
            for(int i = 0; i < tweets.size() - 1; i++) {
                for(int j = 0; j < tweets.size() - i - 1; j++) {
                    if(tweets[j].favoriteCount > tweets[j + 1].favoriteCount) {
                        std::swap(tweets[j], tweets[j + 1]);
                    }
                }
            }
            return;
        }
        else {
            for(int i = 0; i < tweets.size() - 1; i++) {
                for(int j = 0; j < tweets.size() - i - 1; j++) {
                    if(tweets[j].favoriteCount < tweets[j + 1].favoriteCount) {
                        std::swap(tweets[j], tweets[j + 1]);
                    }
                }
            }
        }
    }    
}

void insertionSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) {
    if(sortBy == "tweetID") {
        if(ascending) {
            for(int i = 1; i < tweets.size(); i++) {
                long long key = tweets[i].tweetID;
                int j = i - 1;
                while(j >= 0 && tweets[j].tweetID > key) {
                    tweets[j + 1].tweetID = tweets[j].tweetID;
                    j--;
                }
                tweets[j + 1].tweetID = key;
            }
        }
        else {
            for(int i = 1; i < tweets.size(); i++) {
                long long key = tweets[i].tweetID;
                int j = i - 1;
                while(j >= 0 && tweets[j].tweetID < key) {
                    tweets[j + 1].tweetID = tweets[j].tweetID;
                    j--;
                }
                tweets[j + 1].tweetID = key;
            }
        }
    }
    else if(sortBy == "retweetCount") {
        if(ascending) {
            for(int i = 1; i < tweets.size(); i++) {
                int key = tweets[i].retweetCount;
                int j = i - 1;
                while(j >= 0 && tweets[j].retweetCount > key) {
                    tweets[j + 1].retweetCount = tweets[j].retweetCount;
                    j--;
                }
                tweets[j + 1].retweetCount = key;
            }
        }
        else {
            for(int i = 1; i < tweets.size(); i++) {
                int key = tweets[i].retweetCount;
                int j = i - 1;
                while(j >= 0 && tweets[j].retweetCount < key) {
                    tweets[j + 1].retweetCount = tweets[j].retweetCount;
                    j--;
                }
                tweets[j + 1].retweetCount = key;
            }
        }
    }
    else if(sortBy == "favoriteCount") {
        if(ascending) {
            for(int i = 1; i < tweets.size(); i++) {
                int key = tweets[i].favoriteCount;
                int j = i - 1;
                while(j >= 0 && tweets[j].favoriteCount > key) {
                    tweets[j + 1].favoriteCount = tweets[j].favoriteCount;
                    j--;
                }
                tweets[j + 1].favoriteCount = key;
            }
        }
        else {
            for(int i = 1; i < tweets.size(); i++) {
                int key = tweets[i].favoriteCount;
                int j = i - 1;
                while(j >= 0 && tweets[j].favoriteCount < key) {
                    tweets[j + 1].favoriteCount = tweets[j].favoriteCount;
                    j--;
                }
                tweets[j + 1].favoriteCount = key;
            }
        }
    }
}

void merge(std::vector<Tweet>& tweets, int left, int mid, int right, const std::string& sortBy, bool ascending) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    if(sortBy == "tweetID") {
        long long* leftArr = new long long[leftSize];
        long long* rightArr = new long long[rightSize];

        for(int i = 0; i < leftSize; i++) {  // copying values to temp arrays
            leftArr[i] = tweets[left + i].tweetID;
        }
        for(int j = 0; j < rightSize; j++) {
            rightArr[j] = tweets[mid + 1 + j].tweetID;
        }

        int i = 0, j = 0, k = left;

        while(i < leftSize && j < rightSize) {  // compare and assing it to existing array
            if(ascending) {
                if(leftArr[i] < rightArr[j]) {
                    tweets[k++].tweetID = leftArr[i++];
                }
                else {
                    tweets[k++].tweetID = rightArr[j++]; 
                }
            }
            else {
                if(leftArr[i] > rightArr[j]) {
                    tweets[k++].tweetID = leftArr[i++];
                }
                else {
                    tweets[k++].tweetID = rightArr[j++]; 
                }    
            }
        }

        while(i < leftSize) {
            tweets[k++].tweetID = leftArr[i++];
        }
        
        while(j < rightSize) {
            tweets[k++].tweetID = rightArr[j++];
        }

        delete[] leftArr;
        delete[] rightArr;
    }
    else if(sortBy == "retweetCount") {
        int* leftArr = new int[leftSize];
        int* rightArr = new int[rightSize];

        for(int i = 0; i < leftSize; i++) {  // copying values to temp arrays
            leftArr[i] = tweets[left + i].retweetCount;
        }
        for(int j = 0; j < rightSize; j++) {
            rightArr[j] = tweets[mid + 1 + j].retweetCount;
        }

        int i = 0, j = 0, k = left;

        while(i < leftSize && j < rightSize) {  // compare and assing it to existing array
            if(ascending) {
                if(leftArr[i] < rightArr[j]) {
                    tweets[k++].retweetCount = leftArr[i++];
                }
                else {
                    tweets[k++].retweetCount = rightArr[j++]; 
                }
            }
            else {
                if(leftArr[i] > rightArr[j]) {
                    tweets[k++].retweetCount = leftArr[i++];
                }
                else {
                    tweets[k++].retweetCount = rightArr[j++]; 
                }    
            }
        }

        while(i < leftSize) {
            tweets[k++].retweetCount = leftArr[i++];
        }
        
        while(j < rightSize) {
            tweets[k++].retweetCount = rightArr[j++];
        }

        delete[] leftArr;
        delete[] rightArr;
    }
    else if(sortBy == "favoriteCount") {
        int* leftArr = new int[leftSize];
        int* rightArr = new int[rightSize];

        for(int i = 0; i < leftSize; i++) {  // copying values to temp arrays
            leftArr[i] = tweets[left + i].favoriteCount;
        }
        for(int j = 0; j < rightSize; j++) {
            rightArr[j] = tweets[mid + 1 + j].favoriteCount;
        }

        int i = 0, j = 0, k = left;

        while(i < leftSize && j < rightSize) {  // compare and assing it to existing array
            if(ascending) {
                if(leftArr[i] < rightArr[j]) {
                    tweets[k++].favoriteCount = leftArr[i++];
                }
                else {
                    tweets[k++].favoriteCount = rightArr[j++]; 
                }
            }
            else {
                if(leftArr[i] > rightArr[j]) {
                    tweets[k++].favoriteCount = leftArr[i++];
                }
                else {
                    tweets[k++].favoriteCount = rightArr[j++]; 
                }    
            }
        }

        while(i < leftSize) {
            tweets[k++].favoriteCount = leftArr[i++];
        }
        
        while(j < rightSize) {
            tweets[k++].favoriteCount = rightArr[j++];
        }

        delete[] leftArr;
        delete[] rightArr;
    }
}

void mergeSort(std::vector<Tweet>& tweets, int left, int right, const std::string& sortBy, bool ascending) {
    if(left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(tweets, left, mid, sortBy, ascending);
    mergeSort(tweets, mid + 1, right, sortBy, ascending);
    merge(tweets, left, mid, right, sortBy, ascending);
}