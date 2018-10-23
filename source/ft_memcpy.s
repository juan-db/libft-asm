section .text
	global _ft_memcpy

; void* memcpy(void* dst, const void* src, size_t n)
_ft_memcpy:
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end
	cmp rdx, 0
	jl end

	cld
	mov rax, rdi
	mov rcx, rdx
	rep movsb

end:
	ret