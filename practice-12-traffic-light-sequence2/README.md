# Practice 12 – Pedestrian Traffic Lights 2

This practice uses **five LEDs**, a **push button** and a **16x2 LCD display** to simulate a pedestrian crossing using digital inputs, outputs, functions and delays in Arduino.

When the push button is pressed, the program runs a traffic light sequence to stop cars and allow pedestrians to cross. The LCD displays messages indicating the current stage.

## Tinkercad

[Open practice in Tinkercad.](https://www.tinkercad.com/things/80TK0wnU7cO-practica-2-semafor)

## How it works

Five LEDs represent the traffic lights: two for pedestrians and three for cars. They are connected to digital pins **2 to 6**. A push button connected to pin **7** requests a pedestrian crossing when its input reads `HIGH`.

A **16x2 LCD display** is assigned Arduino pins **13, 12, 11, 10, 9 and 8** using the `LiquidCrystal` library.

The sketch defines reusable functions to turn LEDs on and off and combines them into the following sequence:

- **Waiting for a request** – the car green LED is on and all other LEDs are off. The LCD is instructed to display `Peatons stop`. In this branch, the pedestrian red LED is also off.
- **Cars stop** – the LCD displays `Cars stop`. All LEDs turn off for one second, then the car yellow LED blinks three times, with one second on and one second off per blink.
- **Pedestrians cross** – the LCD displays `Peatons go`. All LEDs turn off for one second. The car red and pedestrian red LEDs then turn on together for one second. The pedestrian red LED turns off, and the pedestrian green LED blinks twice before remaining on for one more second. The car red LED stays on during this crossing stage.
- **Cars resume** – the pedestrian green LED turns off and the pedestrian red LED turns on. After one second, the car red LED turns off and the car green LED turns on for three seconds.

After the sequence, `loop()` reads the button again. If it is still held down, the entire crossing sequence runs again. Otherwise, the program returns to the waiting state.

The program uses blocking `delay()` calls, so it does not read the button during the crossing sequence. It does not use the Serial Monitor.

**LCD setup note:** the supplied sketch declares the LCD but does not call `lcd.begin(16, 2)`. Add this line inside `setup()` to initialize the display. The waiting message currently uses `lcd.println()`; use `lcd.print("Peatons stop")` for LCD text output.

## Components

- 1 × Arduino board
- 1 × 16x2 LCD display compatible with `LiquidCrystal`
- 2 × red LEDs
- 2 × green LEDs
- 1 × yellow LED
- 5 × LED current-limiting resistors
- 1 × push button
- 1 × pull-down resistor for the button, such as 10 kΩ
- 1 × potentiometer for LCD contrast, if required by the display
- Breadboard
- Jumper wires

## Pin configuration

### LEDs and push button

| Component | Arduino pin |
|---|---:|
| Pedestrian red LED | 2 |
| Pedestrian green LED | 3 |
| Car red LED | 4 |
| Car yellow LED | 5 |
| Car green LED | 6 |
| Push button | 7 |

The button is configured as `INPUT`, so use an external pull-down resistor to keep pin **7** at `LOW` when released. Pressing the button should connect the input to the board's logic supply so that it reads `HIGH`.

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

Connect the LCD power, ground and contrast connections as required by the display, and connect RW to ground.

## Learning objectives

- Control multiple digital outputs with Arduino.
- Read a push button using `digitalRead()`.
- Use a pull-down resistor with an `INPUT` pin.
- Control a 16x2 LCD using the `LiquidCrystal` library.
- Use `lcd.begin()`, `lcd.clear()`, `lcd.setCursor()` and `lcd.print()`.
- Create reusable functions with parameters.
- Use `if` and `else` to respond to user input.
- Build a timed traffic light sequence.
- Use `delay()` to control blinking and state durations.
- Understand how blocking delays affect button responsiveness.
- Combine LEDs and LCD messages to represent a pedestrian crossing.

## How to run

1. Connect the five LEDs to Arduino pins **2 to 6**, using a current-limiting resistor for each LED.
2. Connect the push button to pin **7** with an external pull-down resistor so that pressing it produces a `HIGH` input.
3. Connect the LCD according to the pin configuration above, including its power and contrast connections.
4. Open `pr_ctica_2_sem_for1.ino` in the Arduino IDE. If prompted, let the IDE create a matching sketch folder.
5. Add `lcd.begin(16, 2);` inside `setup()` and replace `lcd.println("Peatons stop");` with `lcd.print("Peatons stop");`.
6. Select the correct board and port, then upload the sketch.
7. Observe the car green LED while the button is released.
8. Press the button to start the yellow blinking stage and pedestrian crossing sequence.
9. Release the button to return to the waiting state after the sequence finishes. Holding it down triggers another sequence.

## Files

Suggested project structure:

```text
pr_ctica_2_sem_for1/
├── README.md
└── pr_ctica_2_sem_for1.ino
```
