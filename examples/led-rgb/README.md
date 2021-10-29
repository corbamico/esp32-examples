# Example: Led blink

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This example demonstrates usage of C++17 and GPIO Blink in ESP-IDF.

## How to use example

### Configure the project

To run this example, no additional configuration is necessary.

for Dev board, ESP-C3-32S-Kit could be easier one, which use led as IO3,4,5,18,19:
https://docs.ai-thinker.com/esp32c3

### Build and Flash

Build the project and flash it to the board, then run monitor tool to view serial output:

```
idf.py -p PORT flash monitor
```

(Replace PORT with the name of the serial port to use.)

(To exit the serial monitor, type ``Ctrl-]``.)

See the Getting Started Guide for full steps to configure and use ESP-IDF to build projects.

## Example Output

```
I (283) blink: init led gpio
I (283) gpio: GPIO[3]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0
I (293) gpio: GPIO[4]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (303) gpio: GPIO[5]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0
I (313) gpio: GPIO[18]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (323) gpio: GPIO[19]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0
I (323) blink: led tick: 0
I (2333) blink: led tick: 1
I (4333) blink: led tick: 2
I (6333) blink: led tick: 3
I (8333) blink: led tick: 4
I (10333) blink: led tick: 5
```
