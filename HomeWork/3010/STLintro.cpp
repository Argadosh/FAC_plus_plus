// STLintro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <random>
#include <numeric>
#include <numbers>
#include <iomanip>
#include "STLintro.h"


using namespace std;

vector<string> get_terms_from_expression(const string& s) { return {}; }

int main()
{
    //��������� ����� vector
    // 
    //������ ������� ���������� ����������� ���������� ������ ��� �������� ����� ���������.
    //���� ������ ����� ������������� ����������������, ����� ��������� ��� ������ ��� ������� ����� ���������, 
    //��� ������������� ��������� ������ ������� � ����������� � ���� ���� ���������.
    //��� ������������ ������� ������ � ����� ������ ������� ���������, ������� ������� �� ������������������ ������ ���, 
    //����� ������� ����������� � ���������.

    //������ ����� ��������� ���������� ����� �������� ��������� �������������� ��������� ��� ���������� �����, 
    //� ����� ������� ��������� ����� ����� ����������� �������, ����������� ����� ���������, 
    //������ ����������� ��� ���������� ��� ���������(�.�.��� size()).
    //���������� ����� ������������� ��������� ��������� ����� ��� ������� ����� �������������� ������ � ������������������, 
    //�� � ����� ������ ����������������� ������ ����������� ������ ����� ��������������� �������� ��������� �������, 
    //����� ������� ��������� ��������� � ����� ������� ����� ���� ���������� 
    //� ���������������� ���������� ��������� ����������.

    //�������, �� ��������� � ���������, ������� ���������� ������ ������ � ����� �� ����������� ������������ ���������� 
    //��������� � ������������� �����.

    //�� ��������� � ������� ������������ ������������ �������������������(deques, lists � forward_lists), 
    //������� ����� ���������� ��� ������� � ����� ���������(��� � �������) � ������������ ���������� ��� 
    //���������� ��� �������� ��������� � �����.��� ��������, ��������� �� �������� ��� ��������� ��������� � �������, 
    //�������� �� �����, ��� �������� ����, ��� ������ ����������

    //1. �������� ������������

    //vector (size_type n, const value_type& val)
    vector<int> int_vec(15);
    vector<string> str_vec(10, "empty value");
    vector<vector<double>> dbl_matrix(10, vector<double>(20,-1.0)); //������� 10*20 �� -1

    //vector (InputIterator first, InputIterator last)
    vector<string> str_vec2(str_vec.begin() + 1, str_vec.begin() + 4);

    //vector (const vector& x)
    vector<vector<double>> dbl_matrix2(dbl_matrix);

    //vector (vector&& x)
    vector<string> terms(get_terms_from_expression("3.5*sin(x^ln(x-y/z))-2*exp(-1)"));

    //vector (initializer_list<value_type> il)
    vector<pair<int, string>> pairs_vec({ {1,"one"}, {2,"two"}, {3,"three"} });



    //2. ������ ��� ������ � ��������
    //��������� �������
    int_vec.size();

    //��������� �������
    int_vec.resize(20);
    //void resize (size_type n, const value_type& val)
    int_vec.resize(30, -1);

    //����������������� ���������� ���������
    int_vec.capacity();

    //�������� �� �������
    int_vec.empty();

    //�������������� ���������
    int_vec.reserve(100);



    //3. ������ � ���������
    int_vec[10]; //�� �������
   
    //int_vec.at(105); //�� ������� � ��������� ������ �� ������� �������
    pairs_vec.front(); //������ � ���������� ��������
    pairs_vec.back() = {2,""}; //������ � ���������� ��������

    //���������
    int_vec.begin();
    int_vec.end();

    int_vec.cbegin();
    int_vec.cend();

    int_vec.rbegin();
    int_vec.rend();



    //4. ������ ��� �����������
    //void assign (size_type n, const value_type& val);
    str_vec.assign(20, "new value");

    //void assign (initializer_list<value_type> il);
    str_vec.assign({"one", "two", "three"});

    str_vec.push_back("additional string");
    str_vec.pop_back();

    //iterator insert (const_iterator position, const value_type& val);
    str_vec.insert(str_vec.begin() + 2, "abracadabra");
    str_vec.insert(str_vec.begin() + 2, str_vec2.cbegin(), str_vec2.cend());

    //iterator erase (const_iterator position)
    str_vec.erase(str_vec.begin() + 5);

    str_vec.swap(str_vec2); //����� ���������� ��� �����������

    str_vec.clear(); //������� �������

    swap(str_vec, str_vec2);



    //������-���������
    //[ captures ] ( params ) lambda-specifiers requires(optional) { body }

    //������� (captures) - ��� ������ �� ���� ��� ����� ��������, ����������� ��������, 
    //�� ������ ������������ � ������� �� ���������. ������ capture ���������� ������� ����������, 
    //������� �������� �� ���� ������ - �������.
    //������������� ���������� �� ��������� ��������
    //    & (������� ������ ������������ ���������� �� ������) �
    //    = (������� ������ ������������ ���������� �� �����).

    //�������� ������ � �������� ���� ���������� �� ������ �� ������� ���������� � �������������� ������������� ����
    //[&](/*some parameters*/) {/*some code*/};
    //�������� ������ ��� �������
    //[](/*some parameters*/) {/*some code*/};

    //lambda-specifiers requires(optional)
    //[captures] (params) mutable throw() -> int { body }

    cout << "Lambda expression\n";
    int x = 2, y = 1;
    auto f = [&x, y](double z)mutable->int { x *= 2; y = y + 1;  cout << "x=" << x << " y=" << y << endl; return x * y / z; };
    cout << f(3.5); 
    cout << " x=" << x << " y=" << y << endl<<endl;



    //������������� ��������� STL 
    // #include <algorithm>
    // https://en.cppreference.com/w/cpp/algorithm
    // 
    //���������� ���������� ���������� ������� ��� ��������� �����(��������, �����, ����������, �������, ���������������), 
    //������� �������� � ����������� ���������. �������� ��������, ��� �������� ������������ ��� [first, last), 
    //��� last ���������� ������� ����� ���������� ��������, ������� ����� ��������� ��� ��������.

    //Non-modifying sequence operations

    // - �������� ������� ��� ���� ��������� ���������
    all_of(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2; }); //��� �� �������� ������� ��������
    any_of(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2; }); //���� �� ���� �� ���� �������� �������
    none_of(int_vec.begin(), int_vec.end(), [](auto x) {return x>=0 && x==pow((int)sqrt(x),2); }); //��� ����� �� ��������

    // - �������������� ��������� ��������� ���������
    cout << "Example for_each\n";
    int sumlengths = 0;
    for_each(str_vec.begin()+2, str_vec.end()-3, [&sumlengths](auto str) {sumlengths += str.length(); });
    cout << sumlengths << endl<<endl;

    // - ����� �������� ���������
    cout << "Example find\n";
    cout << find(int_vec.begin(), int_vec.end(), -1) - int_vec.begin() << endl;
    cout << find_if(int_vec.begin(), int_vec.end(), [](auto x) {return x < 0; }) - int_vec.begin() << endl;
    find_if_not(int_vec.begin(), int_vec.end(), [](auto x) {return x < 0; });
    vector<int> intsamples{ 2,3,4,5,2,3,4,0 };
    find_first_of(int_vec.begin(), int_vec.end(), intsamples.begin(), intsamples.end());
    
    //���� ������ ��������� ������������������ ��������� � ��������
    cout << search(intsamples.begin(), intsamples.end(), intsamples.begin() + 1, intsamples.begin() + 3) - intsamples.begin() << endl <<endl;

    //������� ���������
    count(int_vec.begin(), int_vec.end(), -1);
    count_if(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2 == 0; }); //������� ������ �����

    //Modifying sequence operations

    // - ����������� ���������
    cout << "Example copy: "<< str_vec2.size() << " ";
    copy(str_vec.begin(), str_vec.end(), back_inserter(str_vec2));
    cout << str_vec2.size() << endl << endl;

    copy_n(str_vec.begin(), 3, str_vec2.begin());
    copy_if(str_vec.begin(), str_vec.end(), back_inserter(str_vec2), [](const auto& x) {return x.length() % 2; });

    // - ��������� ���������
    vector<int> int_vec2;
    transform(int_vec.begin(), int_vec.end(), back_inserter(int_vec2), [](auto x) {return x * x; });
    transform(int_vec.begin(), int_vec.end(), int_vec.begin(), [](auto x) {return x * x; });
    replace(int_vec.begin(), int_vec.end(), 2, 7);
    replace_if(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2 == 0; }, 0);

    // - �������� ��������� ���������
    fill(int_vec.begin(), int_vec.begin() + 3, 10);
    fill_n(int_vec.begin()+3, 3, -10);
    generate(int_vec2.begin(), int_vec2.end(), [] {return rand(); });
    generate_n(int_vec2.begin(), int_vec2.size()/2, [] {return rand(); });

    // - �������� ��������� ����������
    cout << "Example remove\n";
    remove(int_vec.begin(), int_vec.end(), 10);
    for (auto x : int_vec) cout << x << " "; cout << endl <<endl;
    remove_if(int_vec.begin(), int_vec.end(), [](auto x) {return x < -1; });

    // - ������������ ���������
    std::random_device rd;
    std::mt19937 mtrand(rd());
    for (auto x : int_vec2) cout << x << " "; cout << endl;
    shuffle(int_vec2.begin(), int_vec2.end(), mtrand);
    for (auto x : int_vec2) cout << x << " "; cout << endl << endl;
    rotate(int_vec2.begin(), int_vec2.begin()+4, int_vec2.end());
    reverse(int_vec2.begin(), int_vec2.end());

    // - ���������� ���������
    sort(int_vec2.begin(), int_vec2.end()); //�� �������� <
    sort(int_vec2.begin(), int_vec2.end(),std::greater<int>()); //����������� � ������� ��������
    stable_sort(int_vec2.begin(), int_vec2.end());
    is_sorted(int_vec2.begin(), int_vec2.end()); //�������� �� ��������������� �� ��������� <

    //������������ �������� ���, ��� ����� �� int_vec.begin() + 3 �������� �� ������, 
    //� ������ �� ������, ��� *(int_vec.begin() + 3)
    nth_element(int_vec.begin(), int_vec.begin() + 3, int_vec.end());

    is_sorted_until(int_vec.begin(), int_vec.end());

    //Min/max ���������
    cout << "Minmax algorithms\n";
    cout << *min_element(int_vec2.begin(), int_vec2.end()) << endl;
    min({ 3453,243,2526 });
    max_element(int_vec2.begin(), int_vec2.end());
    auto mm = minmax({ 3453,243,2526 });
    cout << mm.first << " " << mm.second << endl << endl;

    //�������� ��������� ������ �� ��������������� ����������
    lower_bound(int_vec2.begin(), int_vec2.end(), 4); //�������� �� ������ ������� �� �������, ��� 4
    upper_bound(int_vec2.begin(), int_vec2.end(), 4); //�������� �� ������ ������� �������, ��� 4

    //��������� ���������
    // #include <numeric>
    // #include <numbers>

    cout << "Example numbers\n";
    cout << setprecision(16);
    cout << std::numbers::pi << " " << std::numbers::e <<" "<< std::numbers::sqrt2 << endl<<endl;

    //��������� ��������
    iota(int_vec.begin(), int_vec.end(), -5); //��������� �������� ����������������� ����������, ������� � -5
    cout << accumulate(int_vec.begin(), int_vec.end(), 0) << endl; //������� ����� � ���������, ������� � ��������� ���������� ��������
    inner_product(int_vec.begin(), int_vec.end(), int_vec.begin(), 0); //��������� ������������

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
