(require "test.lisp")
(defun permute (lst &key repeatedNumber)
  "Permute a list."
  ; Repetead number is nil by default.
  (if 
    (null lst) 
    '(()) 
     (mapcan #'(lambda (head)
	           (loop for next in (permute (remove head lst :count repeatedNumber))
  		   	collect (cons head next)
		   )
	       ) 
	     lst
     )
  )
)
(print (permute '(1 2 3 3 3 4)))
