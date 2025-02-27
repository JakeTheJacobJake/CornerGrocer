/*
 * main.cpp
 *
 *  Created on: Feb 26, 2025
 *      Author: jacobhough_snhu
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

// GroceryTracker class definition
class GroceryTracker {
private:
	// Map to store the frequency of each item.
	std::map<std::string, int> itemFrequency;

	// Loads data from the input file and counts the frequency of each item.
	void loadData(const std::string& filename) {
		std::ifstream infile(filename);
		if (!infile) {
			std::cerr << "Error opening file: " << filename << std::endl;
			return;
		}
		std::string item;
		// Reach each item (assumed to be whitespaced-delimited) and update the frequency count.
		while (infile >> item) {
			itemFrequency[item]++;
		}
		infile.close();
	}

	// Creates a backup file (frequency.dat) with each item and its frequency.
	void backupData(const std::string& backupFilename) {
		std::ofstream outfile(backupFilename);
		if (!outfile) {
			std::cerr << "Error creating backup file: " << backupFilename << std::endl;
			return;
		}
		// Write each item and its count on a new line.
		for (const auto& pair : itemFrequency) {
			outfile << pair.first << " " << pair.second << std::endl;
		}
		outfile.close();
	}

public:
	// Constructor: loads the data and wires the backup file.
	GroceryTracker(const std::string& filename, const std::string& backupFilename) {
		loadData(filename);
		backupData(backupFilename);
	}

	// Returns the frequency for a specific item.
	int getFrequency(const std::string& item) {
		auto it = itemFrequency.find(item);
		if (it != itemFrequency.end()) {
			return it->second;
		}
		return 0; // Return 0 if the item was not found.
	}

	// Prints all items with their frequencies.
	void printFrequencyList() {
		std::cout << "\nItem Frequencies:\n";
		for (const auto& pair : itemFrequency) {
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}

	// Prints a histogram whre each asterisk represents one occurrence of the item.
	void printHistogram() {
		std::cout << "\nItem Histogram:\n";
		for (const auto& pair : itemFrequency) {
			std::cout << pair.first << ": ";
			for (int i = 0; i < pair.second; i++) {
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	// File names as specified in the asignment.
	const std::string inputFilename = "CS210_Project_Three_Input_File.txt";
	const std::string backupFilename = "frequency.dat";

	// Create a GroceryTracker object which automatically loads data and creates the backup file.
	GroceryTracker tracker(inputFilename, backupFilename);

	int choice;
	do {
		// Display the menu options to the user.
		std::cout << "\nMenu Options:\n";
		std::cout << "1. Lookup item frequency\n";
		std::cout << "2. Print frequncy list\n";
		std::cout << "3. Print histogram\n";
		std::cout << "4. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

        // Process the menu selection using a switch statement.
        switch (choice) {
            case 1: {
            	std::string searchItem;
            	std::cout << "Enter the item to search: ";
            	std::cin >> searchItem;
            	int frequency = tracker.getFrequency(searchItem);
            	std::cout << searchItem << " appears " << frequency << " times." << std::endl;
            	break;
            }
            case 2:
            	tracker.printFrequencyList();
            	break;
            case 3:
            	tracker.printHistogram();
            	break;
            case 4:
            	std::cout << "Exiting program." << std::endl;
            	break;
            default:
            	std::cout << "Invalid option. Please try again." << std::endl;
		}
	} while (choice != 4);

	return 0;
}



