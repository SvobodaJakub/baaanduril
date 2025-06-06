# baaAnduril: TS10 & TS25 & SP10Pro & D3AA & D2 Anti-dog and anti-car simple low-consumption hacks upon Anduril 2 Flashlight Firmware and FSM UI Toolkit

# 🐑

- TS10v1 & TS25: Fet PWM timing reduced to about 85% of the original, IDK if that gives 85% of the output, but it is noticeably less hot and TS10v1 turbo and strobe now runs on a protected 3A cell.
- For TS10v2, use the lowfet build, that also works with a protected 3A cell. (HD10 turbo current measurement with a multimeter showed roughly between 2A to 3A if I remember correctly.)
- New defaults:
    - Steps 1-7 have a bit lower intensity than the usual defaults.
        - Step 1 intensity 1/150 (Hank: 3/150) instead of usual 10/150.
        - Step 7 intensity 118/150 instead of usual 130/150.
    - Step 8 instead of turbo in simple mode, intensity 134/150.
    - The reason is that after a while, eyes adapt and the intensity is subjectively very similar, but the runtimes are now improved.
    - No turbo in simple mode (except for SP10Pro, set to the least-accessible turbo).
    - Very low thermal ceiling, set to 39°C (102°F), to prevent low-temperature burns and provide longer runtimes.
    - Tactical (6C) mode new defaults:
        - 1H: Strobe. A very contentious topic, but from my personal experience, it helped me to deter a dog to come too close.
        - 2H: Bike flasher. I use it to shine at the ground while crossing a particular sidewalk at night, which is at a bad spot and people get killed there regularly. The brightness variance is enough to draw attention, but not too disorienting to hurt drivers' perceptions nor reactions. **Do not shine at drivers, when in a city with many lights, it could make the user indistinguishable from a nonanimate object at an unrecognizable distance and could hide the user via the photonic barrier effect.**
        - 3H: Step 7 steady light for quick inspections.
    - Auto-lockout after 1 minute, brightness memory for 1 minute.
    - Default brightness around level 5 (goes to level 5 on the stepped ramp).
    - Stepped ramp.
    - Simple UI after reset.
    - No police strobe.
    - RGB-Aux shows voltage, high brightness when not locked, low brightness when locked (disabled in kids mode).
    - I like these defaults and having them set automatically on reset is convenient. If not your cup of tea (likely), the commit diff shows what to tweak probably quicker than discovering it independently.
