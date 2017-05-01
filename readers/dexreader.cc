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

    seek(0);

    // read magic
    ifs_.read(reinterpret_cast<char *>(header->magic), DEX_MAGIC_SIZE);

    // compare magic
    if(std::strncmp(reinterpret_cast<const char *>(header->magic),
                    DEX_MAGIC,
                    DEX_MAGIC_SIZE) != 0)
    {
        throw Dexception(reinterpret_cast<const char*>(header->magic));
    }

    // read checksum (adler32 of everything by magic and this field)
    header->checksum = read<uint32_t>();

    // read file signature
    ifs_.read(reinterpret_cast<char *>(header->signature), DEX_SIGNATURE_SIZE);

    // the rest of the header is heterogeneous (20 final members)
    uint32_t* latter = &(header.get())->file_size;
    for(auto i = 0; i < 20; i++)
        *(latter + i) = read<uint32_t>();
    
    // general assertions
    assert(header->proto_ids_size <= 0xffff);
	
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
