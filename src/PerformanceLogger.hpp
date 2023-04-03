#ifndef PERFORMANCE_LOGGER_HPP
#define PERFORMANCE_LOGGER_HPP
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace Performance {
struct Tracker {
  std::chrono::steady_clock::time_point start;
  std::chrono::steady_clock::time_point end;
};

// clang-ignore
class Log {
public:
  Log();
  Log(bool isEnable) { this->isEnable = isEnable; };
  inline Log(Log &&other) noexcept;
  inline Log &operator=(Log &&other) noexcept;
  inline explicit Log(const Log &other) noexcept = default;
  inline Log &operator=(const Log &other) noexcept = default;
  // Log(const Log&) = delete;
  // Log& operator=(const Log&) = delete;

  // destructor
  ~Log() = default;

  // Log(const Log&) = delete;
  inline bool getEnable() noexcept { return isEnable; }
  inline void setEnable(bool isEnable) noexcept { this->isEnable = isEnable; }
  inline void time(const std::string &workName) noexcept {
    if (isEnable == false)
      return;
    // if (!actionMap.contains(workName)) {
    if (actionMap.find(workName) == actionMap.end()) {
      actionMap[workName] = std::vector<Tracker>();
    }

    Tracker tracker;
    tracker.start = std::chrono::steady_clock::now();
    tracker.end = tracker.start;
    actionMap[workName].push_back(tracker);
  }

  inline void timeEnd(const std::string &workName) noexcept {
    if (isEnable == false)
      return;
    Tracker tracker = actionMap[workName].back();
    tracker.end = std::chrono::steady_clock::now();
    actionMap[workName].back() = tracker;
  }
  // Usage:
  /*
  Performance::Log::time("workName");
  // do something
  Performance::Log::timeEnd("workName");
  //...
  Performance::Log::prettyPrint();
  */
  inline void prettyPrint() noexcept {
    // if (actionMap.empty()) {
    //     std::cout << "No action has been logged" << std::endl;
    //     return;
    // }
    if (isEnable == false)
      return;
    std::map<std::string, int> generalMap;
    int generalTime = 0;
    for (auto &[key, value] : actionMap) {
      int sumTotalTime = 0;
      for (auto &tracker : value) {
        auto totalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
                             tracker.end - tracker.start)
                             .count();
        sumTotalTime += static_cast<int>(totalTime);
      }
      generalMap[key] = sumTotalTime;
      generalTime += sumTotalTime;
    }
    std::cout << "{" << std::endl;
    //             std::cout << "'" << key << "': " << sumTotalTime << ","
    //               << std::endl;
    std::cout << "  \"General Time\": " << generalTime << "," << std::endl;
    int totalFinding = 0;
    for (auto &[key, value] : generalMap) {
      double percentage = value / (static_cast<double>(generalTime)) * 100;
      totalFinding += actionMap[key].size();
      std::cout << "  \"" << key << "\": {\n\t\"totalTime\":\t\"" << value
                << "ns\",\n\t\"timePercent\":\t\"" << percentage
                << "%\",\n\t\"CallCount\":\t" << actionMap[key].size()
                << "\n\t}," << std::endl;
    }
    std::cout << "  \"Total Finding\": " << totalFinding << "\n" << std::endl;
    std::cout << "}" << std::endl;

    actionMap.clear(); // clear map
  }

private:
  bool isEnable = true;
  std::map<std::string, std::vector<Tracker>> actionMap;
};
inline Log::Log() { actionMap = std::map<std::string, std::vector<Tracker>>(); }

} // namespace Performance
extern Performance::Log Console();

#endif