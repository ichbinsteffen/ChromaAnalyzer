/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ChromaAnalyzerAudioProcessorEditor::ChromaAnalyzerAudioProcessorEditor (ChromaAnalyzerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    setSize (400, 300);
    windowWidth = 400;
    windowHeight = 300;
    
    //addAndMakeVisible(FFT_Canvas = new DrawableComposite() );
    
    //gridImage = Image(Image::RGB, windowWidth, windowHeight, true);
    
    //Graphics g (gridImage);
    
    //fftSize = pow(2, p.FFT_size); // actual FFT Size number is 2^FFT_size
    
    //color = juce::Colour::fromRGB(250, 250, 250);
    
    //binStepSize = (p.getSampleRate()) / fftSize;
    
    // C = 110, 220, 440, 880, 1320, 1760
    // D =
    // E
    // F
    // G =
    
//    
//    for (size_t i = 1; i <= windowWidth; ++i) {
//        fake_FFT[i-1] = 0.5;
//    }
    
}

ChromaAnalyzerAudioProcessorEditor::~ChromaAnalyzerAudioProcessorEditor()
{
}

//==============================================================================
void ChromaAnalyzerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
    
    
    
    /*
    for (size_t i; i <= fftSize; ++i)
    {
        float magnitude = processor.bufferMonoMix->getSample(1, i);
        
        int mapped_Magnitude_Value = static_cast<int>(magnitude * windowHeight);
        
        gridImage.setPixelAt(i, mapped_Magnitude_Value, color);
    }
    */
    
    
    
    
    
    // FAKE FFT CODE
     
//    for (size_t i = 1; i <= windowWidth; ++i) {
//        gridImage.setPixelAt(i, static_cast<int>(fake_FFT[i-1] * windowHeight), color);
//    }
//    
//    juce::RectanglePlacement *rectPlace = new RectanglePlacement(1);
//    
//    g.drawImageWithin(gridImage, 0, 0, windowWidth, windowHeight, *rectPlace);
//    
//    
//    
}

void ChromaAnalyzerAudioProcessorEditor::resized() {
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
