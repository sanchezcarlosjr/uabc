(require "test.lisp")

(defun remdup (lst)
  (reduce
    	   #'(lambda (acc actual) 
	  	(setf element (list actual))
		(if (not (equal (last acc) element)) (append acc element) acc)
	   ) 
	  lst 
	  :initial-value '()
   )
)

(test #'remdup '(a a a b b c c c a a d d e e e e f) '(A B C A D E F))
