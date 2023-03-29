#Nhap vao a,b. Tinh tong, hieu, tich, thuong a,b.
.data
	tb1: .asciiz "Nhap a: "
	tb2: .asciiz "Nhap b: "	
	tb3: .asciiz "Tong la: "
	tb4: .asciiz "\nHieu la: "
	tb5: .asciiz "\nTich la: "
	tb6: .asciiz "\nThuong la: "
	tb7: .asciiz "\nDu la: "
	a: .word 0
	b: .word 0
.text
	#xuat tb1
	li $v0,4
	la $a0,tb1
	syscall

	#Nhap a
	li $v0,5
	syscall

	#Luu vao a
	sw $v0,a

	#xuat tb2
	li $v0,4
	la $a0,tb2
	syscall

	#Nhap b
	li $v0,5
	syscall

	#Luu vao s1
	sw $v0,b

	#load a vao $s0, b vao $s1
	lw $s0,a
	lw $s1,b
	
	#Tinh tong
	add $s2,$s0,$s1
	
	#Xuat tb3
	li $v0,4
	la $a0,tb3
	syscall

	#Xuat s2
	li $v0,1
	move $a0,$s2
	syscall
	
	#Tinh hieu
	sub $s2,$s0,$s1
	
	#Xuat tb4
	li $v0,4
	la $a0,tb4
	syscall

	#Xuat s2
	li $v0,1
	move $a0,$s2
	syscall
	
	#Tinh tich
	mult $s0,$s1
	mflo $s2
	
	
	#Xuat tb5
	li $v0,4
	la $a0,tb5
	syscall

	#Xuat s2
	li $v0,1
	move $a0,$s2
	syscall
	
	#Tinh thuong
	div $s0,$s1
	mflo $s2
	mfhi $s3
	
	#Xuat tb6
	li $v0,4
	la $a0,tb6
	syscall

	#Xuat s2
	li $v0,1
	move $a0,$s2
	syscall
	

	#Xuat tb7
	li $v0,4
	la $a0,tb7
	syscall

	#Xuat s3
	li $v0,1
	move $a0,$s3
	syscall
	
	

	
