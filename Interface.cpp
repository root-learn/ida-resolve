00000000 struct __cppobj UnkClass6 : UnkClass3 // sizeof=0x50
00000000 {                                       // XREF: UnkClass7.baseclass_0/r
00000020     BYTE gap_8_1[8];
00000028     BYTE gap_36[36];
0000004C     BYTE unk_6;
0000004D     BYTE gap_2[3];
00000050 };

00000000 struct __cppobj UnkClass7 : UnkClass6 // sizeof=0xA8
00000000 {
00000050     BYTE gap_36[32];
00000070     DWORD *unk_7;
00000074     BYTE gap_4_4[4];
00000078     BYTE unk_8;
00000079     BYTE unk_9;
0000007A     BYTE gap_7[10];
00000084     float unk_10;
00000088     float unk_11;
0000008C     BYTE gap_26[28];
000000A8 };

00000000 struct __cppobj UnkClass3 // sizeof=0x20
00000000 {                                       // XREF: IList.baseclass_0/r
00000000                                         // UnkClass4.baseclass_0/r ...
00000000     void *vftable;
00000004     DWORD *unk_1;
00000008     WORD AccessMode;
0000000A     WORD unk_3;
0000000C     WORD newIndexList;
0000000E     WORD unk_4;
00000010     DWORD unk_5;
00000014     BYTE gap_8[4];
00000018     AFile *AFileBasedPath;
0000001C     UnkClass3 *self;
00000020 };

00000000 struct __cppobj Mem : IList // sizeof=0x64
00000000 {                                       // XREF: sub_3BA8340/r
00000000                                         // sub_3BA7C70/r
00000058     DWORD dirListIndex;
0000005C     AFile *dirName;
00000060     BYTE finishOperation;
00000061     BYTE gap_3[3];
00000064 };

00000000 struct __cppobj IList : UnkClass3 // sizeof=0x58
00000000 {                                       // XREF: Mem.baseclass_0/r
00000020     WORD virtualMemAccessMode;
00000022     WORD errLevel;
00000024     LONG spinDest;
00000028     DWORD roofUnkClass5Index;
0000002C     DWORD **unkClass5;
00000030     HANDLE *hFile;
00000034     DWORD floorUnkClass5Index;
00000038     DWORD bufferSize;
0000003C     DWORD elapsedTime;
00000040     BYTE gap_14[8];
00000048     DWORD unk_11;
0000004C     WORD unk_12;
0000004E     WORD unkClass5Size;
00000050     DWORD ***headUnkClass5;
00000054     void *unk_14_func1;
00000058 };

00000000 struct __cppobj AMem : UnkClass1 // sizeof=0x2C
00000000 {                                       // XREF: .data:AMem_50C0E78/r
00000010     DWORD heapSize;
00000014     DWORD tail;                         // XREF: sub_3BA4BB0+4DB/w
00000018     DWORD actualMemSize;                // XREF: heapCompactAndRetry+3/r
00000018                                         // heapCompactAndRetry+20/w ...
0000001C     Mem **MemListHead;                  // XREF: IList_3BA6960_func1+7E/r
0000001C                                         // IList_3BA6960_func1+AC/w ...
00000020     DWORD checkTailTraversalIndex;
00000024     DWORD getActiveMemListRegion;
00000028     BYTE unk_5;
00000029     BYTE unk6;
0000002A     BYTE gap_2[2];
0000002C };

UnkClass6 *__thiscall UnkClass6_19FDB20_ctor(UnkClass6 *this)
{
  UnkClass3_3BC9410_ctor(this);
  this->vftable = &UnkClass6_4230C50::vftable;
  memZeroSet(this->gap_36, 0x40u);
  *&this->unk_6 = 9;
  return this;
}

UnkClass7 *__thiscall UnClass7_404570_ctor(UnkClass7 *this)
{
  UnkClass6_19FDB20_ctor(this);
  this->vftable = &UnkClass7_4218D68::vftable;
  memZeroSet(&this->gap_36[24], 0x40u);
  this->unk_7 = 8;
  this->unk_9 = 1;
  this->unk_8 = 1;
  UnkClass7_makeFilePath(this, "Image");
  this->unk_10 = 1.0;
  this->unk_11 = 1.0;
  return this;
}

