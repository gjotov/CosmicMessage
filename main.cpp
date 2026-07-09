/**
 * @file cosmic_message.cpp
 * @brief Universal Self-Bootstrapping Interstellar Message Generator
 * @version 2.0 (C++17)
 *
 * This software compiles a multi-modular scientific message intended for
 * Messaging Extraterrestrial Intelligence (METI). It generates:
 *   - Module 1: Physics (Quantum Hydrogen spin-flip & Pulsar Coordinates)
 *   - Module 2: Biochemistry (Atomic elements, DNA double-helix, Human anatomy)
 *   - Module 3: Computer Architecture (OISC Subleq CPU Logic & Pointers)
 *
 * It compiles these into a 1D bitstream, packs them into bytes, appends the
 * Subleq binary executable payload, and serializes everything into 'cosmic_message.bin'.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
#include <string>
#include <algorithm>

 // Universal constants for the message grid dimensions 
 // Primes: 23 x 29 = 667 bits per page
constexpr int WIDTH = 23;
constexpr int HEIGHT = 29;

using Grid = std::vector<std::vector<bool>>;

// PART 1: INTERSTELLAR EXCEPTION HANDLING (Universal Exit Codes)

enum CosmicExitCode {
    SUCCESS = -1,
    ARITHMETIC_ERROR = -2,
    MEMORY_OUT_OF_BOUNDS = -3,
    LOGICAL_ERROR = -4
};

std::string decode_cosmic_alert(int code) {
    switch (code) {
    case SUCCESS:
        return "SUCCESS: Execution terminated normally.";
    case ARITHMETIC_ERROR:
        return "ALERT [Code -2]: Arithmetic exception (overflow / division by zero).";
    case MEMORY_OUT_OF_BOUNDS:
        return "ALERT [Code -3]: Segmentation fault (memory access out of bounds).";
    case LOGICAL_ERROR:
        return "ALERT [Code -4]: Critical logic corruption detected.";
    default:
        return "ALERT [Unknown]: Undefined processor halt code: " + std::to_string(code);
    }
}

// PART 2: GRAPHICAL MODULE GENERATORS (Layer 0 & Layer 1 Specifications)

// Module 1: Quantum Hydrogen Transition & Pulsar Triangulation Map
Grid create_scientific_hydrogen() {
    Grid grid(HEIGHT, std::vector<bool>(WIDTH, false));

    // Sync borders (top and bottom)
    for (int x = 0; x < WIDTH; ++x) {
        grid[0][x] = true;
        grid[HEIGHT - 1][x] = true;
    }

    // Left Hydrogen Atom (Parallel spins: Proton UP, Electron UP)
    grid[5][4] = true; grid[5][3] = true; grid[5][5] = true; grid[4][4] = true; grid[6][4] = true; // Proton
    grid[2][4] = true; grid[3][3] = true; grid[3][5] = true; // Proton Spin UP

    // Electron Orbit
    std::vector<std::pair<int, int>> orbit_l = { {2,4}, {5,1}, {8,4}, {5,7} };
    for (auto [y, x] : orbit_l) grid[y][x] = true;
    grid[5][7] = true; grid[4][7] = true; grid[3][7] = true; grid[3][6] = true; // Electron with Spin UP

    // Emitted Photon (Sine wave indicating transition)
    grid[5][9] = true; grid[4][10] = true; grid[5][11] = true; grid[6][12] = true; grid[5][13] = true;

    // Right Hydrogen Atom (Anti-parallel spins: Proton UP, Electron DOWN)
    grid[5][18] = true; grid[5][17] = true; grid[5][19] = true; grid[4][18] = true; grid[6][18] = true; // Proton
    grid[2][18] = true; grid[3][17] = true; grid[3][19] = true; // Proton Spin UP

    // Electron Orbit
    std::vector<std::pair<int, int>> orbit_r = { {2,18}, {5,15}, {8,18}, {5,21} };
    for (auto [y, x] : orbit_r) grid[y][x] = true;
    grid[5][21] = true; grid[6][21] = true; grid[7][21] = true; grid[7][22] = true; // Electron with Spin DOWN

    // Pulsar Coordinate Map (Center is our Sun)
    int cx = 11, cy = 17;
    grid[cy][cx] = true;

    // Pulsar 1 (Vector Up-Left)
    grid[16][10] = true; grid[15][9] = true; grid[14][8] = true; grid[13][7] = true;
    grid[13][5] = true;  grid[13][4] = true; // Binary Period representation

    // Pulsar 2 (Vector Up-Right)
    grid[16][12] = true; grid[15][13] = true; grid[14][14] = true; grid[13][15] = true; grid[12][16] = true;
    grid[12][18] = true; grid[12][19] = true; // Binary Period representation

    // Pulsar 3 (Vector Down)
    grid[18][11] = true; grid[19][11] = true; grid[20][11] = true; grid[21][11] = true;
    grid[21][9] = true;  grid[21][8] = true; // Binary Period representation

    // Solar System layout (Sun + Planets, Earth shifted up)
    grid[25][2] = true; grid[26][2] = true; grid[25][3] = true; grid[26][3] = true; // Sun
    grid[25][5] = true; // Mercury
    grid[25][7] = true; // Venus
    grid[24][9] = true; grid[25][9] = true; // Earth (shifted up with pointer)
    grid[25][11] = true; // Mars
    grid[25][13] = true; grid[25][14] = true; // Jupiter

    return grid;
}

// Module 2: Organic Chemistry, DNA Structure & Anatomy
Grid create_scientific_biology() {
    Grid grid(HEIGHT, std::vector<bool>(WIDTH, false));

    for (int x = 0; x < WIDTH; ++x) {
        grid[0][x] = true;
        grid[HEIGHT - 1][x] = true;
    }

    // Chemical elements of life (Atomic numbers: H=1, C=6, N=7, O=8, P=15)
    std::vector<int> elements = { 1, 6, 7, 8, 15 };
    std::vector<int> cols = { 3, 7, 11, 15, 19 };
    for (size_t i = 0; i < elements.size(); ++i) {
        int col = cols[i];
        grid[2][col] = true; // Header marker
        int elem = elements[i];
        // Encode atomic number vertically as 4-bit binary
        for (int bit_idx = 0; bit_idx < 4; ++bit_idx) {
            grid[3 + bit_idx][col] = (elem >> (3 - bit_idx)) & 1;
        }
    }

    // DNA Double Helix geometry (Major/minor grooves & chemical bonds)
    struct DnaRow { int row; int x1; int x2; int bond; };
    std::vector<DnaRow> dna = {
        {9,  6, 16, 2}, {10, 5, 17, 0}, {11, 5, 17, 0}, {12, 6, 16, 1},
        {13, 8, 14, 2}, {14, 10, 12, 2}, {15, 11, 11, 0}, {16, 12, 10, 2},
        {17, 14, 8,  2}, {18, 16, 6,  1}, {19, 17, 5,  0}, {20, 17, 5,  0},
        {21, 16, 6,  2}
    };
    for (auto d : dna) {
        grid[d.row][d.x1] = true;
        grid[d.row][d.x2] = true;
        int start = std::min(d.x1, d.x2) + 1;
        int end = std::max(d.x1, d.x2);
        if (d.bond == 2) { // Strong triple hydrogen bonds (G-C representation)
            for (int x = start; x < end; ++x) grid[d.row][x] = true;
        }
        else if (d.bond == 1) { // Weaker double bonds (A-T representation, dotted line)
            for (int x = start; x < end; ++x) {
                if (x % 2 == 0) grid[d.row][x] = true;
            }
        }
    }

    // Humanoid schematic (Bilateral symmetry, head, spine, limbs)
    grid[23][11] = true; // Head
    grid[24][10] = true; grid[24][11] = true; grid[24][12] = true; // Shoulders
    grid[25][11] = true; // Torso
    grid[26][10] = true; grid[26][12] = true; // Legs

    // Physical Height Scale (Value 8 on Hydrogen scale: 8 * 21cm = 168cm)
    grid[23][7] = true; grid[24][7] = true; grid[25][7] = true; grid[26][7] = true; // Ruler
    grid[23][5] = true; grid[24][5] = false; grid[25][5] = false; grid[26][5] = false; // Binary 8

    // Population Scale (Order of magnitude 9 -> ~10^9 inhabitants)
    grid[24][15] = true; grid[24][16] = false; grid[24][17] = false; grid[24][18] = true;

    return grid;
}

// Module 3: Geometric CPU Blueprint (Subleq Processor Logic)
Grid create_super_detailed_cpu() {
    Grid grid(HEIGHT, std::vector<bool>(WIDTH, false));

    for (int x = 0; x < WIDTH; ++x) {
        grid[0][x] = true;
        grid[HEIGHT - 1][x] = true;
    }

    // Memory Address Tape (Turing-style cells)
    for (int x = 1; x < 22; ++x) {
        grid[2][x] = true;
        grid[4][x] = true;
    }
    for (int x : {1, 5, 9, 13, 17, 21}) {
        grid[2][x] = true; grid[3][x] = true; grid[4][x] = true;
    }

    // Address Pointers (Arrows mapping memory addresses)
    grid[5][3] = true; grid[5][11] = true; grid[5][19] = true;
    for (int y : {6, 7, 8}) {
        grid[y][3] = true; grid[y][11] = true; grid[y][19] = true;
    }

    // Memory Variables defined geometrically (Triangle, Square, Diamond)
    // Triangle (3 vertices / Variable A)
    grid[9][3] = true; grid[10][2] = true; grid[10][4] = true; grid[11][1] = true; grid[11][2] = true; grid[11][3] = true; grid[11][4] = true; grid[11][5] = true;
    // Square (4 vertices / Variable B)
    grid[9][10] = true; grid[9][11] = true; grid[9][12] = true; grid[10][10] = true; grid[10][12] = true; grid[11][10] = true; grid[11][11] = true; grid[11][12] = true;
    // Diamond (5 vertices / Variable C)
    grid[9][19] = true; grid[10][18] = true; grid[10][20] = true; grid[11][19] = true;

    // ALU Subtraction Module "(-)" and Data Feedback Loop
    grid[14][11] = true; grid[13][11] = true; grid[15][11] = true; grid[14][10] = true; grid[14][12] = true; // ALU subtraction gate
    for (int x = 3; x <= 9; ++x) grid[14][x] = true; // Data pipeline from A
    grid[13][3] = true; grid[14][3] = true;
    grid[12][11] = true; grid[13][10] = true; // Feedback loop back to B

    // Branching Logic (Coordinate Axis representation)
    for (int x = 3; x <= 19; ++x) grid[18][x] = true; // Coordinate line
    grid[17][11] = true; grid[19][11] = true; grid[16][11] = true; // Zero point marker "0"

    // YES Branch (Result <= 0) -> Jump Execution Pointer (IP) to C (Diamond)
    grid[18][3] = true; grid[17][4] = true; grid[19][4] = true; // Arrow pointing negative
    grid[19][3] = true; grid[20][3] = true; grid[21][3] = true; // Branch line
    grid[23][3] = true; grid[24][3] = true; // Assignment '='
    grid[25][3] = true; grid[26][2] = true; grid[26][4] = true; grid[27][3] = true; // Diamond (C)

    // NO Branch (Result > 0) -> Step Execution Pointer: IP = IP + Triangle (3)
    grid[18][19] = true; grid[17][18] = true; grid[19][18] = true; // Arrow pointing positive
    grid[19][19] = true; grid[20][19] = true; grid[21][19] = true; // Branch line
    grid[23][19] = true; grid[24][19] = true; // Assignment '='
    grid[25][19] = true; grid[26][19] = true; grid[26][18] = true; grid[26][20] = true; // '+' Sign
    grid[27][19] = true; // Triangle (Step value 3)

    return grid;
}

// PART 3: RECIPIENT EMULATION TEST (Local Subleq execution)

void simulate_recipient_vm(std::vector<int>& memory) {
    std::cout << "\n[EMULATOR] Initiating execution of compiled Subleq payload...\n";
    int ip = 0;
    int step = 0;

    while (ip >= 0 && ip < static_cast<int>(memory.size())) {
        int a = memory[ip];
        int b = memory[ip + 1];
        int c = memory[ip + 2];

        // Check for universal Exit/Alert codes
        if (a < 0) {
            std::cout << "[EMULATOR] Execution Halted: " << decode_cosmic_alert(a) << "\n";
            break;
        }

        // Out of bounds safety check
        if (a >= static_cast<int>(memory.size()) || b >= static_cast<int>(memory.size())) {
            std::cout << "[EMULATOR] Memory Failure: " << decode_cosmic_alert(MEMORY_OUT_OF_BOUNDS) << "\n";
            break;
        }

        int val_a = memory[a];
        int val_b = memory[b];
        int result = val_b - val_a;
        memory[b] = result;

        std::cout << "  Step " << step << ": mem[" << b << "] = " << val_b << " - " << val_a << " = " << result << "\n";

        if (result <= 0) {
            ip = c;
        }
        else {
            ip += 3;
        }
        step++;
    }
    std::cout << "[EMULATOR] Target variable 'b' result: " << memory[10] << "\n";
}


// PART 4: VISUALIZER AND ASSEMBLER

void render_terminal_module(const Grid& grid, const std::string& name) {
    std::cout << "\n--- " << name << " ---\n";
    for (const auto& row : grid) {
        std::cout << "|";
        for (bool pixel : row) {
            std::cout << (pixel ? "##" : "  ");
        }
        std::cout << "|\n";
    }
    std::cout << std::string(WIDTH * 2 + 2, '=') << "\n";
}

int main() {

    std::cout << "[COMPILER] Initiating Interstellar Assembler...\n";

    // 1. Generate structural modules (Pages 1, 2, 3)
    Grid mod1 = create_scientific_hydrogen();
    Grid mod2 = create_scientific_biology();
    Grid mod3 = create_super_detailed_cpu();

    // Render modules in terminal
    render_terminal_module(mod1, "PAGE 1: HYDROGEN STANDARD & ASTROMETRY");
    render_terminal_module(mod2, "PAGE 2: BIOCHEMISTRY & GENETICS");
    render_terminal_module(mod3, "PAGE 3: HARDWARE BLUEPRINT");

    // 2. Flatten 2D grids into a 1D bitstream (2001 bits total)
    std::vector<bool> bitstream;
    bitstream.reserve(3 * WIDTH * HEIGHT);

    for (const auto& mod : { mod1, mod2, mod3 }) {
        for (const auto& row : mod) {
            for (bool bit : row) {
                bitstream.push_back(bit);
            }
        }
    }

    // 3. Pack bits into bytes (8 bits per byte)
    std::vector<uint8_t> output_bytes;
    uint8_t current_byte = 0;
    int bit_count = 0;

    for (bool bit : bitstream) {
        current_byte = (current_byte << 1) | bit;
        bit_count++;
        if (bit_count == 8) {
            output_bytes.push_back(current_byte);
            current_byte = 0;
            bit_count = 0;
        }
    }
    if (bit_count > 0) {
        current_byte = current_byte << (8 - bit_count);
        output_bytes.push_back(current_byte);
    }

    // Append payload separator (0xFF)
    output_bytes.push_back(0xFF);

    // 4. Set up the Subleq Binary Program Payload 
    // (Doing addition: 5 + 7 = 12)
    std::vector<int> subleq_payload = {
        9, 11, 3,    // IP 0: subleq(9, 11, 3) -> mem[11] = mem[11] - mem[9]  (0 - 5 = -5)
        11, 10, 6,   // IP 3: subleq(11, 10, 6) -> mem[10] = mem[10] - mem[11] (7 - (-5) = 12)
        -1, -1, -1,  // IP 6: subleq(-1, -1, -1) -> HALT / SUCCESS (Normal Exit)
        5,           // Addr 9: Variable 'a'
        7,           // Addr 10: Variable 'b'
        0            // Addr 11: Variable 'Z' (temp buffer)
    };

    // Serialize payload ints to binary bytes
    for (int num : subleq_payload) {
        output_bytes.push_back(static_cast<uint8_t>(num));
    }

    // 5. Write the final assembled image to disk
    std::ofstream out("cosmic_message.bin", std::ios::binary);
    if (out.is_open()) {
        out.write(reinterpret_cast<const char*>(output_bytes.data()), output_bytes.size());
        out.close();
        std::cout << "\n[COMPILER] Output binary file 'cosmic_message.bin' generated successfully.\n";
        std::cout << "[COMPILER] Total serialized message size: " << output_bytes.size() << " bytes.\n";
    }
    else {
        std::cerr << "\n[COMPILER] ERROR: Failed to open output file for writing!\n";
        return 1;
    }

    // 6. Test compilation logic on a local emulator simulation
    simulate_recipient_vm(subleq_payload);

    return 0;
}