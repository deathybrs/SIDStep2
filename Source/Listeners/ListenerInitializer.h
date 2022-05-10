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


class ListenerInitializer
{
public:
    ListenerInitializer ();

    ~ListenerInitializer () = default;

    ListenerInitializer (
            const ListenerInitializer& other
            ) = delete;

    ListenerInitializer (
            ListenerInitializer&& other
            ) = delete;

    auto
        operator= (
                const ListenerInitializer& other
                ) -> ListenerInitializer& = delete;

    auto
        operator= (
                ListenerInitializer&& other
                ) -> ListenerInitializer& = delete;

private:
    SharedResourcePointer < ListenerList < BankLoad > >            bankLoadListeners;
    SharedResourcePointer < ListenerList < BankNew > >             bankNewListeners;
    SharedResourcePointer < ListenerList < BankProgramChanged > >  bankProgramChangedListeners;
    SharedResourcePointer < ListenerList < BankRefreshLive > >     bankRefreshLive;
    SharedResourcePointer < ListenerList < BankRepaintWaveform > > bankRepaintWaveformListeners;
    SharedResourcePointer < ListenerList < BankSave > >            bankSaveListeners;
    SharedResourcePointer < ListenerList < BankSaveAs > >          bankSaveAsListeners;
    SharedResourcePointer < ListenerList < BankStartSaveAs > >     bankStartSaveAsListeners;
    SharedResourcePointer < ListenerList < BankTreeChanged > >     bankTreeChangedListeners;

    SharedResourcePointer < ListenerList < ExportAttackChanged > >        exportAttackChanged;
    SharedResourcePointer < ListenerList < ExportBandPassChanged > >      exportBandPassChanged;
    SharedResourcePointer < ListenerList < ExportCutoffChanged > >        exportCutoffChanged;
    SharedResourcePointer < ListenerList < ExportDecayChanged > >         exportDecayChanged;
    SharedResourcePointer < ListenerList < ExportHighPassChanged > >      exportHighPassChanged;
    SharedResourcePointer < ListenerList < ExportLowPassChanged > >       exportLowPassChanged;
    SharedResourcePointer < ListenerList < ExportPatchChanged > >         exportPatchChanged;
    SharedResourcePointer < ListenerList < ExportPitchBendChanged > >     exportPitchBendChanged;
    SharedResourcePointer < ListenerList < ExportPulseWidthChanged > >    exportPulseWidthChanged;
    SharedResourcePointer < ListenerList < ExportReleaseChanged > >       exportReleaseChanged;
    SharedResourcePointer < ListenerList < ExportResonanceChanged > >     exportResonanceChanged;
    SharedResourcePointer < ListenerList < ExportSustainChanged > >       exportSustainChanged;
    SharedResourcePointer < ListenerList < ExportTremoloAmountChanged > > exportTremoloAmountChanged;
    SharedResourcePointer < ListenerList < ExportTremoloSpeedChanged > >  exportTremoloSpeedChanged;
    SharedResourcePointer < ListenerList < ExportVibratoAmountChanged > > exportVibratoAmountChanged;
    SharedResourcePointer < ListenerList < ExportVibratoSpeedChanged > >  exportVibratoSpeedChanged;
    SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > >   exportVoiceFilterChanged;
    SharedResourcePointer < ListenerList < ExportVolumeChanged > >        exportVolumeChanged;
    SharedResourcePointer < ListenerList < ShowExportManager > >          showExportManager;

