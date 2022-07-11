#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Listeners/ListenerInitializer.h"

class AbstractNoteTableRow
        : public Component
        , public NoteTableSelectionChanged
{
public:
    explicit
        AbstractNoteTableRow (
                const std::shared_ptr < EventDispatcher >& dispatcher
                );

    ~AbstractNoteTableRow () override;

    void
        onNoteTableSelectionChanged (
                unsigned int selected_row
                ) override;

    virtual auto
        Get () const -> ArpRow = 0;

    virtual void
        Set (
                unsigned int row_num
              , ArpRow       value
                ) = 0;

protected:
    std::shared_ptr < EventDispatcher > dispatcher;
    bool                                selected {
            false
    };
    int row {
            -1
    };
};
