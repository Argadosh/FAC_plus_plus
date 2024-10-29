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
    //Шаблонный класс vector
    // 
    //Внутри векторы используют динамически выделяемый массив для хранения своих элементов.
    //Этот массив может потребоваться перераспределить, чтобы увеличить его размер при вставке новых элементов, 
    //что подразумевает выделение нового массива и перемещение в него всех элементов.
    //Это относительно дорогая задача с точки зрения времени обработки, поэтому векторы не перераспределяются каждый раз, 
    //когда элемент добавляется в контейнер.

    //Вместо этого векторные контейнеры могут выделять некоторое дополнительное хранилище для возможного роста, 
    //и таким образом контейнер может иметь фактическую емкость, превышающую объем хранилища, 
    //строго необходимый для размещения его элементов(т.е.его size()).
    //Библиотеки могут реализовывать различные стратегии роста для баланса между использованием памяти и перераспределением, 
    //но в любом случае перераспределение должно происходить только через экспоненциально растущие интервалы размера, 
    //чтобы вставка отдельных элементов в конец вектора могла быть обеспечена 
    //с амортизированной постоянной временной сложностью.

    //Поэтому, по сравнению с массивами, векторы потребляют больше памяти в обмен на возможность эффективного управления 
    //хранением и динамического роста.

    //По сравнению с другими контейнерами динамических последовательностей(deques, lists и forward_lists), 
    //векторы очень эффективны при доступе к своим элементам(как и массивы) и относительно эффективны при 
    //добавлении или удалении элементов с конца.Для операций, связанных со вставкой или удалением элементов в позиции, 
    //отличной от конца, они работают хуже, чем другие контейнеры

    //1. Основные конструкторы

    //vector (size_type n, const value_type& val)
    vector<int> int_vec(15);
    vector<string> str_vec(10, "empty value");
    vector<vector<double>> dbl_matrix(10, vector<double>(20,-1.0)); //матрица 10*20 из -1

    //vector (InputIterator first, InputIterator last)
    vector<string> str_vec2(str_vec.begin() + 1, str_vec.begin() + 4);

    //vector (const vector& x)
    vector<vector<double>> dbl_matrix2(dbl_matrix);

    //vector (vector&& x)
    vector<string> terms(get_terms_from_expression("3.5*sin(x^ln(x-y/z))-2*exp(-1)"));

    //vector (initializer_list<value_type> il)
    vector<pair<int, string>> pairs_vec({ {1,"one"}, {2,"two"}, {3,"three"} });



    //2. Методы для работы с размером
    //получение размера
    int_vec.size();

    //изменение размера
    int_vec.resize(20);
    //void resize (size_type n, const value_type& val)
    int_vec.resize(30, -1);

    //зарезервированное количество элементов
    int_vec.capacity();

    //проверка на пустоту
    int_vec.empty();

    //резервирование элементов
    int_vec.reserve(100);



    //3. Доступ к элементам
    int_vec[10]; //по индексу
   
    //int_vec.at(105); //по индексу с проверкой выходы за пределы массива
    pairs_vec.front(); //доступ к начальному элементу
    pairs_vec.back() = {2,""}; //доступ к последнему элементу

    //Итераторы
    int_vec.begin();
    int_vec.end();

    int_vec.cbegin();
    int_vec.cend();

    int_vec.rbegin();
    int_vec.rend();



    //4. Методы для модификации
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

    str_vec.swap(str_vec2); //обмен содержимым без копирования

    str_vec.clear(); //очистка вектора

    swap(str_vec, str_vec2);



    //Ламбда-выражения
    //[ captures ] ( params ) lambda-specifiers requires(optional) { body }

    //Захваты (captures) - это список из нуля или более захватов, разделенных запятыми, 
    //по выбору начинающийся с захвата по умолчанию. Список capture определяет внешние переменные, 
    //которые доступны из тела лямбда - функции.
    //Единственными значениями по умолчанию являются
    //    & (неявный захват используемых переменных по ссылке) и
    //    = (неявный захват используемых переменных по копии).

    //типичная лямбда с захватом всех переменных по ссылке со списком параметров и автовыведением возвращаемого типа
    //[&](/*some parameters*/) {/*some code*/};
    //типичная лямбда без захвата
    //[](/*some parameters*/) {/*some code*/};

    //lambda-specifiers requires(optional)
    //[captures] (params) mutable throw() -> int { body }

    cout << "Lambda expression\n";
    int x = 2, y = 1;
    auto f = [&x, y](double z)mutable->int { x *= 2; y = y + 1;  cout << "x=" << x << " y=" << y << endl; return x * y / z; };
    cout << f(3.5); 
    cout << " x=" << x << " y=" << y << endl<<endl;



    //Универсальные алгоритмы STL 
    // #include <algorithm>
    // https://en.cppreference.com/w/cpp/algorithm
    // 
    //Библиотека алгоритмов определяет функции для различных целей(например, поиск, сортировка, подсчет, манипулирование), 
    //которые работают с диапазонами элементов. Обратите внимание, что диапазон определяется как [first, last), 
    //где last обозначает элемент после последнего элемента, который нужно проверить или изменить.

    //Non-modifying sequence operations

    // - Проверка условия для всех элементов диапазона
    all_of(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2; }); //все ли элементы вектора нечетные
    any_of(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2; }); //есть ли хотя бы один нечетный элемент
    none_of(int_vec.begin(), int_vec.end(), [](auto x) {return x>=0 && x==pow((int)sqrt(x),2); }); //все числа не квадраты

    // - Функциональная обработка элементов диапазона
    cout << "Example for_each\n";
    int sumlengths = 0;
    for_each(str_vec.begin()+2, str_vec.end()-3, [&sumlengths](auto str) {sumlengths += str.length(); });
    cout << sumlengths << endl<<endl;

    // - Поиск элемента диапазона
    cout << "Example find\n";
    cout << find(int_vec.begin(), int_vec.end(), -1) - int_vec.begin() << endl;
    cout << find_if(int_vec.begin(), int_vec.end(), [](auto x) {return x < 0; }) - int_vec.begin() << endl;
    find_if_not(int_vec.begin(), int_vec.end(), [](auto x) {return x < 0; });
    vector<int> intsamples{ 2,3,4,5,2,3,4,0 };
    find_first_of(int_vec.begin(), int_vec.end(), intsamples.begin(), intsamples.end());
    
    //Ищет первое вхождение последовательности элементов в диапазон
    cout << search(intsamples.begin(), intsamples.end(), intsamples.begin() + 1, intsamples.begin() + 3) - intsamples.begin() << endl <<endl;

    //Подсчёт элементов
    count(int_vec.begin(), int_vec.end(), -1);
    count_if(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2 == 0; }); //сколько четных чисел

    //Modifying sequence operations

    // - Копирование элементов
    cout << "Example copy: "<< str_vec2.size() << " ";
    copy(str_vec.begin(), str_vec.end(), back_inserter(str_vec2));
    cout << str_vec2.size() << endl << endl;

    copy_n(str_vec.begin(), 3, str_vec2.begin());
    copy_if(str_vec.begin(), str_vec.end(), back_inserter(str_vec2), [](const auto& x) {return x.length() % 2; });

    // - Изменение элементов
    vector<int> int_vec2;
    transform(int_vec.begin(), int_vec.end(), back_inserter(int_vec2), [](auto x) {return x * x; });
    transform(int_vec.begin(), int_vec.end(), int_vec.begin(), [](auto x) {return x * x; });
    replace(int_vec.begin(), int_vec.end(), 2, 7);
    replace_if(int_vec.begin(), int_vec.end(), [](auto x) {return x % 2 == 0; }, 0);

    // - Создание элементов диапазона
    fill(int_vec.begin(), int_vec.begin() + 3, 10);
    fill_n(int_vec.begin()+3, 3, -10);
    generate(int_vec2.begin(), int_vec2.end(), [] {return rand(); });
    generate_n(int_vec2.begin(), int_vec2.size()/2, [] {return rand(); });

    // - Удаление элементов контейнера
    cout << "Example remove\n";
    remove(int_vec.begin(), int_vec.end(), 10);
    for (auto x : int_vec) cout << x << " "; cout << endl <<endl;
    remove_if(int_vec.begin(), int_vec.end(), [](auto x) {return x < -1; });

    // - Перестановка элементов
    std::random_device rd;
    std::mt19937 mtrand(rd());
    for (auto x : int_vec2) cout << x << " "; cout << endl;
    shuffle(int_vec2.begin(), int_vec2.end(), mtrand);
    for (auto x : int_vec2) cout << x << " "; cout << endl << endl;
    rotate(int_vec2.begin(), int_vec2.begin()+4, int_vec2.end());
    reverse(int_vec2.begin(), int_vec2.end());

    // - Сортировка элементов
    sort(int_vec2.begin(), int_vec2.end()); //по операции <
    sort(int_vec2.begin(), int_vec2.end(),std::greater<int>()); //сортировать в порядке убывания
    stable_sort(int_vec2.begin(), int_vec2.end());
    is_sorted(int_vec2.begin(), int_vec2.end()); //проверка на упорядоченность по оператору <

    //переставляет элементы так, что слева от int_vec.begin() + 3 элементы не больше, 
    //а справа не меньше, чем *(int_vec.begin() + 3)
    nth_element(int_vec.begin(), int_vec.begin() + 3, int_vec.end());

    is_sorted_until(int_vec.begin(), int_vec.end());

    //Min/max алгоритмы
    cout << "Minmax algorithms\n";
    cout << *min_element(int_vec2.begin(), int_vec2.end()) << endl;
    min({ 3453,243,2526 });
    max_element(int_vec2.begin(), int_vec2.end());
    auto mm = minmax({ 3453,243,2526 });
    cout << mm.first << " " << mm.second << endl << endl;

    //Операции двоичного поиска на отсортированных диапазонах
    lower_bound(int_vec2.begin(), int_vec2.end(), 4); //итератор на первый элемент не меньший, чем 4
    upper_bound(int_vec2.begin(), int_vec2.end(), 4); //итератор на первый элемент больший, чем 4

    //Численные алгоритмы
    // #include <numeric>
    // #include <numbers>

    cout << "Example numbers\n";
    cout << setprecision(16);
    cout << std::numbers::pi << " " << std::numbers::e <<" "<< std::numbers::sqrt2 << endl<<endl;

    //Численные операции
    iota(int_vec.begin(), int_vec.end(), -5); //заполняет диапазон последовательными значениями, начиная с -5
    cout << accumulate(int_vec.begin(), int_vec.end(), 0) << endl; //считает сумму в диапазоне, начиная с заданного начального значения
    inner_product(int_vec.begin(), int_vec.end(), int_vec.begin(), 0); //скалярное произведение

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
