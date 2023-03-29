#Nhap vao a,b. Tinh tong, hieu, tich, thuong a,b.
.data
	tb1: .asciiz "Nhap a: "
	tb2: .asciiz "Nhap b: "	
	menu: .asciiz "\n======Menu======\n1. Tong\n2.Hieu\n3.Tich\n4.Thuong\n5.Thoat\n===============\nChon: "
	tb3: .asciiz "\nKet qua: "
	tb4: .asciiz "\nChuc nang khong ton tai"
	tb5: .asciiz " Du la: "
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

	#Luu vao b
	sw $v0,b
xuat_menu:
	#Xuat menu
	li $v0,4
	la $a0,menu
	syscall

	#Nhap chon
	li $v0,5
	syscall

	#luu vao t0
	move $t0,$v0
	#Load a vao s0, b vao s1
	lw $s0,a
	lw $s1,b

	#Luu gia tri chon vao $t0
	beq $t0,1,TinhTong
	beq $t0,2,TinhHieu
	beq $t0,3,TinhTich
	beq $t0,4,TinhThuong
	beq $t0,5,KetThuc	
	j NhapSai
TinhTong:
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
	
	j xuat_menu

TinhHieu:
	#Tinh hieu
	sub $s2,$s0,$s1
	
	#Xuat tb3
	li $v0,4
	la $a0,tb3
	syscall

	#Xuat s2
	li $v0,1
	move $a0,$s2
	syscall
	
	j xuat_menu

TinhTich:
	#Tinh tich
	mult $s0,$s1
	mflo $s2
	
	
	#Xuat tb3
	li $v0,4
	la $a0,tb3
	syscall

	#Xuat s2
	li $v0,1
	move $a0,$s2
	syscall
	
	j xuat_menu
TinhThuong:
	#Tinh thuong
	div $s0,$s1
	mflo $s2
	mfhi $s3
	
	#Xuat tb3
	li $v0,4
	la $a0,tb3
	syscall

	#Xuat s2
	li $v0,1
	move $a0,$s2
	syscall
	

	#Xuat tb5
	li $v0,4
	la $a0,tb5
	syscall

	#Xuat s3
	li $v0,1
	move $a0,$s3
	syscall
	
	j xuat_menu

NhapSai:
	li $v0,4
	la $a0,tb4
	syscall
	j xuat_menu
KetThuc:

	
