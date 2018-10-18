section .text
	global _ft_isalpha

; rdi - character to check
_ft_isalpha:
	; test if the number is a lowercase character
	; test rdi >= 'a' && rdi <= 'z'
	cmp rdi, 'a'	; compare 'a' to the first argument
	jl test_upper	; if the argument is less than the ascii value of a it is not alphabetical
	cmp rdi, 'z'
	jg test_upper

	jmp equal		; c >= a && c <= z, therefore isalpha(c) > 0


test_upper:
	; test if the number is an uppercase character
	; test rdi >= 'A' && rdi <= 'Z'
	cmp rdi, 'A'
	jl not_equal
	cmp rdi, 'Z'
	jg not_equal


equal:
	mov rax, 1
	ret

not_equal:
	mov rax, 0
	ret