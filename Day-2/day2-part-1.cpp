#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt");
    string input, line;

    while (getline(file, line)) {
        input += line;
    }
    file.close();

    long long ts = 0;

    stringstream ss(input);
    string range;

    while (getline(ss, range, ',')) {
        int t = range.find('-');
        long long start = stoll(range.substr(0, t));
        long long end = stoll(range.substr(t + 1));

        for (long long num = start; num <= end; num++) {
            string s = to_string(num);

            if (s.length() % 2 != 0)
                continue;

            int mid = s.length() / 2;
            string first = s.substr(0, mid);
            string second = s.substr(mid);
            
            if (first == second) {
                ts += num;
            }
        }
    }

    cout<<ts;

    return 0;
}
