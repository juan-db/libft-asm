section .text
	extern _ft_strlen

	global _ft_puts

; rdi - const char* s
; return non-negative on success, EOF on failure
_ft_puts:
	; check if the string is null
	cmp rdi, 0
	jne calculate_length

	lea rdi, [rel null_message]

calculate_length:
	; call to strlen to get the length of the given string to know how many bytes write(2) should write
	; increase stack pointer (16-byte aligned)
	sub rsp, 16
	; preserve rdi on the stack since strlen might modify this register
	push rdi
	call _ft_strlen
	; pop rdi from stack after function call
	pop rdi
	; decrease stack pointer back to its original size
	add rsp, 16

	; syscall to write(2) for s
	; 3d argument - size_t nbyte - amount of bytes to write
	; length of string was calculated by call to strlen above and value returned in rax
	mov rdx, rax
	; 2nd argument - const void* buff - buffer to write from
	xchg rsi, rdi	
	; 1st argument - int fildes - file descriptor to write to
	mov rdi, 1
	; opcode for write(2)
	mov rax, 0x2000004
	syscall

	; syscall to write(2) for terminating newline
	mov rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel newline]
	mov rdx, 1
	syscall

	; check if write returned -1 to indicated fail
	cmp rax, -1
	je fail

	; anything other than -1 from write indicates success
	mov rax, 1
	ret

fail:
	mov rax, -1 ; TODO eof
	ret

section .data
null_message db "(null)", 0
newline db "", 0xa