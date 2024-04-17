#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define TABLE_SIZE 2048;
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
    unordered_map<int, vector<Entry>> table;

    // Hash function to map keys to indices
    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    int addressRegister, programCounter, instructionRegister;
    MainMemory()
    {
        this->addressRegister = addressRegister = 0;
        this->programCounter = programCounter = 0;
        this->instructionRegister = instructionRegister = 0;
    }
    // Insert a value into the hash table
    void insert(int key, int value)
    {
        int index = hashFunction(key);
        Entry entry = {key, value};
        table[index].push_back(entry);
    }
    int retrieveleft4Bits(int key)
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
    int key, choice;
    // Create an instance of the MainMemory hash table
    MainMemory memory;

    // Insert some values into the hash table
    memory.insert(0, 33);
    memory.insert(2, 5678);

    // Retrieve values from the hash table
    cout << "Value for key 0: " << memory.retrieve(0) << endl;
    cout << "Value for key 1: " << memory.retrieve(1) << endl;
    cout << "Value for key 2: " << memory.retrieve(2) << endl;
    do
    {
        cout << "\n Welcome to the Basic ProcessorSimulator";

        cout << "\nChoose the options below";
        cout << "\n 1. Insert instructions and data in the memory";
        cout << "\n 2. See the Main Memory";
        cout << "\n 3. Manually check the values ";
        cout << "\n 4. Exit\n";
        cout << "\n Your Choice: ";
        cin >> choice;
        switch (choice)
        {
            // manually search for any key with its value and left 4digits
        case 3:
            // Retrieve values from the hash table
            cout << "Enter key to retrieve value: ";
            cin >> key;
            int retrievedValue = memory.retrieve(key);
            if (retrievedValue != -1)
            {
                cout << "Value for key " << key << ": " << retrievedValue << endl;
            }
            else
            {
                cout << "Key not found!" << endl;
            }

            // Retrieve the left 4 bits of a value from the hash table
            int left4Bits = memory.retrieveleft4Bits(key);
            if (left4Bits != -1)
            {
                cout << "left 4 bits of the value for key " << key << ": " << left4Bits << endl;
            }
        }
    } while (choice != 4);
    return 0;
}