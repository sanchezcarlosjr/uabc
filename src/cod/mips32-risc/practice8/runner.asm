# Subroutine under test
# a=0;
# b=100;
# c=0;
# while (a != b) {
#  a=b+c;
# }
# c=a+b;

.data
    failmsg: .asciiz "failed for test input: "
    okmsg: .asciiz "all tests passed"

.text
run_test:
        # params
        li      $a0, 0      #a
        li      $a1, 100    #b
        li      $a2, 0      #c

        li $s0, 200        # c should be

        # call subroutine under test
        jal     WHILE

        # assert
        bne     $v0, $s0, exit_fail
        bne     $v1, $s1, exit_fail


exit_ok:
        la      $a0, okmsg              # put address of okmsg into a0
        li      $v0, 4                  # 4 is print string
        syscall

        li      $v0, 10                 # 10 is exit with zero status (clean exit)
        syscall

exit_fail:
        la      $a0, failmsg            # put address of failmsg into a0
        li      $v0, 4                  # 4 is print string
        syscall

        move    $a0, $s3                # set arg of syscall to input that failed the test
        li      $v0, 1                  # 1 is print int
        syscall

        li      $a0, 1                  # set exit code to 1
        li      $v0, 17                 # terminate with the exit code in $a0
        syscall

# Include your implementation here if you wish to run this from the MARS GUI.
.include "impl.asm"