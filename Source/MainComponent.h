/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once
#include "maximilian.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

// Custom Juce Look and Feel Method
class OtherLookAndFeel : public LookAndFeel_V4
{
public:
	OtherLookAndFeel()
	{
		setColour(Slider::thumbColourId, Colours::black);
	}


	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
	{
		auto radius = jmin(width / 2, height / 2) - 4.0f;
		auto centreX = x + width * 0.5f;
		auto centreY = y + height * 0.5f;
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;
		auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

		// fill
		g.setColour(Colours::orange);
		g.fillEllipse(rx, ry, rw, rw);
		// outline
		g.setColour(Colours::orange);
		g.drawEllipse(rx, ry, rw, rw, 1.0f);

		Path p;
		auto pointerLength = radius * 0.33f;
		auto pointerThickness = 2.0f;
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

		// pointer
		g.setColour(Colours::black);
		g.fillPath(p);
	}

private:
	//OtherLookAndFeel otherLookAndFeel; // [2]
	Slider dial1;
	Slider dial2;
	TextButton button1;
	TextButton button2;
};

// bpm sliders:
class OtherLookAndFeelBlue : public LookAndFeel_V4
{
public:
	OtherLookAndFeelBlue()
	{
		setColour(Slider::thumbColourId, Colours::black);
	}


	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
	{
		auto radius = jmin(width / 2, height / 2) - 4.0f;
		auto centreX = x + width * 0.5f;
		auto centreY = y + height * 0.5f;
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;
		auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

		// fill
		g.setColour(Colours::cornflowerblue);
		g.fillEllipse(rx, ry, rw, rw);
		// outline
		g.setColour(Colours::blue);
		g.drawEllipse(rx, ry, rw, rw, 1.0f);

		Path p;
		auto pointerLength = radius * 0.33f;
		auto pointerThickness = 2.0f;
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

		// pointer
		g.setColour(Colours::black);
		g.fillPath(p);
	}

private:
	//OtherLookAndFeel otherLookAndFeel; // [2]
	Slider dial1;
	Slider dial2;
	TextButton button1;
	TextButton button2;
};

//======================
class MainComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

	// Wavetable Fill Function:
	void fill_sine()/*fills the table with a single cycle of a sine wave */ {
		int j; for (j = 0; j < table_len; j++) table[j] = (float)sin(2 * PI * j / table_len);
	}

	// Wavetable Interpolation Function:
	double waveform_interpolation(double wavetable_phase) 
	{
		// the indexes:
		int x0 = (int)wavetable_phase;
		int x1 = (int)(wavetable_phase + 1.0);
		// variables to store the values at the indexes:
		double f0, f1;
		// if the second index is greater than the legnth of the wavetable, wrap it to index 0:
		if (x1 >= table_len) x1 = 0;
		// set the values to the values at the indexes:
		f0 = table[x0];
		f1 = table[x1];
		double out = f0 + (f1 - f0) * (wavetable_phase - x0);
		// Interpolate between the values:
		return out;
	}


private:
    //==============================================================================
	// Maximilian Objects:
	maxiOsc osc1, squareOsc, sampledWaveform;
	maxiSample sample1, sample2;
	maxiClock clock;
	vector<maxiSample> waveTable;

	int waveUpdateCounter = 0;
	double wave = 0.0;
	// Buffer Traversing Variables:
	double counter = 0;
	int numSamples;
	float numSeconds;
	double outputSignal = 0.0;

	//
	vector<double> oldBuffer; // the delay line 
	vector<double> taps; // the actual sample values of each tap
	vector<double> ind; // the index of each tap
	vector<int> dt; // the delay time of each tap
	vector<double> interpTap; // interpolation samples

	// Wave table things:
	int wavetableSamplingRate = 44100;
	//double wavetableFrequency = 1.0;
	double wavetablePhase = 0.0;
	int table_len = 512;
	double table[512];

	// Slider Values:
	int numTaps = 1;
	float delayTimeGlobal = 0.1;
	float delayTimeLocal = 0.1;
	double gain = 0.0;
	double pAmp = 0.0;
	double wavetableFrequency = 1.0;
	double wavetableAmp = 100.0;
	double dryVol = 0.1;
	double feedbackGain = 0.0;
	int bpmValue = 120;
	int beatDivision = 0;
	double beatDivisionMultiplier = 4.0;
	bool timeByBeatDivision = true;
	int sampledWaveAmplitude = 44100;

	enum BeatDivisionChoice
	{
		Sixteenth = 0,
		Eight = 1,
		Quarter = 2,
		Half = 3,
		Whole = 4,
		
	};

	// BPM knob, then using conversion derive the time division. 20 bpm - 240 bpm
	// 60 000 / bpm (120) = a quarter note e.g. 500
	// Division knob : i.e. if 1, quarter note
	
	// waves: ( (60 000 / bpm)*DivisionKnob ) / numTaps
	// divide the total samples in the waveform by the number of taps = increment thru waveform
	// Waves : ( numtap[i] * Division ) + yOffset =

	// ( tapnum * bufferIcrement ) *

	// tap 2 = 2* 500 = 1000ms
	// offset = take the waveform we are using, take its buffer size. Divide byffer size of the waveform by the number of taps - this is our increment
			// e.g. 600 / 4Taps = 150
	// So then : 2*150 = 300
	// we want the value at index 300 of our waveform e.g. -0.25
	// Rescale -1 and 1 to -500 to 500. so : -0.25 * 500 = -125
	// So then 1000ms - 125 = NewTime / indexinDelayBuffer.


	Slider numTapSlider, phasorStartSlider, phasorAmpSlider, delayTimeLocalSlider, delayTimeGlobalSlider, drySignalVolumeSlider;
	Slider wavetableAmplitudeSlider, feedbackGainSlider, beatDivisionSlider, bpmSlider, sampledWaveSlider;
	
	Label numTapsLabel, delayTimeLocalLabel, delayTimeGlobalLabel, phasorStartLabel, phasorAmpLabel, drySignalVolumeLabel;
	Label wavetableAmplitudeLabel, feedbackGainLabel, beatDivisionLabel, bpmLabel, sampledWaveLabel;
	OtherLookAndFeel otherLookAndFeel;
	OtherLookAndFeelBlue otherLookAndFeelBlue;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
