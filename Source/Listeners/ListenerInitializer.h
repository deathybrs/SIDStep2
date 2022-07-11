#pragma once


#include <JuceHeader.h>

#include "Bank/BankLoad.h"
#include "Bank/BankNew.h"
#include "Bank/BankProgramChanged.h"
#include "Bank/BankRefreshLive.h"
#include "Bank/BankRepaintWaveform.h"
#include "Bank/BankSave.h"
#include "Bank/BankSaveAs.h"
#include "Bank/BankStartSaveAs.h"
#include "Bank/BankTreeChanged.h"

#include "Export/ExportAttackChanged.h"
#include "Export/ExportBandPassChanged.h"
#include "Export/ExportCutoffChanged.h"
#include "Export/ExportDecayChanged.h"
#include "Export/ExportHighPassChanged.h"
#include "Export/ExportLowPassChanged.h"
#include "Export/ExportPatchChanged.h"
#include "Export/ExportPitchBendChanged.h"
#include "Export/ExportPulseWIdthChanged.h"
#include "Export/ExportReleaseChanged.h"
#include "Export/ExportResonanceChanged.h"
#include "Export/ExportSustainChanged.h"
#include "Export/ExportTremoloAmountChanged.h"
#include "Export/ExportTremoloSpeedChanged.h"
#include "Export/ExportVibratoAmountChanged.h"
#include "Export/ExportVibratoSpeedChanged.h"
#include "Export/ExportVoiceFilterChanged.h"
#include "Export/ExportVolumeChanged.h"
#include "Export/ShowExportManager.h"

#include "Live/LiveAddPatchClicked.h"
#include "Live/LiveArtistChanged.h"
#include "Live/LiveAttackChanged.h"
#include "Live/LiveBandPassChanged.h"
#include "Live/LiveCutoffChanged.h"
#include "Live/LiveDecayChanged.h"
#include "Live/LiveDoneExporting.h"
#include "Live/LiveExportArmed.h"
#include "Live/LiveHighPassChanged.h"
#include "Live/LiveLowPassChanged.h"
#include "Live/LivePatchChanged.h"
#include "Live/LivePatchEditorModeClicked.h"
#include "Live/LivePatchListChanged.h"
#include "Live/LivePatchListMode.h"
#include "Live/LivePatchListSelectedIndexChanged.h"
#include "Live/LivePatchSelected.h"
#include "Live/LivePitchBendChanged.h"
#include "Live/LivePulseWidthChanged.h"
#include "Live/LiveReleaseChanged.h"
#include "Live/LiveRemovePatchClicked.h"
#include "Live/LiveReplacePatchClicked.h"
#include "Live/LiveResonanceChanged.h"
#include "Live/LiveSustainChanged.h"
#include "Live/LiveTitleChanged.h"
#include "Live/LiveTremoloAmountChanged.h"
#include "Live/LiveTremoloSpeedChanged.h"
#include "Live/LiveVibratoAmountChanged.h"
#include "Live/LiveVibratoDelayChanged.h"
#include "Live/LiveVibratoSpeedChanged.h"
#include "Live/LiveVoiceFilterChanged.h"
#include "Live/LiveVolumeChanged.h"
#include "Live/LoadLivePatch.h"

#include "MIDI/MidiSignal.h"
#include "MIDI/NoteOff.h"
#include "MIDI/NoteOn.h"
#include "MIDI/PitchBend.h"
#include "MIDI/QuarterNoteTick.h"

#include "Parameters/AttackParameterChanged.h"
#include "Parameters/BandPassParameterChanged.h"
#include "Parameters/CutoffParameterChanged.h"
#include "Parameters/DecayParameterChanged.h"
#include "Parameters/FilterVoiceParameterChanged.h"
#include "Parameters/HighPassParameterChanged.h"
#include "Parameters/LowPassParameterChanged.h"
#include "Parameters/PitchBendParameterChanged.h"
#include "Parameters/ProgramParameterChanged.h"
#include "Parameters/PulseWidthParameterChanged.h"
#include "Parameters/ReleaseParameterChanged.h"
#include "Parameters/ResonanceParameterChanged.h"
#include "Parameters/SustainParameterChanged.h"
#include "Parameters/TremoloAmountParameterChanged.h"
#include "Parameters/TremoloSpeedParameterChanged.h"
#include "Parameters/VibratoAmountParameterChanged.h"
#include "Parameters/VibratoDelayParameterChanged.h"
#include "Parameters/VibratoSpeedParameterChanged.h"
#include "Parameters/VolumeParameterChanged.h"

#include "Patch Editor/PatchEditorAttackChanged.h"
#include "Patch Editor/PatchEditorDecayChanged.h"
#include "Patch Editor/PatchEditorDeleteWavetableRowClicked.h"
#include "Patch Editor/PatchEditorLiveModeClicked.h"
#include "Patch Editor/PatchEditorNameChanged.h"
#include "Patch Editor/PatchEditorNewWavetableCommandClicked.h"
#include "Patch Editor/PatchEditorNewWavetableRowClicked.h"
#include "Patch Editor/PatchEditorPitchBendRangeChanged.h"
#include "Patch Editor/PatchEditorPulseWidthCenterChanged.h"
#include "Patch Editor/PatchEditorPulseWidthDefaultChanged.h"
#include "Patch Editor/PatchEditorPulseWidthRangeChanged.h"
#include "Patch Editor/PatchEditorReleaseChanged.h"
#include "Patch Editor/PatchEditorShowNoteTable.h"
#include "Patch Editor/PatchEditorShowPulseTable.h"
#include "Patch Editor/PatchEditorShowWavetable.h"
#include "Patch Editor/PatchEditorSustainChanged.h"
#include "Patch Editor/PatchEditorTremoloDefaultAmountChanged.h"
#include "Patch Editor/PatchEditorTremoloDefaultSpeedChanged.h"
#include "Patch Editor/PatchEditorTremoloRangeChanged.h"
#include "Patch Editor/PatchEditorTremoloSpeedChanged.h"
#include "Patch Editor/PatchEditorVibratoDefaultAmountChanged.h"
#include "Patch Editor/PatchEditorVibratoDefaultSpeedChanged.h"
#include "Patch Editor/PatchEditorVibratoDelayChanged.h"
#include "Patch Editor/PatchEditorVibratoRangeChanged.h"
#include "Patch Editor/PatchEditorVibratoSpeedChanged.h"

#include "Frame.h"
#include "NoteTableRowChanged.h"
#include "NoteTableSelectionChanged.h"
#include "PulseTableRowChanged.h"
#include "PulseTableSelectionChanged.h"
#include "SampleRateChanged.h"
#include "WavetableRowChanged.h"
#include "WavetableSelectionChanged.h"


class EventDispatcher
{
public:
    EventDispatcher ();

    ~EventDispatcher () = default;

    EventDispatcher (
            const EventDispatcher& other
            ) = delete;

    EventDispatcher (
            EventDispatcher&& other
            ) = delete;

    auto
        operator= (
                const EventDispatcher& other
                ) -> EventDispatcher& = delete;

    auto
        operator= (
                EventDispatcher&& other
                ) -> EventDispatcher& = delete;

    std::shared_ptr < ListenerList < BankLoad > >            bankLoadListeners;
    std::shared_ptr < ListenerList < BankNew > >             bankNewListeners;
    std::shared_ptr < ListenerList < BankProgramChanged > >  bankProgramChangedListeners;
    std::shared_ptr < ListenerList < BankRefreshLive > >     bankRefreshLive;
    std::shared_ptr < ListenerList < BankRepaintWaveform > > bankRepaintWaveformListeners;
    std::shared_ptr < ListenerList < BankSave > >            bankSaveListeners;
    std::shared_ptr < ListenerList < BankSaveAs > >          bankSaveAsListeners;
    std::shared_ptr < ListenerList < BankStartSaveAs > >     bankStartSaveAsListeners;
    std::shared_ptr < ListenerList < BankTreeChanged > >     bankTreeChangedListeners;

