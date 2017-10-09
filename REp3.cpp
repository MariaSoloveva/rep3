#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);
    auto lambda = [&e2, &dist] () -> T { return dist(e2); };
    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

int main(int argc, const char * argv[]) {
    // 1
    vector<int> v = generate_random_vector(10, -100, 50);
    int a = 0;
    cin >> a;
    int b = v[0];
    for (int i = 0; i < v.size(); ++i) {
        v[i] *= 2;
    }
    //
    for (int i = 0; i < v.size(); ++i) {
        v[i] -= a;
    }
    //
    for (int i = 0; i < v.size(); ++i) {
        v[i] /= b;
    }
    // 2
    int sum = 0;
    vector<int> p = generate_random_vector(10, -100, 50);
    for (int i = 0; i < p.size(); ++i) {
        sum += v[i];
    }
    cout << sum << endl;
    //
    int sumKV = 0;
    for (int i = 0; i < p.size(); ++i) {
        sumKV += pow(v[i], 2);
    }
    cout << sumKV << endl;
    //
    int sumSix = 0;
    for (int i = 0; i < 6; ++i) {
        sumSix += v[i];
    }
    cout << sumSix << endl;
    //
    int k1 = 0;
    int k2 = 0;
    int sumK = 0;
    cin >> k1 >> k2;
    for (int i = k1; i < k2 + 1; ++i) {
        sumK += v[i];
    }
    cout << sumK << endl;
    //
    int avarage = sum / p.size();
    cout << avarage << endl;
    //
    int s1 = 0;
    int s2 = 0;
    int avarageS1S2 = 0;
    cin >> s1 >> s2;
    for (int i = s1; i < s2 + 1; ++i) {
        avarageS1S2 += v[i];
    }
    avarageS1S2 = avarageS1S2 / (s2 - s1 + 1);
    cout << avarageS1S2 << endl;
    // 3
    vector<int> z = generate_random_vector<int>(20, -100, 50);
    int temp = 0;
    for (int i = 0; i < 3; ++i) {
        temp = z[i];
        z[i] = z[17 + i];
        z[17 + i] = temp;
    }
    // 4
    for (int i = 0; i < z.size(); ++i) {
        if (z[i] < 0) {
            z.erase(z.begin() + i);
            break;
        }
    }
    //
    int flag = 1;
    for (int i = 0; i < z.size(); ++i) {
        if ((z[i] % 2 == 0) && flag) {
            z.erase(z.begin() + i);
            flag = 0;
        }
    }
    // 5
    cout << "Enter sity name" << endl;
    string sityName = "";
    cin >> sityName;
    if (sityName.size() % 2 == 0) {
        cout << "Even number of characters" << endl;
    } else {
        cout << "Odd number of characters" << endl;
    }
    // 6
    cout << "Enter two surnames" << endl;
    string surName1 = "";
    string surName2 = "";
    cin >> surName1 >> surName2;
    if (surName1.size() > surName2.size()) {
        cout << surName1 << " is longer than " << surName2 << endl;
    } else if (surName1.size() == surName2.size()) {
        cout << surName1 << " is same length to " << surName2 << endl;
    } else {
        cout << surName1 << " is shorter than " << surName2 << endl;
    }
    // 7
    cout << "Enter 3 sity names" << endl;
    string sityName1 = "";
    string sityName2 = "";
    string sityName3 = "";
    cin >> sityName1 >> sityName2 >> sityName3;
    if ((sityName1.size() > sityName2.size()) && (sityName1.size() < sityName3.size())) {
        cout << "The shotrtest: " << sityName2 <<
        ", the longest: " << sityName3 << endl;
    } else if ((sityName2.size() > sityName1.size()) && (sityName2.size() < sityName3.size())) {
        cout << "The shotrtest: " << sityName1 <<
        ", the longest: " << sityName3 << endl;
    } else if ((sityName3.size() > sityName2.size()) && (sityName3.size() < sityName1.size())) {
        cout << "The shotrtest: " << sityName2 <<
        ", the longest: " << sityName1 << endl;
    } else if ((sityName1.size() > sityName3.size()) && (sityName1.size() < sityName2.size())) {
        cout << "The shotrtest: " << sityName3 <<
        ", the longest: " << sityName2 << endl;
    } else if ((sityName2.size() > sityName3.size()) && (sityName2.size() < sityName1.size())) {
        cout << "The shotrtest: " << sityName3 <<
        ", the longest: " << sityName1 << endl;
    } else if ((sityName3.size() > sityName1.size()) && (sityName3.size() < sityName2.size())) {
        cout << "The shotrtest: " << sityName1 <<
        ", the longest: " << sityName2 << endl;
    }
    // 8
    cout << "Enter a word" << std::endl;
    string word = "";
    cin >> word;
    cout << "Enter m and n" << endl;
    int m = 0;
    int n = 0;
    cin >> m >> n;
    while ((n > word.size()) || (m > word.size()) || (m > n)) {
        cout << "Error, enter m and n again" << endl;
        cin >> m >> n;
    }
    for (int i = m - 1; i < n; ++i) {
        cout << word[i];
    }
    // 9
    cout << "Enter a word" << endl;
    string word2 = "";
    cin >> word2;
    size_t iWordSize2 = word2.size();
    for (int i = 0; i < iWordSize2; ++i) {
        word2.push_back('*');
        word2.replace(0, 0, "*");
    }
    cout << word2;
    // 10
    cout << "Enter a word" << endl;
    string word3 = "";
    cin >> word3;
    double sumnumb = 0;
    for (int i = 0; i < word3.size(); ++i) {
        if (word3[i] == 'a') {
            ++sumnumb;
        }
    }
    cout << (sumnumb * 100) / word3.size() << "%" << endl;
    // 11
    string canString = "Can you can a can as a canner can can a can ?";
    cout << "Enter new word" << endl;;
    string newWord = "";
    cin >> newWord;
    while (canString.find(" can ") != string::npos) {
        size_t index = canString.find(" can ");
        canString.replace(index + 1, 3, newWord);
    }
    cout << canString;
    return 0;
}
