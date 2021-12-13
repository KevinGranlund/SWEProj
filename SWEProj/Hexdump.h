#pragma once

#include <ostream>
#include <string>


constexpr size_t DEFAULT_LINE_WIDTH = 64;

class Hexdump final {
private:
    std::string _outStr;

public:

    /*
     *      data        pointer to the data to be dumped
     *      size        size of data to be dumped (in bytes)
     *      line_width  max line width of returned string
     */

    Hexdump(const void* dataPointer, size_t size, size_t lineWidth = DEFAULT_LINE_WIDTH);


    //get the hex dump string
    inline const std::string& str() const { return _outStr; }
};

