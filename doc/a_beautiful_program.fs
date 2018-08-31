\ nice working program - without responses

  1 2 3 4   5 6 7  64        rstack back  .s
               swap          plus   emit  .s
  back back    swap          plus   emit  .s

  back back    swap drop     plus   emit  .s
  back back    swap drop     plus   emit  .s
  back back    swap drop     plus   emit  .s
  back back    swap drop     plus   emit  .s

  back back    swap drop     plus   emit  .s

  drop back    back back                  .s
  swap drop    swap drop                  .s

  emit A   emit B   emit C   emit D   cr 
  emit E   emit F   emit G   drop         .s

  emit A   emit B   emit C   emit D   cr 
  emit E   emit F   emit G   drop         .s

  emit A   emit B   emit C   emit D   cr 
  emit E   emit F   emit G   drop

\ loads the stack with ints 1-7
\ and a seed (offset) value for ASCII (65 - 1 = 64)
\ 65 is ascii 'A'  (66 is 'B' and so on)

\ prints them in sequence
\ reuses them when it gets to the end

\ wastes possibly the least amount of stack space
\ possible, given the initial 'additive' method
\ to populate the stack with a sequence of ASCII
\ characters.
