#ifndef DEX_H
#define DEX_H

#include <cstdint>

#include "exceptions/dexception.h"

#define DEX_MAGIC "dex\n035\0"
#define DEX_MAGIC_SIZE sizeof(DEX_MAGIC + 1)
#define DEX_HEADER_SIZE 0x70
#define DEX_SIGNATURE_SIZE 20

namespace dex {

    /*
     * TODO: implement utils for the uint encoding, MUTF8, etc.
     */

    enum class EndianTag : uint32_t {
        ENDIAN_CONSTANT = 0x12345678,
        REVERSE_ENDIAN_CONSTANT = 0x78563412
    };

    struct DexHeader {
        uint8_t magic[DEX_MAGIC_SIZE];
        uint32_t checksum; // adler32
        uint8_t signature[DEX_SIGNATURE_SIZE]; // SHA-1 hash
        uint32_t file_size;
        uint32_t header_size; // DEX_HEADER_SIZE
        EndianTag endian_tag;
        uint32_t link_size;
        uint32_t link_offset;
        uint32_t map_offset;
        uint32_t strings_ids_size;
        uint32_t strings_ids_offset;

        // TODO: finish

        bool hasBeenLinked() const
        {
            return (link_size == 0);
        }
    };

} // namespace dex

#endif // DEX_H
