#include <iostream>
#include <algorithm>

using value_type = int;

value_type *local_minimum_in_an_array(value_type *begin, value_type *end)
{
    value_type *aux = end;

    while (begin != aux)
    {
        value_type *mid = begin + (aux - begin) / 2;

        if (mid != begin && *mid >= *(mid - 1))
        {
            aux = mid - 1;
        }
        else if (mid != aux - 1 && *mid >= *(mid + 1))
        {
            begin = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return end;
}

bool find_a_duplicate(value_type *begin, value_type *end){
    while(begin != end){
        int idx = abs(*begin) - 1;

        if(*(begin+idx) < 0){
            return true;
        }

        *(begin+idx) = -*(begin+idx);
        begin++;
    }

    return false;
}

std::pair<value_type, value_type> longest_row_of_zeros(value_type **matrix, int rows, int cols)
{
    int row_with_most_zeros = -1;
    int max_zeros = 0;

    for (int i = 0; i < rows; ++i)
    {
        value_type zeros_in_the_row = std::count(&matrix[i][0], &matrix[i][cols], 0);
        if (zeros_in_the_row > max_zeros)
        {
            max_zeros = zeros_in_the_row;
            row_with_most_zeros = i;
        }
        else if (zeros_in_the_row == max_zeros)
        {
            row_with_most_zeros = -1;
        }
    }

    std::pair<value_type, value_type> result = std::make_pair(row_with_most_zeros, max_zeros);

    return result;
}

std::pair<std::pair<value_type *, value_type *>, value_type *> sum_of_two(value_type *beginA, value_type *endA, value_type *beginB, value_type *endB)
{
    value_type *aux = beginA;

    while (aux != endA - 1)
    {
        for (auto it = aux + 1; it != endA; ++it)
        {
            value_type sum = *aux + *it;
            for (auto it2 = beginB; it2 != endB; ++it2)
            {
                if (*it2 == sum)
                {
                    return std::make_pair(std::make_pair(aux, it), it2);
                }
            }
        }

        aux++;
    }

    return std::make_pair(std::make_pair(endA, endA), endB);
}

std::pair<value_type *, value_type *> find_the_duplicate(value_type *begin, value_type *end)
{
    value_type *aux = begin;

    while (aux != end - 1)
    {
        value_type *low = std::lower_bound(begin, end, *aux);
        value_type *upper = std::upper_bound(begin, end, *aux);

        if (low != upper-1 && (upper != end || *(upper-1) == *aux))
        {
             return std::make_pair(low, low+1);
        }

        aux++;
    }

    return std::make_pair(end, end);
}