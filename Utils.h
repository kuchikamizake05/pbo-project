#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
public:
    // Simple string date comparison (YYYY-MM-DD format allows lexicographical comparison)
    static bool isDateOverlap(const std::string& start1, const std::string& end1, 
                              const std::string& start2, const std::string& end2);
};

#endif // UTILS_H
