#include <stdio.h>
#include "math_utils.h"

// Preprocessor Macros
#define TEAM_NAME "Apex Racing Team"
#define VEHICLE_CODE "EV-27"

// Global Variables
int target_speed_kmh = 75; // Initialized global
int throttle_input_raw;    // Uninitialized global

int main(void) {
    printf("=======================================\n");
    printf("  %s - %s Firmware Demo\n", TEAM_NAME, VEHICLE_CODE);
    printf("=======================================\n");

    int raw_motor_rpm = 13500;
    int safe_rpm = clamp_rpm(raw_motor_rpm);
    int sum = add_numbers(target_speed_kmh, 25);

    printf("Target Speed: %d km/h | Calculated: %d\n", target_speed_kmh, sum);
    printf("Raw Motor RPM: %d -> Clamped Safe RPM: %d (Max: %d)\n", raw_motor_rpm, safe_rpm, MAX_RPM);
    printf("Build & execution successful!\n");

    return 0;
}
