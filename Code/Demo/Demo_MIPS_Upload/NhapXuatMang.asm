#Viet chuong trinh nhap xuat mang 1 chieu
.data 
	tb1: .asciiz "Nhap n: "
	tb2: .asciiz "a["
	tb3: .asciiz "]: "
	tb4: .asciiz "Mang vua nhap la: "
	tb5: .asciiz "\nTong la: "
	n: .word 0
	arr: .space 100

.text
	#xuat tb1
	li $v0,4
	la $a0,tb1
	syscall

	#nhap so nguyen
	li $v0,5
	syscall

	#luu vao n
	sw $v0,n
	
	#khoi tao vong lap
	la $s0,arr # s0 = arr
	lw $s1,n # s1 = n
	li $t0,0 # i = 0
LapNhap:
	#xuat tb2
	li $v0,4
	la $a0,tb2
	syscall

	#xuat i
	li $v0,1
	move $a0,$t0
	syscall

	#xuat tb3
	li $v0,4
	la $a0,tb3
	syscall

	#nhap so nguyen
	li $v0,5
	syscall 

	#luu vao a[i]
	sw $v0,($s0)

	#tang dia chi mang
	addi $s0,$s0,4
	#tang i
	addi $t0,$t0,1
	#kiem tra i < n
	blt $t0,$s1,LapNhap

	#xuat tb4
	li $v0,4
	la $a0,tb4
	syscall

	#khoi tao vong lap
	la $s0,arr# s0 = arr
	li $t0,0 # i = 0
LapXuat:
	#xuat a[i]
	li $v0,1
	lw $a0,($s0)
	syscall
	
	#xuat khoang trang
	li $v0,11
	li $a0,' '
	syscall

	addi $s0, $s0, 4
	addi $t0, $t0, 1
	blt $t0, $s1, LapXuat

	li $v0, 4
	la $a0, tb5
	syscall

	li $t0, 0
	la $s0, arr
	li $s2, 0

LapTong:
	lw $t2, ($s0)
	add $s2, $s2, $t2
	
	addi $s0, $s0, 4
	addi $t0, $t0, 1
	blt $t0, $s1, LapTong

	li $v0, 1
	move $a0, $s2
	syscall