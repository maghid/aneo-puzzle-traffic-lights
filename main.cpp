#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class DistanceUtils {

    static int toMetersPerSecond(int speedInKmPerHour) {
        return round(speedInKmPerHour / 3.6)
    }

    static int toKmPerHour(int speedInMetersPerSecond) {
        return round(speedInMetersPerSecond * 3.6)
    }

};

struct TrafficLight {

    TrafficLight(int distance, int duration) : distance(distance), duration(duration) {}

    int distance;
    int duration;

    void print() {
        cerr << "Traffic Light " << "distance:" << distance << " || duration:" << duration << endl;
    }

    bool isGreen(int speedInKmPerH) {
        int speedInMetersPerSecond = DistanceUtils::toMetersPerSecond(speedinMetersPerSecond);
        int timeOfPassageInSeconds = distance / speedInMetersPerSecond;
        if ((timeOfPassageInSeconds / duration)%2 == 0) {
            // If time of passage / durations is even, the light is green
            return true;
        } else {
            return false;
        }
    }

    int getNextSpeed(int speedInKmPerH) {
        int speedInMetersPerSecond = DistanceUtils::toMetersPerSecond(speedinMetersPerSecond);
        int timeOfPassageInSeconds = distance / speedInMetersPerSecond;
        int timeOfNextGreenInSeconds = (ceil(timeOfPassageInSeconds / duration)) * duration;
        int newSpeedInMetersPerSecond = distance / timeOfNextGreenInSeconds;
        return DistanceUtils::toKmPerHour(newSpeedInMetersPerSecond);
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
                break;
            }
        }
        allGreen = true;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << currentSpeed << endl;
}