    std::shared_ptr < ListenerList < ExportAttackChanged > >        exportAttackChanged;
    std::shared_ptr < ListenerList < ExportBandPassChanged > >      exportBandPassChanged;
    std::shared_ptr < ListenerList < ExportCutoffChanged > >        exportCutoffChanged;
    std::shared_ptr < ListenerList < ExportDecayChanged > >         exportDecayChanged;
    std::shared_ptr < ListenerList < ExportHighPassChanged > >      exportHighPassChanged;
    std::shared_ptr < ListenerList < ExportLowPassChanged > >       exportLowPassChanged;
    std::shared_ptr < ListenerList < ExportPatchChanged > >         exportPatchChanged;
    std::shared_ptr < ListenerList < ExportPitchBendChanged > >     exportPitchBendChanged;
    std::shared_ptr < ListenerList < ExportPulseWidthChanged > >    exportPulseWidthChanged;
    std::shared_ptr < ListenerList < ExportReleaseChanged > >       exportReleaseChanged;
    std::shared_ptr < ListenerList < ExportResonanceChanged > >     exportResonanceChanged;
    std::shared_ptr < ListenerList < ExportSustainChanged > >       exportSustainChanged;
    std::shared_ptr < ListenerList < ExportTremoloAmountChanged > > exportTremoloAmountChanged;
    std::shared_ptr < ListenerList < ExportTremoloSpeedChanged > >  exportTremoloSpeedChanged;
    std::shared_ptr < ListenerList < ExportVibratoAmountChanged > > exportVibratoAmountChanged;
    std::shared_ptr < ListenerList < ExportVibratoSpeedChanged > >  exportVibratoSpeedChanged;
    std::shared_ptr < ListenerList < ExportVoiceFilterChanged > >   exportVoiceFilterChanged;
    std::shared_ptr < ListenerList < ExportVolumeChanged > >        exportVolumeChanged;
    std::shared_ptr < ListenerList < ShowExportManager > >          showExportManager;

