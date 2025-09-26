#include <iostream>
using namespace std;

void processCricketScores() {

    class PlayerScore {
    public:
        string playerName;
        int runs;

        void input(){
            cout<<"Enter name: ";
            cin>>playerName;
            cout<<"Enter runs: ";
            cin>>runs;
        }
        void display() {
            cout << playerName << " scored " << runs << " runs." << endl;
        }
    };

    string name;
    int runs;
    PlayerScore p1;
    p1.input();

    PlayerScore p2;
    p2.input();

    PlayerScore p3;
    p3.input();
    int totalRuns = p1.runs + p2.runs + p3.runs;
    double averageRuns = totalRuns / 3.0;

    cout << "Cricket Team Scores:" << endl;
    p1.display();
    p2.display();
    p3.display();

    cout << "Total runs scored by team: " << totalRuns << endl;
    cout << "Average runs per player: " << averageRuns << endl;
}

int main() {
    processCricketScores();


    return 0;
}
