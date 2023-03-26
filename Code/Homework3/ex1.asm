# Khai báo các thanh ghi sử dụng trong chương trình
.data
	n: .word 0           # số nguyên n nhập vào
	# Cac thong bao
	tb: .asciiz "Nhap so nguyen n: \n"
	kq1: .asciiz "So nguyen to\n"
	kq2: .asciiz "Khong phai so nguyen to\n"

.text
main:
	# Xuat tb nhap n:
	li $v0, 4
	la $a0, tb
	syscall

    	# Nhập giá trị của n từ bàn phím
    	li $v0, 5
    	syscall
    	sw $v0, n
	    
	lw $t0, n
	li $t1, 1
	li $t2, 0 # count = 0
	ble $t0, 1, not_prime
	
loop:
	div $t0, $t1
	addi $t1, $t1, 1
	mfhi $t3
	beq $t3, 0, increase_count
	ble $t1, $t0, loop
check_count:
	# if count == 2 -> is_prime
	# else not_prime
	beq $t2, 2, is_prime
	j not_prime
increase_count:
	# count += 1
	addi $t2, $t2, 1
	j loop
is_prime:
	# Xuat tb so nguyen to
	li $v0, 4
	la $a0, kq1
	syscall
	j finish
not_prime:
	# Xuat tb khong phai so nguyen to
	li $v0, 4
	la $a0, kq2
	syscall
	j finish

finish:
