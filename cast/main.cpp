#include <iostream>
#include <map>

#include "cast.h"

struct GPS_Data {
    std::string service{};
    unsigned num_of_sat = 0;
};

template <class StreamType>
StreamType& operator<<(StreamType& stream, const GPS_Data& data)
{
    stream << "Service: " << data.service << ", Number of satellites: " << data.num_of_sat;
    return stream;
}

int main()
{
    std::map<std::string, unsigned> all_data = {
        { "GPS", 14 },
        { "GLONASS", 10 },
        { "GALILEO", 8 },
    };

    GPS_Data gps_1;
    for (const auto& variable : all_data) {
        gps_1 = cast(variable);
        const auto gps_2 = cast(variable).to<GPS_Data>();

        std::cout << gps_1 << std::endl;
        std::cout << gps_2 << std::endl;
    }
}