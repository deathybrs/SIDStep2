#include "Pattern.h"


Pattern::Pattern(double time, unsigned short value, unsigned char channel): UnsignedShortCommand(time, value), channel(channel) {}


Array<unsigned char> Pattern::ToBin() {
    Array<unsigned char> ret;

    unsigned char first = GetCommandByte();
    const unsigned char upperNybble = ((GetValue() & 0x300) >> 8) | (channel & 0x3) << 2;
    first |= upperNybble;

    const unsigned char lowerByte = GetValue() & 0xFF;

    ret.add(first);
    ret.add(lowerByte);

    return ret;
}


unsigned char Pattern::GetCommandByte() { return GC_PATTERN; }


unsigned char Pattern::GetChannel() const { return channel; }


void Pattern::SetChannel(unsigned char value) { this->channel = value; }
