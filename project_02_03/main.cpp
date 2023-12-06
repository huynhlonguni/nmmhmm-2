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

	inp >> line;
	BigInt g(line);

	inp >> line;
	BigInt x(line);

	inp >> line;
	BigInt c1(line);

	inp >> line;
	BigInt c2(line);

	BigInt h = BigInt::powMod(g, x, p);

	BigInt s = BigInt::powMod(c1, x, p);
	BigInt s_inv = BigInt::inverseMod(s, p);

	BigInt m = BigInt::mulMod(c2, s_inv, p);

	out << h.toHexString() << endl;
	out << m.toHexString() << endl;
	
	return 0;
}