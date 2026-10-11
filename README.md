# CosmicMessage

A C++17 system utility designed to compile and serialize a self-extracting, mathematically and physically rigorous message intended for Messaging Extraterrestrial Intelligence.\

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/)

## Architecture Overview
The assembled file (`cosmic_message.bin`) is structured into two main components:
1. **The Header**: Three 23x29 prime-dimension visual modules:
   * **Module 1**: Defines the universal time/distance scale using the 21cm Hydrogen spin-flip transition and provides our galactic coordinates relative to major pulsars.
   * **Module 2**: Establishes our organic base (H, C, N, O, P), displays the DNA double-helix, and defines humanoid bipedal morphology and scales.
   * **Module 3**: Provides a complete hardware schematic of a Subleq OISC (One-Instruction Set Computer) processor, enabling the recipient to emulate our computer.
2. **The Payload**: Raw executable machine code (Subleq integer array) representing a self-extracting archive of our data.

## Features
* **Resilient to Cosmic Radiation**: The geometric data-packing structure is highly tolerant to bit flips.
* **Integrated Subleq VM**: Includes a local emulator to test and simulate execution of the payload on Earth before transmission.

## How to Build and Run
```bash
g++ -std=c++17 -O3 main.cpp -o cosmic_message
./cosmic_message
```

The bridge is built. The math is universal.
