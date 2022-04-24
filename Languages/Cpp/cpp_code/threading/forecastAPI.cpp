#include <iostream>
#include <thread>
#include <string>
#include <map>
// for sleep_for()
#include <chrono>
using namespace std::chrono_literals;

void RefreshForecast(std::map<std::string, int> forecastMap) {
	while (true) {
		for (auto &item: forecastMap) {
			item.second++;
			std::cout << item.first << " - " << item.second << std::endl;
		}
		std::cout << "---------" << std::endl;
		std::this_thread::sleep_for(2000ms);
	}
}

int main() {

	std::map<std::string, int> forecastMap = {
		{"New York", 15},
		{"Mumbai", 20},
		{"Berlin", 18}
	};

	std::thread bgWorker(RefreshForecast, forecastMap);
	
	// For Windows
	// system("pause>nul");
	// For Linux
	// system("read x 2> nul; rm nul || pause > nul");
	// System independent
	std::cin.get();
	// In case the buffer is messing with it
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n')

}
