#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cfenv>

using namespace std;

class DistanceUtils {
public:
    static float toMetersPerSecond(int speedInKmPerHour) {
        return speedInKmPerHour / 3.6;
    }
    static float toKmPerHour(float speedInMetersPerSecond) {
        return speedInMetersPerSecond * 3.6;
    }
    static int roundHalfwayDownward(float number){
        if (fmod(number,0.5) == 0){
            // Number ends in .0 or .5
            return floor(number);
        } else {
            return round(number);
        }

    }
};

struct TrafficLight {

    TrafficLight(int distance, int duration) : distance(distance), duration(duration) {}

    float distance;
    int duration;

    void print() {
        cerr << "Traffic Light " << "distance:" << distance << " || duration:" << duration << endl;
    }

    bool isGreen(int speedInKmPerH) {
        // cerr << "Start cycle" << endl;
        cerr << "Speed in km/h: " << speedInKmPerH << endl;
        float speedInMetersPerSecond = DistanceUtils::toMetersPerSecond(speedInKmPerH);
        // cerr << "Speed in m/s: " << speedInMetersPerSecond << endl;
        int timeOfPassageInSeconds = distance / speedInMetersPerSecond;
        // cerr << "Time of passage in seconds: " << timeOfPassageInSeconds << endl;
        int cycleNumber = floor(timeOfPassageInSeconds / duration);
        if (cycleNumber%2 == 0){
            // If time of passage / duration is even, the light is green
            cerr << "Light is green" << endl;
            return true;
        } else {
            cerr << "Light is red" << endl;
            return false;
        }
    }

    int getNextSpeed(int speedInKmPerH) {
        // cerr << "Calculating new speed" << endl;
        float speedInMetersPerSecond = DistanceUtils::toMetersPerSecond(speedInKmPerH);
        float timeOfPassageInSeconds = distance / speedInMetersPerSecond;
        int cycleNumber = floor(timeOfPassageInSeconds / duration);
        if (cycleNumber%2 != 0) {
            cycleNumber++;
        }
        // cerr << "Cyclenumber: " << cycleNumber << endl;
        float timeOfNextGreenInSeconds = cycleNumber * duration;
        cerr << "Time of next green: " << timeOfNextGreenInSeconds << endl;
        float newSpeedInMetersPerSecond = distance / timeOfNextGreenInSeconds;
        cerr << "New speed in m/s: " << newSpeedInMetersPerSecond << endl;
        return DistanceUtils::roundHalfwayDownward(DistanceUtils::toKmPerHour(newSpeedInMetersPerSecond));
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
    // theProblem.print();

    // Start at max speed and check if it works for all the lights
    // If the current speed is too fast for one, calculate the speed you would need to run it as soon as it turns green
    // again, then repeat.

    int currentSpeed = theProblem.maxSpeed;
    bool allGreen = false;

    while(!allGreen){
        for (auto trafficLight : theProblem.trafficLights) {
            if (!trafficLight.isGreen(currentSpeed)){
                // Calculate speed to run this traffic light as soon as it turns green
                currentSpeed = trafficLight.getNextSpeed(currentSpeed);
                // cerr << "New speed in km/h:  " << currentSpeed << endl;
                allGreen = false;
                break;
            } else {
                allGreen = true;
            }
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << currentSpeed << endl;
}