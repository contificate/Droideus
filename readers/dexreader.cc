#include "dexreader.h"

DexReader::DexReader(const std::string &fileLocation)
    : ifs_{fileLocation, (std::ios::binary | std::ios::ate)} {

    if(!ifs_.is_open())
        throw std::runtime_error("Could not open file!");

    size_ = ifs_.tellg();
    ifs_.seekg(0, std::ios::beg);
}

std::unique_ptr<DexHeader> DexReader::readHeader()
{
    auto header = std::make_unique<DexHeader>();

    // read magic
    seek(0);
    ifs_.read(reinterpret_cast<char *>(header->magic), DEX_MAGIC_SIZE);

    // compare magic
    if(std::strncmp(reinterpret_cast<const char *>(header->magic),
                    DEX_MAGIC,
                    DEX_MAGIC_SIZE) != 0)
    {
        throw Dexception(reinterpret_cast<const char*>(header->magic));
    }

    // read checksum
    header->checksum = read<uint32_t>();

    // read file signature
    ifs_.read(reinterpret_cast<char *>(header->signature), DEX_SIGNATURE_SIZE);

    header->file_size = read<uint32_t>();
    assert((header->header_size = read<uint32_t>()) == DEX_HEADER_SIZE);

    header->endian_tag = static_cast<EndianTag>(read<uint32_t>());

    header->link_size = read<uint32_t>();
    header->link_offset = read<uint32_t>();
    header->map_offset = read<uint32_t>();
    header->strings_ids_size = read<uint32_t>();
    header->strings_ids_offset = read<uint32_t>();

    return header;
}

void DexReader::seek(const std::streampos offset)
{
    ifs_.seekg(offset);
}

void DexReader::skip(const std::streamsize len)
{
    ifs_.ignore(len);
}

std::streampos DexReader::pos()
{
    return ifs_.tellg();
}

DexReader::~DexReader()
{
    ifs_.close();
}
