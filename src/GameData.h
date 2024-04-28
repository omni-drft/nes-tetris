#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

struct GameData
{
	unsigned int maxScore;
	unsigned int gamesPlayed;
};

inline bool fileExists(const std::string& filename) {
    DWORD attributes = GetFileAttributesA(filename.c_str());
    return (attributes != INVALID_FILE_ATTRIBUTES && !(attributes & FILE_ATTRIBUTE_DIRECTORY));
}

inline void saveGameData(const GameData& data, std::string& fileName)
{
    // Check if the file exists
    if (!fileExists(fileName)) {
        // If the file doesn't exist, create it with default values
        std::cout << "File doesn't exist. Creating with default values." << std::endl;
        std::ofstream newFile(fileName, std::ios::binary);
        if (!newFile) {
            std::cerr << "Error creating file." << std::endl;
            return;
        }
        // Write default values
        newFile.write(reinterpret_cast<const char*>(&data), sizeof(GameData));
        newFile.close();
    }
    else {
        // If the file exists, open it for writing
        std::ofstream file(fileName, std::ios::binary);
        if (!file) {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }
        // Write data to the file
        file.write(reinterpret_cast<const char*>(&data), sizeof(GameData));
        file.close();
    }
}

inline GameData loadGameData(std::string& filename) {
    GameData data;

    // Check if the file exists
    if (!fileExists(filename)) {
        // File doesn't exist, create it with default values
        std::cout << "File doesn't exist. Creating with default values." << std::endl;
        data.gamesPlayed = 0;
        data.maxScore = 0;
        saveGameData(data, filename);
        return { 0, 0 };
    }

    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for reading." << std::endl;
        // Initialize data with default values
        data.maxScore = 0;
        data.gamesPlayed = 0;
        return data;
    }
    file.read(reinterpret_cast<char*>(&data), sizeof(GameData));
    file.close();
    return data;
}