    SharedResourcePointer < ListenerList < LiveAddPatchClicked > >               liveAddPatchClickedListeners;
    SharedResourcePointer < ListenerList < LiveArtistChanged > >                 liveArtistChangedListeners;
    SharedResourcePointer < ListenerList < LiveAttackChanged > >                 liveAttackChangedListeners;
    SharedResourcePointer < ListenerList < LiveBandPassChanged > >               liveBandPassChangedListeners;
    SharedResourcePointer < ListenerList < LiveCutoffChanged > >                 liveCutoffChangedListeners;
    SharedResourcePointer < ListenerList < LiveDecayChanged > >                  liveDecayChangedListeners;
    SharedResourcePointer < ListenerList < LiveDoneExporting > >                 liveDoneExportingListeners;
    SharedResourcePointer < ListenerList < LiveExportArmed > >                   liveExportArmedListeners;
    SharedResourcePointer < ListenerList < LiveHighPassChanged > >               liveHighPassChangedListeners;
    SharedResourcePointer < ListenerList < LiveLowPassChanged > >                liveLowPassChangedListeners;
    SharedResourcePointer < ListenerList < LivePatchChanged > >                  livePatchChangedListeners;
    SharedResourcePointer < ListenerList < LivePatchEditorModeClicked > >        livePatchEditorModeClickedListeners;
    SharedResourcePointer < ListenerList < LivePatchListChanged > >              livePatchListChangedListeners;
    SharedResourcePointer < ListenerList < LivePatchListMode > >                 livePatchListModeListeners;
    SharedResourcePointer < ListenerList < LivePatchListSelectedIndexChanged > > livePatchListSelectedIndexChangedListeners;
    SharedResourcePointer < ListenerList < LivePatchSelected > >                 livePatchSelectedListeners;
    SharedResourcePointer < ListenerList < LivePitchBendChanged > >              livePitchBendChangedListeners;
    SharedResourcePointer < ListenerList < LivePulseWidthChanged > >             livePulseWidthChangedListeners;
    SharedResourcePointer < ListenerList < LiveReleaseChanged > >                liveReleaseChangedListeners;
    SharedResourcePointer < ListenerList < LiveRemovePatchClicked > >            liveRemovePatchClickedListeners;
    SharedResourcePointer < ListenerList < LiveReplacePatchClicked > >           liveReplacePatchClickedListeners;
    SharedResourcePointer < ListenerList < LiveResonanceChanged > >              liveResonanceChangedListeners;
    SharedResourcePointer < ListenerList < LiveSustainChanged > >                liveSustainChangedListeners;
    SharedResourcePointer < ListenerList < LiveTitleChanged > >                  liveTitleChangedListeners;
    SharedResourcePointer < ListenerList < LiveTremoloAmountChanged > >          liveTremoloAmountChangedListeners;
    SharedResourcePointer < ListenerList < LiveTremoloSpeedChanged > >           liveTremoloSpeedChangedListeners;
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > >          liveVibratoAmountChangedListeners;
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > >           liveVibratoDelayChangedListeners;
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > >           liveVibratoSpeedChangedListeners;
    SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > >            liveVoiceFilterChangedListeners;
    SharedResourcePointer < ListenerList < LiveVolumeChanged > >                 liveVolumeChangedListeners;
    SharedResourcePointer < ListenerList < LoadLivePatch > >                     loadLivePatchListeners;

    SharedResourcePointer < ListenerList < MIDISignal > >      midiSignalListeners;
    SharedResourcePointer < ListenerList < NoteOn > >          noteOnListeners;
    SharedResourcePointer < ListenerList < NoteOff > >         noteOffListeners;
    SharedResourcePointer < ListenerList < PitchBend > >       pitchBendListeners;
    SharedResourcePointer < ListenerList < QuarterNoteTick > > quarterNoteTickListeners;

