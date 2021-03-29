(defun test (a b c)
  (print (funcall a b))
  (assert (equal (funcall a b) c))
)
