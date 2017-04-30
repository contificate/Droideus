#ifndef DEXREADER_H
#define DEXREADER_H

#include <cassert>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "formats/dexfile.h"

using dex::DexHeader;
using dex::EndianTag;

class DexReader
{
public:
    explicit DexReader(const std::string& fileLocation);

    // TODO: return DexFile

    std::unique_ptr<DexHeader> readHeader();

    ~DexReader();

private:
    std::ifstream ifs_;
    std::streamsize size_;

    void seek(const std::streampos offset);
    void skip(const std::streamsize len);
    std::streampos pos();

    template<typename T>
    T read()
    {
        static_assert(std::is_fundamental<T>::value, "Type must be primitive");
        T buffer{0};
        ifs_.read(reinterpret_cast<char *>(&buffer), sizeof(T));
        return buffer;
    }

};

#endif // DEXREADER_H
