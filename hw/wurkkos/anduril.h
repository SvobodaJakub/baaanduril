// Wurkkos config options for Anduril
// Copyright (C) 2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// allow Aux Config and Strobe Modes in Simple UI
#undef USE_EXTENDED_SIMPLE_UI

// Allow 3C in Simple UI for switching between smooth and stepped ramping
#define USE_SIMPLE_UI_RAMPING_TOGGLE


#define DEFAULT_2C_STYLE 2 // not easily accessible turbo

#define DEFAULT_2C_STYLE_SIMPLE 0  // no turbo at all in simple

// DISABLE enable SOS in the blinkies group
#undef USE_SOS_MODE
#undef USE_SOS_MODE_IN_BLINKY_GROUP

// enable factory reset on 13H without loosening tailcap
// only really needed on TS10, but doesn't hurt on other models
#define USE_SOFT_FACTORY_RESET

// higher temperature limit because attiny1616 is more accurate -> lower to prevent low-temp tissue burns
#undef DEFAULT_THERM_CEIL
#define DEFAULT_THERM_CEIL 39

#undef RAMP_STYLE
#define RAMP_STYLE 1  // 0 = smooth, 1 = stepped

#define DEFAULT_MANUAL_MEMORY_TIMER 1

#undef USE_EXTENDED_SIMPLE_UI

#undef USE_POLICE_COLOR_STROBE_MODE

#undef  TACTICAL_LEVELS
#define TACTICAL_LEVELS 152,155,118 // tac strobe, bike strobe (it would be 156 with police strobe compiled in), steady 7/8 (1-134)

#define DEFAULT_AUTOLOCK_TIME 1

#define DEFAULT_BIKING_LEVEL 110
#define MAX_BIKING_LEVEL 110

#define DEFAULT_DONT_RAMP_AFTER_MOON 1

#define DEFAULT_MANUAL_MEMORY 68

// off mode: high (2)
// lockout: low (1)
#define INDICATOR_LED_DEFAULT_MODE ((1<<2) + 2)
