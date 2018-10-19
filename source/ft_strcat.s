section .text
	global _ft_strcat

; rdi - s1
; rsi - s2
_ft_strcat:
	; check s1 and s2 for null
	cmp rdi, 0
	je null
	cmp rsi, 0
	je null

	; keep references to rdi & rsi
	mov r10, rdi
	mov r11, rsi

	; find end of s1
	cld
	mov rcx, -1
	mov al, 0
	repne scasb
	dec rdi

	; find end of s2
	xchg rdi, rsi
	mov rcx, -1
	repne scasb

	; copy s2 onto end of s1
	mov rdi, rsi ; rdi - movs destination, therefore rdi == s1 + strlen(s1)
	mov rsi, r11 ; rsi - movs source, therefore rsi == s2
	not rcx
	rep movsb

	; return value - rdi (s1)
	mov rax, r11
	ret

null:
	mov rax, rdi
	ret

section .data
hello db "hello"