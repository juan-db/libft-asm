section	.text
	global zeroToNine
	
zero_to_nine:
	; store r12 
	push r12
	mov rcx, 10		; amount of times to loop
	push '0'

	mov	rdi, 1		; file descriptor (stdout)
	mov rsi, rsp	; buffer
	mov	rdx, 1		; message length
	
l1:
	; Write a digit with sys_write to fd 1
	mov	rax, 1		; system call number (sys_write)
	xchg r12, rcx
	syscall			; call kernel
	xchg rcx, r12
	inc byte [rsp]

	loop l1

	add rsp, 8
	pop r12

	ret