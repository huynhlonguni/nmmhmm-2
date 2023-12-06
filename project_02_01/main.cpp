#include <fstream>
#include "../BigInt.h"

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		cout << argv[0] << " <input file> [<output file>]" << endl;
		exit(1);
	}
	ofstream outfile;
	if (argc > 2) outfile.open(argv[2]);

	ostream &out = argc > 2 ? outfile : cout;

	ifstream inp(argv[1]);
	string line;

	inp >> line;
	BigInt p(line);
	BigInt p1 = p - 1;

	inp >> line;
	BigInt BigN(line);
	long long n = BigN.toLongLong();

	vector<BigInt> U_p;
	U_p.reserve(n);

	for (int i = 0; i < n; i++) {
		inp >> line;
		U_p.emplace_back(line);
	}

	inp >> line;
	BigInt g(line);

	int isPrimitiveRoot = 1;

	for (int i = 0; i < n; i++) {
		BigInt power = p1 / U_p[i];
		if (BigInt::powMod(g, power, p) == 1) {
			isPrimitiveRoot = 0;
			break;
		}
	}

	out << isPrimitiveRoot << endl;
	
	return 0;
}