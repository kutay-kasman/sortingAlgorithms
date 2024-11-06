#include "tweet.h"
using namespace std;

int main() {
    vector<Tweet> tweets, tweetsNS, tweetsSA, tweetsSD;
    vector<Tweet> tweets5K, tweets10K, tweets20K, tweets30K, tweets40K, tweets50K;
    
    //permutations files
    tweets = readTweetsFromFile("./data/permutations/tweets.csv");
    tweetsNS = readTweetsFromFile("./data/permutations/tweetsNS.csv");
    tweetsSA = readTweetsFromFile("./data/permutations/tweetsSA.csv");
    tweetsSD = readTweetsFromFile("./data/permutations/tweetsSD.csv");

    //sizes files
    tweets5K = readTweetsFromFile("./data/sizes/tweets5K.csv");
    tweets10K = readTweetsFromFile("./data/sizes/tweets10K.csv");
    tweets20K = readTweetsFromFile("./data/sizes/tweets20K.csv");
    tweets30K = readTweetsFromFile("./data/sizes/tweets30K.csv");
    tweets40K = readTweetsFromFile("./data/sizes/tweets40K.csv");
    tweets50K = readTweetsFromFile("./data/sizes/tweets50K.csv");

    // measue time for buble sort, insertion sort and merge sort for permutations directory
    vector<Tweet> bubleTweets = tweets;
    vector<Tweet> bubleTweetsNS = tweetsNS;
    vector<Tweet> bubleTweetsSA = tweetsSA;
    vector<Tweet> bubleTweetsSD = tweetsSD;

    vector<Tweet> insertionTweets = tweets;
    vector<Tweet> insertionTweetsNS = tweetsNS;
    vector<Tweet> insertionTweetsSA = tweetsSA;
    vector<Tweet> insertionTweetsSD = tweetsSD;

    vector<Tweet> mergeTweets = tweets;
    vector<Tweet> mergeTweetsNS = tweetsNS;
    vector<Tweet> mergeTweetsSA = tweetsSA;
    vector<Tweet> mergeTweetsSD = tweetsSD;

    //measue time for buble sort, insertion sort and merge sort for sizes directory
    vector<Tweet> bubleTweets5 = tweets5K;
    vector<Tweet> bubleTweets10 = tweets10K;
    vector<Tweet> bubleTweets20 = tweets20K;
    vector<Tweet> bubleTweets30 = tweets30K;
    vector<Tweet> bubleTweets40 = tweets40K;
    vector<Tweet> bubleTweets50 = tweets50K;

    vector<Tweet> insertionTweets5 = tweets5K;
    vector<Tweet> insertionTweets10 = tweets10K;
    vector<Tweet> insertionTweets20 = tweets20K;
    vector<Tweet> insertionTweets30 = tweets30K;
    vector<Tweet> insertionTweets40 = tweets40K;
    vector<Tweet> insertionTweets50 = tweets50K;

    vector<Tweet> mergeTweets5 = tweets5K;
    vector<Tweet> mergeTweets10 = tweets10K;
    vector<Tweet> mergeTweets20 = tweets20K;
    vector<Tweet> mergeTweets30 = tweets30K;
    vector<Tweet> mergeTweets40 = tweets40K;
    vector<Tweet> mergeTweets50 = tweets50K;


    clock_t bubbleS = clock();
    bubbleSort(bubleTweets, "retweetCount", true);
    double bubbleDuration = (clock() - bubbleS) / (double)CLOCKS_PER_SEC;

    bubbleS = clock();
    bubbleSort(bubleTweetsSA, "retweetCount", true);
    double bubbleSADuration = (clock() - bubbleS) / (double)CLOCKS_PER_SEC;

    bubbleS = clock();
    bubbleSort(bubleTweetsSD, "retweetCount", true);
    double bubbleSDDuration = (clock() - bubbleS) / (double)CLOCKS_PER_SEC;

    bubbleS = clock();
    bubbleSort(bubleTweetsNS, "retweetCount", true);
    double bubbleNSDuration = (clock() - bubbleS) / (double)CLOCKS_PER_SEC;

    cout << "Buble Sort: "<< bubbleDuration << " " << bubbleSADuration << " " <<bubbleSDDuration <<" "<< bubbleNSDuration <<"\n";

    clock_t insertionS = clock();
    insertionSort(insertionTweets, "retweetCount", true);
    double insertionDuration = (clock() - insertionS) / (double)CLOCKS_PER_SEC;

    insertionS = clock();
    insertionSort(insertionTweetsSA, "retweetCount", true);
    double insertionSADuration = (clock() - insertionS) / (double)CLOCKS_PER_SEC;

    insertionS = clock();
    insertionSort(insertionTweetsNS, "retweetCount", true);
    double insertionSDDuration = (clock() - insertionS) / (double)CLOCKS_PER_SEC;

    insertionS = clock();
    insertionSort(insertionTweetsSD, "retweetCount", true);
    double insertionNSDuration = (clock() - insertionS) / (double)CLOCKS_PER_SEC;

    cout << "Insertion Sort: "<< insertionDuration << " "<< insertionSADuration << " " << insertionSDDuration << " " <<insertionNSDuration <<"\n";

    clock_t mergeS= clock();
    mergeSort(mergeTweets, 0, mergeTweets.size() - 1, "retweetCount", true);
    double mergeDuration = (clock() - mergeS) / (double)CLOCKS_PER_SEC;

    mergeS= clock();
    mergeSort(mergeTweetsSA, 0, mergeTweets.size() - 1, "retweetCount", true);
    double mergeSADuration = (clock() - mergeS) / (double)CLOCKS_PER_SEC;

    mergeS= clock();
    mergeSort(mergeTweetsSD, 0, mergeTweets.size() - 1, "retweetCount", true);
    double mergeSDDuration = (clock() - mergeS) / (double)CLOCKS_PER_SEC;

    mergeS= clock();
    mergeSort(mergeTweetsNS, 0, mergeTweets.size() - 1, "retweetCount", true);
    double mergeNSDuration = (clock() - mergeS) / (double)CLOCKS_PER_SEC;

    cout << "Merge Sort: "<< mergeDuration << " "<< mergeSADuration << " "<< mergeSDDuration << " " << mergeNSDuration <<"\n";




    clock_t bubbleStart = clock();
    bubbleSort(bubleTweets5, "favoriteCount", true);
    double bubble5Duration = (clock() - bubbleStart) / (double)CLOCKS_PER_SEC;

    bubbleStart = clock();
    bubbleSort(bubleTweets10, "favoriteCount", true);
    double bubble10Duration = (clock() - bubbleStart) / (double)CLOCKS_PER_SEC;

    bubbleStart = clock();
    bubbleSort(bubleTweets20, "favoriteCount", true);
    double bubble20Duration = (clock() - bubbleStart) / (double)CLOCKS_PER_SEC;

    bubbleStart = clock();
    bubbleSort(bubleTweets30, "favoriteCount", true);
    double bubble30Duration = (clock() - bubbleStart) / (double)CLOCKS_PER_SEC;

    bubbleStart = clock();
    bubbleSort(bubleTweets40, "favoriteCount", true);
    double bubble40Duration = (clock() - bubbleStart) / (double)CLOCKS_PER_SEC;

    bubbleStart = clock();
    bubbleSort(bubleTweets50, "favoriteCount", true);
    double bubble50Duration = (clock() - bubbleStart) / (double)CLOCKS_PER_SEC;

    cout << "Buble Sort: "<< bubble5Duration << " " << bubble10Duration << " " <<bubble20Duration <<" "<< bubble30Duration
        <<" " << bubble40Duration << " " << bubble50Duration   <<"\n";

    clock_t insertionStart = clock();
    insertionSort(insertionTweets5, "favoriteCount", true);
    double insertion5Duration = (clock() - insertionStart) / (double)CLOCKS_PER_SEC;

    insertionStart = clock();
    insertionSort(insertionTweets10, "favoriteCount", true);
    double insertion10Duration = (clock() - insertionStart) / (double)CLOCKS_PER_SEC;

    insertionStart = clock();
    insertionSort(insertionTweets20, "favoriteCount", true);
    double insertion20Duration = (clock() - insertionStart) / (double)CLOCKS_PER_SEC;

    insertionStart = clock();
    insertionSort(insertionTweets30, "favoriteCount", true);
    double insertion30Duration = (clock() - insertionStart) / (double)CLOCKS_PER_SEC;

    insertionStart = clock();
    insertionSort(insertionTweets40, "favoriteCount", true);
    double insertion40Duration = (clock() - insertionStart) / (double)CLOCKS_PER_SEC;

    insertionStart = clock();
    insertionSort(insertionTweets50, "favoriteCount", true);
    double insertion50Duration = (clock() - insertionStart) / (double)CLOCKS_PER_SEC;

    cout << "Insertion Sort: "<< insertion5Duration << " "<< insertion10Duration << " " << insertion20Duration << " " <<insertion30Duration
    << " " << insertion40Duration << " " << insertion50Duration <<"\n";

    clock_t mergeStart = clock();
    mergeSort(mergeTweets5, 0, mergeTweets5.size() - 1,"favoriteCount", true);
    double merge5Duration = (clock() - mergeStart) / (double)CLOCKS_PER_SEC;

    mergeStart = clock();
    mergeSort(mergeTweets10, 0, mergeTweets10.size() - 1, "favoriteCount", true);
    double merge10Duration = (clock() - mergeStart) / (double)CLOCKS_PER_SEC;

    mergeStart = clock();
    mergeSort(mergeTweets20, 0, mergeTweets20.size() -1, "favoriteCount", true);
    double merge20Duration = (clock() - mergeStart) / (double)CLOCKS_PER_SEC;

    mergeStart = clock();
    mergeSort(mergeTweets30, 0, mergeTweets30.size() - 1, "favoriteCount", true);
    double merge30Duration = (clock() - mergeStart) / (double)CLOCKS_PER_SEC;

    mergeStart = clock();
    mergeSort(mergeTweets40, 0, mergeTweets40.size() - 1, "favoriteCount", true);
    double merge40Duration = (clock() - mergeStart) / (double)CLOCKS_PER_SEC;

    mergeStart = clock();
    mergeSort(mergeTweets50, 0, mergeTweets50.size() - 1, "favoriteCount", true);
    double merge50Duration = (clock() - mergeStart) / (double)CLOCKS_PER_SEC;

    cout << "Merge Sort: "<< merge5Duration << " "<< merge10Duration << " " << merge20Duration << " " <<merge30Duration
    << " " << merge40Duration << " " << merge50Duration <<"\n";



    clock_t binaryS = clock();
    binarySearch(mergeTweets5, 1773335, "favoriteCount");
    double binary5Duration = (clock() - binaryS) / (double)CLOCKS_PER_SEC;

    binaryS = clock();
    binarySearch(mergeTweets10, 1773335, "favoriteCount");
    double binary10Duration = (clock() - binaryS) / (double)CLOCKS_PER_SEC;

    binaryS = clock();
    binarySearch(mergeTweets20, 1773335, "favoriteCount");
    double binary20Duration = (clock() - binaryS) / (double)CLOCKS_PER_SEC;

    binaryS = clock();
    binarySearch(mergeTweets30, 1773335, "favoriteCount");
    double binary30Duration = (clock() - binaryS) / (double)CLOCKS_PER_SEC;

    binaryS = clock();
    binarySearch(mergeTweets40, 1773335, "favoriteCount");
    double binary40Duration = (clock() - binaryS) / (double)CLOCKS_PER_SEC;

    binaryS = clock();
    binarySearch(mergeTweets50, 1773335, "favoriteCount");
    double binary50Duration = (clock() - binaryS) / (double)CLOCKS_PER_SEC;


    cout << "Binary Sort: "<< binary5Duration << " "<< binary10Duration << " " << binary20Duration << " " <<binary30Duration
    << " " << binary40Duration << " " << binary50Duration <<"\n";

    clock_t tresholdS = clock();
    countAboveThreshold(tweets5K, "favoriteCount", 250);
    double treshold5Duration = (clock() - tresholdS) / (double)CLOCKS_PER_SEC;

    tresholdS = clock();
    countAboveThreshold(tweets10K, "favoriteCount", 250);
    double treshold10Duration = (clock() - tresholdS) / (double)CLOCKS_PER_SEC;

    tresholdS = clock();
    countAboveThreshold(tweets20K, "favoriteCount", 250);
    double treshold20Duration = (clock() - tresholdS) / (double)CLOCKS_PER_SEC;

    tresholdS = clock();
    countAboveThreshold(tweets30K, "favoriteCount", 250);
    double treshold30Duration = (clock() - tresholdS) / (double)CLOCKS_PER_SEC;

    tresholdS = clock();
    countAboveThreshold(tweets40K, "favoriteCount", 250);
    double treshold40Duration = (clock() - tresholdS) / (double)CLOCKS_PER_SEC;

    tresholdS = clock();
    countAboveThreshold(tweets50K, "favoriteCount", 250);
    double treshold50Duration = (clock() - tresholdS) / (double)CLOCKS_PER_SEC;


    cout << "Count Treshold: "<< treshold5Duration << " "<< treshold10Duration << " " << treshold20Duration << " " <<treshold30Duration
    << " " << treshold40Duration << " " << treshold50Duration <<"\n";




    return 0;
}
