
#include <LiquidCrystal.h> // Version 1.0.7 Latest
#include <IRremote.hpp> //Version 2.x



//Portas LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Porta IR
const int pinIR = 13;

//Portas Leds
const int ledVermelho = A1;
const int ledVerde = A2;

//Portas RGB
const int rgbVermelho = 10;
const int rgbAzul = 9;
const int rgbVerde = 8;

//Porta PIR
const int sensorPir = 6;

//Variaveis Locais
int valorSensorPir = 0;
int botaoCor = 0;

bool lampadaOn = false;
bool presenca = false;

// DESLIGA 
void desligar() {
	digitalWrite(rgbVermelho, LOW);
  	digitalWrite(rgbVerde, LOW);
  	digitalWrite(rgbAzul, LOW);
  	digitalWrite(ledVermelho, LOW);
  	digitalWrite(ledVerde, LOW);
  lcd.clear();
}

//***SISTEMA DE DETECCAO***
bool detectarPresenca(int valorPIR) {
  //Serial.println("Debug Detectar Presenca");
  if (valorPIR == 1) {
  	return true;
  }
  return false;
}

void exibirPresenca(bool presenca){
  //Serial.println("Debug Exibir Presenca");
  if (presenca) {
  	digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
  	digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
}
//***FIM SISTEMA DE PRESENCA***

//***SISTEMA RGB***
void definirCor(int botao) {
	desligar();
    String cor = "";
  switch (botao) {
  	case 16:
    	digitalWrite(rgbVermelho, HIGH);
    	
    	cor = "Vermelho";
    	break;
    case 17:
    	digitalWrite(rgbAzul, HIGH);
    	cor = "Azul";
    	break;
    case 18:
    	digitalWrite(rgbVerde, HIGH);
    	cor = "Verde";
    	break;
    case 20:
    	digitalWrite(rgbVermelho, HIGH);
    	digitalWrite(rgbAzul, HIGH);
    	cor = "Magenta";
    	break;
    case 21:
    	digitalWrite(rgbVermelho, HIGH);
    	digitalWrite(rgbVerde, HIGH);
    	cor = "Amarelo";
    	break;
    case 22:
    	digitalWrite(rgbAzul, HIGH);
    	digitalWrite(rgbVerde, HIGH);
    	cor = "Ciano";
    	break;
    case 25:
    	digitalWrite(rgbVermelho, HIGH);
    	digitalWrite(rgbAzul, HIGH);
    	digitalWrite(rgbVerde, HIGH);
    	cor = "Branco";
    	break;
    default:
        break;
  }
  lcd.clear();
  lcd.print(cor);
}
//***FIM SISTEMA RGB***


//***CONTROLE***
// Map the IR code to the corresponding remote button.
// The buttons are in this order on the remote:
//    0   1   2
//    4   5   6
//    8   9  10
//   12  13  14
//   16  17  18
//   20  21  22
//   24  25  26
//
// Return -1, if supplied code does not map to a key.

// Código retirado e adaptado de um exemplo do Tinkercad
// Components > Starters > Infrared Receiver

int mapCodeToButton(unsigned long code) {
  // For the remote used in the Tinkercad simulator,
  // the buttons are encoded such that the hex code
  // received is of the format: 0xiivvBF00
  // Where the vv is the button value, and ii is
  // the bit-inverse of vv.
  // For example, the power button is 0xFF00BF000

  // Check for codes from this specific remote
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    // No longer need the lower 16 bits. Shift the code by 16
    // to make the rest easier.
    code >>= 16;
    // Check that the value and inverse bytes are complementary.
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }
  return -1;
}

int readInfrared() {
  int result = -1;
  // Check if we've received a new code
  if (IrReceiver.decode()) {
    // Get the infrared code
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    // Map it to a specific button on the remote
    result = mapCodeToButton(code);
    // Enable receiving of the next value
    IrReceiver.resume();
  }
  return result;
}
bool verificarBotaoLigar(int botaoLigar) {
  if (botaoLigar == 0) {
  	return true;
  }
  return false;
}

// Fim codigo Tinkercad

//    0   1   2
//    4   5   6
//    8   9  10
//   12  13  14
//   16  17  18
//   20  21  22
//   24  25  26

// 16 VERMELHO
// 17 AZUL
// 18 VERDE
// 20 MAGENTA
// 21 AMARELO
// 22 CIANO
// 25 BRANCO

//***FIM CONTROLE***


void setup() {
  	Serial.begin(9600);
  	lcd.begin(16,2); //start lcd
  
  	IrReceiver.begin(pinIR);

    //conecta RGB
    pinMode(rgbVermelho, OUTPUT);
    pinMode(rgbAzul, OUTPUT);
    pinMode(rgbVerde, OUTPUT);

    //conecta LED
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);

    //conecta PIR
    pinMode(sensorPir, INPUT);    
}

void loop() {
  
  
   botaoCor = readInfrared();
   if (botaoCor != -1) {
     definirCor(botaoCor);
   }
  
   valorSensorPir = digitalRead(sensorPir);
  presenca = detectarPresenca(valorSensorPir);

  exibirPresenca(presenca);
  
 
    
  
}



