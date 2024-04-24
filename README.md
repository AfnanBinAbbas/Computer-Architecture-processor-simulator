Processor Project

## Version 0.2.5: Instruction Format and Addressing Modes

### Instruction Format Specification:
The instruction format consists of 16 bits, organized as follows:
- Address Field (Bits 0-10): Reserved for specifying memory addresses, ranging from 0 to 2047.
- Opcode Field (Bits 11-13): 3 bits allocated for opcode representation, allowing for up to 16 unique opcodes, each performing distinct operations.
- Addressing Bit (Bit 14): Designated for addressing mode selection, distinguishing between direct and indirect addressing modes. '0' signifies direct addressing, while '1' indicates indirect addressing.

## Version 0.2.6: Instruction Set Architecture

### Memory Reference Instructions:
- OR (000): Performs a bitwise OR operation between the accumulator and a specified memory location.
- Add (ADD) (001): Adds data from memory to the accumulator.
- Load (LDA) (010): Loads data from memory into the accumulator.
- Store (STA) (011): Stores data from the accumulator into memory.
- Jump (JMP) (100): Unconditionally jumps to a specified memory address.
- Branch and save address (BSA) (101): Jumps to a specified memory location and saves the return address in memory.
- Increment and Skip if Zero (ISZ) (110): Increments a specified memory location by 1 and skips the next instruction if the result is zero.

### Register Reference Instructions:
- Clear Accumulator (CLA): Clears the content of the accumulator, setting it to zero.
- Clear E-register (CLE): Clears the E-register, used for arithmetic operations involving larger numbers or fractions.
- Circular Shift Right (CIR): Performs a circular shift of the bits in the accumulator to the right.
- Clear I-register (CLI): Clears the I-register, used for indexing operations.
- Halt (HLT): Halts the execution of the program.

### I/O Reference Instructions:
- Interrupt Enable (ION): Enables interrupts, allowing the processor to respond to external events.
- Interrupt Disable (IOF): Disables interrupts, preventing the processor from responding to external events.
- Input (INP): Reads input from an input device and loads it into the accumulator.
- Output (OUT): Writes the value in the accumulator to an output device.

For further details and updates, please refer to the project documentation.