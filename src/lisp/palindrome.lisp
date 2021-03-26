(
  defun isPalindrome(x)
    (equal (reverse x) x)
)
(write(isPalindrome (string-upcase (read-line))))