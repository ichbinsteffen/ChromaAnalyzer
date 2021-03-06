/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
ChromaAnalyzerAudioProcessor::ChromaAnalyzerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{

}

ChromaAnalyzerAudioProcessor::~ChromaAnalyzerAudioProcessor()
{
    delete myFFT;
}

//==============================================================================
const String ChromaAnalyzerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ChromaAnalyzerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ChromaAnalyzerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double ChromaAnalyzerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ChromaAnalyzerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ChromaAnalyzerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ChromaAnalyzerAudioProcessor::setCurrentProgram (int index)
{

}

const String ChromaAnalyzerAudioProcessor::getProgramName (int index)
{
    return {};
}

void ChromaAnalyzerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ChromaAnalyzerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    myFFT = new FFT::FFT(FFT_size,0);
    int block_size = this->getBlockSize();
    
    bufferMonoMix.setSize(1, 512);
}

void ChromaAnalyzerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ChromaAnalyzerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void ChromaAnalyzerAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    const int bufferSize = buffer.getNumSamples();
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i) {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
    
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    
    

    for (int sampleIndex = 0; sampleIndex <  bufferSize ; sampleIndex++)
    {
        float LeftValue = buffer.getSample(0, sampleIndex);
        float RightValue = buffer.getSample(1, sampleIndex);
            
        float mixedValue = (LeftValue + RightValue) * 0.5;

        bufferMonoMix.setSample(0, sampleIndex, mixedValue);
    }

    float *bufferMonoMix_Ptr = bufferMonoMix.getWritePointer(0);
    //myFFT->performFrequencyOnlyForwardTransform(bufferMonoMix_Ptr);
}

//==============================================================================
bool ChromaAnalyzerAudioProcessor::hasEditor() const {
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ChromaAnalyzerAudioProcessor::createEditor()
{
    return new ChromaAnalyzerAudioProcessorEditor (*this);
}

//==============================================================================
void ChromaAnalyzerAudioProcessor::getStateInformation (MemoryBlock& destData) {
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void ChromaAnalyzerAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ChromaAnalyzerAudioProcessor();
}
