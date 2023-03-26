.data
	tb1: .asciiz "Nhap n: \n"
	tb2: .asciiz "So doi xung\n"
	tb3: .asciiz "So khong doi xung\n"
.text
	li $v0, 4
	la $a0, tb1
	syscall

	# Nhap n
	li $v0, 5
	syscall
	move $s0, $v0
	
	# Khoi tao lan 1
	li $t0, 0
	add $t0, $s0, $zero  # ori_num = s0
	li $t1, 10  # c = 10
	li $t3, 1
Count:
	div $t0, $t1
	mflo $s1
	li $t0, 0
	add $t0, $s1, $zero
	mult $t3, $t1
	mflo $t3
	bgt $t0, 0, Count

	# Khoi tao lan 2
	div $t3, $t1
	mflo $t3
	li $t0, 0
	add $t0, $s0, $zero  # ori_num = s0
	li $t2, 0  # reverse_num = 0
Reverse:
	div $t0, $t1
	mflo $s1
	li $t0, 0
	add $t0, $s1, $zero
	mfhi $s2
	mult $s2, $t3
	mflo $s3
	add $t2, $t2, $s3
	div $t3, $t1
	mflo $t3
	beq $t0, 0, check
	j Reverse
check:
	beq $t2, $s0, DoiXung
	j KhongDoiXung
DoiXung:
	li $v0, 4
	la $a0, tb2
	syscall
	j finish
KhongDoiXung:
	li $v0, 4
	la $a0, tb3
	syscall
finish:
