  _BYTE Buffer[200]; // [esp+DCh] [ebp-190h] BYREF
  char v28; // [esp+1A4h] [ebp-C8h] BYREF

  v2 = *FileName == 33;
  v25 = a2;
  if ( v2 )
    FileName += 2;
  v4 = fopen(FileName, "rb");
  v5 = v4;
  if ( !v4 )
    return 0;
  fread(Buffer, 0xAu, 1u, v4);
  v7 = 10;
  v8 = "#?RADIANCE";
  v9 = Buffer;
  do
  {
    if ( *v9 != *v8 )
      goto LABEL_29;
    v7 -= 4;
    v8 += 4;
    v9 += 4;
  }
  while ( v7 >= 4 );
  if ( *v8 != *v9 || v8[1] != v9[1] )
  {
LABEL_29:
    fclose(v5);
    return 0;
  }
  fseek(v5, 1, 1);
  v10 = 0;
  for ( i = &v28; ; ++i )
  {
    v12 = v10;
    v10 = fgetc(v5);
    if ( v10 == 10 && v12 == 10 )
      break;
  }
  v13 = v26;
  do
  {
    v14 = fgetc(v5);
    *v13++ = v14;
  }
  while ( v14 != 10 );
  if ( !sscanf(v26, "-Y %ld +X %ld", &v24, &v23) )
    goto LABEL_21;
  v15 = v24;
  *a2 = v23;
  a2[1] = v15;
  v16 = heapAlloc(0x58u);
  v17 = v16 ? IList_3BA3ED0_ctor(v16, 12 * v23 * v24, 4, 4, 0) : 0;
  a2[2] = v17;
  IListNode = IList_pusReadIListNode(v17);
  v19 = operator new(4 * v23);
  if ( v19 )
  {
    v20 = v24 - 1;
    if ( v24 - 1 >= 0 )
    {
      v21 = v23;
      do
      {
        if ( !sub_1A987D0(v19, v21) )
          break;
        sub_1A98690(v23);
        --v20;
        v21 = v23;
        IListNode += 3 * v23;
      }
      while ( v20 >= 0 );
    }