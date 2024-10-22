# handwired/katze_launchbox

Presentation clicker given to a friend, with a key and switches to activate the big red button to go to the next slide.

-   Keyboard Maintainer: [Kat Fairbanks](https://github.com/katzenbar)
-   Hardware Supported: RP2040
-   Hardware Availability:
    -   [KB2040](https://www.adafruit.com/product/5302)
    -   [Toggle Switch](https://www.adafruit.com/product/3218)
    -   [Key Switch](https://www.adafruit.com/product/5929)
    -   [Big Button](https://www.adafruit.com/product/1190)
    -   [Small Buttons](https://www.adafruit.com/product/1479)

Make example for this keyboard (after setting up your build environment):

    make handwired/katze_launchbox:default

Flashing example for this keyboard:

    make handwired/katze_launchbox:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

-   **Bootmagic reset**: Hold down the BIG BUTTON and plug in the keyboard (key and toggle positions do not matter)
-   **Physical reset button**: You'll have to crack open the box to get to this, but it should be possible to get the plate out of the snap fit with some force.
-   **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
