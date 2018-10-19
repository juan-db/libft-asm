section .text
	global _ft_isprint

; rdi number to check
_ft_isprint:
	cmp rdi, 40q
	jl not_equal
	cmp rdi, 176q
	jg not_equal

equal:
	mov rax, 1
	ret

not_equal:
	mov rax, 0
	ret