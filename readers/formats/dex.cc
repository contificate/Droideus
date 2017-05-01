#include "dex.h"

/*
 * General dex utilities (pretty printers)
 */

namespace dex {

std::string endian_tag_to_string(const EndianTag tag)
{
    std::string endian = (tag == EndianTag::ENDIAN_CONSTANT ? "Little" : "Big");
    return (endian += " endian");
}

} // namespace dex
