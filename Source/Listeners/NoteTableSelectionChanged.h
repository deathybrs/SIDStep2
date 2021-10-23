// ReSharper disable CppInconsistentNaming
#pragma once
class NoteTableSelectionChanged
{
public:
    virtual ~NoteTableSelectionChanged () = default;

    virtual void
        onNoteTableSelectionChanged (
                unsigned int row
                ) = 0;
};
