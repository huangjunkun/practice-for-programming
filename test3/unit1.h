//---------------------------------------------------------------------------

#ifndef _UNIT1_H_
#define _UNIT1_H_
//---------------------------------------------------------------------------
#include <Windows.h>
#include <string>
#include <iterator>
#include <iostream>
//using namespace std;

typedef struct TServerKey
{
    std::string  Modulus;
    std::string  PublicKey;
    std::string  PrivateKey;
} TServerKey;

std::ostream& operator << (std::ostream& os, const TServerKey& k);
std::istream& operator >> (std::istream& is, TServerKey& k);

typedef int(*MyFun1)(int arg1,int arg2,int arg3,int arg4);
DWORD WINAPI IdleShowTime(LPVOID lpParameter);
DWORD WINAPI MonitorKeyEAC(LPVOID lpParameter);



template <class T>
struct	TypeTrait
{
    typedef	T	NoPtrResult;
};
template <class T>
struct TypeTrait<T*>
{
    typedef	T	NoPtrResult;
};
template <typename T, class Comp >  //=less<T>
bool    bubbleSort(T first, T last, Comp) //
{
    Comp    comp;
    if(distance(first, last)<1)
        return false;
    //std::size_t k = 0;
    bool    bSorted = false;
    for(T i=last-1; !bSorted&&i>=first; i--) //advance(i, -1)
    {
        bSorted = true;
        for(T j=first; j<i; j++)
            if(!comp(*j, *(j+1)) )
            {
                typename std::iterator_traits<T>::value_type temp = *j;
                *j = *(j+1);
                *(j+1) = temp;
                bSorted = false;
                //cout << *j << " " <<*(j+1) << "----\n";
            }
    }
    return true;
}
template <typename T,
class Comp >  //=less<T>
T   _partition(T first, T last, Comp comp) //
{
    typename std::iterator_traits<T>::value_type temp = *first;
    --last;
    while(first<last)
    {
        while(first<last&&!comp(*last, temp) )
            last--;
        *first = *last;
        while(first<last&&comp(*first, temp) )
            first++;
        *last = *first;
    }
    *first = temp;
    return  first;
}
template <typename T, class Comp >  //=less<T>
void quickSort(T first, T last, Comp comp) //
{
    if(first<last)
    {
        T   pos = _partition(first, last, comp);
        quickSort(first, pos, comp);
        quickSort(pos+1, last, comp);
    }
}
template <typename T, class Comp >  //=less<T>
bool    selectSort(T first, T last, Comp comp) //
{
    if(distance(first, last)<1)
        return false;

    for(T i=first; i<last-1; i++)//
    {
        T       pTemp = i;
        typename std::iterator_traits<T>::value_type temp = *i;
        for(T j=i+1; j<last; j++)
            if(!comp(temp, *j) )
            {
                pTemp = j;
                temp = *j;
            }
        if(pTemp!=i)
        {
            *pTemp = *i;
            *i = temp;
        }
    }
    return true;
}
template <typename T, class Comp >  //=less<T>
bool    insertSort(T first, T last, Comp comp) //
{
    if(distance(first, last)<1)
        return false;

    for(T i=first+1; i<last; i++)//
    {
        for(T j=first; j<i; j++)
            if(!comp(*j, *i) )
            {
                typename std::iterator_traits<T>::value_type temp = *i;
                //or: copy_backward(j, last, j+1);//...<algotithm>
                for(T k=j; k<last; k++)
                    *(j+1) = *j;
                *j = temp;
            }
    }
    return true;
}

template <typename T, class Comp >  //=less<T>
void    Merge(T first1, T last1, T first2, T last2,
              T result, Comp comp) //
{
    for(; first1!=last1&&first2!=last2; result++) //first1++, first2++
        if(comp(*first1, *first2) )
            *result = *(first1++);
        else
            *result = *(first2++);
    /*  */
    if(first1==last1)
        for(; first2!=last2;)
            *result++ = *(first2++);// ...
    else//(first2==last2)
        for(; first1!=last1;)
            *result++ = *(first1++);// ...
    //or ....
    copy(first2, last2, copy(first1, last1, result) );

}
// ....
template <typename T, class Comp >  //=less<T>
void    MSort(T first, T last, T result, Comp comp) //
{
    if(first==last-1)
        *result = *first; // ...
    else
    {
        std::size_t length = distance(first, last);
        typedef typename std::iterator_traits<T>::value_type value_type;
        T   pTemp = new value_type[length];
        T   mid = first+length/2;

        MSort(first, mid, pTemp, comp);
        MSort(mid, last, pTemp+length/2, comp);
        Merge(pTemp, pTemp+length/2, pTemp+length/2, pTemp+length,  \
              result, comp);
        /*
            copy(pTemp, pTemp+length/2, ostream_iterator<int>(cout, " ") );
            cout << "---- " ;
            copy(pTemp+length/2, pTemp+length, ostream_iterator<int>(cout, " ") );
            cout << "\n ************************************************\n";
            copy(result, result+length, ostream_iterator<int>(cout, " ") );
            cout << "\n ************************************************\n";
        */
        delete[] &pTemp;

    }
}
template <typename T, class Comp >  //=less<T>
bool    mergeSort(T first, T last, Comp comp) //
{
    if(distance(first, last)<1)
        return false;
    MSort(first, last, first, comp);

    return true;
}
// .................
template <typename T, class Comp >  //=less<T>
bool    heapAdjust(T first, T last, typename std::size_t index, Comp comp) //
{
    typedef typename std::iterator_traits<T>::value_type Type;
    Type    temp = *first;
    T   pTemp = first;
    //std::size_t length = distance(first, last);
    index=(2*index)+1;
    for(T i=first+index; i<last; \
            index=(2*index)+1, i=first+index )
    {
        if(i<last-1&& *i<*(i+1))    i++;
        if(comp(*i, temp) )    break;
        *pTemp = *i;
        pTemp = i;
    }
    *pTemp = *first;
    return true;
}
template <typename T, class Comp >  //=less<T>
bool    heapSort(T first, T last, Comp comp) //
{
    if(distance(first, last)<1)
        return false;
    typedef typename std::size_t size_t;
    std::size_t  length = distance(first, last);
    std::size_t  j=length/2;
    for(T i=first+length/2; i>=first; i--, j-- )
        heapAdjust(i, last, j, comp);  //建大顶堆
    typedef typename std::iterator_traits<T>::value_type Type;
    for(T i=first+length-1; i>first; i--)
    {
        Type    temp;
        temp = *first;
        *first = *i;
        *i = temp;
        heapAdjust(first, i,  1, comp);//重新建大顶堆
    }

    return true;
}
template <typename T, class Comp >  //=less<T>
bool    shellSort(T first, T last, Comp comp) //
{
    if(distance(first, last)<0)
        return false;

    return true;
}

//---------------------------------------------------------------------------
#endif
