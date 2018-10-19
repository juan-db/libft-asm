section .text
	global _ft_isdigit

; rdi - number to check
_ft_isdigit:
	; test %rdi >= '0' && %rdi <= '9'
	cmp rdi, '0'
	jl not_equal
	cmp rdi, '9'
	jg not_equal

equal:
	mov rax, 1		; move 1 into %rax, 1st return register
	ret

not_equal:
	mov rax, 0		; move 0 into %rax, 1st return register
	ret