- Ultra simple/kids mode (15+C in simple UI reconfigures simple mode to a single brightness at around step 4, no auto-lockout).
- Non-extended simple UI (no 3H, no 7C, no 7H) with nonconfigurable tactical mode (6C works, but 7H within doesn't).
- Tactical (6C) mode enabled in simple UI if simple UI is configured with 4 or more steps.
- SP10Pro: NiMH shortcut to reconfigure the ramp to a Li-Ion-equivalent brightness (resulting in rough equivalency for steps 1-5) for NiMH power, because SP10Pro is noticeably dimmer on NiMH than on Li-Ion (15+C in advanced UI)
- The hacks are not sophisticated, likely broken for other models than TS10 & TS25 & SP10Pro & D3AA ( & yet-untested D2, waiting for flashing adapter), and not maintainable nor upstreamable. Made while being sleep-deprived.

- Approximate battery life for TS10 with the default Wurkkos 14500 (about 700 mAh):
    - Step 6: approx 1 hour
    - Step 5: approx 3 hours
    - Step 4: approx 11 hours
    - Step 3: approx 36 hours
    - Step 2: approx a week
    - Step 1: at least 7 days

- Approximate battery life for SP10Pro with white Eneloop and with the NiMH ramp set:
    - Step 6: approx 1 hour
    - Step 5: approx 2 hours
    - Step 4: approx 7 hours
    - Step 3: approx 15 hours
    - Step 2: approx 3 days
    - Step 1: at least 17 days

- Approximate battery life for D2 with Vapcell H10 (I don't have the flashing kit, test based on setting the default Anduril, which should be identical):
    - Step 6: approx 2h:20m
    - Step 5: approx 4 hours
    - Step 4: approx 11 hours

- The brightness levels 1-5 are subjectively roughly comparable across all the listed flashlights, as long as D3AA runs on NiMH.

- No measurements with D3AA, didn't play much with it.

- Binary builds in the [`/hex`](https://github.com/SvobodaJakub/baaanduril/tree/trunk/hex) directory (not the proper place to put them in, but this is not meant for upstreaming nor being taken seriously, also sleep deprived).


The original README.md follows:

---

# Anduril Flashlight Firmware + FSM Flashlight UI Toolkit

Anduril is a user interface for flashlights.  It is written with FSM, a UI
toolkit for flashlights.

What is FSM?  The "SM" means "Spaghetti Monster", and the "F" can be any F word
you like, such as "Flashlight" or whatever suits your mood.  FSM also means
"Finite State Machine", which is the type of abstraction used for defining user
interfaces.  It is like a flowchart turned into executable code.


## Using Anduril

Anduril has many features, but the only things a person *really* needs to know
to use it are:

  - Click for on/off
  - Hold to change brightness

For more in-depth use, read its [user manual](docs/anduril-manual.md)
for full details.

If you want to know what changed recently, check the [ChangeLog](ChangeLog.md).

For info about hardware-specific features, like what the channel modes are on
multi-channel lights, browse into the [hw/](hw/) directories to find the
hardware model and any hardware-specific documentation.


## Flashing Firmware

Get the latest updates by flashing new firmware!

A few things are needed to flash firmware:

  - A firmware ".hex" file.  Here's
    [how to find the right .hex file](docs/which-hex-file.md).

  - A flashing adapter.  The type of adapter depends on which MCU chip your
    light uses.  It may be an UPDI 3-pin adapter (attiny1616 and newer) or an
    AVR ISP 6-pin adapter (attiny85, attiny1634).

    **UPDI** typically uses a "pogo pin" adapter, with spring-loaded pins to
    hold against copper pads on the driver circuit.

    **AVR ISP** typically has two parts -- a USB device (like a USBASP), and a
    physical adapter (like a pogo pin adapter or SOIC8 clip).  SOIC8 is the
    least convenient, and is mostly only used on old models with attiny85
    chips.

  - A firmware flashing program.  A few compatible programs include
    `avrdude`, `pymcuprog`, and `ZFlasher`.

  - A computer or phone.  Almost any modern computer or phone should be able to
    do it, as long as you can plug the adapter in and run a flashing program.

One particularly useful guide is at https://anduril.click/ .

More info about installing flashing programs is below, in
[Flashing Programs](#flashing-programs).


## Compiling

The firmware can be deeply customized by modifying it and compiling your own
versions, and this is encouraged.

To compile the firmware, it is strongly recommended that you use a Linux
computer, ideally running Debian or Ubuntu (but almost any distro should work).
Virtual machines work well, such as running WSL inside Windows.  There is also
a Docker container available (TODO: add link(s) here), if that is more
convenient.

### Prerequisites:

- AVR toolchain packages:  
  `sudo apt install gcc-avr avr-libc binutils-avr`

- Other misc packages:  
  `sudo apt install git wget unzip bash`

- Atmel DFPs (Device Family Packs).  A small script is included to
  download and install these for you:  
  `./make dfp`

### Building

Use the `make` script included in this repo.  Run `./make --help` for details
about how to use it.  In most cases though, you should be able to just run
`./make` by itself to compile all available build targets.  Or give it a search
term to limit builds to only a few, like `./make hank boost` to build all
firmwares for Hanklights with optional boost drivers.

The compiled firmware goes into the `hex/` directory, ready to be used by any
firmware flashing program.


## Customizing Settings Per User

The build can be [customized per user](docs/per-user-config.md) by placing
overrides into the `users/myname/` directory and letting the build script know
your username.  That way, your favorite settings can be applied automatically
without having to modify the original source files.


## Flashing Programs

### AVRdude

Usually avrdude installs in a single command:

`sudo apt install avrdude`

### PyMCUprog

If you use `pymcuprog` to flash firmware, a few extras are needed:

```sh
sudo apt install python3 python3-pip python3-venv
python3 -m venv .venv
source .venv/bin/activate
pip install pymcuprog
```

You'll need to `source .venv/bin/activate` every time you start a fresh shell,
if you want to use pymcuprog.  The activation lasts until the shell is
closed or until you run `deactivate`.


## Contributing

If you'd like to help, there are several ways...

  - ToyKeeper has a [Patreon site](https://patreon.com/ToyKeeper) for
    donations, to help figuratively and literally keep the lights on.

  - Send pull requests or patches, to improve things directly.  These can be
    code, documentation, tools, or anything you think is useful.

  - File bug reports for any problems you find.

  - Answer people's questions on public forums.  If the same questions come up
    a lot, consider adding it to the documentation here.

  - Ask manufacturers to use this firmware, and to support its development.

