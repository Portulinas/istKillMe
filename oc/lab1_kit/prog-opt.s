;; Organization of Computers (OC)
;; Lab: Pipelining
;; Ricardo.Chaves@tecnico.ulisboa.pt
;; IST, Lisbon-Portugal, 01-10-2015

;; The following program computes the compensated factorial of N-1, using a
;; floating-point representation and the Lucas number for n = N+1. The
;; outcome values are stored in variables fibo and lucas, respectively.
;; 
;;   #define N 10
;;   double A[N-1] = {0, 1, 3, 0, 7, 0, 1, 5, 3};
;;   int64 x=2, y=1, lucas, fact=1, i=1;
;;   double *pA = &A[0];                      
;;           
;;   do {                 
;;     fact = fact * i + *pA;            
;;     lucas=x+y; x=y; y=lucas;           
;;     pA++;
;;     i++;     
;;   } while(i!=N);
  	
  	 
        .data
fact:   .word    0x0
lucas:  .word    0x0
A:      .word    0, 1, 3, 0, 7
        .word    0, 1, 5, 3

        .code
        daddi    $1, $0, A      ; $1 = Index for A
        daddi    $2, $0, 2      ; $2 = 2 ;; x
        daddi    $3, $0, 1      ; $3 = 1 ;; y
        daddi    $5, $0, 1      ; $5 = 1 ;; i	
        daddi    $6, $0, 10     ; $6 = N ;; N =10
        daddi    $12, $0, 1     ; $12 = 1 ;; fact=1

loop:   lw       $16, 0($1) 	; $16 = A[i-1]
        dmul     $12, $12, $5   ; $12 = fact *i 
				;dadd     $12, $12, $16  ; $12 = fact *i + A[i-1]  <-- RAW!
        dadd     $4, $2, $3     ; $4 = lucas = x + y
        daddi    $2, $3, 0      ; 
        daddi    $3, $4, 0      ; 

        daddi    $1, $1, 8	; pA++
        daddi    $5, $5, 1	; i++
				dadd     $12, $12, $16  ; $12 = fact *i + A[i-1]  <-- NO RAW!
        bne      $6, $5, loop   ; Exit loop if i == N
	
        sw       $12, fact($0)     ; Store factorial result
        sw       $4, lucas($0)     ; Store lucas result
        halt

;; Expected result: fact  =  b6628(hex)/ 747048(dec)
;;                  lucas =     7b(hex)/ 123(dec)
