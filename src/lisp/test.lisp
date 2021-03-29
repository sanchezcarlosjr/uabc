(defun test (expected func parameterA parameterB)
  (print (funcall func parameterA parameterB))
  (assert (equal (funcall func parameterA parameterB) expected))
)
