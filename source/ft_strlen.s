section .text
	global _ft_strlen

; rdi - string to be searched
_ft_strlen:
	; input validation - if first argument (str) is null
	cmp rdi, 0
	je null

	mov al, 0
	; string to search is already in rdi since it's the first argument
	cld
	mov rcx, -1
	repne scasb
	not rcx
	mov rax, rcx
	dec rax
	ret

null:
	mov rax, 0
	ret