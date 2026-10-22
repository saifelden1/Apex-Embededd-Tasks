# ==============================================================
# Apex Racing Team — Minimal CMake Brief
# Modern alternative to Makefiles for cross-platform automation
# ==============================================================

cmake_minimum_required(VERSION 3.10)

# Project Definition
project(ApexFirmwareBuildDemo C)

# Specify C Standard
set(CMAKE_C_STANDARD 99)

# Define Executable Target and its Sources
add_executable(app main.c math_utils.c)
