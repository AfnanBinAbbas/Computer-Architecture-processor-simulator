#include <iostream>
#include <vector>

using namespace std;

// Instructions
// (010) LOAD
// (011) STORE
// (001) ADD
// (100) JUMP
// (101) BRANCH AND SAVE ADDRESS [BSA]
// (110) INCREMENT AND SKIP IF ZERO [ISZ]

// CLEAR ACCUMULATOR
// CLEAR E REGISTER
// CIRCULAR SHIFT RIGHT
// CLEAR I REGISTER
// HALT (HLT)

// INTERTTUPR ENABLE (ION)
// INTERTTUPR DISABLE (IOF)
// INPUT
// OUTPUT

// Define the size of the hash table
const int TABLE_SIZE = 2048; // 2^11

// Define the structure for hash table entries
struct Entry
{
    int key;
    int value;
    int left4Bits; // Store the left 4 bits separately
};

// Define the hash table class
class MainMemory
{
private:
    vector<Entry> table[TABLE_SIZE];

    // Hash function to map keys to indices
    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    int addressRegister, programCounter, instructionRegister;
    MainMemory()
    {
        this->addressRegister = 0;     // AR
        this->programCounter = 0;      // PC
        this->instructionRegister = 0; // IR
    }
    // Insert a value into the hash table
    void insert(int key, int value)
    {
        int index = hashFunction(key);
        Entry entry = {key, value, (value & 0b1111000000000000) >> 12}; // Extract left 4 bits
        table[index].push_back(entry);
    }
    int retrieveLeft4Bits(int key)
    {
        int index = hashFunction(key);
        for (const Entry &entry : table[index])
        {
            if (entry.key == key)
            {
                return entry.left4Bits;
            }
        }
        // Return -1 if key is not found
        return -1;
    }
    // Retrieve a value from the hash table
    int retrieve(int key)
    {
        int index = hashFunction(key);
        for (const Entry &entry : table[index])
        {
            if (entry.key == key)
            {
                return entry.value;
            }
        }
        // Return -1 if key is not found
        return -1;
    }

    // FETCH, DECODE AND EXECUTE
    void fetch()
    {
        // PC = 1
        // AR = 1
        addressRegister = programCounter;

        // MDR -> 1 (LOAD 5)
        //
    };
};

int main()
{
    int key, value, choice, instruction;
    int HLT = 0b0000, ADD = 0b001, LOAD = 0b010, STORE = 0b011,
        STP = 0b000000000000000, ANS = 0b000000000000000, JUMP = 0b100,
        BSA = 0b101, ISZ = 0b110;
    // Create an instance of the MainMemory hash table
    MainMemory memory;

    // Insert some values into the hash table
    // memory.insert(0, 33);
    // memory.insert(2, 100000);

    // // Retrieve values from the hash table
    // cout << "Value for key 0: " << memory.retrieve(0) << endl;
    // cout << "Value for key 1: " << memory.retrieve(1) << endl;
    // cout << "Value for key 2: " << memory.retrieve(2) << endl;

    do
    {
        cout << "\n Welcome to the Basic Processor Simulator";

        cout << "\nChoose the options below";
        cout << "\n 1. Insert instructions and data in the memory";
        cout << "\n 2. Retrieve data from the memory";
        cout << "\n 3. See the Main Memory";
        cout << "\n 4. Exit\n";
        cout << "\n Your choice: ";
        cin >> choice;
        switch (choice)
        {
            // Inserting data into the memory
        case 1:
            memory.programCounter = 0;        // int
            key = memory.addressRegister = 0; // 11 bit
            memory.instructionRegister = 0;   // 15 bit
            cout << "\nEnter the instruction to execute\n";
            cout << " 1. OR\n 2. ADD\n 3. LOAD\n 4. STORE\n 5. JUMP\n 6. BSA (Branch and Save Address)\n 7. ISZ (Increment and Skip if Zero)\n"; // Memory Reference ins.
            cout << " 8. CLEAR AC\n 9. CLEAR E\n 10. CIR\n 11. CLI\n 12. HLT\n";                                                                 // Register Reference ins.
            cout << " 13. ION\n 14. IOF\n 15. INP\n 16. OUT";                                                                                    // I/O Reference ins.
            cout << endl;
            cout << "\n Your choice: ";
            cin >> instruction;
            if (instruction == 2) // add
            {

                // for (int programCounter = 0; memory.instructionRegister == 0; programCounter++)
                // {
                cout << "\nEnter values to add\n";
                cout << "\nEnter operand #1: ";
                cin >> value; // saving at key = 0
                memory.insert(0, value);
                cout << "Enter opearand #2: ";
                cin >> value; // saving at key = 1
                key++;
                memory.insert(key, value);
                cout << "Succesfully saved in the memory!\n";
                // memory.retrieve(0);
                // memory.retrieve(1);
                key++;

                int instruction_1 = HLT, instruction_2 = 0b001000000000001, instruction_3 = 0b000100000000101, instruction_4 = 0b000000000000110;
                memory.insert(key, instruction_1); // saving at key = 2
                key++;
                memory.insert(key, instruction_2); // saving at key = 3
                key++;
                memory.insert(key, instruction_3); // saving at key = 4
                key++;
                int retrievedOperandValue_1 = memory.retrieve(0);
                int retrievedOperandValue_2 = memory.retrieve(1);
                int retrievedValue_3 = retrievedOperandValue_1 + retrievedOperandValue_2;
                memory.insert(key, retrievedValue_3); // saving at key = 5
                key++;

                // memory.fetch();       // AR = PC
                // memory.retrieve(key); // IR = M[AR]

                //              Hashtable for instructions
                //
                // 000000000000. OPERAND #1
                // 000000000001. OPERAND #2
                // 000000000010. Load (0000) 0  --> 15b000000000000000
                // 000000000011. ADD (0010) 1   --> 15b000000000000000
                // 000000000100. Store (0001) 6 -->
                // 000000000101. STP (0110)
                // 000000000110. ANSWER
                // }
                break;
            }
      
        case 2:
        {
            // Retrieve values from the hash table
            cout << "\n\tRetrieve value in the memory\n";

            cout << "Enter key to retrieve value: ";
            cin >> key;
            int retrievedValue = memory.retrieve(key);
            cout << endl;

            if (retrievedValue != -1)
            {
                cout << "Value for key " << key << " (in hex): " << retrievedValue << endl;
            }
            else
            {
                cout << "Key not found!" << endl;
            }

            // Retrieve the left 4 bits of a value from the hash table
            int left4Bits = memory.retrieveLeft4Bits(key);
            if (left4Bits != -1)
            {
                cout << "Left 4 bits of the value for key " << key << ": " << left4Bits << endl;
            }
            break;
        }
	  case 3:
            break;
        // MANUALLY search for any key with its value and left 4 digits
        default:
            cout << "\nInvalid choice!";
            break;
        }
    } while (choice != 4);
    return 0;
}
