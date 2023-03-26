.data
	tb1: .asciiz "Nhap n: \n"
	tb2: .asciiz "So chinh phuong\n"
	tb3: .asciiz "So khong chinh phuong\n"
.text
	li $v0, 4
	la $a0, tb1
	syscall

	# Nhap n
	li $v0, 5
	syscall
	move $s0, $v0
	
	# Khoi tao
	li $t1, 1

Loop:
	mult $t1, $t1
	mflo $t3
	beq $t3, $s0, is_square
	addi $t1, $t1, 1
	blt $t1, $v0, Loop
not_square:
	li $v0, 4
	la $a0, tb3
	syscall
	j finish
is_square:
	li $v0, 4
	la $a0, tb2
	syscall
	j finish

finish:

