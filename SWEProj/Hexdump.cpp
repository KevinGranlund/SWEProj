
#include "hexdump.h"
#include <iomanip>
#include <memory>
#include <sstream>


typedef uint8_t byte_t;  //1 byte data type

constexpr size_t MIN_LINE_WIDTH = 4;     //minimum line width (byte(2) + blank(1) + ascii(1) = 4)
constexpr byte_t BYTE_MASK = 0xFF;  //uses as mask for the least significant byte


Hexdump::Hexdump(const void* dataPointer, size_t size, size_t lineWidth) {
    // There's not any data and an empty string is returned
    if (size == 0) {
        _outStr = std::string();
        return;
    }

    // The pointer is null.. empty string is returned
    if (dataPointer == nullptr) {
        _outStr = std::string();
        return;
    }


    // this is the nuber of bytes that are printed per line
    // the output is as follows: 2 digits hex + blank + ASCII char ( = 4 chars )
    size_t bytesPerLine = lineWidth / 4;

    // ascii buffer to be output
    std::unique_ptr<char[]> asciiBuf(new char[bytesPerLine + 1]);
    asciiBuf[bytesPerLine] = 0;  // zero (\0) termination

    // return value string stream
    std::ostringstream hexDump;
    hexDump << std::setfill('0') << std::hex;

    // data as byte type pointer
    auto byteData = reinterpret_cast<const byte_t*>(dataPointer);

    size_t lineBytes = 0;  // number of bytes in the current line
    for (size_t i = 0; i < size; i++) {
        // data output to string stream
        hexDump << std::setw(2) << (byteData[i] & BYTE_MASK);

        // srites to the ascii buffer.. any charachter that's not visible is replaced with '.'
        asciiBuf[i % bytesPerLine] = isgraph(byteData[i]) ? static_cast<char>(byteData[i]) : '.';

        hexDump << ' ';

        // output ascii buffer to stringstream and make a line break (if not last line)
        if (++lineBytes >= bytesPerLine) {
            hexDump << std::string(asciiBuf.get());
            if ((i + 1) < size) hexDump << std::endl;
            lineBytes = 0;
        }
    }

    // this gets the number of bytes in the last line.. likely not a full line
    size_t bytesLastLine = size % bytesPerLine;

    // output dummy bytes (if this is necessary)
    if (bytesLastLine) {
        auto dummies = bytesPerLine - bytesLastLine;  // number of dummy bytes

        hexDump << std::setfill(' ');
        hexDump << std::setw(static_cast<int>(dummies) * 3) << "";  // output "empty bytes"
        asciiBuf[bytesLastLine] = 0;                                  // move zero termination
        hexDump << std::string(asciiBuf.get());
    }

    // store hex dump string
    _outStr = hexDump.str();
}

