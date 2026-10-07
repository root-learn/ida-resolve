.text:01A98920 ; =============== S U B R O U T I N E =======================================
.text:01A98920
.text:01A98920
.text:01A98920 ; char __fastcall sub_1A98920(char *FileName, _DWORD *)
.text:01A98920 sub_1A98920     proc near               ; CODE XREF: sub_417F60+2E↑p
.text:01A98920
.text:01A98920 var_264         = dword ptr -264h
.text:01A98920 var_260         = dword ptr -260h
.text:01A98920 var_25C         = dword ptr -25Ch
.text:01A98920 var_258         = byte ptr -258h
.text:01A98920 Buffer          = byte ptr -190h
.text:01A98920 var_C8          = byte ptr -0C8h
.text:01A98920
.text:01A98920                 sub     esp, 264h
.text:01A98926                 cmp     byte ptr [ecx], 21h ; '!'
.text:01A98929                 push    ebp
.text:01A9892A                 mov     ebp, edx
.text:01A9892C                 push    edi
.text:01A9892D                 mov     [esp+26Ch+var_25C], ebp
.text:01A98931                 jnz     short loc_1A98936
.text:01A98933                 add     ecx, 2
.text:01A98936
.text:01A98936 loc_1A98936:                            ; CODE XREF: sub_1A98920+11↑j
.text:01A98936                 push    offset Mode     ; "rb"
.text:01A9893B                 push    ecx             ; FileName
.text:01A9893C                 call    _fopen
.text:01A98941                 mov     edi, eax
.text:01A98943                 add     esp, 8
.text:01A98946                 test    edi, edi
.text:01A98948                 jnz     short loc_1A98955
.text:01A9894A                 pop     edi
.text:01A9894B                 xor     al, al
.text:01A9894D                 pop     ebp
.text:01A9894E                 add     esp, 264h
.text:01A98954                 retn
.text:01A98955 ; ---------------------------------------------------------------------------
.text:01A98955
.text:01A98955 loc_1A98955:                            ; CODE XREF: sub_1A98920+28↑j
.text:01A98955                 push    edi             ; Stream
.text:01A98956                 push    1               ; ElementCount
.text:01A98958                 lea     eax, [esp+274h+Buffer]
.text:01A9895F                 push    0Ah             ; ElementSize
.text:01A98961                 push    eax             ; Buffer
.text:01A98962                 call    _fread
.text:01A98967                 add     esp, 10h
.text:01A9896A                 mov     edx, 0Ah
.text:01A9896F                 mov     eax, offset aRadiance ; "#?RADIANCE"
.text:01A98974                 lea     ecx, [esp+26Ch+Buffer]
.text:01A9897B                 push    esi
.text:01A9897C                 lea     esp, [esp+0]
.text:01A98980
.text:01A98980 loc_1A98980:                            ; CODE XREF: sub_1A98920+76↓j
.text:01A98980                 mov     esi, [ecx]
.text:01A98982                 cmp     esi, [eax]
.text:01A98984                 jnz     loc_1A98AF6
.text:01A9898A                 sub     edx, 4
.text:01A9898D                 add     eax, 4
.text:01A98990                 add     ecx, 4
.text:01A98993                 cmp     edx, 4
.text:01A98996                 jnb     short loc_1A98980
.text:01A98998                 mov     dl, [eax]
.text:01A9899A                 cmp     dl, [ecx]
.text:01A9899C                 jnz     loc_1A98AF6
.text:01A989A2                 mov     al, [eax+1]
.text:01A989A5                 cmp     al, [ecx+1]
.text:01A989A8                 jnz     loc_1A98AF6
.text:01A989AE                 push    1               ; Origin
.text:01A989B0                 push    1               ; Offset
.text:01A989B2                 push    edi             ; Stream
.text:01A989B3                 call    _fseek
.text:01A989B8                 add     esp, 0Ch
.text:01A989BB                 xor     al, al
.text:01A989BD                 lea     esi, [esp+270h+var_C8]
.text:01A989C4                 push    ebx
.text:01A989C5
.text:01A989C5 loc_1A989C5:                            ; CODE XREF: sub_1A98920+B9↓j
.text:01A989C5                 push    edi             ; Stream
.text:01A989C6                 mov     bl, al
.text:01A989C8                 call    _fgetc
.text:01A989CD                 add     esp, 4
.text:01A989D0                 cmp     al, 0Ah
.text:01A989D2                 jnz     short loc_1A989D8
.text:01A989D4                 cmp     bl, al
.text:01A989D6                 jz      short loc_1A989DB
.text:01A989D8
.text:01A989D8 loc_1A989D8:                            ; CODE XREF: sub_1A98920+B2↑j
.text:01A989D8                 inc     esi
.text:01A989D9                 jmp     short loc_1A989C5
.text:01A989DB ; ---------------------------------------------------------------------------
.text:01A989DB
.text:01A989DB loc_1A989DB:                            ; CODE XREF: sub_1A98920+B6↑j
.text:01A989DB                 lea     esi, [esp+274h+var_258]
.text:01A989DF                 nop
.text:01A989E0
.text:01A989E0 loc_1A989E0:                            ; CODE XREF: sub_1A98920+CE↓j
.text:01A989E0                 push    edi             ; Stream
.text:01A989E1                 call    _fgetc
.text:01A989E6                 mov     [esi], al
.text:01A989E8                 add     esp, 4
.text:01A989EB                 inc     esi
.text:01A989EC                 cmp     al, 0Ah
.text:01A989EE                 jnz     short loc_1A989E0
.text:01A989F0                 lea     ecx, [esp+274h+var_264]
.text:01A989F4                 push    ecx
.text:01A989F5                 lea     edx, [esp+278h+var_260]
.text:01A989F9                 push    edx
.text:01A989FA                 lea     eax, [esp+27Ch+var_258]
.text:01A989FE                 push    offset aYLdXLd  ; "-Y %ld +X %ld"
.text:01A98A03                 push    eax             ; Buffer
.text:01A98A04                 call    _sscanf
.text:01A98A09                 add     esp, 10h
.text:01A98A0C                 test    eax, eax
.text:01A98A0E                 jz      short loc_1A98A7D
.text:01A98A10                 mov     ecx, [esp+274h+var_264]
.text:01A98A14                 mov     edx, [esp+274h+var_260]
.text:01A98A18                 push    58h ; 'X'
.text:01A98A1A                 mov     [ebp+0], ecx
.text:01A98A1D                 mov     [ebp+4], edx
.text:01A98A20                 call    heapAlloc
.text:01A98A25                 add     esp, 4
.text:01A98A28                 test    eax, eax
.text:01A98A2A                 jz      short loc_1A98A4C
.text:01A98A2C                 mov     edx, [esp+274h+var_260]
.text:01A98A30                 imul    edx, [esp+274h+var_264]
.text:01A98A35                 push    0
.text:01A98A37                 lea     ecx, [edx+edx*2]
.text:01A98A3A                 push    4
.text:01A98A3C                 add     ecx, ecx
.text:01A98A3E                 add     ecx, ecx
.text:01A98A40                 push    4
.text:01A98A42                 push    ecx
.text:01A98A43                 mov     ecx, eax
.text:01A98A45                 call    IList_3BA3ED0_ctor
.text:01A98A4A                 jmp     short loc_1A98A4E
.text:01A98A4C ; ---------------------------------------------------------------------------
.text:01A98A4C
.text:01A98A4C loc_1A98A4C:                            ; CODE XREF: sub_1A98920+10A↑j
.text:01A98A4C                 xor     eax, eax
.text:01A98A4E
.text:01A98A4E loc_1A98A4E:                            ; CODE XREF: sub_1A98920+12A↑j
.text:01A98A4E                 mov     ecx, eax        ; int
.text:01A98A50                 mov     [ebp+8], eax
.text:01A98A53                 call    IList_pusReadIListNode
.text:01A98A58                 mov     esi, eax
.text:01A98A5A                 mov     eax, [esp+274h+var_264]
.text:01A98A5E                 xor     ecx, ecx
.text:01A98A60                 mov     edx, 4
.text:01A98A65                 mul     edx
.text:01A98A67                 seto    cl
.text:01A98A6A                 neg     ecx
.text:01A98A6C                 or      ecx, eax
.text:01A98A6E                 push    ecx             ; Size
.text:01A98A6F                 call    ??2@YAPAXI@Z    ; operator new(uint)
.text:01A98A74                 mov     ebx, eax
.text:01A98A76                 add     esp, 4
.text:01A98A79                 test    ebx, ebx
.text:01A98A7B                 jnz     short loc_1A98A93
.text:01A98A7D
.text:01A98A7D loc_1A98A7D:                            ; CODE XREF: sub_1A98920+EE↑j
.text:01A98A7D                 push    edi             ; Stream
.text:01A98A7E                 call    _fclose
.text:01A98A83                 add     esp, 4
.text:01A98A86                 pop     ebx
.text:01A98A87                 pop     esi
.text:01A98A88                 pop     edi
.text:01A98A89                 xor     al, al
.text:01A98A8B                 pop     ebp
.text:01A98A8C                 add     esp, 264h
.text:01A98A92                 retn
.text:01A98A93 ; ---------------------------------------------------------------------------
.text:01A98A93
.text:01A98A93 loc_1A98A93:                            ; CODE XREF: sub_1A98920+15B↑j
.text:01A98A93                 mov     ebp, [esp+274h+var_260]
.text:01A98A97                 add     ebp, 0FFFFFFFFh
.text:01A98A9A                 js      short loc_1A98AC8
.text:01A98A9C                 mov     eax, [esp+274h+var_264]
.text:01A98AA0
.text:01A98AA0 loc_1A98AA0:                            ; CODE XREF: sub_1A98920+1A6↓j
.text:01A98AA0                 push    eax
.text:01A98AA1                 push    ebx
.text:01A98AA2                 call    sub_1A987D0

;;this is comment, the rest is not interest code