
class AMem : public UnkClass1
{
  DWORD heapSize;
  DWORD tail;
  DWORD actualMemSize;
  MemList **MemListHead;
  DWORD checkTailTraversalIndex;
  DWORD getActiveMemListRegion;
  BYTE unk_1;
  BYTE unk2;
  BYTE gap_2[2];
};


DWORD __thiscall AMem_orderNewList(AMem *this, MemList *a2)
{
  signed int tail; // eax
  size_t v4; // edi
  unsigned int *v5; // eax
  size_t v6; // edx
  unsigned int *v7; // ecx
  signed int v8; // eax
  MemList **MemListHead; // ecx
  DWORD checkTailTraversalIndex; // eax

  tail = this->tail;
  if ( (signed int)this->heapSize >= tail )
  {
    if ( tail >= 0x10000 )
      logErrorAndExitProgram((int)"Too many items in AIList", 0, 0, (int)".\\IList.cpp", 162, 1);
    v4 = 8 * this->tail;
    v5 = MemList_addNewListMem(this->MemListHead, v4);
    v6 = v4 - this->actualMemSize;
    v7 = &v5[this->tail];
    this->MemListHead = (MemList **)v5;
    memZeroSet(v7, v6);
    this->tail *= 2;
    this->actualMemSize = v4;
  }
  v8 = this->tail;
  if ( (signed int)this->checkTailTraversalIndex >= v8 )
    this->checkTailTraversalIndex = 0;
  MemListHead = this->MemListHead;
  while ( MemListHead[this->checkTailTraversalIndex] )
  {
    if ( (signed int)++this->checkTailTraversalIndex >= v8 )
      this->checkTailTraversalIndex = 0;
  }
  checkTailTraversalIndex = this->checkTailTraversalIndex;
  ++this->heapSize;
  MemListHead[checkTailTraversalIndex] = a2;    // seem linked list is circular linkelist
  return this->checkTailTraversalIndex;
}
