# include <iostream>

void DisplayMatrix() {

}

void FillZeros() {

}

void Spiral() {

}

int GetLength() {
	int length = 0;
	std::string input;
	while (1) {
		length = 0; // Reset
		std::cout << "Length of the side of a square: ";
		std::cin >> input;
		for (int i = 0; i < input.length(); i++) {
			if (!std::isdigit(input[i])) {
				length = -1; // Change length value here to test later
				break;
			}
		}
		if (length == -1) { // Value isn't an integer
			std::cout << "Input must be an integer, please try again" << std::endl;
			std::cin.ignore();
			std::cin.clear();
			
		} else { // Value is an integer, convert break and return
			length = std::stoi(input);
			break;
		}
	}
	return length;
}

int main() {
	int length = GetLength();
	return 0;
}