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
	BigInt a(line);

	inp >> line;
	BigInt b(line);

	BigInt A = BigInt::powMod(g, a, p);
	BigInt B = BigInt::powMod(g, b, p);
	BigInt K = BigInt::powMod(A, b, p); //(g^a)^b = g^(ab)

	out << A.toHexString() << endl;
	out << B.toHexString() << endl;
	out << K.toHexString() << endl;
	
	return 0;
}