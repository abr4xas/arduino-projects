#include <DHT.h>
#include <SPI.h>
#include <U8g2lib.h>

#define DHTPIN A0
#define DHTTYPE DHT11 // DHT 11
DHT dht = DHT(DHTPIN, DHTTYPE);

U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, 13, 11, 10, 9, 8); // D0=13, D1=11, CS=10, DC=9, Reset=8

/* u8g2.begin() is required and will sent the setup/init sequence to the display */
void setup(void)
{
	u8g2.begin();
	dht.begin();
}

/* draw something on the display with the `firstPage()`/`nextPage()` loop*/
void loop(void)
{
	float t = dht.readTemperature();
	float h = dht.readHumidity();

	u8g2.firstPage();
	do
	{
		u8g2.setFont(u8g2_font_ncenB14_tr);
		u8g2.drawStr(0, 30, "Temp: ");
		u8g2.drawStr(0, 50, "Hum: ");
		u8g2.setCursor(66, 30); // set position
		u8g2.print(t, 0);
		u8g2.drawStr(90, 30, "c ");
		u8g2.setCursor(60, 50);
		u8g2.print(h, 0); // display humidity from DHT11
		u8g2.drawStr(85, 50, "% ");
	} while (
		u8g2.nextPage());
	delay(2000);
}
