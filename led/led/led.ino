int LED_PIN = 2;

// Ejecuta una sola vez las siguientes instrucciones
void setup()
{
	// El led se conecta a un pin de salida
	pinMode(LED_PIN, OUTPUT);
}

// Repite para siempre las siguientes instrucciones
void loop()
{
	// Enciende el LED (a nivel alto)
	digitalWrite(LED_PIN, HIGH);

	// Espera 1000 milisegundos (1 segundo)
	delay(1000);

	// Apaga el pin 2 (a nivel bajo)
	digitalWrite(LED_PIN, LOW);

	// Espera 1000 milisegundos (1 segundo)
	delay(1000);
}
