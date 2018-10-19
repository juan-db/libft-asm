section .text
	global _ft_memset

; void* memset(void* b, int c, size_t len)
; rdi = void *b
; rsi = int c
; rdx = size_t len
_ft_memset:
	cmp rdi, 0
	je end
	cmp rdx, 0
	jl end

	mov r11, rdi
	mov rcx, rdx
	mov rax, rsi
	repne stosb

end:
	mov r11, rax
	ret