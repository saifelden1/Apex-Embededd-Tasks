#include "math_utils.h"

// Implemented utility functions
int add_numbers(int a, int b) {
    return a + b;
}

int clamp_rpm(int requested_rpm) {
    if (requested_rpm > MAX_RPM) {
        return MAX_RPM;
    }
    if (requested_rpm < MIN_RPM) {
        return MIN_RPM;
    }
    return requested_rpm;
}
