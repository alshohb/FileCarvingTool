#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Helper function to convert a hex string to a byte array.
std::vector<char> hex_to_bytes(const std::string& hex) {
    std::vector<char> bytes;
    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        char byte = (char)strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

// Function to find all occurrences of a pattern in the file data.
std::vector<size_t> find_pattern(const std::vector<char>& data, const std::vector<char>& pattern) {
    std::vector<size_t> positions;

    size_t pos = std::search(data.begin(), data.end(), pattern.begin(), pattern.end()) - data.begin();
    while (pos != data.size()) {
        positions.push_back(pos);
        pos = std::search(data.begin() + pos + pattern.size(), data.end(), pattern.begin(), pattern.end()) - data.begin();
    }

    return positions;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <header> <footer>\n";
        return 1;
    }

    std::string input_file = argv[1];
    std::vector<char> header = hex_to_bytes(argv[2]);
    std::vector<char> footer = hex_to_bytes(argv[3]);

    std::ifstream file(input_file, std::ios::binary);
    if (!file) {
        std::cerr << "File could not be opened.\n";
        return 1;
    }

    std::vector<char> file_data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::vector<size_t> header_positions = find_pattern(file_data, header);
    std::vector<size_t> footer_positions = find_pattern(file_data, footer);

    // Only process the first matching header and the nearest following footer
    if (!header_positions.empty() && !footer_positions.empty()) {
        size_t start = header_positions[0] + header.size();
        auto footer_it = std::find_if(footer_positions.begin(), footer_positions.end(), [start](size_t pos) {
            return pos > start;
            });

        if (footer_it != footer_positions.end()) {
            size_t end = *footer_it;
            size_t size = end - start;

            std::ofstream out_file("extracted_0.jpg", std::ios::binary);
            if (out_file && size > 0) {
                out_file.write(file_data.data() + start, size);
                out_file.close();
                std::cout << "Extracted file from offset " << start << " to " << end << std::endl;
            }
            else {
                std::cerr << "Failed to write extracted file." << std::endl;
            }
        }
    }
    else {
        std::cerr << "No valid header and footer positions found." << std::endl;
    }

    return 0;
}
