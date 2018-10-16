section .text
	extern ft_isdigit
	extern ft_isalpha

	global ft_isalnum

ft_isalnum:
	mov r11, rdi
	call ft_isdigit
	cmp rax, 0
	jne equal

	mov rdi, r11
	call ft_isalpha
	cmp rax, 0
	je not_equal

equal:
	mov rax, 1
	ret

not_equal:
	mov rax, 0
	ret