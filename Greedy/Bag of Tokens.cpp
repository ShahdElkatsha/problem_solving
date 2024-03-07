//Array , Two Pointers , Greedy , Sorting

/*
the problem:
You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] donates the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin() , tokens.end());
        int left = 0 , right = tokens.size()-1;
        int maxScore = 0 , currScore = 0;

        while( left <= right ){
            // If we have enough power to use the token at left pointer
            if ( power >= tokens[left] ){
                currScore++;
                power -= tokens[left++];// Consume power and move left pointer to right
            }else{  // If we don't have enough power, we'll try to gain power using token at right pointer
                currScore--;
                power += tokens[right--];// Gain power by token at right and move right pointer to the left
            }

            if( currScore < 0 )    break;
            
            maxScore = max(maxScore , currScore);
        }
        return maxScore;
    }
};


int main() {
    Solution solution;
    // Example usage
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    cout << "Maximum score: " << solution.bagOfTokensScore(tokens, power) << endl;
    return 0;
}
