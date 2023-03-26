.data
	tb1: .asciiz "Nhap ky tu: "
	tb2: .asciiz "\nKy tu la so"
	tb3: .asciiz "\nKy tu la chu in thuong"
	tb4: .asciiz "\nKy tu la chu in hoa"
.text
	li $v0, 4
	la $a0, tb1
	syscall

	li $v0, 12
	syscall

	move $s0, $v0

	bge $s0, '0', LessNine
	j Greater_a

LessNine:
	ble $s0, '9', So
	j Greater_a

So:
	li $v0, 4
	la $a0, tb2
	syscall
	j Finish
Greater_a:
	bge $s0, 'a', Less_z
	j Greater_A
Less_z:
	ble $s0, 'z', ChuThuong
	j Greater_A
ChuThuong:
	li $v0, 4
	la $a0, tb3
	syscall
	j Finish
Greater_A:
	bge $s0, 'A', Less_Z
	j Finish
Less_Z:
	ble $s0, 'Z', ChuHoa
ChuHoa:
	li, $v0, 4
	la, $a0, tb4
	syscall
Finish: