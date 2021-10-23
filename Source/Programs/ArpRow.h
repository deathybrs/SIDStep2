#pragma once


enum ARP_ROW_TYPE
{
    RELATIVE
  , ABSOLUTE
  , COMMAND
};


struct ArpRow
{
    ARP_ROW_TYPE rowType;
    int value;
};
