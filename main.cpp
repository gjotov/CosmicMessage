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

// Module 1: Quantum Hydrogen & Pure Math Astrometry Vector Table
Grid create_scientific_hydrogen() {
    Grid grid(HEIGHT, std::vector<bool>(WIDTH, false));

    // 1. Sync borders (top and bottom)
    for (int x = 0; x < WIDTH; ++x) {
        grid[0][x] = true;
        grid[HEIGHT - 1][x] = true;
    }

    // 2. Quantum Hydrogen Transition (Universally valid physics - kept from v2.0)
    grid[5][4] = true; grid[5][3] = true; grid[5][5] = true; grid[4][4] = true; grid[6][4] = true; // Proton L
    grid[2][4] = true; grid[3][3] = true; grid[3][5] = true; // Spin UP
    std::vector<std::pair<int, int>> orbit_l = { {2,4}, {5,1}, {8,4}, {5,7} };
    for (auto [y, x] : orbit_l) grid[y][x] = true;
    grid[5][7] = true; grid[4][7] = true; grid[3][7] = true; grid[3][6] = true; // Electron Spin UP

    grid[5][9] = true; grid[4][10] = true; grid[5][11] = true; grid[6][12] = true; grid[5][13] = true; // Photon wave

    grid[5][18] = true; grid[5][17] = true; grid[5][19] = true; grid[4][18] = true; grid[6][18] = true; // Proton R
    grid[2][18] = true; grid[3][17] = true; grid[3][19] = true; // Spin UP
    std::vector<std::pair<int, int>> orbit_r = { {2,18}, {5,15}, {8,18}, {5,21} };
    for (auto [y, x] : orbit_r) grid[y][x] = true;
    grid[5][21] = true; grid[6][21] = true; grid[7][21] = true; grid[7][22] = true; // Electron Spin DOWN

    // 3. Separator Line (Shows transition from Physics to Math Table)
    for (int x = 2; x < 21; ++x) {
        if (x % 2 == 0) grid[11][x] = true; // Dotted line
    }

    // 4. THE DATA MATRIX (Rows 14 to 22)
    // Helper lambda to write a formatted row: ID(2), Freq(4), X(4), Y(4), Z(4)
    auto write_table_row = [&](int row, int id, int freq, int x, int y, int z) {
        // ID (Cols 1-2)
        grid[row][1] = (id >> 1) & 1; grid[row][2] = id & 1;
        // Freq (Cols 4-7)
        for(int i=0; i<4; ++i) grid[row][4+i] = (freq >> (3-i)) & 1;
        // X (Cols 9-12)
        for(int i=0; i<4; ++i) grid[row][9+i] = (x >> (3-i)) & 1;
        // Y (Cols 14-17)
        for(int i=0; i<4; ++i) grid[row][14+i] = (y >> (3-i)) & 1;
        // Z (Cols 19-22)
        for(int i=0; i<4; ++i) grid[row][19+i] = (z >> (3-i)) & 1;
    };

    // Header Row (Visual definition of data block sizes for parsing logic)
    // Format: [11] [1111] [1111] [1111] [1111]
    write_table_row(14, 0b11, 0b1111, 0b1111, 0b1111, 0b1111);

    // Entity 00: Our Sun (Origin point: Coordinates 0,0,0)
    // x, y, z are formatted as [Sign bit][3-bit Value] -> 0000 is +0
    write_table_row(16, 0b00, 0b0000, 0b0000, 0b0000, 0b0000);

    // Entity 01: Pulsar A
    // X=+5 (0101), Y=-3 (1011), Z=+2 (0010)
    write_table_row(18, 0b01, 0b1010, 0b0101, 0b1011, 0b0010);

    // Entity 10: Pulsar B
    // X=-6 (1110), Y=+4 (0100), Z=-1 (1001)
    write_table_row(20, 0b10, 0b0111, 0b1110, 0b0100, 0b1001);

    // Entity 11: Galactic Doppler Velocity Vector of our Sun
    // X=+3 (0011), Y=-7 (1111), Z=+6 (0110)
    write_table_row(22, 0b11, 0b1111, 0b0011, 0b1111, 0b0110);

    return grid;
}

