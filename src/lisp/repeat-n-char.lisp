(defun repeatNTimes(lst n) 
        (
	     mapcan #'(lambda (element) (loop repeat n collect element)) lst
	)
)
(write (repeatNTimes '(1 2 3) 2))
