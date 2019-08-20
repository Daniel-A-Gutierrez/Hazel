#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <sstream>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


//logging
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"


#ifdef HZ_PLATFORM_WINDOWS
#include <Windows.h>
#endif

