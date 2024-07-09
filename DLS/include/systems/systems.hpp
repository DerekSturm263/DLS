#pragma once

#include "audio.hpp"
#include "debug.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "random.hpp"
#include "scene.hpp"
#include "simulation.hpp"
#include "time.hpp"
#include "window.hpp"

REGISTER_SYSTEM(dls::debug::systems::debug);
REGISTER_SYSTEM(dls::graphics::systems::graphics);
REGISTER_SYSTEM(dls::input::systems::input);
REGISTER_SYSTEM(dls::math::systems::random);
REGISTER_SYSTEM(dls::core::systems::scene);
REGISTER_SYSTEM(dls::graphics::systems::window);
