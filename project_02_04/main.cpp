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
	BigInt y(line);

	inp >> line;
	BigInt m(line);

	inp >> line;
	BigInt r(line);

	inp >> line;
	BigInt h(line);

	const bool skipSizeCheck = 1;
	int valid = 0;

	//Input specified that (r < p) and (h < p - 1) are always true, therefore we can short-circuit it here
	if (skipSizeCheck || (r < p && h < p - 1)) {
		BigInt gm = BigInt::powMod(g, m, p);
		BigInt yr = BigInt::powMod(y, r, p);
		BigInt rh = BigInt::powMod(r, h, p);

		valid = gm == BigInt::mulMod(yr, rh, p);
	}

	out << valid << endl;

	return 0;
}