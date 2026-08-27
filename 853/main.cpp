#include <bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, double>> cars;

    for (int i = 0; i < position.size(); i++) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    sort(cars.begin(), cars.end());

    int result = 1;
    double maxTime = cars.back().second;

    for (int i = cars.size() - 2; i >= 0; i--) {
        if (cars[i].second > maxTime) {
            result++;
            maxTime = cars[i].second;
        }

    }

    return result;
}

int main() {
    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};

    int result = carFleet(target, position, speed);

    cout << result << endl;

    return 0;
}