# stradapad

QMK keyboard dir for the 2x2 + 2-encoder + OLED macropad on a Seeed XIAO RP2040.
Drop the `stradapad/` folder into `qmk_firmware/keyboards/`, build with:

    qmk compile -kb stradapad -km via

## Pin map (D-label -> GP, as wired)

| Function           | D-label | GPIO |
|---------------------|---------|------|
| Switch 1            | D0      | GP26 |
| Switch 2            | D1      | GP27 |
| Switch 3            | D2      | GP28 |
| Switch 4            | D3      | GP29 |
| OLED SDA            | D4      | GP6  |
| OLED SCL            | D5      | GP7  |
| Encoder 1 A         | D6      | GP0  |
| Encoder 1 B         | D7      | GP1  |
| Encoder 1 switch    | D8      | GP2  |
| Encoder 2 A         | D9      | GP4  |
| Encoder 2 B         | D10     | GP3  |

All 11 GPIO used — no spare pins on this board for anything added later.

## What changed from the matrix plan

Switched the 4 main keys + the encoder 1 push switch to `DIRECT_PINS` (5 pins,
one per key, common ground) instead of a 2x2 row/col matrix. Same pin count,
no diodes, and the encoder's switch slots in as a 5th direct key instead of
needing a custom matrix.c to mix matrix + direct pin types.

## To-do on your end

- `config.h`: verify the I2C macro names (`I2CD0`/`I2C0_SDA_PIN`) against
  whatever QMK version you're building against — this is the one part of
  the RP2040 platform that's moved around across releases.
- `via.json`: import this in VIA's Design tab so VIA recognizes the board
  (it's not in VIA's official repo). VIA v3+ should auto-populate an
  Encoders panel from the firmware's `ENCODER_MAP` once flashed — you
  shouldn't need to hand-write encoder menus in this file, but worth
  confirming once you're on the device.
- `keymap.c`: the keycodes (`KC_MUTE`, `KC_VOLU`, etc.) are placeholders —
  remap everything live in VIA once it's flashed.
