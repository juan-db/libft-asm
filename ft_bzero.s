section .text
	global ft_bzero

; rdi - address of memory to clear
; rsi - amount of bytes to clear
ft_bzero:
	; validation
	cmp rdi, 0
	jle end

	cmp rsi, 0
	jle end

	; core logic
	cld				; clear direction flag which determines in which direction string instructions operate
					; if the flag is cleared it goes left to right, if it's set it goes right to left.
	mov rcx, rsi	; move count into rcx for loop
	mov al, 0		; move character to be written with stosb to cl
	rep stosb		; repeat stosb and decrement rcx until rcx == 0.
					; stosb copies the value from cl to 

end:
	; return
	ret