
template < class T > struct BiList
{
  T val;
  BiList< T > *next;
  BiList< T > *prev;
};

template < class T > BiList< T > *add(BiList< T > *h, const T &d);

template < class T > BiList< T > *insert(BiList< T > *h, const T &d);

template < class T > BiList< T > *add(BiList< T > *h, const T &d);

template < class T > BiList< T > *insert(BiList< T > *h, const T &d);

template < class T > BiList< T > *cut(BiList< T > *h);

template < class T > BiList< T > *erase(BiList< T > *h);

template < class T > BiList< T > *clear(BiList< T > *h);

template < class T > BiList< T > *clear(BiList< T > *h, BiList< T > *e);

template < class T, class F > F traverse_from_head(F f, BiList< T > *h, BiList< T > *e);

template < class T, class F > F traverse_from_tail(F f, BiList< T > *h, BiList< T > *e);

int main()
{}
