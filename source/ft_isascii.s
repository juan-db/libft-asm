section .text
	global _ft_isascii

; characters 0 to 0177
_ft_isascii:
; 	cmp rdi, 0
; 	jl not_equal
; 	cmp rdi, 177o
; 	jg not_equal

; equal:
; 	mov rax, 1		; move 1 into %rax, 1st return register
; 	ret

not_equal:
	mov rax, 0		; move 0 into %rax, 1st return register
	ret