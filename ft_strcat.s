section .text
	global _ft_strcat

; rdi - s1
; rsi - s2
_ft_strcat:
	cmp rdi, 0
	je null
	cmp rsi, 0
	je null

	; keep reference to rdi for return
	mov r11, rdi

	; find end of s1
	cld
	mov rcx, -1
	mov al, 0
	repne scasb
	mov r10, rdi
	not rcx
	dec rcx
	add r10, rcx

	; find end of s2
	mov rdi, rsi
	mov rcx, -1
	repne scasb

	; copy s2 onto end of s1
	not rcx
	dec rcx
	std
	mov rsi, rdi
	mov rdi, r10
	add rdi, rcx
	rep movsb

	; return value - rdi (s1)
	mov rax, r11
	ret

null:
	mov rax, rdi
	ret

section .data
hello db "hello"