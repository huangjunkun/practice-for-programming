//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include "Unit1.h"

using namespace std;

ostream& operator << (ostream& os, const TServerKey& k)
{
    os << k.PublicKey.c_str() << endl
       << k.Modulus.c_str() << endl
       << k.PrivateKey.c_str() << endl;
    return  os;
}
istream& operator >> (istream& is, TServerKey& k)
{
    string  strTemp;
    is >> strTemp;
    k.PublicKey = strTemp.c_str();
    is >> strTemp;
    k.Modulus = strTemp.c_str();
    is >> strTemp;
    k.PrivateKey = strTemp.c_str();
    return  is;
}
DWORD WINAPI IdleShowTime(LPVOID lpParameter)
{
	//assert (false);
	return 0;
}
DWORD WINAPI MonitorKeyEAC(LPVOID lpParameter)
{
    bool*   lpESCDown = reinterpret_cast<bool*>(lpParameter);
    char    ch;
    do
    {
        ch = getch();
    }while(ch!=27);
    *lpESCDown = true;
    return 1;
}
// ---- test MostDerived<...>  ---------------------
class Widget
{
public:
    int value_;
    Widget(int value) : value_(value) {}
    operator int ()
    {
        return  value_;
    }
    // ....
};
class ScrollBar : public Widget
{
    //...
};
class Button : public Widget
{
    // ...
};
class GraphicButton : public Button
{
    //...
};

// ---- test GenScatterHierarchy<...> -----------------
template <class T>
struct Holder
{
    T   value_;
    Holder() :value_( T(100) ) {}
};   
//---------------------------------------------------------------------------
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
	for(T i=last-1;!bSorted&&i>=first; i--)//advance(i, -1)
    {
        bSorted = true;
		for(T j=first;j<i;j++)
			if(!comp(*j, *(j+1)) )
			{
				typename TypeTrait<T>::NoPtrResult temp = *j;
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
T   partition(T first, T last, Comp comp) //
{
    typename TypeTrait<T>::NoPtrResult temp = *first;
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
        T   pos = partition(first, last, comp);
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
        typename TypeTrait<T>::NoPtrResult temp = *i;
        for(T j=i+1;j<last;j++)
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
        for(T j=first;j<i;j++)
            if(!comp(*j, *i) )
            {
                typename TypeTrait<T>::NoPtrResult temp = *i;
                //or: copy_backward(j, last, j+1);//...<algotithm>
                for(T k=j;k<last;k++)
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
    for(;first1!=last1&&first2!=last2;result++)//first1++, first2++
        if(comp(*first1, *first2) )
            *result = *(first1++);
        else
            *result = *(first2++);
    /*  */
    if(first1==last1)
        for(;first2!=last2;)
            *result++ = *(first2++);// ...
    else//(first2==last2)
        for(;first1!=last1;)
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
        typedef typename TypeTrait<T>::NoPtrResult Type;
        T   pTemp = new Type[length];
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
        delete[]    pTemp;

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
    typedef typename TypeTrait<T>::NoPtrResult Type;
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
    typedef typename TypeTrait<T>::NoPtrResult Type;
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