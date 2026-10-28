#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

std::vector<int> separator(std::vector<int> v, std::function<bool(int)> predytak){
    std::vector<int> v2;
    for (int e : v) {
        if (predytak(e)) {
            v2.push_back(e);
        }
    }
    return v2;
}

int silnia_it(int n) {
    int wynik = 1;
    for(int i = 2; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

int silnia_rek(int n) {
    if(n == 0 || n == 1){
        return 1;
    }else{
        return n * silnia_rek(n - 1);
    }
}

void buzz_fuzz(int n, int b = 2, int f = 3){
    for(int i = 1; i <= n; i++){
        if(i % b == 0 && i % f == 0){
            std::cout << i << " BUZZ FUZZ" << std::endl;
        }else if(i % b == 0 && i % f != 0){
            std::cout << i << " BUZZ" << std::endl;
        }else if(i % b != 0 && i % f == 0){
            std::cout << i << " FUZZ" << std::endl;
        }else{
            std::cout << i << std::endl;
        }
    }
}

bool is_prime(int n){
    int b = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            b += 1;
        }
    }
    if(b == 2){
        return true;
    }else{
        return false;
    }
}

std::vector<int> intersection(std::vector<int> s1, std::vector<int> s2){
    std::vector<int> vec{};
    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                vec.push_back(s1[i]);
            }
        }
    }
    return vec;
}

int count_with_lib(std::vector<float> v, float x) {
    return std::count(v.begin(), v.end(), x);
}

int count_without_lib(std::vector<float> v, float x) {
    int licznik = 0;
    for (float element : v) {
        if (element == x) {
            licznik++;
        }
    }
    return licznik;
}

void square(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void rev_triangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int Bin2Dec(std::string s) {
    int wynik = 0;
    for (char c : s) {
        wynik = wynik * 2 + (c - '0');
    }
    return wynik;
}

std::string Dec2Bin(int n) {
    if (n == 0) return "0";
    std::string s = "";
    while (n > 0) {
        s = std::to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}

std::vector<std::string> sort_string_by_length(std::vector<std::string> v) {
    std::sort(v.begin(), v.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    return v;
}

std::string czas_pomiedzy(std::string t1, std::string t2) {
    int h1 = std::stoi(t1.substr(0, 2));
    int m1 = std::stoi(t1.substr(3, 2));
    int s1 = std::stoi(t1.substr(6, 2));

    int h2 = std::stoi(t2.substr(0, 2));
    int m2 = std::stoi(t2.substr(3, 2));
    int s2 = std::stoi(t2.substr(6, 2));

    int sekundy1 = h1 * 3600 + m1 * 60 + s1;
    int sekundy2 = h2 * 3600 + m2 * 60 + s2;
    int roznica = std::abs(sekundy2 - sekundy1);

    int h_res = roznica / 3600;
    int m_res = (roznica % 3600) / 60;
    int s_res = roznica % 60;

    auto formatuj = [](int x) {
        return (x < 10 ? "0" : "") + std::to_string(x);
    };

    return formatuj(h_res) + ":" + formatuj(m_res) + ":" + formatuj(s_res);
}

void dzien_roku_2022(int n) {
    if (n < 1 || n > 365) return;

    int dni_w_miesiacach[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string miesiace[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    std::string dni_tygodnia[] = {"sobota", "niedziela", "poniedziałek", "wtorek", "środa", "czwartek", "piątek"};

    int m_idx = 0;
    int temp_n = n;
    while (temp_n > dni_w_miesiacach[m_idx]) {
        temp_n -= dni_w_miesiacach[m_idx];
        m_idx++;
    }

    std::string dzien_str = (temp_n < 10 ? "0" : "") + std::to_string(temp_n);
    std::string data = "2022-" + miesiace[m_idx] + "-" + dzien_str;
    std::string dzien_tyg = dni_tygodnia[(n - 1) % 7];

    std::cout << data << " to " << dzien_tyg << std::endl;
}

double oblicz(std::string s) {
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    
    int i = 0;
    auto parsuj_skladnik = [&]() -> double {
        if (i < s.length() && s[i] == '(') {
            i++;
            int poziom = 1;
            std::string podwyrazenie = "";
            while (i < s.length()) {
                if (s[i] == '(') poziom++;
                if (s[i] == ')') poziom--;
                if (poziom == 0) {
                    i++;
                    break;
                }
                podwyrazenie += s[i];
                i++;
            }
            return oblicz(podwyrazenie);
        }
        
        std::string num = "";
        while (i < s.length() && (std::isdigit(s[i]) || s[i] == '.')) {
            num += s[i];
            i++;
        }
        return num.empty() ? 0.0 : std::stod(num);
    };

    double wynik = parsuj_skladnik();
    while (i < s.length()) {
        char op = s[i];
        i++;
        double nastepny = parsuj_skladnik();
        if (op == '+') wynik += nastepny;
        else if (op == '-') wynik -= nastepny;
        else if (op == '*') wynik *= nastepny;
        else if (op == '/') wynik /= nastepny;
    }
    return wynik;
}

int main(){
    return 0;
}