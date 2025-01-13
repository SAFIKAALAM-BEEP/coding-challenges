#include <iostream>
#include <string>
#include "Brainf.cpp"

int main() {
    // BrainfuckInterpreter interpreter;
    // std::string input;
    
    // std::cout << "Brainf*ck Interpreter (type 'exit' to quit, 'reset' to clear memory)\n";
    // std::cout << "Enter your code: ";
    
    // while (true) {
    //     std::getline(std::cin, input);
        
    //     if (input == "exit") {
    //         break;
    //     } else if (input == "reset") {
    //         interpreter.reset();
    //         std::cout << "Memory reset.\n";
    //     } else {
    //         interpreter.interpret(input);
    //         std::cout << "\nEnter your code: ";
    //     }
    // }

    BrainfuckInterpreter interpreter;
    interpreter.loadFromFile("test.bf");
    interpreter.interpret();
    
    return 0;
}
    