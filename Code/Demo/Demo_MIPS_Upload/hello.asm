#viet chuong trinh nhap vao ten, in xin chao + ten
.data
	tb1: .asciiz "Nhap ten: "
	tb2: .asciiz "Xin chao "
	ten: .space 30
.text
	#Xuat tb1
	li $v0,4 #v0 = 4
	la $a0,tb1
	syscall

	#nhap ten
	li $v0,8
	la $a0,ten
	li $a1,30
	syscall

	#Xuat tb2
	li $v0,4 #v0 = 4
	la $a0,tb2
	syscall

	#Xuat ten
	li $v0,4 #v0 = 4
	la $a0,ten
	syscall
