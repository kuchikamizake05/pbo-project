#include "Utils.h"

// No complex logic here, but keeping it consistent with separation.
bool Utils::isDateOverlap(const std::string& start1, const std::string& end1, 
                          const std::string& start2, const std::string& end2) {
    // Overlap logic: Start1 < End2 && Start2 < End1
    return (start1 < end2 && start2 < end1);
}