    SharedResourcePointer < ListenerList < AttackParameterChanged > >        attackParameterChangedListeners;
    SharedResourcePointer < ListenerList < BandPassParameterChanged > >      bandPassParameterChangedListeners;
    SharedResourcePointer < ListenerList < CutoffParameterChanged > >        cutoffParameterChangedListeners;
    SharedResourcePointer < ListenerList < DecayParameterChanged > >         decayParameterChangedListeners;
    SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > >   filterVoiceParameterChangedListeners;
    SharedResourcePointer < ListenerList < HighPassParameterChanged > >      highPassParameterChangedListeners;
    SharedResourcePointer < ListenerList < LowPassParameterChanged > >       lowPassParameterChangedListeners;
    SharedResourcePointer < ListenerList < PitchBendParameterChanged > >     pitchBendParameterChangedListeners;
    SharedResourcePointer < ListenerList < ProgramParameterChanged > >       programParameterChangedListeners;
    SharedResourcePointer < ListenerList < PulseWidthParameterChanged > >    pulseWidthParameterChangedListeners;
    SharedResourcePointer < ListenerList < ReleaseParameterChanged > >       releaseParameterChangedListeners;
    SharedResourcePointer < ListenerList < ResonanceParameterChanged > >     resonanceParameterChangedListeners;
    SharedResourcePointer < ListenerList < SustainParameterChanged > >       sustainParameterChangedListeners;
    SharedResourcePointer < ListenerList < TremoloAmountParameterChanged > > tremoloAmountParameterChangedListeners;
    SharedResourcePointer < ListenerList < TremoloSpeedParameterChanged > >  tremoloSpeedParameterChangedListeners;
    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > vibratoAmountParameterChangedListeners;
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > >  vibratoDelayParameterChangedListeners;
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > >  vibratoSpeedParameterChangedListeners;
    SharedResourcePointer < ListenerList < VolumeParameterChanged > >        volumeParameterChangedListeners;

    SharedResourcePointer < ListenerList < PatchEditorAttackChanged > >               patchEditorAttackChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorDecayChanged > >                patchEditorDecayChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > >       patchEditorDeleteWavetableRowClickedListeners;
    SharedResourcePointer < ListenerList < PatchEditorLiveModeClicked > >             patchEditorLiveModeClickedListeners;
    SharedResourcePointer < ListenerList < PatchEditorNameChanged > >                 patchEditorNameChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > >      patchEditorNewWavetableCommandClickedListeners;
    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > >          patchEditorNewWavetableRowClickedListeners;
    SharedResourcePointer < ListenerList < PatchEditorPitchBendRangeChanged > >       patchEditorPitchBendRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorPulseWidthCenterChanged > >     patchEditorPulseWidthCenterChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorPulseWidthDefaultChanged > >    patchEditorPulseWidthDefaultChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorPulseWidthRangeChanged > >      patchEditorPulseWidthRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorReleaseChanged > >              patchEditorReleaseChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > >               patchEditorShowNoteTableListeners;
    SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > >              patchEditorShowPulseTableListeners;
    SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > >               patchEditorShowWaveTableListeners;
    SharedResourcePointer < ListenerList < PatchEditorSustainChanged > >              patchEditorSustainChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorTremoloDefaultAmountChanged > > patchEditorTremoloDefaultAmountChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorTremoloDefaultSpeedChanged > >  patchEditorTremoloDefaultSpeedChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorTremoloRangeChanged > >         patchEditorTremoloRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorTremoloSpeedChanged > >         patchEditorTremoloSpeedChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultAmountChanged > > patchEditorVibratoDefaultAmountChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultSpeedChanged > >  patchEditorVibratoDefaultSpeedChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoDelayChanged > >         patchEditorVibratoDelayChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoRangeChanged > >         patchEditorVibratoRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoSpeedChanged > >         patchEditorVibratoSpeedChangedListeners;

    SharedResourcePointer < ListenerList < Frame > >                      frameListeners;
    SharedResourcePointer < ListenerList < NoteTableRowChanged > >        noteTableRowChangedListeners;
    SharedResourcePointer < ListenerList < NoteTableSelectionChanged > >  noteTableSelectionChangedListeners;
    SharedResourcePointer < ListenerList < PulseTableRowChanged > >       pulseTableRowChangedListeners;
    SharedResourcePointer < ListenerList < PulseTableSelectionChanged > > pulseTableSelectionChangedListeners;
    SharedResourcePointer < ListenerList < SampleRateChanged > >          sampleRateChangedListeners;
    SharedResourcePointer < ListenerList < WavetableRowChanged > >        wavetableRowChangedListeners;
    SharedResourcePointer < ListenerList < WavetableSelectionChanged > >  wavetableSelectionChangedListeners;
};
