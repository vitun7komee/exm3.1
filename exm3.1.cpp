#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string>& words, vector<string>& chain, int& max_len, vector < vector < string>>& max_chains) {
	if (chain.size() > max_len) { // если текущая цепочка максимальной длины, то сохраняем ее
		max_len = chain.size();
		max_chains.clear();
		max_chains.push_back(chain);
	}
	else if (chain.size() == max_len) { // если текущая цепочка равна по длине максимальной, то добавляем ее в вектор максимальных цепочек
		max_chains.push_back(chain);
	}

	for (int i = 0; i < words.size(); i++) {
		if (find(chain.begin(), chain.end(), words[i]) == chain.end()) { // если слово еще не в цепочке
			if (chain.empty() || chain.back().back() == words[i].front()) { // если последняя буква последнего слова в цепочке совпадает с первой буквой текущего слова
				chain.push_back(words[i]);
				backtrack(words, chain, max_len, max_chains);
				chain.pop_back();
			}
		}
	}
}

int main() {
	vector<string> words = { "hello", "orange", "egg", "elephant", "tennis", "nose", "end" };
	vector<string> chain;
	int max_len = 0;
	vector < vector < string>> max_chains;

	backtrack(words, chain, max_len, max_chains);

	cout << "max chain: " << endl;
	for (string word : max_chains[0]) {
		cout << word << " ";
	}
	cout << endl << "diff roots: " << max_chains.size() << endl;

	return 0;
}