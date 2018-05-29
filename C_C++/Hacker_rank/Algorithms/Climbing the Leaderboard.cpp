/*Alice is playing an arcade game and wants to climb to the top of the leaderboard. Can you help her track her ranking as she plays? The game uses Dense Ranking, so its leaderboard works like this:

The player with the highest score is ranked number  on the leaderboard.
Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.
We want to determine Alice's rank as she progresses up the leaderboard. For example, the four players on the leaderboard have high scores of , , , and . Those players will have ranks , , , and , respectively. If Alice's scores are ,  and , her rankings after each game are ,  and .

You are given an array, , of monotonically decreasing leaderboard scores, and another array, , of Alice's scores for the game. You must print  integers. The  integer should indicate the current rank of alice after her  game.

Input Format

The first line contains an integer , the number of players on the leaderboard. 
The next line contains  space-separated integers , the leaderboard scores in decreasing order. 
The next line contains an integer, , denoting the number games Alice plays. 
The last line contains  space-separated integers , her game scores.

Output Format

Print  integers. The  integer should indicate the rank of alice after playing the  game.
*/

#include <bits/stdc++.h>

using namespace std;

struct rankList
{
    int rank;
    int score;
};
vector<string> split_string(string);

// Complete the climbingLeaderboard function below.

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<rankList> rankList;
    vector<int> output;
    int rank=1;
    int n=0;
    int aIndex=alice.size()-1;
    
    /*Creat a vector that has {rank,score} elements*/
    rankList.push_back ({rank,scores[0]});
    for(int i=1;i<scores.size();i++)
    {
        if(scores[i]<scores[i-1])
        {
            rank++;
            rankList.push_back({rank,scores[i]});
        }
    }
    
    while(aIndex >= 0)
    {
        if(n <= (rankList.size() - 1))
        {
            if(alice[aIndex] >= rankList[n].score)
            {
                output.insert(output.begin(),rankList[n].rank);
                aIndex--; 
            }
            else
            {
                n++;
            }
        }
        else
        {
            output.insert(output.begin(),n+1);
            aIndex--;
        }
    }
    return output;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
