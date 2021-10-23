#ifndef EXPORTATTACKCHANGED_H_INCLUDED
#define EXPORTATTACKCHANGED_H_INCLUDED


class ExportAttackChanged
{
public:
    virtual ~ExportAttackChanged () {}

    virtual void
        onExportAttackChanged (
                unsigned int voice
              , unsigned int value
                ) = 0;
};


#endif  // LIVEATTACKCHANGED_H_INCLUDED
