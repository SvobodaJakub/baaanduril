// Intl-Outdoor (Hank)'s config options for Anduril
// Copyright (C) 2021-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// config preferences for Hank Wang of Intl-Outdoor (Emisar, Noctigon)


#ifdef RGB_LED_OFF_DEFAULT
#undef RGB_LED_OFF_DEFAULT
#endif
#ifdef RGB_LED_LOCKOUT_DEFAULT
#undef RGB_LED_LOCKOUT_DEFAULT
#endif

#define RGB_LED_OFF_DEFAULT 0x29  // high, voltage
#define RGB_LED_LOCKOUT_DEFAULT 0x19  // low, voltage

// half a second per color in rainbow mode
//#define RGB_RAINBOW_SPEED 0x03

// Allow 3C (or 6C) in Simple UI (toggle smooth or stepped ramping)
#define USE_SIMPLE_UI_RAMPING_TOGGLE

// allow Aux Config and Strobe Modes in Simple UI
#undef USE_EXTENDED_SIMPLE_UI

#define DEFAULT_2C_STYLE 2 // not easily accessible turbo

#define DEFAULT_2C_STYLE_SIMPLE 0  // no turbo at all in simple

// for consistency with KR4 (not otherwise necessary though)
#define USE_SOFT_FACTORY_RESET

// lower to prevent low-temp tissue burns
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

#define DEFAULT_MANUAL_MEMORY 70
