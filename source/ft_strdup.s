section .text
	global _ft_strdup

	extern _malloc
	extern _printf

_ft_strdup:
	cmp rdi, 0
	je fail

	push rdi ; preserve pointer to string
	cld
	mov rcx, -1
	mov al, 0
	repne scasb
	not rcx

	push rcx ; preserve length of string
	sub rsp, 8
	mov rdi, rcx
	call _malloc
	add rsp, 8
	pop rcx ; retrieve length of string for rep	add rsp, 8
	pop rsi ; retrieve pointer to string into rsi for movsb
	cmp rax, 0
	je fail


	mov rdi, rax
	rep movsb

end:
	ret

fail:
	mov rax, 0
	ret