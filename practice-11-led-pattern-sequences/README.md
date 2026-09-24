# Practice 11 – LED Pattern Sequences

This practice uses **five LEDs** to create several lighting patterns using digital outputs, loops, functions and delays in Arduino.

The program runs a sequence of different LED effects and prints the name of each effect to the Serial Monitor.

## Tinkercad

> https://www.tinkercad.com/things/2qgXQNXKEKE-led-pattern-sequences

## How it works

Five LEDs are connected to digital pins **7, 6, 5, 4 and 3**.

The sketch defines reusable functions to turn LEDs on and off and then combines them into several patterns:

- **Estel** – blinks the LEDs sequentially from pin 7 to pin 3.
- **Simetria** – lights the LEDs symmetrically from the outside toward the center and back outward.
- **Zigzag** – runs the sequence in one direction and then returns in the opposite direction.
- **Dimm** – progressively turns LEDs off and then turns them back on.
- **All LEDs blink** – all five LEDs blink together five times at the end.

After completing all the patterns, the program stops inside an infinite loop.

The Serial Monitor is initialized at **9600 baud** and displays the name of the pattern currently being executed.

## Components

- 1 × Arduino board
- 5 × LEDs
- 5 × resistors
- Breadboard
- Jumper wires

## Pin configuration

| Component | Arduino pin |
|---|---:|
| LED 1 | 7 |
| LED 2 | 6 |
| LED 3 | 5 |
| LED 4 | 4 |
| LED 5 | 3 |

## Learning objectives

- Control multiple digital outputs with Arduino.
- Create reusable functions with parameters.
- Use `for` loops to control groups of pins.
- Build sequential and symmetric LED animations.
- Organize a program into smaller functions.
- Use `Serial.println()` to identify which sequence is running.
- Use `delay()` to control animation timing.

## How to run

1. Connect the five LEDs to Arduino pins **7 to 3**, using a resistor for each LED.
2. Open `led_pattern_sequences.ino` in the Arduino IDE.
3. Select the correct board and port.
4. Upload the sketch to the Arduino.
5. Open the Serial Monitor at **9600 baud** to see the name of each LED pattern while it runs.

## Files

```text
practice-11-led-pattern-sequences/
├── README.md
└── led_pattern_sequences.ino
```
