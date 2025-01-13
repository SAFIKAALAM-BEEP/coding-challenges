#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class BrainfuckInterpreter {
private:
    static const size_t MEMORY_SIZE = 30000;
    std::vector<unsigned char> memory;
    size_t dataPointer;
    std::string code;
    size_t programCounter;
    
    // Helper function to find brackets
    size_t findMatchingBracket(size_t start, bool forward) {
        int count = 0;
        if (forward) {
            for (size_t i = start; i < code.length(); i++) {
                if (code[i] == '[') count++;
                else if (code[i] == ']') {
                    count--;
                    if (count == 0) return i;
                }
            }
        } else {
            for (int i = start; i >= 0; i--) {
                if (code[i] == ']') count++;
                else if (code[i] == '[') {
                    count--;
                    if (count == 0) return i;
                }
            }
        }
        return start;
    }

public:
    BrainfuckInterpreter() : memory(MEMORY_SIZE, 0), dataPointer(0), programCounter(0) {}
    
    void reset() {
        for (size_t i = 0; i < MEMORY_SIZE; i++) {
            memory[i] = 0;
        }
        dataPointer = 0;
        programCounter = 0;
        code.clear();
    }
    
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        code.clear();
        std::string line;
        while (std::getline(file, line)) {
            code += line;
        }
        file.close();
    }
    
    // For file
    void interpret() {
        programCounter = 0;
        
        while (programCounter < code.length()) {
            char instruction = code[programCounter];
            
            switch (instruction) {
                case '>':
                    if (dataPointer < MEMORY_SIZE - 1) dataPointer++;
                    break;
                    
                case '<':
                    if (dataPointer > 0) dataPointer--;
                    break;
                    
                case '+':
                    memory[dataPointer]++;
                    break;
                    
                case '-':
                    memory[dataPointer]--;
                    break;
                    
                case '.':
                    std::cout << memory[dataPointer];
                    break;
                    
                case ',':
                    char input;
                    std::cin >> std::noskipws >> input;
                    memory[dataPointer] = input;
                    break;
                    
                case '[':
                    if (memory[dataPointer] == 0) {
                        programCounter = findMatchingBracket(programCounter, true);
                    }
                    break;
                    
                case ']':
                    if (memory[dataPointer] != 0) {
                        programCounter = findMatchingBracket(programCounter, false);
                    }
                    break;
            }
            
            programCounter++;
        }
    }

    // For user input 
    // void interpret(const std::string& input) {
    //     code = input;
    //     programCounter = 0;
        
    //     while (programCounter < code.length()) {
    //         char instruction = code[programCounter];
            
    //         switch (instruction) {
    //             case '>':
    //                 if (dataPointer < MEMORY_SIZE - 1) dataPointer++;
    //                 break;
                    
    //             case '<':
    //                 if (dataPointer > 0) dataPointer--;
    //                 break;
                    
    //             case '+':
    //                 memory[dataPointer]++;
    //                 break;
                    
    //             case '-':
    //                 memory[dataPointer]--;
    //                 break;
                    
    //             case '.':
    //                 std::cout << memory[dataPointer];
    //                 break;
                    
    //             case ',':
    //                 char input;
    //                 std::cin >> std::noskipws >> input;
    //                 memory[dataPointer] = input;
    //                 break;
                    
    //             case '[':
    //                 if (memory[dataPointer] == 0) {
    //                     programCounter = findMatchingBracket(programCounter, true);
    //                 }
    //                 break;
                    
    //             case ']':
    //                 if (memory[dataPointer] != 0) {
    //                     programCounter = findMatchingBracket(programCounter, false);
    //                 }
    //                 break;
    //         }
            
    //         programCounter++;
    //     }
    // }
};