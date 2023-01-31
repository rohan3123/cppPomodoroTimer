// Pomodoro timer by Rohan in c++
// libaries 
#include <iostream>
#include <chrono>
#include <thread>

// start
int main() {

    int pomodoro_duration = 25;  // in minutes

    std::cout << "Starting a " << pomodoro_duration << "-minute Pomodoro Timer..." << std::endl;
    std::chrono::seconds duration(pomodoro_duration * 60);
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = start + duration;

    while (std::chrono::steady_clock::now() < end) {
        std::chrono::duration<double> remaining = end - std::chrono::steady_clock::now();
        std::cout << "Time remaining: " << remaining.count() / 60.0 << " minutes\r";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << std::endl << "Time's up! Taking a break now..." << std::endl;

    return 0;
}
