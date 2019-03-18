/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
	// Number of taps: 
	addAndMakeVisible(numTapSlider);
	numTapSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	numTapSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	numTapSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	numTapSlider.setRange(0, 16, 1);
	numTapSlider.onValueChange = [this] { numTaps = numTapSlider.getValue(); };
	numTapSlider.setValue(numTaps);
	numTapSlider.setLookAndFeel(&otherLookAndFeel);
	//
	addAndMakeVisible(numTapsLabel);
	numTapsLabel.setText("Number of Taps", dontSendNotification);
	numTapsLabel.setColour(Label::textColourId, Colours::peru);

	// Phasor Amp:
	addAndMakeVisible(phasorAmpSlider);
	phasorAmpSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	phasorAmpSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	phasorAmpSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	phasorAmpSlider.setRange(-100000.0, 100000.0f, 1.0f);
	phasorAmpSlider.onValueChange = [this] { pAmp = phasorAmpSlider.getValue(); };
	phasorAmpSlider.setValue(pAmp);
	phasorAmpSlider.setLookAndFeel(&otherLookAndFeel);
	//
	addAndMakeVisible(phasorAmpLabel);
	phasorAmpLabel.setText("Pitch Shift", dontSendNotification);
	phasorAmpLabel.setColour(Label::textColourId, Colours::peru);


	// Phasor Start:
	addAndMakeVisible(phasorStartSlider);
	phasorStartSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	phasorStartSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	phasorStartSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	phasorStartSlider.setRange(0.001f, 40.0f, 0.01f);
	phasorStartSlider.onValueChange = [this] {  wavetableFrequency = phasorStartSlider.getValue(); };
	phasorStartSlider.setValue(wavetableFrequency);
	phasorStartSlider.setLookAndFeel(&otherLookAndFeel);
	//
	addAndMakeVisible(phasorStartLabel);
	phasorStartLabel.setText("Wavetable F", dontSendNotification);
	phasorStartLabel.setColour(Label::textColourId, Colours::peru);

	// Delay Time Local:
	addAndMakeVisible(delayTimeLocalSlider);
	delayTimeLocalSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	delayTimeLocalSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	delayTimeLocalSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	delayTimeLocalSlider.setRange(0.0f, 1.0f, 0.1f);
	delayTimeLocalSlider.onValueChange = [this] { delayTimeLocal = delayTimeLocalSlider.getValue(); };
	delayTimeLocalSlider.setValue(delayTimeLocal);
	delayTimeLocalSlider.setLookAndFeel(&otherLookAndFeel);
	//
	addAndMakeVisible(delayTimeLocalLabel);
	delayTimeLocalLabel.setText("Local Delay", dontSendNotification);
	delayTimeLocalLabel.setColour(Label::textColourId, Colours::peru);


	// Delay Time Global: 
	addAndMakeVisible(delayTimeGlobalSlider);
	delayTimeGlobalSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	delayTimeGlobalSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	delayTimeGlobalSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	delayTimeGlobalSlider.setRange(0.1f, 10.0f, 0.1f);
	delayTimeGlobalSlider.onValueChange = [this] { delayTimeGlobal = delayTimeGlobalSlider.getValue(); };
	delayTimeGlobalSlider.setValue(delayTimeGlobal);
	delayTimeGlobalSlider.setLookAndFeel(&otherLookAndFeel);
	//
	addAndMakeVisible(delayTimeGlobalLabel);
	delayTimeGlobalLabel.setText("Global Delay", dontSendNotification);
	delayTimeGlobalLabel.setColour(Label::textColourId, Colours::peru);
	//

	addAndMakeVisible(drySignalVolumeSlider);
	drySignalVolumeSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	drySignalVolumeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	drySignalVolumeSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	drySignalVolumeSlider.setRange(0.0f, 0.5f, 0.1f);
	drySignalVolumeSlider.onValueChange = [this] { dryVol = drySignalVolumeSlider.getValue(); };
	drySignalVolumeSlider.setValue(dryVol);
	drySignalVolumeSlider.setLookAndFeel(&otherLookAndFeel);
		
	addAndMakeVisible(drySignalVolumeLabel);
	drySignalVolumeLabel.setText("Dry Vol", dontSendNotification);
	drySignalVolumeLabel.setColour(Label::textColourId, Colours::peru);
	//

	addAndMakeVisible(wavetableAmplitudeSlider);
	wavetableAmplitudeSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	wavetableAmplitudeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	wavetableAmplitudeSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	wavetableAmplitudeSlider.setRange(0.0f, 441000.0f, 0.1f);
	wavetableAmplitudeSlider.onValueChange = [this] { wavetableAmp = wavetableAmplitudeSlider.getValue(); };
	wavetableAmplitudeSlider.setValue(wavetableAmp);
	wavetableAmplitudeSlider.setLookAndFeel(&otherLookAndFeel);

	addAndMakeVisible(wavetableAmplitudeLabel);
	wavetableAmplitudeLabel.setText("Wavetable Amp", dontSendNotification);
	wavetableAmplitudeLabel.setColour(Label::textColourId, Colours::peru);
	//

	// Feedback Gain:
	addAndMakeVisible(feedbackGainSlider);
	feedbackGainSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	feedbackGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	feedbackGainSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	feedbackGainSlider.setRange(0.0f, 1.0f, 0.1f);
	feedbackGainSlider.onValueChange = [this] { feedbackGain = feedbackGainSlider.getValue(); };
	feedbackGainSlider.setValue(feedbackGain);
	feedbackGainSlider.setLookAndFeel(&otherLookAndFeel);

	addAndMakeVisible(feedbackGainLabel);
	feedbackGainLabel.setText("Feedback Gain", dontSendNotification);
	feedbackGainLabel.setColour(Label::textColourId, Colours::peru);

	// Beat Division Slider:
	addAndMakeVisible(beatDivisionSlider);
	beatDivisionSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	beatDivisionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	beatDivisionSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	beatDivisionSlider.setRange(0.0f, 4.0f, 1.0f);
	beatDivisionSlider.onValueChange = [this] { beatDivision = beatDivisionSlider.getValue(); };
	beatDivisionSlider.setValue(beatDivision);
	beatDivisionSlider.setLookAndFeel(&otherLookAndFeelBlue);

	addAndMakeVisible(beatDivisionLabel);
	beatDivisionLabel.setText("Beat Division", dontSendNotification);
	beatDivisionLabel.setColour(Label::textColourId, Colours::peru);

	// BPM Slider
	addAndMakeVisible(bpmSlider);
	bpmSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	bpmSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	bpmSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	bpmSlider.setRange(20.0f, 240.0f, 1.0f);
	bpmSlider.onValueChange = [this] { bpmValue = bpmSlider.getValue(); };
	bpmSlider.setValue(bpmValue);
	bpmSlider.setLookAndFeel(&otherLookAndFeelBlue);

	addAndMakeVisible(bpmLabel);
	bpmLabel.setText("BPM", dontSendNotification);
	bpmLabel.setColour(Label::textColourId, Colours::peru);

	// Sampled Wave Slider:
	addAndMakeVisible(sampledWaveSlider);
	sampledWaveSlider.setSliderStyle(Slider::SliderStyle::Rotary);
	sampledWaveSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	sampledWaveSlider.setColour(Slider::textBoxTextColourId, Colours::black);
	sampledWaveSlider.setRange(44100.0f, 220500.0f, 1.0f);
	sampledWaveSlider.onValueChange = [this] { sampledWaveAmplitude = sampledWaveSlider.getValue(); };
	sampledWaveSlider.setValue(sampledWaveAmplitude);
	sampledWaveSlider.setLookAndFeel(&otherLookAndFeel);

	addAndMakeVisible(sampledWaveLabel);
	sampledWaveLabel.setText("Segment Size", dontSendNotification);
	sampledWaveLabel.setColour(Label::textColourId, Colours::peru);
	//

	clock.setTicksPerBeat(64); //not sure if needed. seems to be MIDI related
	clock.setTempo(120.0);
	//
	// Buffer initialisations:
	numSeconds = 10.0; // need to be able to vary this. also the max Duration of the phasor will be determined by the storage buffer size
	numSamples = numSeconds * 44100;
	// desiredSamples = numSamples;
	oldBuffer.resize(numSamples);
	taps.resize(16);
	ind.resize(16);
	dt.resize(16);
	interpTap.resize(16);

	//sample1.load("/Users/pootPoot/Documents/Juce_Projects/Delay_Multiple_Taps/words.wav");
	sample1.load("/Users/pootPoot/Documents/Juce_Projects/Delay Standalone/0-Coast.wav");
	//promisesbroken_Fm.wav
	//wood.wav
	sample2.load("/Users/pootPoot/Documents/Juce_Projects/AKWF-FREE-master/AKWF/AKWF_bw_blended/AKWF_blended_0009.wav");

	for (int i = 0; i < numSamples; i++)
	{
		oldBuffer[i] = 0.0;
	}

	for (int i = 0; i < 16; i++)
	{
		taps[i] = 0.0;
		ind[i] = 0.0;
		dt[i] = 0;
		interpTap[i] = 0.0;
	}
	fill_sine();

	setSize(620, 300);
    setAudioChannels (2, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
	auto* leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
	auto* rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

	// Variable to store original signal:
	double dryLeft;
	// wave table increment value:
	double wavetable_sample_increment = wavetableFrequency * table_len / wavetableSamplingRate;

	// Beat Division Switch Statement:
	switch (beatDivision)
	{
	case Sixteenth:
		// Logger::outputDebugString("16\n");
		beatDivisionMultiplier = 0.25;
		break;
	case Eight:
		// Logger::outputDebugString("8\n");
		beatDivisionMultiplier = 0.5;
		break;
	case Quarter:
		// Logger::outputDebugString("4\n");
		beatDivisionMultiplier = 1.0;
		break;
	case Half:
		// Logger::outputDebugString("2\n");
		beatDivisionMultiplier = 2.0;
		break;
	case Whole:
		// Logger::outputDebugString("1\n");
		beatDivisionMultiplier = 4.0;
		break;
	default:
		// Logger::outputDebugString("default is 16th\n");
		beatDivisionMultiplier = 0.25;
		break;
	}
	//Logger::outputDebugString(to_string(beatDivisionMultiplier));

	for (int sample = 0; sample < bufferToFill.numSamples; sample++)
	{
		// Clock: not using this currently
		clock.ticker();
		if (clock.tick) { 
			// Logger::outputDebugString("Ticking");
			// Logger::outputDebugString(to_string(clock.playHead));
		}

		 // wavetable:
		/*// we use this 'wavetableSample' value the same as the value 'phasor' below
		double wavetableSample = waveform_interpolation(wavetablePhase) * 1000;// table[(long)wavetablePhase]; 
		wavetablePhase += wavetable_sample_increment;
		// Wraparound logic, put phase to 0 if greater than table length:
		if (wavetablePhase > table_len) wavetablePhase -= table_len;
		*/
		
		double wavetableSample = (sample2.play(wavetableFrequency, 0, sample2.getLength())) * wavetableAmp;
		// acquire the dry signal:
		dryLeft = sample1.play();// buffer.getReadPointer(0)[sample];

		// Set the current buffer index to the new dry signal:
		oldBuffer[counter] = dryLeft;

		counter++;
		if (counter >= (10.0 * 44100))
		{
			counter = 0;
		}

		// choose either the square wave, or sampledWaveForm to add to the ind[i] below
		double square = ((squareOsc.square(0.1) + 1.0f) / 2.0f) * sampledWaveAmplitude; // 100000;
		double sampledWave = ((sampledWaveform.triangle(0.1) + 1.0f) / 2.0f) * sampledWaveAmplitude; //100000;
		
		if (waveUpdateCounter >= 44100)
		{ 
			wave = sampledWave;
			waveUpdateCounter = 0;
		}

		waveUpdateCounter++;

		// The phasor:
		double phasor = (osc1.phasor(0.5) * pAmp);

		//
	
		outputSignal = (dryLeft * dryVol); // dryLeft + (outputSignal * gain);
		for (int i = 0; i < numTaps; i++)
		{
			// one issue here is tap indexes exceeding the maximum delaytime index:
			// this is because the global delay time doesn't exceed the buffer limit,
			// but adding stuff to it does. so we need either to wrap around, or not include outliers.
			// i take care of this further dfown below in the next loop. 
			if(timeByBeatDivision == false)
			{
				dt[i] = (delayTimeGlobal * 44100) + (i * (delayTimeLocal * 44100));
			} else if (timeByBeatDivision == true)
			{
				double beatsToMs = (60000 / bpmValue) * beatDivisionMultiplier;
				double beatsToSecs = beatsToMs / 1000;
				int numDivisionSamples = beatsToSecs * 44100;
				//Logger::outputDebugString(to_string(numDivisionSamples));
				dt[i] = numDivisionSamples * (i+1);
				//Logger::outputDebugString(to_string( dt[i]) );
			}
			
			// Find the indexes of all of the taps:
			// by subtracting each tap's delaytime from the write pointer:
			// the square wave makes the position of the playhead jump between points:
			ind[i] = (counter + phasor  + ((wavetableSample + 1.0f) / 2.0f)) - dt[i];
				
				// dt[i] + (counter + phasor + (square * 100000.0f)); // with the square wave effect !:)
				//dt[i] + (phasor + (square * 215000.0f));
				// (counter + phasor + ((wavetableSample + 1.0f) / 2.0f)) - dt[i]; // this is the original that was working
				//  counter -dt[i]; 
			 
			// try modulating phasor osc by the wavetableSample value
			// dt[i] + ((wavetableSample + 1.0f) / 2.0f);// 

			//	Logger::outputDebugString(to_string(phasor));
			if (ind[i] >= 0 & ind[i] < (10 * 44100))
			{
				ind[i] = ind[i];
			}
			else if (ind[i] >= (10 * 44100)) {
				ind[i] = ind[i] - (10 * 44100);
			}
			else {
				ind[i] = ind[i] + (10 * 44100);
			}
			//
				// if the overall delay time of any of the taps is larger than the delay buffer, then don't include it:
			if (dt[i] > 441000)
			{
				taps[i] = 0;

			} else {

				// Interpolation : truncate the index so we have a whole number:
				interpTap[i] = int(ind[i]);
				// find the remainder:
				double frac = ind[i] - interpTap[i];
				double next = 0.0;
				// if we dont need to wrap around, then go ahead and read the next sample:
				if (interpTap[i] != (numSamples - 1))
				{
					next = oldBuffer[interpTap[i] + 1];
				}
				else { // else wrap-around:
					next = oldBuffer[0];
				}

				double interpolatedValue = oldBuffer[interpTap[i]] + frac * (next - oldBuffer[interpTap[i]]);
				//double outS = interpolatedValue;
				taps[i] = interpolatedValue;// interpolatedValue;// oldBuffer[ind[i]];
			}
			outputSignal += taps[i];
		}

		leftBuffer[sample] = outputSignal * 0.5; // sample2.play(wavetableFrequency, 0, sample2.getLength()-1);
		rightBuffer[sample] = leftBuffer[sample];
	}

}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(Colours::whitesmoke);

    // You can add your drawing code here!
}

