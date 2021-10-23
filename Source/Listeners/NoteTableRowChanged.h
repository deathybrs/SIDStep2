// ReSharper disable CppInconsistentNaming
#pragma once
struct ArpRow;

class NoteTableRowChanged
{
public:
    virtual ~NoteTableRowChanged () = default;

    virtual void
        onNoteTableRowChanged (
                ArpRow& value
                ) = 0;
};
