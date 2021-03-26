(
   defun insert (position element lst)
    (setf l (nthcdr position lst)) 
    (push element l)
    (append (subseq lst 0 position) l)
)
(setf temp '(1 2 3))
(write (insert 1 'X temp))
