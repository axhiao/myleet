

## 1. Given a set S and an integer x, decide whether there are two elements in S whose sum equals x. Time limit: theta(n*logn).
   
+ sort S
+ S'={x-si | si in S}.
+ sort S'
+ if the same value appears in both S and S', then yes.