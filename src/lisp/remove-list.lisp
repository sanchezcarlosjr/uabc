(
  defun removeFromList(elementToRemove lst)
  (
    if (not lst)
    	NIL
	(
	 if (eq (first lst) elementToRemove) 
	   ; Remove element and recursive call
	   (removeFromList elementToRemove (rest lst))
	   ; Recursive call
	   (cons (first lst) (removeFromList elementToRemove (rest lst)))
	)
  )
)
(write (removeFromList 2 '(1 2 3 4 5 2 6)))
(assert (equal (removeFromList 2 '(1 2 3 4 5 2 6)) '(1 3 4 5 6)))
