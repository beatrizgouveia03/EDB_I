#include <iostream>
#include <array>

#include "exercises.cpp"

int main()
{
    std::array<value_type, 9> v = {10, 8, 6, 4, 3, 5, 7, 9, 7};
    std::array<value_type, 9> v2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::array<value_type, 9> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<value_type, 9> v4 = {8, 2, 2, 6, 5, 4, 7, 1, 9};
    value_type **m1 = new int *[4];
    value_type **m2 = new int *[4];
    value_type **m3 = new int *[4];
    value_type base1[4][4] = {{1, 1, 1, 1}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};
    value_type base2[4][4] = {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
    value_type base3[4][4] = {{1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

    for (int i = 0; i < 4; ++i)
    {
        m1[i] = new int[4];
        m2[i] = new int[4];
        m3[i] = new int[4];
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m1[i][j] = base1[i][j];
            m2[i][j] = base2[i][j];
            m3[i][j] = base3[i][j];
        }
    }

    std::cout << "\nTesting local_minimum_in_an_array algorithm...\n";

    //=== Test #1
    auto result = local_minimum_in_an_array(begin(v), end(v));

    if (result == end(v))
    {
        std::cout << "No local minimum found\n";
    }
    else
    {
        std::cout << "Local minimum found at index " << result - begin(v) << " with value " << *result << std::endl;
    }

    //=== Test #2
    auto result2 = local_minimum_in_an_array(begin(v2), end(v2));

    if (result2 == end(v2))
    {
        std::cout << "No local minimum found\n";
    }
    else
    {
        std::cout << "Local minimum found at index " << result2 - begin(v2) << " with value " << *result2 << std::endl;
    }

    //=== Test #3
    auto result3 = local_minimum_in_an_array(begin(v3), end(v3));

    if (result3 >= end(v3))
    {
        std::cout << "No local minimum found\n";
    }
    else
    {
        std::cout << "Local minimum found at index " << result3 - begin(v3) << " with value " << *result3 << std::endl;
    }

    ////
    ////

    std::cout << "\nTesting find_a_duplicate algorithm...\n";

    //=== Test #4
    auto result4 = find_a_duplicate(begin(v3), end(v3));

    if (result4){
        std::cout << " There are duplicates in the array.\n ";
    } else {
        std::cout << "There are no duplicates in the array.\n";
    }

    //=== Test #5
    auto result5 = find_a_duplicate(begin(v4), end(v4));

    if (result5)
    {
        std::cout << "There are duplicates in the array.\n ";
    }
    else
    {
        std::cout << "There are no duplicates in the array.\n";
    }

    ////
    ////

    std::cout << "\nTesting longest_row_of_zeros algorithm...\n";

    //=== Test #6
    auto result6 = longest_row_of_zeros(m1, 4, 4);

    if (result6.first == -1)
    {
        std::cout << "No longest row of zeros found\n";
    }
    else
    {
        std::cout << "Longest row of zeros found at index " << result6.first << " with value " << result6.second << std::endl;
    }

    //=== Test #7
    auto result7 = longest_row_of_zeros(m2, 4, 4);

    if (result7.first == -1)
    {
        std::cout << "No longest row of zeros found\n";
    }
    else
    {
        std::cout << "Longest row of zeros found at index " << result7.first << " with value " << result7.second << std::endl;
    }

    //=== Test #8
    auto result8 = longest_row_of_zeros(m3, 4, 4);

    if (result8.first == -1)
    {
        std::cout << "No longest row of zeros found\n";
    }
    else
    {
        std::cout << "Longest row of zeros found at index " << result8.first << " with value " << result8.second << std::endl;
    }

    ////
    ////

    std::cout << "\nTesting sum_of_two algorithm...\n";

    //=== Test #9
    auto result9 = sum_of_two(begin(v), end(v), begin(v2), end(v2));

    if (result9.second == end(v2))
    {
        std::cout << "No sum in the array A found in the array B\n";
    }
    else
    {
        std::cout << "Sum in the array A at index " << result9.first.first - begin(v) << " and " << result9.first.second - begin(v) << " found in the array B at index " << result9.second - begin(v2) << std::endl;
    }

    //=== Test #10
    auto result10 = sum_of_two(begin(v), end(v), begin(v3), end(v3));

    if (result10.second == end(v3))
    {
        std::cout << "No sum in the array A found in the array B\n";
    }
    else
    {
        std::cout << "Sum in the array A at index " << result10.first.first - begin(v) << " and " << result10.first.second - begin(v) << " found in the array B at index " << result10.second - begin(v3) << std::endl;
    }

    //=== Test #11
    auto result11 = sum_of_two(begin(v2), end(v2), begin(v3), end(v3));

    if (result11.second == end(v3))
    {
        std::cout << "No sum in the array A found in the array B\n";
    }
    else
    {
        std::cout << "Sum in the array A at index " << result11.first.first - begin(v2) << " and " << result11.first.second - begin(v2) << " found in the array B at index " << result11.second - begin(v3) << std::endl;
    }

    ////
    ////

    std::cout << "\nTesting find_the_duplicate algorithm...\n";

    //=== Test #12
    std::sort(begin(v), end(v));
    auto result12 = find_the_duplicate(begin(v), end(v));

    if (result12.second == end(v))
    {
        std::cout << "No duplicate found in the array\n";
    }
    else
    {
        std::cout << "Duplicate found at index " << result12.first - begin(v) << " and " << result12.second - begin(v) << std::endl;
    }

    //=== Test #13
    std::sort(begin(v2), end(v2));
    auto result13 = find_the_duplicate(begin(v2), end(v2));

    if (result13.second == end(v2))
    {
        std::cout << "No duplicate found in the array\n";
    }
    else
    {
        std::cout << "Duplicate found at index " << result13.first - begin(v2) << " and " << result13.second - begin(v2) << std::endl;
    }

    //=== Test #14
    std::sort(begin(v3), end(v3));
    auto result14 = find_the_duplicate(begin(v3), end(v3));

    if (result14.second == end(v3))
    {
        std::cout << "No duplicate found in the array\n";
    }
    else
    {
        std::cout << "Duplicate found at index " << result14.first - begin(v3) << " and " << result14.second - begin(v3) << std::endl;
    }

    return 0;
}