    std::shared_ptr < ListenerList < LiveAddPatchClicked > >               liveAddPatchClickedListeners;
    std::shared_ptr < ListenerList < LiveArtistChanged > >                 liveArtistChangedListeners;
    std::shared_ptr < ListenerList < LiveAttackChanged > >                 liveAttackChangedListeners;
    std::shared_ptr < ListenerList < LiveBandPassChanged > >               liveBandPassChangedListeners;
    std::shared_ptr < ListenerList < LiveCutoffChanged > >                 liveCutoffChangedListeners;
    std::shared_ptr < ListenerList < LiveDecayChanged > >                  liveDecayChangedListeners;
    std::shared_ptr < ListenerList < LiveDoneExporting > >                 liveDoneExportingListeners;
    std::shared_ptr < ListenerList < LiveExportArmed > >                   liveExportArmedListeners;
    std::shared_ptr < ListenerList < LiveHighPassChanged > >               liveHighPassChangedListeners;
    std::shared_ptr < ListenerList < LiveLowPassChanged > >                liveLowPassChangedListeners;
    std::shared_ptr < ListenerList < LivePatchChanged > >                  livePatchChangedListeners;
    std::shared_ptr < ListenerList < LivePatchEditorModeClicked > >        livePatchEditorModeClickedListeners;
    std::shared_ptr < ListenerList < LivePatchListChanged > >              livePatchListChangedListeners;
    std::shared_ptr < ListenerList < LivePatchListMode > >                 livePatchListModeListeners;
    std::shared_ptr < ListenerList < LivePatchListSelectedIndexChanged > > livePatchListSelectedIndexChangedListeners;
    std::shared_ptr < ListenerList < LivePatchSelected > >                 livePatchSelectedListeners;
    std::shared_ptr < ListenerList < LivePitchBendChanged > >              livePitchBendChangedListeners;
    std::shared_ptr < ListenerList < LivePulseWidthChanged > >             livePulseWidthChangedListeners;
    std::shared_ptr < ListenerList < LiveReleaseChanged > >                liveReleaseChangedListeners;
    std::shared_ptr < ListenerList < LiveRemovePatchClicked > >            liveRemovePatchClickedListeners;
    std::shared_ptr < ListenerList < LiveReplacePatchClicked > >           liveReplacePatchClickedListeners;
    std::shared_ptr < ListenerList < LiveResonanceChanged > >              liveResonanceChangedListeners;
    std::shared_ptr < ListenerList < LiveSustainChanged > >                liveSustainChangedListeners;
    std::shared_ptr < ListenerList < LiveTitleChanged > >                  liveTitleChangedListeners;
    std::shared_ptr < ListenerList < LiveTremoloAmountChanged > >          liveTremoloAmountChangedListeners;
    std::shared_ptr < ListenerList < LiveTremoloSpeedChanged > >           liveTremoloSpeedChangedListeners;
    std::shared_ptr < ListenerList < LiveVibratoAmountChanged > >          liveVibratoAmountChangedListeners;
    std::shared_ptr < ListenerList < LiveVibratoDelayChanged > >           liveVibratoDelayChangedListeners;
    std::shared_ptr < ListenerList < LiveVibratoSpeedChanged > >           liveVibratoSpeedChangedListeners;
    std::shared_ptr < ListenerList < LiveVoiceFilterChanged > >            liveVoiceFilterChangedListeners;
    std::shared_ptr < ListenerList < LiveVolumeChanged > >                 liveVolumeChangedListeners;
    std::shared_ptr < ListenerList < LoadLivePatch > >                     loadLivePatchListeners;

    std::shared_ptr < ListenerList < MIDISignal > >      midiSignalListeners;
    std::shared_ptr < ListenerList < NoteOn > >          noteOnListeners;
    std::shared_ptr < ListenerList < NoteOff > >         noteOffListeners;
    std::shared_ptr < ListenerList < PitchBend > >       pitchBendListeners;
    std::shared_ptr < ListenerList < QuarterNoteTick > > quarterNoteTickListeners;

    std::shared_ptr < ListenerList < AttackParameterChanged > >        attackParameterChangedListeners;
    std::shared_ptr < ListenerList < BandPassParameterChanged > >      bandPassParameterChangedListeners;
    std::shared_ptr < ListenerList < CutoffParameterChanged > >        cutoffParameterChangedListeners;
    std::shared_ptr < ListenerList < DecayParameterChanged > >         decayParameterChangedListeners;
    std::shared_ptr < ListenerList < FilterVoiceParameterChanged > >   filterVoiceParameterChangedListeners;
    std::shared_ptr < ListenerList < HighPassParameterChanged > >      highPassParameterChangedListeners;
    std::shared_ptr < ListenerList < LowPassParameterChanged > >       lowPassParameterChangedListeners;
    std::shared_ptr < ListenerList < PitchBendParameterChanged > >     pitchBendParameterChangedListeners;
    std::shared_ptr < ListenerList < ProgramParameterChanged > >       programParameterChangedListeners;
    std::shared_ptr < ListenerList < PulseWidthParameterChanged > >    pulseWidthParameterChangedListeners;
    std::shared_ptr < ListenerList < ReleaseParameterChanged > >       releaseParameterChangedListeners;
    std::shared_ptr < ListenerList < ResonanceParameterChanged > >     resonanceParameterChangedListeners;
    std::shared_ptr < ListenerList < SustainParameterChanged > >       sustainParameterChangedListeners;
    std::shared_ptr < ListenerList < TremoloAmountParameterChanged > > tremoloAmountParameterChangedListeners;
    std::shared_ptr < ListenerList < TremoloSpeedParameterChanged > >  tremoloSpeedParameterChangedListeners;
    std::shared_ptr < ListenerList < VibratoAmountParameterChanged > > vibratoAmountParameterChangedListeners;
    std::shared_ptr < ListenerList < VibratoDelayParameterChanged > >  vibratoDelayParameterChangedListeners;
    std::shared_ptr < ListenerList < VibratoSpeedParameterChanged > >  vibratoSpeedParameterChangedListeners;
    std::shared_ptr < ListenerList < VolumeParameterChanged > >        volumeParameterChangedListeners;

