#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

void compressChunk(const std::string& input, std::string& output, size_t start, size_t end) {
    for (size_t i = start; i < end; ) {
        char currentChar = input[i];
        size_t count = 1;

        // Count occurrences of the current character
        while (i + 1 < end && input[i + 1] == currentChar) {
            count++;
            i++;
        }

        // Append the character and its count to the output
        output += currentChar;
        output += std::to_string(count);
        i++;
    }
}

void compressData(const std::string& input, int numThreads) {
    size_t fileSize = input.size();
    if (fileSize == 0) {
        std::cerr << "Input data is empty!" << std::endl;
        return;
    }
    if (numThreads <= 0 || numThreads > fileSize) {
        std::cerr << "Invalid number of threads!" << std::endl;
        return;
    }

    size_t chunkSize = fileSize / numThreads;
    std::vector<std::string> compressedChunks(numThreads);
    std::vector<std::thread> threads;

    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThreads; i++) {
        size_t start = i * chunkSize;
        size_t end = (i == numThreads - 1) ? fileSize : start + chunkSize;

        threads.emplace_back(compressChunk, std::cref(input), std::ref(compressedChunks[i]), start, end);
    }

    for (auto& t : threads) {
        t.join();
    }
    auto endTime = std::chrono::high_resolution_clock::now();

    // Output compressed data
    for (const auto& chunk : compressedChunks) {
        std::cout << chunk;
    }

    std::cout << "\nCompression completed in "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms using " << numThreads << " threads." << std::endl;
}

int main() {
    std::string input;
    int choice, numThreads;

    do {
        std::cout << "\nSimple Data Compression Tool\n";
        std::cout << "1. Compress Data\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter data to compress: ";
                std::getline(std::cin, input);
                std::cout << "Enter number of threads: ";
                std::cin >> numThreads;
                compressData(input, numThreads);
                break;
            case 2:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}