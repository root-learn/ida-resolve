// a2 can be UnkClass7 or IList
BMap *__thiscall BMapList_3BCA1A0_func2(BMapList *this, BMap *a2)
{
  signed int AVailableEntry; // eax
  BMap *v4; // edi

  AVailableEntry = BMapList_getAVailableEntry(this);
  if ( AVailableEntry < 0 )
    return 0;
  v4 = &this->BMapListArr[4 * AVailableEntry];
  sub_1ACB6A0(v4, a2);
  ++this->nextIndex;
  BMap_setHead(&this->BMap_self, v4);
  dword_50C1D08 += 2;
  this->BMapNext = (dword_50C1D08 | 1);
  return a2;
}

BMap **__thiscall BMap_setHead(BMap *this, BMap *a2)
{
  BMap ***p_BMapNext; // eax
  bool v3; // zf

  p_BMapNext = &this->BMapNext;
  if ( this->BMapNext )
  {
    do
    {
      this = *p_BMapNext;
      v3 = (*p_BMapNext)[1] == 0;
      p_BMapNext = (*p_BMapNext + 1);
    }
    while ( !v3 );
  }
  this->BMapNext = a2;
  a2->BMapPrev = this;
  a2->vftable = this->vftable;
  return a2;
}