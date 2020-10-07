
/*
 * OrderAl.h
 *
 *  Created on: 1 sep. 2020
 *      Author: luisd
 */

#ifndef ORDERAL_H_
#define ORDERAL_H_
#include <vector>
#include <iostream>

template <class T>
class OrderAl {
public:
    static std::vector<T> bubble(std::vector<T>, bool(*)(T,T));
    static std::vector<T> insersion(std::vector<T>, bool(*)(T,T));

    static std::vector<T> selection(std::vector<T>, bool(*)(T,T));
    static std::vector<T> quickSort(std::vector <T>,int,int,bool(*)(T,T));
    static std::vector<T> mergesort(std::vector<T>, int, int, bool(*)(T,T));

    static bool asc(T,T);
    static bool desc(T,T);


private:
    static std::vector<T> merge(std::vector<T>, int, int, int, bool (*) (T, T));

};



template <class T>
bool OrderAl<T>::asc(T a, T b)
{
    return a < b;
}

template <class T>
bool OrderAl<T>::desc(T a, T b)
{
    return a > b;
}

template <class T>
std::vector<T> OrderAl<T>::bubble(std::vector<T> e, bool compare (T,T))
{
    int n = (int) e.size();

    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; --j) {
            if ( compare(e[j], e[j-1]) ) {
                std::swap(e[j], e[j-1]);
            }
        }
    }

    return e;
}







template <class T>
std::vector<T> OrderAl<T>::insersion(std::vector<T> e, bool compare (T,T))
{
    T index;

    int n = (int) e.size();

    for (int i = 1; i < n; i++)
    {
        index = e[i];

        int j = i-1;

        while ( j >= 0 && compare(index, e[j]) )
        {
            e[j + 1] = e[j];
            j--;
        }

        e[j+1] = index;
    }

    return e;
}


template <class T>
std::vector<T> OrderAl<T>::selection

(std::vector<T> e, bool compara (T,T))
{
    int minimo = 0;

    int n = (int) e.size();

    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if ( compara(e[j], e[minimo]) )
                minimo = j;
        }
        std::swap(e[minimo], e[i]);
    }

    return e;
}





template <class T>
std::vector<T> OrderAl<T>::quickSort(std::vector<T> e, int first, int last, bool compare (T, T))
{
    int left = first;
    int right = last;

    T piv = e[first];

    if ( first < last)
    {
        while ( left < right)
        {
            while ( (left < right) && !compare(piv, e[left])) left++; // <=
            while ( compare(piv, e[right]) ) right--; // >

            if ( left < right)
            {
                std::swap(e[left], e[right]);
            }
        }

        std::swap(e[first], e[right]);

        e = quickSort ( e, first, right-1, compare);
        e = quickSort ( e, left, last, compare);
    }

    return e;
}




template <class T>
std::vector<T> OrderAl<T>::mergesort(std::vector<T> e, int l, int n, bool compare (T, T))
{
    int m = (n + l) / 2;

    if (n > l)
    {
        e = mergesort (e, l, m, compare);
        e = mergesort (e, m+1, n, compare);
        e = merge (e, l, m, n, compare);
    }

    return e;
}

template <class T>
std::vector<T> OrderAl<T>::merge(std::vector<T> e, int l, int m, int n, bool compare (T, T))
{
    int i, j, k;

    /* Definir un vector auxiliar */
    std::vector<T> aux(e.size());

    /* Copiar elementos al vector auxiliar */
    for(i=m+1;i>l;i--)
        aux[i-1] = e[i-1];

    for (j=m; j<n; j++)
        aux[n+m-j] = e[j+1];

    /* Proceso de mezcla en el orden especificado */
    for(k=l;k<=n;k++)
        if (compare(aux[i], aux[j])) // <
            e[k] = aux[i++];
        else
            e[k] = aux[j--];

    return e;
}




#endif /* ORDERAL_H_ */
