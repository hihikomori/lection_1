#include <cstddef>
#include <iostream>

struct funcPod
{
  void operator()(int val) const
  {
    std::cout << val << '\t';
  }
};

template < class T > struct BiList
{
  T val;
  BiList< T > *next;
  BiList< T > *prev;
};

template < class T > BiList< T > *add(BiList< T > *h, const T &d)
{
  BiList< T > *head = new BiList< T >{d, h, h ? h->prev : nullptr};

  if (head->prev) {
    head->prev->next = head;
  }

  if (head->next) {
    head->next->prev = head;
  }
  return head;
}

template < class T > BiList< T > *insert(BiList< T > *h, const T &d)
{
  if (!h) {
    return nullptr;
  }

  BiList< T > *head = new BiList< T >{d, h->next, h};

  if (h->next) {
    head->next->prev = head;
  }
  h->next = head;

  return head;
}

template < class T > BiList< T > *cut(BiList< T > *h) noexcept
{
  if (!h) {
    return nullptr;
  }

  BiList< T > *prev = h->prev;
  BiList< T > *next = h->next;

  if (prev) {
    prev->next = next;
  }

  if (next) {
    next->prev = prev;
  }

  delete h;

  return next;
}

template < class T > BiList< T > *erase(BiList< T > *h) noexcept
{
  if (!h || !h->next) {
    return nullptr;
  }

  cut(h->next);

  return h;
}

template < class T > BiList< T > *clear(BiList< T > *h, BiList< T > *e) noexcept
{
  while (h != nullptr && h != e) {
    h = cut(h);
  }
  return h;
}

template < class T, class F > F traverse_from_head(F f, BiList< T > *h, BiList< T > *e)
{
  while (h != nullptr && h != e) {
    f(h->val);
    h = h->next;
  }
  return f;
}

template < class T, class F > F traverse_from_tail(F f, BiList< T > *t, BiList< T > *e)
{
  while (t != nullptr && t != e) {
    f(t->val);
    t = t->prev;
  }

  return f;
}

template < class T > BiList< T > *ToListConverter(const T *array, size_t s)
{
  if (!array || !s) {
    return nullptr;
  }

  BiList< T > *head = add(static_cast< BiList< int > * >(nullptr), array[0]);
  BiList< T > *list = head;
  for (size_t i = 1; i < s; ++i) {
    list = insert(list, array[i]);
  }

  return head;
}

int main()
{
  int arr[] = {5, 2, 3, 1, 4};
  BiList< int > *list = ToListConverter(arr, 5);

  traverse_from_head(funcPod{}, list, static_cast< BiList< int > * >(nullptr));
  std::cout << "\n";

  list = clear(list, static_cast< BiList< int > * >(nullptr));
}