    std::shared_ptr < ListenerList < PatchEditorAttackChanged > >               patchEditorAttackChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorDecayChanged > >                patchEditorDecayChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorDeleteTableRowClicked > >       patchEditorDeleteWavetableRowClickedListeners;
    std::shared_ptr < ListenerList < PatchEditorLiveModeClicked > >             patchEditorLiveModeClickedListeners;
    std::shared_ptr < ListenerList < PatchEditorNameChanged > >                 patchEditorNameChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorNewTableCommandClicked > >      patchEditorNewWavetableCommandClickedListeners;
    std::shared_ptr < ListenerList < PatchEditorNewTableRowClicked > >          patchEditorNewWavetableRowClickedListeners;
    std::shared_ptr < ListenerList < PatchEditorPitchBendRangeChanged > >       patchEditorPitchBendRangeChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorPulseWidthCenterChanged > >     patchEditorPulseWidthCenterChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorPulseWidthDefaultChanged > >    patchEditorPulseWidthDefaultChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorPulseWidthRangeChanged > >      patchEditorPulseWidthRangeChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorReleaseChanged > >              patchEditorReleaseChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorShowNoteTable > >               patchEditorShowNoteTableListeners;
    std::shared_ptr < ListenerList < PatchEditorShowPulseTable > >              patchEditorShowPulseTableListeners;
    std::shared_ptr < ListenerList < PatchEditorShowWaveTable > >               patchEditorShowWaveTableListeners;
    std::shared_ptr < ListenerList < PatchEditorSustainChanged > >              patchEditorSustainChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorTremoloDefaultAmountChanged > > patchEditorTremoloDefaultAmountChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorTremoloDefaultSpeedChanged > >  patchEditorTremoloDefaultSpeedChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorTremoloRangeChanged > >         patchEditorTremoloRangeChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorTremoloSpeedChanged > >         patchEditorTremoloSpeedChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorVibratoDefaultAmountChanged > > patchEditorVibratoDefaultAmountChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorVibratoDefaultSpeedChanged > >  patchEditorVibratoDefaultSpeedChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorVibratoDelayChanged > >         patchEditorVibratoDelayChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorVibratoRangeChanged > >         patchEditorVibratoRangeChangedListeners;
    std::shared_ptr < ListenerList < PatchEditorVibratoSpeedChanged > >         patchEditorVibratoSpeedChangedListeners;

    std::shared_ptr < ListenerList < Frame > >                      frameListeners;
    std::shared_ptr < ListenerList < NoteTableRowChanged > >        noteTableRowChangedListeners;
    std::shared_ptr < ListenerList < NoteTableSelectionChanged > >  noteTableSelectionChangedListeners;
    std::shared_ptr < ListenerList < PulseTableRowChanged > >       pulseTableRowChangedListeners;
    std::shared_ptr < ListenerList < PulseTableSelectionChanged > > pulseTableSelectionChangedListeners;
    std::shared_ptr < ListenerList < SampleRateChanged > >          sampleRateChangedListeners;
    std::shared_ptr < ListenerList < WavetableRowChanged > >        wavetableRowChangedListeners;
    std::shared_ptr < ListenerList < WavetableSelectionChanged > >  wavetableSelectionChangedListeners;
};
