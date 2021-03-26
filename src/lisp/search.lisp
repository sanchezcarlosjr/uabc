(
 defun element(n lst)
   (if (<= n 0)
      NIL
      (if (eq (- n 1) 0) (car lst)
   	(element (- n 1) (cdr lst)))
   )
)
(write (element 2 NIL))
