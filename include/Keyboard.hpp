#pragma once
#include "Key.hpp"
#include "KeyState.hpp"
#include "KeyMods.hpp"

std::string ParseKeyEvent(Key key, KeyState, int scancode, KeyMods mods);