#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct TrafficLight {
    int distance;
    int duration;
    vector<int> greenSpeeds;
};

class Problem {
public:
    int maxSpeed;
    vector<TrafficLight> trafficLights;

    void parseInput() {
        int speed;
        cin >> speed; cin.ignore();
        int lightCount;
        cin >> lightCount; cin.ignore();
        for (int i = 0; i < lightCount; i++) {
            int distance;
            int duration;
            cin >> distance >> duration; cin.ignore();
            cerr << distance << endl;
            cerr << duration << endl;
        }
        cerr << lightCount << endl;
        cerr << speed << endl;

    }
};

int main()
{
    Problem problem;
    problem.parseInput();


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}