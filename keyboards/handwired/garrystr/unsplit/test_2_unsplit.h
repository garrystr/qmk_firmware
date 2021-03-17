#pragma once

#include "quantum.h"

#define LAYOUT( \
	K00, K90, K01, K91, K02, K92, K03,      K04, K94, K05, K95, K06, K96, \
	K10, K80, K11, K81, K12, K82, K13, K83, K14, K84, K15, K85,      K86, \
	K20, K70, K21, K71, K22, K72, K23, K73, K24, K74, K25, K75, K26,      \
	     K60, K31, K61, K32, K62, K33, K63, K34, K64, K35, K65, K36, K66, \
	K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55, K46       \
) \
{ \
{ K00,   K90,   K01,   K91,   K02,   K92,   K03,   KC_NO, K04,   K94,   K05,   K95,   K06,   K96   }, \
{ K10,   K80,   K11,   K81,   K12,   K82,   K13,   K83,   K14,   K84,   K15,   K85,   KC_NO, K86   }, \
{ K20,   K70,   K21,   K71,   K22,   K72,   K23,   K73,   K24,   K74,   K25,   K75,   K26,   KC_NO }, \
{ KC_NO, K60,   K31,   K61,   K32,   K62,   K33,   K63,   K34,   K64,   K35,   K65,   K36,   K66   }, \
{ K40,   K50,   K41,   K51,   K42,   K52,   K43,   K53,   K44,   K54,   K45,   K55,   K46,   KC_NO } \
}
