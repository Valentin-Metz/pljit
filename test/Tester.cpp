#include <filesystem>
#include <fstream>
#include <iostream>
#include <source_location>
#include <gtest/gtest.h>

// Example program from the sheet
std::string example_program = "PARAM width, height, depth;\n"
                              "VAR volume;\n"
                              "CONST density = 2400;\n\n"
                              "BEGIN\n"
                              "volume := width * height * depth;\n"
                              "RETURN density * volume\n"
                              "END.";

// Vector of valid programs
std::vector<std::string> valid_programs;
// Vector of invalid programs
std::vector<std::string> invalid_programs;

int main(int argc, char* argv[]) {
    // Read all files in folder "valid_source" into std::vector<std::string> valid_programs
    std::string tester_location = std::source_location::current().file_name();
    for (auto const& dir_entry : std::filesystem::directory_iterator{tester_location.substr(0, tester_location.size() - 10) + "valid_source"}) {
        std::ifstream ifs(dir_entry.path());
        valid_programs.push_back({(std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())});
    }
    // Read all files in folder "invalid_source" into std::vector<std::string> invalid_programs
    for (auto const& dir_entry : std::filesystem::directory_iterator{tester_location.substr(0, tester_location.size() - 10) + "invalid_source"}) {
        std::ifstream ifs(dir_entry.path());
        invalid_programs.push_back({(std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())});
    }

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
