
1 2 3 4   5 6 7 8                                          .s
rstack  99  drop   64   drop  back  plus             emit  .s
-99    back swap   drop dup   drop  plus  back swap  emit  .s
-99    swap drop   back swap  drop  plus             emit  .s
       back back   swap drop        plus             emit  .s
       back back   swap drop        plus             emit  .s
       back back   swap drop        plus             emit  .s
       back back   swap drop        plus             emit  .s



1 2 3 4   5 6 7 8  .s
rstack  99  drop   64   drop  back  plus  emit  .s
-99    back swap   drop dup   drop  plus  back swap  emit  .s
-99    swap drop   back swap  drop  plus  emit  .s
       back back   swap drop        plus  emit  .s
       back back   swap drop        plus  emit  .s
       back back   swap drop        plus  emit  .s
       back back   swap drop        plus  emit  .s

\ factored a bit more:

1 2 3 4 5 6 7 63 rstack                   .s 63 7 6 5 4 3 2 1  ok
back      swap drop   plus     emit A     .s 65 63 1 7 6 5 4 3  ok
back back swap drop   plus     emit B     .s 66 63 65 1 7 6 5 4  ok
back back swap drop   plus     emit C     .s 67 63 66 65 1 7 6 5  ok
back back swap drop   plus     emit D     .s 68 63 67 66 65 1 7 6  ok
back back swap drop   plus     emit E     .s 69 63 68 67 66 65 1 7  ok
back back swap drop   plus     emit F     .s 70 63 69 68 67 66 65 1  ok
back back swap drop   plus     emit @     .s 64 63 70 69 68 67 66 65  ok  \ END

\ good
1 2 3 4   5 6 7  64   rstack  back swap plus emit A        .s 65 1 7 6 5 4 3 2  ok

\ better
1 2 3 4   5 6 7  64    rstack     back     .s 7 6 5 4 3 2 1 64  ok
             swap        plus     emit A   .s 65 1 7 6 5 4 3 2  ok
  back back  swap        plus     emit B   .s 66 65 7 6 5 4 3 2  ok
  back back  swap drop   plus     emit C   .s 67 65 66 7 6 5 4 3  ok
  back back  swap drop   plus     emit D   .s 68 65 67 66 7 6 5 4  ok
  back back  swap drop   plus     emit E   .s 69 65 68 67 66 7 6 5  ok
  back back  swap drop   plus     emit F   .s 70 65 69 68 67 66 7 6  ok
  back back  swap drop   plus              .s 65 70 69 68 67 66 7 71  ok
                                  emit G   .s 71 65 70 69 68 67 66 7  ok
  drop                                     .s 7 71 65 70 69 68 67 66  ok

\ even better

 1 2 3 4   5 6 7  64           rstack     back     .s 7 6 5 4 3 2 1 64  ok
              swap               plus     emit A   .s 65 1 7 6 5 4 3 2  ok
  back back   swap               plus     emit B   .s 66 65 7 6 5 4 3 2  ok
  back back   swap  drop         plus     emit C   .s 67 65 66 7 6 5 4 3  ok
  back back   swap  drop         plus     emit D   .s 68 65 67 66 7 6 5 4  ok
  back back   swap  drop         plus     emit E   .s 69 65 68 67 66 7 6 5  ok
  back back   swap  drop         plus     emit F   .s 70 65 69 68 67 66 7 6  ok
  back back   swap  drp ?  drop  plus     emit G   .s 71 65 70 69 68 67 66 7  ok
  drop back   back back    swap  drop swap drop    .s 7 71 70 69 68 67 66 65  ok
