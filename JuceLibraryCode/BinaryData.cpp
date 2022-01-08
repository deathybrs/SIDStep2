/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== commands.txt ==================
static const unsigned char temp_binary_data_0[] =
"Program Change\r\n"
"Note On\r\n"
"Note Off\r\n"
"Arp\r\n"
"Pitch Bend\r\n"
"Pulse Width\r\n"
"Change Attack+Decay\r\n"
"Change Sustain+Release\r\n"
"Voice Filter On/Off\r\n"
"Vibrato Amount\r\n"
"Vibrato Speed\r\n"
"Vibrato Delay\r\n"
"Cutoff\r\n"
"Resonance\r\n"
"Set Filter Type\r\n"
"Volume\r\n";

const char* commands_txt = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes);
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x75aa7839:  numBytes = 221; return commands_txt;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "commands_txt"
};

const char* originalFilenames[] =
{
    "commands.txt"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
