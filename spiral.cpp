# include <iostream>


class Spiral{
	public:
	  int matrix[0];
	  int length;
};

// Fills the matrix array inside of spiral with 0's
void FillZeros(Spiral& s) {
	for (int i = 0; i < sizeof(s.matrix) / sizeof(s.matrix[0]); i++){
		s.matrix[i] = 0;
	}
}

// Displays the current matrix inside spiral
void DisplayMatrix(Spiral& s) {
	for (int i = 0; i < sizeof(s.matrix) / sizeof(s.matrix[0]); i++){
		std::cout << s.matrix[i] << " ";
		if ((i + 1) % s.length == 0) {
			std::cout << std::endl;
		}
	}
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
	Spiral spiral;
	spiral.length = GetLength();
	// Increase size of the array
	int *newArr = new int[spiral.length * spiral.length];
	//std::copy(spiral.matrix, spiral.matrix + std::min(0, (spiral.length * spiral.length)), newArr);
	int *temp = spiral.matrix;
	spiral.matrix = newArr;
	delete[] temp;
	FillZeros(spiral);
	DisplayMatrix(spiral);
	return 0;
}