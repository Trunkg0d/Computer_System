.data
	tb1: .asciiz "Nhap so nguyen duong n: \n"
	tb2: .asciiz "So hoan thien \n"
	tb3: .asciiz "So khong hoan thien \n"
	n: .word 0
.text
	# Xuat thong bao 1
	li $v0, 4
	la $a0, tb1
	syscall
	
	# Nhap n
	li $v0, 5
	syscall
	sw $v0, n
	
	lw $t0, n
	li $t1, 1 # i = 1
	li $t2, 0 # sum = 0

Loop:
	div $t0, $t1
	mfhi $t3
	addi $t1, $t1, 1
	beq $t3, 0, increase_sum
	blt $t1, $t0, Loop
j check
increase_sum:
	addi $t3, $t1, -1
	add $t2, $t2, $t3
	j Loop

check:
	beq $t2, $t0, is_perfect
	j not_perfect

is_perfect:
	li $v0, 4
	la $a0, tb2
	syscall
	j finish

not_perfect:
	li $v0, 4
	la $a0, tb3
	syscall
	j finish

finish:

