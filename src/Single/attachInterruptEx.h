#pragma once
#include <functional>

extern void attachInterruptEx(unsigned pin, std::function<void(void)>, int mode);

// to detach the intterrupt, the standard detachInterrupt can be used