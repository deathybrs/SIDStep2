// ReSharper disable CppClangTidyCppcoreguidelinesMacroUsage
// ReSharper disable CppClangTidyBugproneMacroParentheses
#pragma once

#define SID_VOICE_1	0
#define SID_VOICE_2	1
#define SID_VOICE_3	2


// These three macros are used in the PluginProcessor constructor to do the
// initial construction of the parameter, add it to the ParameterProcessor, and
// set its initial value.
//
// Might not be necessary to set its initial value here, as it could be set later
// when the patches are initialized.
#define CREATE_PARAMETER_BASE(type,arguments,call,call_arguments) \
	type ## Parameter *parameter = new type ## Parameter arguments; \
	addParameter(parameter); \
	parameterProcessor->set ## call ## Parameter ## call_arguments;
#define CREATE_VOICE_PARAMETER(type,arguments,call) /*,group*/ \
{ \
	CREATE_PARAMETER_BASE(type, arguments, call, (v, parameter)) \
}
#define CREATE_PARAMETER(type,arguments,call) \
{ \
	CREATE_PARAMETER_BASE(type, arguments, call, (parameter)) \
}


// These three macros are the private field and public setter for the 
// Parameter object (not value) in the ParameterProcessor.
//
// It is called by the above macros to add the created parameter to the 
// ParameterProcessor.
#define SET_VOICE_PARAMETER(name,type,simpletype,evnt) \
private: \
	Array<type ## Parameter *> _ ## name ## Parameters; \
public: \
	void ParameterProcessor::on ## evnt ## (unsigned int voice, simpletype value) { \
		_ ## name ## Parameters[voice]->set ## type(value); \
	} \
	\
	void ParameterProcessor::set ## name ## Parameter(unsigned int voice, type ## Parameter *value) { \
		_ ## name ## Parameters.set(voice, value); \
	}
#define SET_PARAMETER(name,type,simpletype,evnt) \
private: \
	type ## Parameter *_ ## name ## Parameter; \
public: \
	void ParameterProcessor::on ## evnt ## (simpletype value) { \
		_ ## name ## Parameter->set ## type(value); \
	} \
	\
	void ParameterProcessor::set ## name ## Parameter(type ## Parameter *value) { \
		_ ## name ## Parameter = value; \
	}


// These two macros are called in the PluginProcessor to handle the actual 
// processing of parameters when they change.  These should be replaced with
// code that fires events rather than a direct call.  It is necessary to fire
// the events here rather than directly in the Parameter object because the
// Parameter objects don't actually know what they are.
#define PROCESS_PARAMETER(name,type,evnt,listener) \
	if (_ ## name ## Parameter != nullptr && _ ## name ## Parameter->isDirty()) { \
		listener->call(&evnt::on ## evnt, _ ## name ## Parameter->get ## type()); \
		_ ## name ## Parameter->setDirty(false); \
	}
//PROCESS_VOICE_PARAMETER(
//	VibratoSpeed
//	, UnsignedPercent
//	, VibratoSpeedParameterChanged
//	, dispatcher->vibratoSpeedParameterChangedListeners);
#define PROCESS_VOICE_PARAMETER(name,type,evnt,listener) \
	if (_ ## name ## Parameters[v] != nullptr && _ ## name ## Parameters[v]->isDirty()) { \
		listener->call(&evnt::on ## evnt, v, _ ## name ## Parameters[v]->get ## type()); \
		_ ## name ## Parameters[v]->setDirty(false); \
	}


// These three macros are the getters and setters for the parameters in the
// objects that contain them - SIDRegisters and SIDExpressions.  This will
// be replaced by private fields and methods that respond to the Events that 
// set them.  Additionally, ParameterProcessor will need to have events for the
// Live parameters.
// Looks like these events should be in SIDProgram and its children rather than 
// in SIDRegisters and SIDExpressions.
#define VOICE_REGISTER(type,levnt,pevnt,writecommand) \
	void on ## levnt(unsigned int voice, type value) override writecommand \
	void on ## pevnt(unsigned int voice, type value) override writecommand
#define SID_REGISTER(type,levnt,pevnt,writecommand) \
	void on ## levnt(type value) override writecommand \
	void on ## pevnt(type value) override writecommand
#define EVENT(evnt, parameters) \
class evnt { \
public: \
    evnt () {} \
	virtual ~evnt() = default; \
	evnt (const evnt& other) = default; \
	evnt (evnt&& other) = default; \
	auto operator=(const evnt& other) -> evnt& = default; \
	auto operator=(evnt&& other) -> evnt& = default; \
	\
	virtual void on ## evnt ## parameters ## = 0; \
};
