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

    TrafficLight(int distance, int duration) : distance(distance), duration(duration) {}

    int distance;
    int duration;
    vector<int> greenSpeeds;

    void print() {
        cerr << "Traffic Light " << "distance:" << distance << " || duration:" << duration << endl;
    }
};

class Problem {
public:
    int maxSpeed;
    int lightCount;
    vector<TrafficLight> trafficLights;

    static Problem initializeProblem() {
        Problem problem;
        cin >> problem.maxSpeed; cin.ignore();
        cin >> problem.lightCount; cin.ignore();
        for (int i = 0; i < problem.lightCount; i++) {
            int distance;
            int duration;
            cin >> distance >> duration; cin.ignore();
            problem.trafficLights.emplace_back(distance, duration);
        }

        return problem;
    }

    void print(){
        cerr << "Speed Limit:" << maxSpeed << endl;
        cerr << "Light Count:" << lightCount << endl;
        for (auto tf : trafficLights) {
            tf.print();
        }

    }
};

int main()
{
    Problem theProblem = Problem::initializeProblem();
    theProblem.print();


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}