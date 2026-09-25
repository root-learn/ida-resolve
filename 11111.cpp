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


DWORD AMEM::orderNewList(MemList *newMemList)
{
  int tail;
  size_t actual_mem_size; // edi
  MemList *newMemList; // eax
  size_t diff_gap; // edx
  MemList *tail; // ecx
  signed int tail_i; // eax
  MemList **MemListHead; // ecx
  DWORD checkTailTraversalIndex; // eax

  tail_help = this->tail;
  if ( (signed int)this->heapSize >= tail_help )
  {
    if ( tail_help >= 0x10000 )
      logErrorAndExitProgram((int)"Too many items in AIList", 0, 0, (int)".\\IList.cpp", 162, 1);
    actual_mem_size = 8 * this->tail;
    MemList newMemList = (MemList*)MemList_addNewListMem(this->MemListHead, actual_mem_size);
    diff_gap = actual_mem_size - this->actualMemSize;
    tail = &newMemList[this->tail];
    this->MemListHead = *newMemList;
    memZeroSet(tail, diff_gap);
    this->tail *= 2;
    this->actualMemSize = actual_mem_size;
  }
  tail_i = this->tail;
  if ( (signed int)this->checkTailTraversalIndex >= tail_i )
    this->checkTailTraversalIndex = 0;
  MemListHead = this->MemListHead;
  while ( MemListHead[this->checkTailTraversalIndex] )
  {
    if ( (signed int)++this->checkTailTraversalIndex >= tail_i )
      this->checkTailTraversalIndex = 0;
  }
  checkTailTraversalIndex = this->checkTailTraversalIndex;
  ++this->heapSize;
  MemListHead[checkTailTraversalIndex] = newMemList;    // seem linked list is circular linkelist
  return this->checkTailTraversalIndex;
}