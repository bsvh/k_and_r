;; Define a procedure that takes three numbers as arguments and returns the sum
;; of the squares of the two larger numbers

(define (sum-of-larger-squares a b c)
  (define (sum-of-squares a b)
    (+ (* a a) (* b b)))
  (cond ((and (<= a b) (<= a c) (sum-of-squares b c)))
        ((and (<= b a) (<= b c) (sum-of-squares a c)))
        (else (sum-of-squares a b))))
