/*****************************************************************************

Red light (640nm-680nm):
Red light affects phytochrome reversibility and is the most important for flowering and fruiting regulation. These wavelengths encourage stem growth, flowering and fruit production, and chlorophyll production.
The 660nm wavelength has a very strong photosynthetic action and also exhibits the highest action on red-absorbing phytochrome regulated germination, flowering and other processes.
Most effective for light cycle extension or night interruption to induce flowering of long-day plants or to prevent flowering of short-day plants.


Blue light (430nm-450nm):
This range of spectrum enables cryptochromes and phototropins to mediate plant responses such as phototropic curvature, inhibition of elongation growth, chloroplast movement, stomatal opening and seedling growth regulation.
It affects chlorophyll formation, photosynthesis processes, and through the cryptochrome and phytochrome system, raises the photomorphogenetic response.
In more practical terms, these wavelengths encourage vegetative growth and are essential in lighting for seedlings and young plants during the vegetative stage of their growth cycle, especially when “stretching” must be reduced or eliminated.
It also stimulates the production of secondary pigments which can enhance colors and is known to also stimulate Terpene (i.e. fragrance) production.


Green light (500nm-550nm):
Most green light is reflected off the plant and plays a much smaller role in plant growth. However, there are some important aspects of light in this range so a certain amount of light in this spectrum range is beneficial.
Green light is sometimes used as a tool for eliciting specific plant responses such as stomatal control, phototropism, photomorphogenic growth and environmental signaling.
When combined with blue, red and far-red wavelengths, green light completes a comprehensive spectral treatment for understanding plant physiological activity. The function of green light is less well understood than the other spectrums, and there are only certain species of plants that require green light for normal growth.
It’s effects appear to be very strain specific. The pigments that can absorb green are found deeper in the leaf structure so it is thought that because green light reflects off of the Chlorophyll in leaf surfaces and thus is reflected deeper into the shaded areas of the canopy than Red and Blue which are readily absorbed, that green may actually be mostly absorbed through the undersides of the leaves as it bounces around in the shaded depths of the canopy.


Source: https://californialightworks.com/light-spectrum-and-plant-growth/
Wavelenght converter to RGB: https://academo.org/demos/wavelength-to-colour-relationship/

Developer: Yoran Broodcooren
Version: 1.0

*****************************************************************************/

#include <FastLED.h>
#define NUM_LEDS 59
#define DATA_PIN 12
#define BLUE_MODULO 3

CRGBArray<NUM_LEDS> leds;

void setup()
{
	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
	FastLED.clear();
	FastLED.setBrightness(255);
	gettingStarted();
	FastLED.show();
}

void loop()
{
	// put your main code here, to run repeatedly:
	gettingStarted();
	FastLED.show();
}

void gettingStarted()
{
	for (int i = 0; i < NUM_LEDS; i++)
	{
		leds[i] = CRGB(255, 0, 0);
		if (i % BLUE_MODULO == 0)
		{
			leds[i] = CRGB(61, 0, 255);
		}
	}
}