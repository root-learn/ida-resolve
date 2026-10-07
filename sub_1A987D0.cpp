char __userpurge sub_1A987D0@<al>(FILE *a1@<edi>, _BYTE *a2, int a3)
{
  int v3; // ebx
  _BYTE *v5; // esi
  char v6; // al
  int v7; // ebp
  unsigned __int8 v8; // al
  unsigned __int8 v9; // bl
  unsigned __int8 v10; // bl
  char v11; // al
  _BYTE *v12; // ecx
  _BYTE *v13; // esi
  FILE *v14; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = a3;
  if ( (a3 - 8) > 0x7FF7 )
    return sub_1A98720(a2, a3, v14);
  if ( fgetc(v14) == 2 )
  {
    v5 = a2;
    a2[1] = fgetc(a1);
    a2[2] = fgetc(a1);
    v6 = fgetc(a1);
    if ( a2[1] == 2 && a2[2] >= 0 )
    {
      for ( i = 0; i < 4; ++i )
      {
        v7 = 0;
        if ( v3 > 0 )
        {
          do
          {
            v8 = fgetc(a1);
            v9 = v8;
            if ( v8 <= 0x80u )
            {
              if ( v8 )
              {
                v13 = &a2[4 * v7 + i];
                v7 += v8;
                do
                {
                  --v9;
                  *v13 = fgetc(a1);
                  v13 += 4;
                }
                while ( v9 );
                v5 = a2;
              }
            }
            else
            {
              v10 = v8 & 0x7F;
              v11 = fgetc(a1);
              if ( v10 )
              {
                v12 = &v5[4 * v7 + i];
                v7 += v10;
                do
                {
                  --v10;
                  *v12 = v11;
                  v12 += 4;
                }
                while ( v10 );
              }
            }
          }
          while ( v7 < a3 );
          v3 = a3;
        }
      }
      return feof(a1) == 0;
    }
    else
    {
      *a2 = 2;
      a2[3] = v6;
      return sub_1A98720(a2 + 4, a3 - 1, a1);
    }
  }
  else
  {
    fseek(a1, -1, 1);
    return sub_1A98720(a2, a3, a1);
  }
}