// Module 2: Organic Chemistry, DNA Structure & Anatomy
// Upgraded to eliminate chirality ambiguity and define positional Base-10 counting.
Grid create_scientific_biology() {
    Grid grid(HEIGHT, std::vector<bool>(WIDTH, false));

    // 1. Sync borders (top and bottom)
    for (int x = 0; x < WIDTH; ++x) {
        grid[0][x] = true;
        grid[HEIGHT - 1][x] = true;
    }

    // Chemical elements of life (Atomic numbers: H=1, C=6, N=7, O=8, P=15)
    std::vector<int> elements = {1, 6, 7, 8, 15};
    std::vector<int> cols = {2, 6, 10, 14, 18};
    for (size_t i = 0; i < elements.size(); ++i) {
        int col = cols[i];
        grid[2][col] = true; // Header marker
        int elem = elements[i];
        // Encode atomic number vertically as 4-bit binary
        for (int bit_idx = 0; bit_idx < 4; ++bit_idx) {
            grid[3 + bit_idx][col] = (elem >> (3 - bit_idx)) & 1;
        }
    }

    // BASE-10 MATHEMATICAL PROOF (Col 21)
    // We define the number 10 (1010) and show its prime factors: 2 (0010) and 5 (0101)
    grid[2][21] = true;  // Math Marker
    grid[3][21] = true;  // 1 (bit of 1010)
    grid[4][21] = false; // 0
    grid[5][21] = true;  // 1
    grid[6][21] = false; // 0 -> Declares our mathematical base is 10.


    // Instead of a flat drawing, we encode a 3D coordinate table of a chiral 
    // deoxyribose sugar unit.
    // Table Format: [Atom type: 3 bits] [X: 5 bits] [Y: 5 bits] [Z: 5 bits]
    // Values are scaled by 0.5 Angstroms with Sign-Magnitude representation (1st bit is sign).
    auto write_stereo_row = [&](int row, int atom_z, int x, int y, int z) {
        // Atom Type / Atomic Z (Cols 1-3)
        for(int i=0; i<3; ++i) grid[row][1+i] = (atom_z >> (2-i)) & 1;
        // X (Cols 5-9)
        for(int i=0; i<5; ++i) grid[row][5+i] = (x >> (4-i)) & 1;
        // Y (Cols 11-15)
        for(int i=0; i<5; ++i) grid[row][11+i] = (y >> (4-i)) & 1;
        // Z (Cols 17-21)
        for(int i=0; i<5; ++i) grid[row][17+i] = (z >> (4-i)) & 1;
    };

    // Table Header for parsing logic [111] [11111] [11111] [11111]
    write_stereo_row(9, 0b111, 0b11111, 0b11111, 0b11111);

    // Chiral Carbon 1' (C1*): Origin at (0, 0, 0)
    write_stereo_row(11, 6, 0b00000, 0b00000, 0b00000);

    // Chiral Carbon 2' (C2*): X=+3, Y=+1, Z=-2 (0.5A scale)
    write_stereo_row(13, 6, 0b00011, 0b00001, 0b10010);

    // Oxygen 1 (O1): X=-1, Y=+3, Z=+2 (Forces Right-Handed L-enantiomer geometry)
    write_stereo_row(15, 8, 0b10001, 0b00011, 0b00010);

    // Nitrogen (N1 of base): X=-3, Y=-1, Z=-2
    write_stereo_row(17, 7, 0b10011, 0b10001, 0b10010);

    // Visual Double-Helix projection (Simplified, purely topological border)
    // Left strand boundary
    grid[19][3] = true; grid[20][2] = true; grid[21][3] = true;
    // Right strand boundary
    grid[19][19] = true; grid[20][20] = true; grid[21][19] = true;

    // Bipedal organism schema (Symmetrical torso, head, limbs)
    grid[23][11] = true; // Head
    grid[24][10] = true; grid[24][11] = true; grid[24][12] = true; // Shoulders
    grid[25][11] = true; // Torso
    grid[26][10] = true; grid[26][12] = true; // Legs

    // Physical Height Scale (Value 8 on Hydrogen scale: 8 * 21cm = 168cm)
    grid[23][7] = true; grid[24][7] = true; grid[25][7] = true; grid[26][7] = true; // Scale Bar
    grid[23][5] = true; grid[24][5] = false; grid[25][5] = false; grid[26][5] = false; // Binary 8

    // Population Scale (Order of magnitude 9 -> ~10^9 inhabitants, referencing Base-10 proof)
    grid[24][15] = true; grid[24][16] = false; grid[24][17] = false; grid[24][18] = true;

    return grid;
}

