#include "pljit_core/include/PLjit.hpp"
#include "pljit_core/include/PLjit_Error.hpp"
#include "pljit_core/include/PLjit_FunctionHandle.hpp"
#include <exception>
#include <fstream>
#include <iostream>

/// Reads the location of a source.txt file from commandline with arguments to be passed to it right after
/// Usage: ./pljit source_code.txt 1 2 3 4
int main([[maybe_unused]] int argc, char* argv[]) {
    // Ensure we get a source.txt
    if (argc <= 1) {
        std::cout << "Please supply a source.txt file as first argument" << std::endl;
    }

    // Read source.txt
    std::ifstream ifs(argv[1]);
    std::string valid_source((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    // Parse arguments
    std::vector<std::int64_t> arguments;
    for (int i = 2; i < argc; ++i) {
        try {
            arguments.push_back(std::stoll(argv[i]));
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << std::endl;
            return 1;
        } catch (const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << std::endl;
            return 1;
        }
    }

    // Construct PLjit
    pljit::PLjit pljit;
    // Register the source code
    auto handle = pljit.registerFunction(valid_source);
    // Execute the source code
    auto result = handle.execute(arguments);

    // Check the result
    if (result.index() == 0) {
        // On success, we print the received result
        std::cout << std::get<0>(result) << std::endl;

        // Exit program indicating success
        return 0;
    } else {
        // Otherwise, we display the error
        std::get<1>(result).print();

        //Exit program indicating failure
        return 1;
    }
}
