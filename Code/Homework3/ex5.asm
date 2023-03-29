.data
	prompt: .asciiz "Nhap mot lua chon:\n"
	menu:   .asciiz "\n1. Chuc nang 1: Nhap mang\n2. Chuc nang 2: Xuat mang\n3. Chuc nang 3: Liet ke so nguyen to\n4. Chuc nang 4: Tim gia tri lon nhat\n5. Chuc nang 5: Tinh trung binh mang\n0. Thoat khoi chuong trinh\n"
	invalid_sta: .asciiz "Lua chon khong hop le. Vui long nhap lai.\n"
	tb1: .asciiz "Chuc nang 1\n"
	tb2: .asciiz "Mang vua nhap la\n"
	tb3: .asciiz "\nCac so nguyen to trong mang la: "
	tb4: .asciiz "\nSo lon nhat trong mang la: "

	f1_1: .asciiz "Nhap n: "
	f1_2: .asciiz "a["
	f1_3: .asciiz "]: "
	f1_4: .asciiz "\nMang vua nhap la: "
	f1_5: .asciiz "\nTrung binh mang la: "
	n: .word 0
	f: .word 0
	arr: .space 100
.text

# Ham in ra man hinh menu
print_menu:
    	# In ra chuoi "menu"
    	la $a0, menu
    	li $v0, 4
    	syscall

    	# In ra chuoi "prompt"
    	la $a0, prompt
    	li $v0, 4
    	syscall

    	# Doc gia tri nhap tu ban phim
    	li $v0, 5
    	syscall
    	move $s0, $v0

    	# Tra ve gia tri nhap tu ban phim
    	beq $s0, 1, function_1
	beq $s0, 2, function_2
	beq $s0, 3, function_3
	beq $s0, 4, function_4
	beq $s0, 5, function_5
	beq $s0, 0, exit
	bgt $s0, 5, invalid

# Ham xu ly chuc nang 1
function_1:
    	# TODO: viet ma xu ly cho chuc nang 1
	#nhap so nguyen
	li $v0, 4
	la $a0, f1_1
	syscall
	li $v0,5
	syscall

	#luu vao n
	sw $v0,n
	
	#khoi tao vong lap
	la $s0,arr # s0 = arr
	lw $s1,n # s1 = n
	li $t0,0 # i = 0
	j LapNhap

    	# Quay ve menu chinh
    	j main_loop

# Ham xu ly chuc nang 2
function_2:
    	# TODO: viet ma xu ly cho chuc nang 2
	li $v0, 4
	la $a0, tb2
	syscall

	la $s0,arr # s0 = arr
	lw $s1,n # s1 = n
	li $t0,0 # i = 0
	j LapXuat
    	# Quay ve menu chinh
    	j main_loop

# Ham xu ly chuc nang 3
function_3:
    	# TODO: viet ma xu ly cho chuc nang 5
	li $v0, 4
	la $a0, tb3
	syscall

	la $s0,arr # s0 = arr
	lw $s1,n # s1 = n
	li $t0,0 # i = 0

	LapXuatPrime:
		lw $s2, ($s0)
		jal LapNguyenTo

		addi $s0, $s0, 4
		addi $t0, $t0, 1
		blt $t0, $s1, LapXuatPrime

    	# Quay ve menu chinh
    	j main_loop

# Ham xu ly chuc nang 4
function_4:
    	# TODO: viet ma xu ly cho chuc nang 4
	li $v0, 4
	la $a0, tb4
	syscall

	la $s0,arr # s0 = arr
	lw $s1,n # s1 = n
	lw $t3, ($s0)
	li $t0, 0 # i = 0
	j LapMax
    	# Quay ve menu chinh
    	j main_loop

# Ham xu ly chuc nang 5
function_5:
    	# TODO: viet ma xu ly cho chuc nang 3
	li $v0, 4
	la $a0, f1_5
	syscall

	lw $s1, n # s1 = n
	li $t0, 0
	la $s0, arr
	li $s2, 0
	j LapTong

    	# Quay ve menu chinh	
    	j main_loop

# Ham xu ly cac chuc nang
main_loop:
    	# In ra menu
    	jal print_menu
invalid:
	li $v0, 4
    	la $a0, invalid_sta
    	syscall
	j exit

LapNhap:
	#xuat tb2
	li $v0,4
	la $a0,f1_2
	syscall

	#xuat i
	li $v0,1
	move $a0,$t0
	syscall

	#xuat tb3
	li $v0,4
	la $a0,f1_3
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
	j main_loop
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
	j main_loop

LapTong:
	lw $t2, ($s0)
	add $s2, $s2, $t2
	
	addi $s0, $s0, 4
	addi $t0, $t0, 1
	blt $t0, $s1, LapTong
	
	mtc1 $s2, $f0
	cvt.s.w $f0, $f0

	lw $t1, n
	mtc1 $t1, $f1
	cvt.s.w $f1, $f1

	div.s $f2, $f0, $f1
	
	li $v0, 2
	mov.s $f12, $f2
	syscall
	j main_loop
LapMax:
	lw $t1, ($s0)
	bgt $t1, $t3, ChangeFlag
	j Increase
ChangeFlag:
	add $t3, $t1, $zero
	j Increase
Increase:
	addi $s0, $s0, 4
	addi $t0, $t0, 1
	blt $t0, $s1, LapMax
	
	# Ket thuc vong lap
	li $v0, 1
	move $a0, $t3
	syscall
	j main_loop
LapNguyenTo:
	li $s3, 0
	li $t1, 1
	li $t2, 0 # count = 0
	ble $s2, 1, not_prime
	loop:
		div $s2, $t1
		addi $t1, $t1, 1
		mfhi $t3
		beq $t3, 0, increase_count
		ble $t1, $s2, loop
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
		li $v0, 1
		move $a0, $s2
		syscall

		#xuat khoang trang
		li $v0,11
		li $a0,' '
		syscall

		jr $ra
	not_prime:
		jr $ra
exit:
