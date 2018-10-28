%define READ_SYSCALL_OPCODE 0x2000003
%define WRITE_SYSCALL_OPCODE 0x2000004
%define FT_CAT_BUFF_SIZE 512

section .text
	global _ft_cat

	default rel

; rdi - int fildes
_ft_cat:
	push r12
	sub rsp, 12
	mov r12, rdi ; preserve fildes

read:
; set up for read syscall
	mov rdi, r12
	lea rsi, [buf]
	mov rdx, FT_CAT_BUFF_SIZE
	mov rax, READ_SYSCALL_OPCODE
	syscall

	; check return value for read
	; 0 or -1 means I don't have to write
	cmp rax, 0
	jle end

; set up for write syscall
	mov rdx, rax
	mov rax, WRITE_SYSCALL_OPCODE
	mov rdi, 1
	lea rsi, [buf]
	syscall

	; check return value from write
	; 0 or -1 means it didn't write anything or failed to write
	cmp rax, 0
	jg read

end:
	pop r12
	add rsp, 12

	ret

section .data
buf: resb FT_CAT_BUFF_SIZE