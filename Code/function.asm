#viet ham tinh x^n
.data
	tb1: .asciiz "Nhap x: "
	tb2: .asciiz "Nhap n: "
	tb3: .asciiz "x^n = "
	x: .word 0
	n: .word 0
	kq: .word 0
.text
	# Xuat thong bao 1
	li $v0, 4
	la $a0, tb1
	syscall

	# nhap x
	li $v0, 5
	syscall

	# luu vao x
	sw $v0, x
	
	# Xuat thong bao 2
	li $v0, 4
	la $a0, tb2
	syscall

	# Nhap n
	li $v0, 5
	syscall

	# luu vao n
	sw $v0, n

	#truyen tham so
	lw $a0, x
	lw $a1, n

	# goi ham
	jal _TinhXmuN

	# lay ket qua tra ve
	sw $v0, kq

	#xuat tb3
	li $v0, 4
	la $a0, tb3

	#xuat kq
	li $v0, 1
	lw $a0, kq
	syscall

	# ket thuc
	li $v0, 10

# =================== Ham Tinh XmuN ====================
# dau thu tuc
_TinhXmuN:
	addi $sp, $sp, -16 # khai bao stack
	# backup thanh ghi
	sw $ra, ($sp) # backup $ra
	sw $s0, 4($sp)
	sw $t0, 8($sp)

# than thu tuc
	# Khoi tao
	li $s0, 1 # Tich = 1
	li $t0, 1 # i = 1
_TinhXmuN.Lap:
	mult $s0, $a0 # T = T * x
	mflo $s0
	# Tang i
	addi $t0, $t0, 1
	# Kiem tra i <= n thi Lap
	ble $t0, $a1, _TinhXmuN.Lap

	# Luu ket qua tra ve
	move $v0, $s0

# cuoi thu tuc
	# restore thanh ghi
	lw $ra, ($sp)
	lw $s0, 4($sp)
	lw $t0, 8($sp)
	# xoa stack
	addi $sp, $sp, 16
	# quay ve
	jr $ra