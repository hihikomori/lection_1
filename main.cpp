
template < class T > struct BiList
{
  T val;
  BiList< T > *next;
  BiList< T > *prev;
};

// /new/ -> h -> h.next
// h.prev-> ↑
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
  BiList< T > *head = new BiList< T >{d, h ? h->prev : nullptr, h};

  if (h->next) {
    head->next->prev = head;
  }
  h->next = head;

  return head;
}

template < class T > BiList< T > *cut(BiList< T > *h) noexcept
{
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
  while (h != e) {
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

template < class T > BiList< T > *ToListConverter(T *array);

int main()
{}
