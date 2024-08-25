# Projeto: Protótipo de Lâmpada RGB

Este projeto foi desenvolvido utilizando o Tinkercad para simular um protótipo de lâmpada RGB controlada por um Arduino Uno. A lâmpada pode alterar suas cores com base em diferentes entradas, como sensores e potenciômetros.

## Componentes Utilizados

Abaixo estão listados os componentes utilizados no projeto:

| Nome               | Quantidade | Componente             |
|--------------------|------------|------------------------|
| U1                 | 1          | Arduino Uno R3         |
| D1                 | 1          | LED Vermelho           |
| D2                 | 1          | LED Verde              |
| D3                 | 1          | LED RGB                |
| U2                 | 1          | Display LCD 16x2       |
| PIR1               | 1          | Sensor PIR             |
| U3                 | 1          | Sensor IR              |
| R1, R5, R6, R2, R3, R4 | 6      | Resistor de 1 kΩ       |
| Rpot1              | 1          | Potenciômetro de 250 kΩ|

## Montagem

1. **Arduino Uno R3 (U1):** O microcontrolador principal que gerencia o controle dos LEDs RGB e outros componentes.
2. **LEDs (D1, D2, D3):** LEDs Vermelho, Verde e RGB, que são usados para criar a lâmpada RGB com diferentes cores.
3. **Display LCD 16x2 (U2):** Utilizado para mostrar o estado atual da lâmpada, como a cor atual e se o sensor foi acionado.
4. **Sensor PIR (PIR1):** Sensor de movimento que aciona a mudança de cor da lâmpada.
5. **Sensor IR (U3):** Sensor infravermelho utilizado para detectar objetos ou entradas de controle remoto.
6. **Resistores (R1, R5, R6, R2, R3, R4):** Usados para limitar a corrente nos LEDs e outros componentes.
7. **Potenciômetro (Rpot1):** Ajusta o brilho dos LEDs RGB.
8. **Breadboard:** Facilita a montagem do circuito sem necessidade de solda.
9. **Jumpers:** Fios de conexão entre os componentes e o Arduino.

## Funcionamento

O protótipo de lâmpada RGB funciona da seguinte forma:

- **Controle de Cores:** O Arduino Uno controla os LEDs RGB e Vermelho/Verde para criar diferentes cores.
- **Sensores:** O Sensor PIR detecta movimento, enquanto o Sensor IR pode ser utilizado para detecção de objetos ou controle remoto.
- **Potenciômetro:** Ajusta o brilho dos LEDs.
- **Display LCD:** Exibe informações como a cor atual dos LEDs e o estado dos sensores.

## Simulação

O projeto pode ser simulado no Tinkercad. Basta montar o circuito conforme descrito acima, carregar o código para o Arduino e iniciar a simulação.

## Código

O código para o Arduino pode ser escrito para controlar os LEDs RGB e interagir com os sensores e o display LCD. Um exemplo básico de código seria:

```cpp
// Exemplo de código para o controle dos LEDs RGB
void setup() {
  // Configuração inicial do Arduino
}

void loop() {
  // Lógica para controlar os LEDs e ler os sensores
}