void MainComponent::resized()
{
	numTapSlider.setBounds(10, 10, 100, 100);
	numTapsLabel.setBounds(10, 115, 170, 30);

	delayTimeLocalSlider.setBounds(110, 10, 100, 100);
	delayTimeLocalLabel.setBounds(122, 115, 80, 30);

	delayTimeGlobalSlider.setBounds(210, 10, 100, 100);
	delayTimeGlobalLabel.setBounds(210, 115, 170, 30);

	drySignalVolumeSlider.setBounds(310, 10, 100, 100);
	drySignalVolumeLabel.setBounds(310, 115, 80, 30);

	// BPM:
	bpmSlider.setBounds(420, 10, 100, 100);
	bpmLabel.setBounds(420, 115, 80, 30);

	// Beat Division:
	beatDivisionSlider.setBounds(520, 10, 100, 100);
	beatDivisionLabel.setBounds(520, 115, 100, 30);

	// Next row:
	phasorStartSlider.setBounds(10, 140, 100, 100);
	phasorStartLabel.setBounds(10, 245, 80, 30);

	phasorAmpSlider.setBounds(110, 140, 100, 100);
	phasorAmpLabel.setBounds(115, 245, 100, 30);

	wavetableAmplitudeSlider.setBounds(210, 140, 100, 100);
	wavetableAmplitudeLabel.setBounds(210, 245, 110, 30);

	feedbackGainSlider.setBounds(310, 140, 100, 100);
	feedbackGainLabel.setBounds(310, 245, 100, 30);

	sampledWaveSlider.setBounds(520, 140, 100, 100);
	sampledWaveLabel.setBounds(520, 245, 100, 30);

	
}
