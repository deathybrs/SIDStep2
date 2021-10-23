#pragma once


class PatchEditorVibratoDelayChanged
{
public:
    virtual ~PatchEditorVibratoDelayChanged () {}

    virtual void
        onPatchEditorVibratoDelayChanged (
                unsigned int value
                ) = 0;
};
