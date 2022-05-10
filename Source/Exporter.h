#pragma once
#include <array>
#include <memory>
#include <string>
#include <vector>
enum class COMMANDS;

class Command;
class Recorder;


class Exporter
{
public:
    explicit
        Exporter (
                std::shared_ptr < Recorder >& record
                );

    void
        ToPatterns (
                std::string title
              , std::string artist
                ) const;

private:
    auto
        BuildPattern (
                unsigned                                           first_frame
              , int                                                last_frame
              , const std::vector < std::shared_ptr < Command > >& temp_pattern
                ) const -> std::vector < std::shared_ptr < Command > >;

    void
        AddOrReusePattern (
                std::vector < std::shared_ptr < Command > >& new_pattern
              , std::vector < int >&                         pattern_list
                );

    std::shared_ptr < Recorder >                                recording;
    std::vector < int >                                         globalPatternList;
    std::array < std::vector < int > , 3 >                      voicePatternList;
    std::vector < std::vector < std::shared_ptr < Command > > > patterns;
};