#include "MinimumDelay.h"

#include <chrono>
#include <iostream>
#include <future>

namespace RRUtils {

MinimumDelay::MinimumDelay() {
    m_start_time = std::chrono::system_clock::now();
}

void MinimumDelay::reset() {
    m_start_time = std::chrono::system_clock::now();
}

void MinimumDelay::wait_for_minimum(std::chrono::milliseconds delay_ms) const {
    using namespace std::chrono;
    auto delta = duration_cast<milliseconds>(system_clock::now() - m_start_time);

    if (delay_ms > delta) {
        std::chrono::milliseconds to_wait = delay_ms - delta;
        //std::cerr << "========== : " << to_wait.count() << std::endl;
        std::this_thread::sleep_for(to_wait);
    }
}

}