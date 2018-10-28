%define READ_SYSCALL_OPCODE 0x2000003
%define WRITE_SYSCALL_OPCODE 0x2000004
%define FT_CAT_BUFF_SIZE 512

section .text
	global _ft_cat

	default rel

_ft_cat:
read:
	; set up for read syscall
	push rdi
	lea rsi, [buf]
	mov rdx, FT_CAT_BUFF_SIZE
	mov rax, READ_SYSCALL_OPCODE
	syscall
	; check return value for read
	cmp rax, -1
	je end
	cmp rax, 0
	je end

write:
	; set up for write syscall
	mov rdx, rax
	mov rax, WRITE_SYSCALL_OPCODE
	mov rdi, 1
	lea rsi, [buf]
	syscall

	pop rdi
	jmp read

end:
	ret

section .data
buf: resb FT_CAT_BUFF_SIZE