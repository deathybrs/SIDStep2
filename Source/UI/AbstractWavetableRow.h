#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Listeners/ListenerInitializer.h"

class AbstractWavetableRow
        : public Component
        , public WavetableSelectionChanged
{
public:
    explicit
        AbstractWavetableRow (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    ~AbstractWavetableRow () override;

    //void setSelected(bool value);
    void
        onWavetableSelectionChanged (
                unsigned int selected_row
                ) override;

    virtual unsigned int
        get () const = 0;

    virtual void
        set (
                unsigned int row_num
              , unsigned int value
                ) = 0;

protected:
    std::shared_ptr < EventDispatcher > dispatcher;
    bool                                selected;
    int                                 row;
};
