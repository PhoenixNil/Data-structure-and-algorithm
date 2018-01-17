List Merge(List L1, List L2)
{
  List p1, p2, p3, L, h;
  p1 = L1->Next;
  p2 = L2->Next;
  L = (List)malloc(sizeof(List));
  L->Next = NULL;
  h = L;
  while (p1 && p2)
  {
    if (p1->Data < p2->Data)
    {
      L->Next = p1;
      L = L->Next;
      p1 = p1->Next;
    }
    else
    {
      L->Next = p2;
      L = L->Next;
      p2 = p2->Next;
    }
  }
  while (p1)
  {
    L->Next = p1;
    L = L->Next;
    p1 = p1->Next;
  }
  while (p2)
  {
    L->Next = p2;
    p2 = p2->Next;
    L = L->Next;
  }
  L1->Next = NULL;
  L2->Next = NULL;
  return h;
}