# Practice 11 – LED Pattern Sequences

This practice uses **five LEDs** and a **16x2 LCD display** to create and identify several lighting patterns using digital outputs, loops, functions and delays in Arduino.

The program runs a sequence of different LED effects. The name of each effect is displayed both on the **Serial Monitor** and on the **LCD screen** while the corresponding LED pattern is running.

## Tinkercad

[Open this project in Tinkercad](https://www.tinkercad.com/things/2qgXQNXKEKE-led-pattern-sequences)

## How it works

Five LEDs are connected to digital pins **7, 6, 5, 4 and 3**.

A **16x2 LCD display** is controlled using the `LiquidCrystal` library and Arduino pins **13, 12, 11, 10, 9 and 8**.

The sketch defines reusable functions to turn LEDs on and off and then combines them into several patterns:

- **Estel** – blinks the LEDs sequentially from pin 7 to pin 3. The LCD displays `Estel`.
- **Simetria** – lights the LEDs symmetrically from the outside toward the center and back outward. The LCD displays `Simetria`.
- **Zigzag** – runs the sequence in one direction and then returns in the opposite direction. The LCD displays `Zigzag`.
- **Dimm** – progressively turns LEDs off and then turns them back on. The LCD displays `Dimm`.
- **All LEDs blink** – after the previous patterns, the LCD is cleared and all five LEDs blink together five times.

Before displaying the name of each pattern, the LCD is cleared using `lcd.clear()` and the text is written starting at position **0,0**.

The Serial Monitor is initialized at **9600 baud** and also displays the name of each LED pattern.

After completing all the effects, the `loop()` function starts again and the complete sequence repeats continuously.

## Components

- 1 × Arduino board
- 1 × 16x2 LCD display
- 5 × LEDs
- 5 × resistors
- Breadboard
- Jumper wires

## Pin configuration

### LEDs

| Component | Arduino pin |
|---|---:|
| LED 1 | 7 |
| LED 2 | 6 |
| LED 3 | 5 |
| LED 4 | 4 |
| LED 5 | 3 |

### LCD

The LCD is configured in the sketch as:

```cpp
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
```

| LCD connection | Arduino pin |
|---|---:|
| RS | 13 |
| Enable | 12 |
| D4 | 11 |
| D5 | 10 |
| D6 | 9 |
| D7 | 8 |

## Learning objectives

- Control multiple digital outputs with Arduino.
- Control a 16x2 LCD using the `LiquidCrystal` library.
- Display information on an LCD while the program is running.
- Use `lcd.clear()`, `lcd.setCursor()` and `lcd.print()`.
- Create reusable functions with parameters.
- Use `for` loops to control groups of pins.
- Build sequential and symmetric LED animations.
- Organize a program into smaller functions.
- Use `Serial.println()` to identify which sequence is running.
- Use `delay()` to control animation timing.
- Combine visual information from LEDs and an LCD display.

## How to run

1. Connect the five LEDs to Arduino pins **7 to 3**, using a resistor for each LED.
2. Connect the LCD to Arduino pins **13, 12, 11, 10, 9 and 8** according to the pin configuration above.
3. Open `led_pattern_sequences.ino` in the Arduino IDE.
4. Select the correct board and port.
5. Upload the sketch to the Arduino.
6. Open the Serial Monitor at **9600 baud**.
7. Observe the LED patterns while the LCD and Serial Monitor display the name of the current sequence.
8. After the final five simultaneous LED blinks, the complete sequence starts again.

## Files

```text
practice-11-led-pattern-sequences/
├── README.md
└── led_pattern_sequences.ino
```
