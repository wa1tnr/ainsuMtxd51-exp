\ nice working program - with responses included

   1 2 3 4   5 6 7  64           rstack     back     .s 7 6 5 4 3 2 1 64   ok
                swap               plus     emit A   .s 65 1 7 6 5 4 3 2  ok
   back back    swap               plus     emit B   .s 66 65 7 6 5 4 3 2  ok

   back back    swap drop          plus     emit C   .s 67 65 66 7 6 5 4 3  ok
   back back    swap drop          plus     emit D   .s 68 65 67 66 7 6 5 4  ok
   back back    swap drop          plus     emit E   .s 69 65 68 67 66 7 6 5  ok
   back back    swap drop          plus     emit F   .s 70 65 69 68 67 66 7 6  ok

   back back    swap drop          plus     emit G   .s 71 65 70 69 68 67 66 7  ok

   drop back    back back                            .s 70 69 68 67 66 7 71 65  ok
   swap drop                                         .s 71 70 69 68 67 66 7 65  ok
   swap drop                                         .s 7 71 70 69 68 67 66 65  ok

   emit A   emit B  emit C  emit D  cr 
   emit E   emit F  emit G  drop          .s 7 71 70 69 68 67 66 65  cr 

   emit A   emit B  emit C  emit D  cr 
   emit E   emit F  emit G  drop          .s 7 71 70 69 68 67 66 65  ok

