#include <iostream>
#include <vector>

// Remove the magic number 10 (length of array)
const int numOfWords = 10;

using namespace std;
class MakeSentences {
	public:
		void getInputWords(string);
		bool wordExist(string, vector<string>);
		void printOutAllWords();
		void makeTheSentence();
	private:
		vector<string> noun;
		vector<string> verb;
};
/*
	According to the arg "wordType" put the input word into vector "noun" or "verb"
	Before pushing word into the vector, also check if the word already exists in the vector
*/
void MakeSentences::getInputWords(string wordType) {
	string input;
	for (int i = 0 ;i < numOfWords;i++) {
		cout << "Please in put No. " << i+1 << " " << wordType << ":" << endl;
		cin >> input;
		if (wordType == "noun" && !wordExist(input, noun)) {
				noun.push_back(input);
			}
		else if (wordType == "verb" && !wordExist(input, verb)) {
				verb.push_back(input);
			}
		else {
			cout << "The input word already exists!" << endl;
			i--;
			continue;
		}
	}
}

// Go through the vector check if the word exists.
bool MakeSentences::wordExist(string word, vector<string>checkedVector) {
	bool exist = false;
	for (string n : checkedVector) {
		if (n == word) {
			exist = true;
			break;
		}
	}
	return exist;
}

void MakeSentences::printOutAllWords() {
	cout << "All nouns:" << endl;
	for (string n : noun) {
		cout << n << endl;
	}
	
	cout << "All verbs:" << endl;
	for (string n : verb) {
		cout << n << endl;
	}
}

// According to the requirement, use rand() to generate random number,
// and get the word from the vector to make the sentence.
void MakeSentences::makeTheSentence() {
	char command;
	bool endProgram = false;
	while (!endProgram) {
		cout << "Input 'C' to create a sentence, input 'E' to end the program:";
		cin >> command;
		switch (command) {
			case 'C': case 'c': {
				int nounIndex = -1;
				int nounRan = rand() % numOfWords;
				string firstNoun = noun[nounRan];
				nounIndex = nounRan;
				// To avoid same nouns in the sentence
				while (nounRan == nounIndex) {
					nounRan = rand() % numOfWords;
				}
				string secondNoun = noun[nounRan];
				int verbRan = rand() % numOfWords;
				string theVerb = verb[verbRan];
				cout << "The sentence is :" << endl;
				cout << "The " << firstNoun << " " << theVerb << " the " << secondNoun << ".";
				cout << endl;
				break;
			}
			case 'E': case 'e':
				endProgram = true;
				break;
				
			default:
				cout << "Input wrong command the program will terminate.";
				endProgram = true;
				break;
		}
	}
}

class Container {
	public:
		void makeSentence();
};

void Container::makeSentence() {
	MakeSentences makeSentence;
	makeSentence.getInputWords("noun");
	makeSentence.getInputWords("verb");
	makeSentence.printOutAllWords();
	makeSentence.makeTheSentence();
}


int main(int argc, char *argv[]) {
	Container container;
	container.makeSentence();
}