UINT __thiscall IList_3BA6960_func1(IList *this, char *a2, char a3, _DWORD *a4, int a5)
{
  unsigned int *v6; // eax
  Mem *v7; // ebp
  int DirNameAndCleanupConfig; // eax
  unsigned int *v9; // eax
  Mem **v10; // eax
  int v11; // eax
  int v13; // eax
  IList *v14; // ecx
  DWORD **v15; // eax
  DWORD **v16; // eax
  char v17; // [esp+13h] [ebp-205h]
  UINT v18; // [esp+14h] [ebp-204h]
  char v19; // [esp+18h] [ebp-200h] BYREF
  char v20; // [esp+19h] [ebp-1FFh]
  char v21; // [esp+1Ah] [ebp-1FEh]
  char v22; // [esp+1Bh] [ebp-1FDh]
  CHAR v23[4]; // [esp+114h] [ebp-104h]
  CHAR Text[256]; // [esp+118h] [ebp-100h] BYREF

  v18 = 0;
  v17 = byte_50C0E4B;
  byte_50C0E4B = 0;
  setFullDirName(a2, Text, 0);
  v6 = heapAlloc(0x64u);
  if ( v6 )
    v7 = Mem_401700_ctor(v6);
  else
    v7 = 0;
  DirNameAndCleanupConfig = Mem_getDirNameAndCleanupConfig(v7, Text, 0);
  *(*(NtCurrentTeb()->ThreadLocalStoragePointer + TlsIndex) + 8345) = 0;
  if ( !DirNameAndCleanupConfig )
  {
    if ( !AMem_50C0E78.MemListHead )
    {
      v9 = heapAlloc(0xA8u);
      if ( v9 )
        v10 = UnClass7_404570_ctor(v9);
      else
        v10 = 0;
      AMem_50C0E78.MemListHead = v10;
      sub_416470(v10, 96, 96, 1, 1);
    }
    if ( a4 )
    {
      sub_4165A0(AMem_50C0E78.MemListHead, 0);
      sub_46BD60(a4 + 14, AMem_50C0E78.MemListHead, AMem_50C0E78.MemListHead + 14, AMem_50C0E78.MemListHead + 14, 0);
    }
    if ( strSplitFilePath(Text, &v19, 0, 0, 1) )
    {
      v11 = sub_401990(v7, v22 | ((v21 | (v20 << 8)) << 8), 0);
      if ( !a4 )
        goto LABEL_19;
      if ( !v11 )
      {
        v11 = sub_401A60(v7, a4, v22 | ((v21 | (v20 << 8)) << 8));
        goto LABEL_19;
      }
LABEL_20:
      v23[strLength(Text)] = 0;
      if ( !v17 )
        logInitialization(Text, "Unable To Save File");
      if ( v7 )
        IList_3BC81E0_func2(v7);
      return 0;
    }
    v11 = sub_401990(v7, 63, 0);
    if ( a4 )
    {
      if ( v11 )
        goto LABEL_20;
      v11 = sub_401A60(v7, a4, 63);
    }
LABEL_19:
    if ( v11 )
      goto LABEL_20;
    if ( a4 )
    {
      v13 = sub_401B40();
      sub_3BA55F0(v7, v13, 0);
    }
    if ( a3 )
    {
      if ( (this->virtualMemAccessMode & 8) == 0 )
        sub_3BA63D0(this, 1, 1, 1);
      v14 = this;
      if ( (this->virtualMemAccessMode & 8) != 0 )
      {
        this->virtualMemAccessMode &= ~8u;
        v15 = IList_pusWriteUnkClass5Node(this);
        if ( v15 )
        {
          v18 = IList_buildUnkClass5NodeFromUnkgVar(v7, v15, v15[2]);
          IList_setWriteHeadUnkClass5Node(this);
        }
        this->virtualMemAccessMode |= 8u;
        goto LABEL_37;
      }
    }
    else
    {
      v14 = this;
    }
    v16 = IList_pusWriteUnkClass5Node(v14);
    if ( v16 )
    {
      v18 = IList_buildUnkClass5NodeFromUnkgVar(v7, v16, this->roofUnkClass5Index);
      IList_setWriteHeadUnkClass5Node(this);
    }
  }
LABEL_37:
  if ( v7 )
  {
    Mem_changeUnkClass5ListState(v7);
    IList_3BC81E0_func2(v7);
  }
  return v18;
}

.text:03BA6960                 sub     esp, 208h
.text:03BA6966                 mov     al, byte_50C0E4B
.text:03BA696B                 push    ebx
.text:03BA696C                 push    ebp
.text:03BA696D                 push    esi
.text:03BA696E                 push    edi
.text:03BA696F                 xor     ebx, ebx
.text:03BA6971                 mov     edi, ecx
.text:03BA6973                 mov     ecx, [esp+218h+arg_0]
.text:03BA697A                 push    ebx
.text:03BA697B                 lea     edx, [esp+21Ch+Text]
.text:03BA6982                 mov     [esp+21Ch+var_204], ebx
.text:03BA6986                 mov     [esp+21Ch+var_205], al
.text:03BA698A                 mov     byte_50C0E4B, bl
.text:03BA6990                 call    setFullDirName
.text:03BA6995                 push    64h ; 'd'
.text:03BA6997                 call    heapAlloc
.text:03BA699C                 add     esp, 4
.text:03BA699F                 cmp     eax, ebx
.text:03BA69A1                 jz      short loc_3BA69AE
.text:03BA69A3                 mov     ecx, eax
.text:03BA69A5                 call    Mem_401700_ctor
.text:03BA69AA                 mov     ebp, eax
.text:03BA69AC                 jmp     short loc_3BA69B0
.text:03BA69AE ; ---------------------------------------------------------------------------
.text:03BA69AE
.text:03BA69AE loc_3BA69AE:                            ; CODE XREF: IList_3BA6960_func1+41↑j
.text:03BA69AE                 xor     ebp, ebp
.text:03BA69B0
.text:03BA69B0 loc_3BA69B0:                            ; CODE XREF: IList_3BA6960_func1+4C↑j
.text:03BA69B0                 push    ebx
.text:03BA69B1                 lea     ecx, [esp+21Ch+Text]
.text:03BA69B8                 push    ecx
.text:03BA69B9                 mov     ecx, ebp
.text:03BA69BB                 call    Mem_getDirNameAndCleanupConfig
.text:03BA69C0                 mov     edx, TlsIndex
.text:03BA69C6                 mov     ecx, large fs:2Ch
.text:03BA69CD                 mov     edx, [ecx+edx*4]
.text:03BA69D0                 mov     [edx+2099h], bl
.text:03BA69D6                 cmp     eax, ebx
.text:03BA69D8                 jnz     loc_3BA6BA4
.text:03BA69DE                 cmp     AMem_50C0E78.MemListHead, ebx
.text:03BA69E4                 jnz     short loc_3BA6A16
.text:03BA69E6                 push    0A8h
.text:03BA69EB                 call    heapAlloc
.text:03BA69F0                 add     esp, 4
.text:03BA69F3                 cmp     eax, ebx
.text:03BA69F5                 jz      short loc_3BA6A00
.text:03BA69F7                 mov     ecx, eax
.text:03BA69F9                 call    UnClass7_404570_ctor
.text:03BA69FE                 jmp     short loc_3BA6A02
.text:03BA6A00 ; ---------------------------------------------------------------------------
.text:03BA6A00
.text:03BA6A00 loc_3BA6A00:                            ; CODE XREF: IList_3BA6960_func1+95↑j
.text:03BA6A00                 xor     eax, eax
.text:03BA6A02
.text:03BA6A02 loc_3BA6A02:                            ; CODE XREF: IList_3BA6960_func1+9E↑j
.text:03BA6A02                 push    1
.text:03BA6A04                 push    1
.text:03BA6A06                 push    60h ; '`'
.text:03BA6A08                 push    60h ; '`'
.text:03BA6A0A                 mov     ecx, eax
.text:03BA6A0C                 mov     AMem_50C0E78.MemListHead, eax
.text:03BA6A11                 call    sub_416470
.text:03BA6A16
.text:03BA6A16 loc_3BA6A16:                            ; CODE XREF: IList_3BA6960_func1+84↑j
.text:03BA6A16                 mov     esi, [esp+218h+arg_8]
.text:03BA6A1D                 cmp     esi, ebx
.text:03BA6A1F                 jz      short loc_3BA6A45
.text:03BA6A21                 mov     ecx, AMem_50C0E78.MemListHead
.text:03BA6A27                 push    ebx             ; Val
.text:03BA6A28                 call    sub_4165A0
.text:03BA6A2D                 mov     ecx, AMem_50C0E78.MemListHead
.text:03BA6A33                 lea     eax, [ecx+38h]
.text:03BA6A36                 push    ebx
.text:03BA6A37                 push    eax
.text:03BA6A38                 push    eax
.text:03BA6A39                 push    ecx
.text:03BA6A3A                 lea     eax, [esi+38h]
.text:03BA6A3D                 push    eax
.text:03BA6A3E                 mov     ecx, esi
.text:03BA6A40                 call    sub_46BD60
.text:03BA6A45
.text:03BA6A45 loc_3BA6A45:                            ; CODE XREF: IList_3BA6960_func1+BF↑j
.text:03BA6A45                 push    1
.text:03BA6A47                 push    ebx
.text:03BA6A48                 push    ebx
.text:03BA6A49                 lea     edx, [esp+224h+var_200]
.text:03BA6A4D                 lea     ecx, [esp+224h+Text]
.text:03BA6A54                 call    strSplitFilePath
.text:03BA6A59                 push    ebx
.text:03BA6A5A                 test    al, al
.text:03BA6A5C                 jz      short loc_3BA6AA3
.text:03BA6A5E                 movsx   ecx, [esp+21Ch+var_1FF]
.text:03BA6A63                 movsx   edx, [esp+21Ch+var_1FE]
.text:03BA6A68                 movsx   eax, [esp+21Ch+var_1FD]
.text:03BA6A6D                 shl     ecx, 8
.text:03BA6A70                 or      ecx, edx
.text:03BA6A72                 shl     ecx, 8
.text:03BA6A75                 or      ecx, eax
.text:03BA6A77                 push    ecx
.text:03BA6A78                 mov     ecx, ebp
.text:03BA6A7A                 call    sub_401990
.text:03BA6A7F                 cmp     esi, ebx
.text:03BA6A81                 jz      short loc_3BA6ABE
.text:03BA6A83                 cmp     eax, ebx
.text:03BA6A85                 jnz     short loc_3BA6AC2
.text:03BA6A87                 movsx   ecx, [esp+218h+var_1FF]
.text:03BA6A8C                 movsx   edx, [esp+218h+var_1FE]
.text:03BA6A91                 movsx   eax, [esp+218h+var_1FD]
.text:03BA6A96                 shl     ecx, 8
.text:03BA6A99                 or      ecx, edx
.text:03BA6A9B                 shl     ecx, 8
.text:03BA6A9E                 or      ecx, eax
.text:03BA6AA0                 push    ecx
.text:03BA6AA1                 jmp     short loc_3BA6AB6
.text:03BA6AA3 ; ---------------------------------------------------------------------------
.text:03BA6AA3
.text:03BA6AA3 loc_3BA6AA3:                            ; CODE XREF: IList_3BA6960_func1+FC↑j
.text:03BA6AA3                 push    3Fh ; '?'
.text:03BA6AA5                 mov     ecx, ebp
.text:03BA6AA7                 call    sub_401990
.text:03BA6AAC                 cmp     esi, ebx
.text:03BA6AAE                 jz      short loc_3BA6ABE
.text:03BA6AB0                 cmp     eax, ebx
.text:03BA6AB2                 jnz     short loc_3BA6AC2
.text:03BA6AB4                 push    3Fh ; '?'
.text:03BA6AB6
.text:03BA6AB6 loc_3BA6AB6:                            ; CODE XREF: IList_3BA6960_func1+141↑j
.text:03BA6AB6                 push    esi
.text:03BA6AB7                 mov     ecx, ebp
.text:03BA6AB9                 call    sub_401A60
.text:03BA6ABE
.text:03BA6ABE loc_3BA6ABE:                            ; CODE XREF: IList_3BA6960_func1+121↑j
.text:03BA6ABE                                         ; IList_3BA6960_func1+14E↑j
.text:03BA6ABE                 cmp     eax, ebx
.text:03BA6AC0                 jz      short loc_3BA6B09
.text:03BA6AC2
.text:03BA6AC2 loc_3BA6AC2:                            ; CODE XREF: IList_3BA6960_func1+125↑j
.text:03BA6AC2                                         ; IList_3BA6960_func1+152↑j
.text:03BA6AC2                 lea     ecx, [esp+218h+Text]
.text:03BA6AC9                 call    strLength
.text:03BA6ACE                 movsx   ecx, ax
.text:03BA6AD1                 mov     [esp+ecx+218h+var_104], bl
.text:03BA6AD8                 cmp     [esp+218h+var_205], bl
.text:03BA6ADC                 jnz     short loc_3BA6AEF
.text:03BA6ADE                 mov     edx, offset aUnableToSaveFi ; "Unable To Save File"
.text:03BA6AE3                 lea     ecx, [esp+218h+Text] ; lpText
.text:03BA6AEA                 call    logInitialization
.text:03BA6AEF
.text:03BA6AEF loc_3BA6AEF:                            ; CODE XREF: IList_3BA6960_func1+17C↑j
.text:03BA6AEF                 cmp     ebp, ebx
.text:03BA6AF1                 jz      short loc_3BA6AFA
.text:03BA6AF3                 mov     ecx, ebp
.text:03BA6AF5                 call    IList_3BC81E0_func2
.text:03BA6AFA
.text:03BA6AFA loc_3BA6AFA:                            ; CODE XREF: IList_3BA6960_func1+191↑j
.text:03BA6AFA                 pop     edi
.text:03BA6AFB                 pop     esi
.text:03BA6AFC                 pop     ebp
.text:03BA6AFD                 xor     eax, eax
.text:03BA6AFF                 pop     ebx
.text:03BA6B00                 add     esp, 208h
.text:03BA6B06                 retn    10h
.text:03BA6B09 ; ---------------------------------------------------------------------------
.text:03BA6B09
.text:03BA6B09 loc_3BA6B09:                            ; CODE XREF: IList_3BA6960_func1+160↑j
.text:03BA6B09                 cmp     esi, ebx
.text:03BA6B0B                 jz      short loc_3BA6B1F
.text:03BA6B0D                 push    ebx             ; char
.text:03BA6B0E                 mov     ecx, ebp
.text:03BA6B10                 call    sub_401B40
.text:03BA6B15                 cdq
.text:03BA6B16                 push    edx
.text:03BA6B17                 push    eax             ; liDistanceToMove
.text:03BA6B18                 mov     ecx, ebp
.text:03BA6B1A                 call    sub_3BA55F0
.text:03BA6B1F
.text:03BA6B1F loc_3BA6B1F:                            ; CODE XREF: IList_3BA6960_func1+1AB↑j
.text:03BA6B1F                 cmp     [esp+218h+arg_4], bl
.text:03BA6B26                 jz      short loc_3BA6B82
.text:03BA6B28                 mov     dl, [edi+20h]
.text:03BA6B2B                 shr     dl, 3
.text:03BA6B2E                 not     dl
.text:03BA6B30                 test    dl, 1
.text:03BA6B33                 jz      short loc_3BA6B42
.text:03BA6B35                 push    1
.text:03BA6B37                 push    1
.text:03BA6B39                 push    1
.text:03BA6B3B                 mov     ecx, edi
.text:03BA6B3D                 call    sub_3BA63D0
.text:03BA6B42
.text:03BA6B42 loc_3BA6B42:                            ; CODE XREF: IList_3BA6960_func1+1D3↑j
.text:03BA6B42                 movzx   eax, word ptr [edi+20h]
.text:03BA6B46                 mov     cl, al
.text:03BA6B48                 shr     cl, 3
.text:03BA6B4B                 test    cl, 1
.text:03BA6B4E                 mov     ecx, edi        ; int
.text:03BA6B50                 jz      short loc_3BA6B84
.text:03BA6B52                 and     eax, 0FFF7h
.text:03BA6B57                 mov     [edi+20h], ax
.text:03BA6B5B                 call    IList_pusWriteUnkClass5Node
.text:03BA6B60                 cmp     eax, ebx
.text:03BA6B62                 jz      short loc_3BA6B7B
.text:03BA6B64                 mov     ecx, [eax+8]
.text:03BA6B67                 push    ecx             ; Size
.text:03BA6B68                 push    eax             ; Src
.text:03BA6B69                 mov     ecx, ebp        ; int
.text:03BA6B6B                 call    IList_buildUnkClass5NodeFromUnkgVar
.text:03BA6B70                 mov     ecx, edi
.text:03BA6B72                 mov     [esp+218h+var_204], eax
.text:03BA6B76                 call    IList_setWriteHeadUnkClass5Node
.text:03BA6B7B
.text:03BA6B7B loc_3BA6B7B:                            ; CODE XREF: IList_3BA6960_func1+202↑j
.text:03BA6B7B                 or      word ptr [edi+20h], 8
.text:03BA6B80                 jmp     short loc_3BA6BA4
.text:03BA6B82 ; ---------------------------------------------------------------------------
.text:03BA6B82
.text:03BA6B82 loc_3BA6B82:                            ; CODE XREF: IList_3BA6960_func1+1C6↑j
.text:03BA6B82                 mov     ecx, edi        ; int
.text:03BA6B84
.text:03BA6B84 loc_3BA6B84:                            ; CODE XREF: IList_3BA6960_func1+1F0↑j
.text:03BA6B84                 call    IList_pusWriteUnkClass5Node
.text:03BA6B89                 cmp     eax, ebx
.text:03BA6B8B                 jz      short loc_3BA6BA4
.text:03BA6B8D                 mov     ecx, [edi+28h]
.text:03BA6B90                 push    ecx             ; Size
.text:03BA6B91                 push    eax             ; Src
.text:03BA6B92                 mov     ecx, ebp        ; int
.text:03BA6B94                 call    IList_buildUnkClass5NodeFromUnkgVar
.text:03BA6B99                 mov     ecx, edi
.text:03BA6B9B                 mov     [esp+218h+var_204], eax
.text:03BA6B9F                 call    IList_setWriteHeadUnkClass5Node
.text:03BA6BA4
.text:03BA6BA4 loc_3BA6BA4:                            ; CODE XREF: IList_3BA6960_func1+78↑j
.text:03BA6BA4                                         ; IList_3BA6960_func1+220↑j ...
.text:03BA6BA4                 cmp     ebp, ebx
.text:03BA6BA6                 jz      short loc_3BA6BB6
.text:03BA6BA8                 mov     ecx, ebp
.text:03BA6BAA                 call    Mem_changeUnkClass5ListState
.text:03BA6BAF                 mov     ecx, ebp
.text:03BA6BB1                 call    IList_3BC81E0_func2
.text:03BA6BB6
.text:03BA6BB6 loc_3BA6BB6:                            ; CODE XREF: IList_3BA6960_func1+246↑j
.text:03BA6BB6                 mov     eax, [esp+218h+var_204]
.text:03BA6BBA                 pop     edi
.text:03BA6BBB                 pop     esi
.text:03BA6BBC                 pop     ebp
.text:03BA6BBD                 pop     ebx
.text:03BA6BBE                 add     esp, 208h
.text:03BA6BC4                 retn    10h
.text:03BA6BC4 IList_3BA6960_func1 endp
