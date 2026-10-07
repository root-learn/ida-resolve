.text:01A987D0 ; =============== S U B R O U T I N E =======================================
.text:01A987D0
.text:01A987D0
.text:01A987D0 ; char __userpurge sub_1A987D0@<al>(FILE *@<edi>, _BYTE *, int)
.text:01A987D0 sub_1A987D0     proc near               ; CODE XREF: sub_1A98920+182↓p
.text:01A987D0
.text:01A987D0 var_4           = dword ptr -4
.text:01A987D0 arg_0           = dword ptr  4
.text:01A987D0 arg_4           = dword ptr  8
.text:01A987D0
.text:01A987D0                 push    ecx
.text:01A987D1                 push    ebx
.text:01A987D2                 mov     ebx, [esp+8+arg_4]
.text:01A987D6                 lea     eax, [ebx-8]
.text:01A987D9                 push    edi             ; Stream
.text:01A987DA                 cmp     eax, 7FF7h
.text:01A987DF                 ja      loc_1A98906
.text:01A987E5                 call    _fgetc
.text:01A987EA                 add     esp, 4
.text:01A987ED                 cmp     eax, 2
.text:01A987F0                 jz      short loc_1A98810
.text:01A987F2                 push    1               ; Origin
.text:01A987F4                 push    0FFFFFFFFh      ; Offset
.text:01A987F6                 push    edi             ; Stream
.text:01A987F7                 call    _fseek
.text:01A987FC                 mov     ecx, [esp+14h+arg_0]
.text:01A98800                 add     esp, 0Ch
.text:01A98803                 push    edi             ; Stream
.text:01A98804                 push    ebx             ; int
.text:01A98805                 push    ecx             ; int
.text:01A98806                 call    sub_1A98720
.text:01A9880B                 pop     ebx
.text:01A9880C                 pop     ecx
.text:01A9880D                 retn    8
.text:01A98810 ; ---------------------------------------------------------------------------
.text:01A98810
.text:01A98810 loc_1A98810:                            ; CODE XREF: sub_1A987D0+20↑j
.text:01A98810                 push    esi
.text:01A98811                 push    edi             ; Stream
.text:01A98812                 call    _fgetc
.text:01A98817                 mov     esi, [esp+10h+arg_0]
.text:01A9881B                 push    edi             ; Stream
.text:01A9881C                 mov     [esi+1], al
.text:01A9881F                 call    _fgetc
.text:01A98824                 push    edi             ; Stream
.text:01A98825                 mov     [esi+2], al
.text:01A98828                 call    _fgetc
.text:01A9882D                 add     esp, 0Ch
.text:01A98830                 cmp     byte ptr [esi+1], 2
.text:01A98834                 jnz     loc_1A988EE
.text:01A9883A                 test    byte ptr [esi+2], 80h
.text:01A9883E                 jnz     loc_1A988EE
.text:01A98844                 mov     [esp+0Ch+var_4], 0
.text:01A9884C                 push    ebp
.text:01A9884D                 lea     ecx, [ecx+0]
.text:01A98850
.text:01A98850 loc_1A98850:                            ; CODE XREF: sub_1A987D0+103↓j
.text:01A98850                 xor     ebp, ebp
.text:01A98852                 test    ebx, ebx
.text:01A98854                 jle     short loc_1A988C7
.text:01A98856
.text:01A98856 loc_1A98856:                            ; CODE XREF: sub_1A987D0+F1↓j
.text:01A98856                 push    edi             ; Stream
.text:01A98857                 call    _fgetc
.text:01A9885C                 mov     bl, al
.text:01A9885E                 add     esp, 4
.text:01A98861                 cmp     bl, 80h
.text:01A98864                 jbe     short loc_1A98891
.text:01A98866                 push    edi             ; Stream
.text:01A98867                 and     bl, 7Fh
.text:01A9886A                 call    _fgetc
.text:01A9886F                 add     esp, 4
.text:01A98872                 test    bl, bl
.text:01A98874                 jz      short loc_1A988BD
.text:01A98876                 mov     edx, [esp+10h+var_4]
.text:01A9887A                 lea     ecx, [edx+ebp*4]
.text:01A9887D                 movzx   edx, bl
.text:01A98880                 add     ecx, esi
.text:01A98882                 add     ebp, edx
.text:01A98884
.text:01A98884 loc_1A98884:                            ; CODE XREF: sub_1A987D0+BD↓j
.text:01A98884                 dec     bl
.text:01A98886                 mov     [ecx], al
.text:01A98888                 add     ecx, 4
.text:01A9888B                 test    bl, bl
.text:01A9888D                 jnz     short loc_1A98884
.text:01A9888F                 jmp     short loc_1A988BD
.text:01A98891 ; ---------------------------------------------------------------------------
.text:01A98891
.text:01A98891 loc_1A98891:                            ; CODE XREF: sub_1A987D0+94↑j
.text:01A98891                 test    bl, bl
.text:01A98893                 jz      short loc_1A988BD
.text:01A98895                 mov     eax, [esp+10h+var_4]
.text:01A98899                 lea     esi, [eax+ebp*4]
.text:01A9889C                 add     esi, [esp+10h+arg_0]
.text:01A988A0                 movzx   ecx, bl
.text:01A988A3                 add     ebp, ecx
.text:01A988A5
.text:01A988A5 loc_1A988A5:                            ; CODE XREF: sub_1A987D0+E7↓j
.text:01A988A5                 push    edi             ; Stream
.text:01A988A6                 dec     bl
.text:01A988A8                 call    _fgetc
.text:01A988AD                 mov     [esi], al
.text:01A988AF                 add     esp, 4
.text:01A988B2                 add     esi, 4
.text:01A988B5                 test    bl, bl
.text:01A988B7                 jnz     short loc_1A988A5
.text:01A988B9                 mov     esi, [esp+10h+arg_0]
.text:01A988BD
.text:01A988BD loc_1A988BD:                            ; CODE XREF: sub_1A987D0+A4↑j
.text:01A988BD                                         ; sub_1A987D0+BF↑j ...
.text:01A988BD                 cmp     ebp, [esp+10h+arg_4]
.text:01A988C1                 jl      short loc_1A98856
.text:01A988C3                 mov     ebx, [esp+10h+arg_4]
.text:01A988C7
.text:01A988C7 loc_1A988C7:                            ; CODE XREF: sub_1A987D0+84↑j
.text:01A988C7                 mov     eax, [esp+10h+var_4]
.text:01A988CB                 inc     eax
.text:01A988CC                 cmp     eax, 4
.text:01A988CF                 mov     [esp+10h+var_4], eax
.text:01A988D3                 jl      loc_1A98850
.text:01A988D9                 push    edi             ; Stream
.text:01A988DA                 call    _feof
.text:01A988DF                 add     esp, 4
.text:01A988E2                 pop     ebp
.text:01A988E3                 test    eax, eax
.text:01A988E5                 pop     esi
.text:01A988E6                 setz    al
.text:01A988E9                 pop     ebx
.text:01A988EA                 pop     ecx
.text:01A988EB                 retn    8
.text:01A988EE ; ---------------------------------------------------------------------------
.text:01A988EE
.text:01A988EE loc_1A988EE:                            ; CODE XREF: sub_1A987D0+64↑j
.text:01A988EE                                         ; sub_1A987D0+6E↑j
.text:01A988EE                 push    edi             ; Stream
.text:01A988EF                 dec     ebx
.text:01A988F0                 mov     byte ptr [esi], 2
.text:01A988F3                 mov     [esi+3], al
.text:01A988F6                 push    ebx             ; int
.text:01A988F7                 add     esi, 4
.text:01A988FA                 push    esi             ; int
.text:01A988FB                 call    sub_1A98720
.text:01A98900                 pop     esi
.text:01A98901                 pop     ebx
.text:01A98902                 pop     ecx
.text:01A98903                 retn    8
.text:01A98906 ; ---------------------------------------------------------------------------
.text:01A98906
.text:01A98906 loc_1A98906:                            ; CODE XREF: sub_1A987D0+F↑j
.text:01A98906                 mov     edx, [esp+0Ch+arg_0]
.text:01A9890A                 push    ebx             ; int
.text:01A9890B                 push    edx             ; int
.text:01A9890C                 call    sub_1A98720
.text:01A98911                 pop     ebx
.text:01A98912                 pop     ecx
.text:01A98913                 retn    8
.text:01A98913 sub_1A987D0     endp