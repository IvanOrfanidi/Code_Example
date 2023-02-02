#include <iostream>
#include <map>

#include "cast.h"

struct Data {
    std::string service{};
    unsigned counter = 0;
};

template <class StreamType>
StreamType& operator<<(StreamType& stream, const Data& data)
{
    stream << "Service: " << data.service << ", Number of satellites: " << data.counter;
    return stream;
}

int main()
{
    const static std::map<std::string, unsigned> testData = {
        { "GPS", 10 },
        { "GLONASS", 5 },
        { "GALILEO", 8 },
    };

    Data data{};
    for (const auto& variable : testData) {
        data = cast(variable);
        std::cout << data << std::endl;

        data = cast(variable).to<Data>();
        std::cout << data << std::endl;
    }
}