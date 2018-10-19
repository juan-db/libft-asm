section .text
	extern _ft_isdigit
	extern _ft_isalpha

	global _ft_isalnum

_ft_isalnum:
	mov r11, rdi
	call _ft_isdigit
	cmp rax, 0
	jne equal

	mov rdi, r11
	call _ft_isalpha
	cmp rax, 0
	je not_equal

equal:
	mov rax, 1
	ret

not_equal:
	mov rax, 0
	ret