// Module 3: Computational Logic & CPU State Transition Matrix
// Upgraded to define Subleq processing purely through state traces, eliminating visual bias.
Grid create_super_detailed_cpu() {
    Grid grid(HEIGHT, std::vector<bool>(WIDTH, false));

    // 1. Sync borders (top and bottom)
    for (int x = 0; x < WIDTH; ++x) {
        grid[0][x] = true;
        grid[HEIGHT - 1][x] = true;
    }

    // We draw a linear tape representing indexed Memory (M)
    for (int x = 1; x < 22; ++x) {
        grid[2][x] = true;
        grid[4][x] = true;
    }
    for (int x : {1, 4, 7, 10, 13, 16, 19, 21}) {
        grid[2][x] = true; grid[3][x] = true; grid[4][x] = true; // Cell walls
    }

    // Binary Indices of Memory printed above the tape (0, 1, 2, 3, 4, 5)
    grid[1][2]  = false; grid[1][3]  = false; // Index 0 (00)
    grid[1][5]  = false; grid[1][6]  = true;  // Index 1 (01)
    grid[1][8]  = true;  grid[1][9]  = false; // Index 2 (10)
    grid[1][11] = true;  grid[1][12] = true;  // Index 3 (11)

    // We demonstrate the Subleq algorithm as a logical map of registers changing state:
    // Format per row: [Step: 2b] [IP: 3b] [Ptr A: 3b] [Ptr B: 3b] [M[A]: 4b] [M[B] Before: 4b] [M[B] After: 4b]
    auto write_trace_row = [&](int row, int step, int ip, int ptr_a, int ptr_b, int m_a, int m_b_pre, int m_b_post) {
        // Step (Cols 1-2)
        grid[row][1] = (step >> 1) & 1; grid[row][2] = step & 1;
        // IP (Cols 4-6)
        for(int i=0; i<3; ++i) grid[row][4+i] = (ip >> (2-i)) & 1;
        // Ptr A (Cols 8-10)
        for(int i=0; i<3; ++i) grid[row][8+i] = (ptr_a >> (2-i)) & 1;
        // Ptr B (Cols 12-14)
        for(int i=0; i<3; ++i) grid[row][12+i] = (ptr_b >> (2-i)) & 1;
        // M[A] Value (Cols 16-17) - compact 2-bit values
        grid[row][16] = (m_a >> 1) & 1; grid[row][17] = m_a & 1;
        // M[B] Pre Value (Cols 19-20)
        grid[row][19] = (m_b_pre >> 1) & 1; grid[row][20] = m_b_pre & 1;
        // M[B] Post Value (Cols 21-22)
        grid[row][21] = (m_b_post >> 1) & 1; grid[row][22] = m_b_post & 1;
    };

    // Trace Table Header (Establishes column block sizes for their parser)
    write_trace_row(7, 0b11, 0b111, 0b111, 0b111, 0b11, 0b11, 0b11);

    // STEP 0: Initial Instruction Fetch
    // Instruction [3, 4, 6] is at IP 0. Operand values: M[3]=2, M[4]=5
    // Subtract M[3] from M[4] -> 5 - 2 = 3. Since 3 > 0, we do NOT branch. Next IP = IP + 3 = 3.
    write_trace_row(10, 0, 0, 3, 4, 2, 3, 3); // 2-bit values scaled for demonstration

    // STEP 1: Next Instruction Fetch (No Branch taken, pointer stepped to IP=3)
    // At IP 3, we read the next instruction.
    write_trace_row(14, 1, 3, 4, 4, 3, 3, 0); // Demonstrates identical pointers forcing M[B] to become <= 0

    // STEP 2: Branch Taken Demonstration (M[B] became <= 0, we jump to address C)
    // Shows the conditional jump logic in action.
    write_trace_row(18, 2, 6, 0, 0, 0, 0, 0); // HALT State reached

    // =====================================================================
    // SECTION 3: MATHEMATICAL SYMBOLIC EQUATION (Rows 22-26)
    // =====================================================================
    // We write the strict Boolean logic of the branch update in pixel-space:
    // "IP' = (M[B] - M[A] <= 0) ? C : IP + 3"
    // We represent this as a clean, standardized state transition vector:
    grid[22][11] = true; // State Operator Indicator
    grid[24][9] = true; grid[24][10] = true; grid[24][11] = true; grid[24][12] = true; grid[24][13] = true; // Equivalence Bar
    grid[26][11] = true;

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

// Interleaved TMR (Triple Modular Redundancy)
    // Send the whole array three times sequentially: [ABC] [ABC] [ABC]
    // If a cosmic ray wipes a chunk, majority logic still recovers the data!
    for (int i = 0; i < 3; ++i) {
        for (int num : subleq_payload) {
            output_bytes.push_back(static_cast<uint8_t>(num));
        }
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